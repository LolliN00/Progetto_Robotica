#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "cooperative_localization/msg/measurement.hpp"
#include "cooperative_localization/msg/dataset_status.hpp"
#include "ekf_centralized.h"
#include "data_loader.h"
#include "groundtruth_loader.h"
#include <memory>
#include <vector>
#include <set>

using std::placeholders::_1;

class CentralizedEkfNode : public rclcpp::Node {
public:
    CentralizedEkfNode() : Node("centralized_ekf_node"), 
                          last_time_(0.0), has_time_(false) {
        
        // Parameters
        declare_parameter("num_robots", 2);
        declare_parameter("dataset_path", std::string("MRCLAM1/MRCLAM_Dataset1/"));
        declare_parameter("print_interval", 5.0); // seconds
        declare_parameter("use_groundtruth_init", true); // New parameter
        
        int num_robots;
        std::string dataset_path;
        bool use_groundtruth_init;
        
        get_parameter("num_robots", num_robots);
        get_parameter("dataset_path", dataset_path);
        get_parameter("print_interval", print_interval_);
        get_parameter("use_groundtruth_init", use_groundtruth_init);
        
        num_robots_ = num_robots;
        
        // Initialize EKF with groundtruth or default state
        Eigen::VectorXd initial_state;
        if (use_groundtruth_init) {
            RCLCPP_INFO(get_logger(), "Loading initial state from groundtruth...");
            initial_state = getInitialStateFromGroundtruth(dataset_path, num_robots);
        } else {
            RCLCPP_INFO(get_logger(), "Using default initial state...");
            initial_state = Eigen::VectorXd::Zero(num_robots * 3);
        }
        
        ekf_ = std::make_unique<EkfCentralized>(num_robots, initial_state);
        
        // Load landmarks from dataset
        DataLoader loader;
        if (loader.loadLandmarkGroundtruth(dataset_path + "Landmark_Groundtruth.dat")) {
            ekf_->setLandmarks(loader.getLandmarks());
            RCLCPP_INFO(get_logger(), "Loaded %zu landmarks", loader.getLandmarks().size());
        } else {
            RCLCPP_WARN(get_logger(), "Failed to load landmarks");
        }
        
        // Subscribers
        odom_sub_ = create_subscription<nav_msgs::msg::Odometry>(
            "/odom", 10, std::bind(&CentralizedEkfNode::odomCallback, this, _1));
        landmark_sub_ = create_subscription<cooperative_localization::msg::Measurement>(
            "/landmark", 10, std::bind(&CentralizedEkfNode::landmarkCallback, this, _1));
        robot_sub_ = create_subscription<cooperative_localization::msg::Measurement>(
            "/robot", 10, std::bind(&CentralizedEkfNode::robotCallback, this, _1));
        status_sub_ = create_subscription<cooperative_localization::msg::DatasetStatus>(
            "/dataset_status", 10, std::bind(&CentralizedEkfNode::statusCallback, this, _1));
        
        // Timer for periodic state printing
        print_timer_ = create_wall_timer(
            std::chrono::duration<double>(print_interval_),
            std::bind(&CentralizedEkfNode::printState, this));
        
        RCLCPP_INFO(get_logger(), "Centralized EKF node initialized for %d robots", num_robots);
        RCLCPP_INFO(get_logger(), "Waiting for data on topics: /odom, /landmark, /robot");
    }

private:
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        double time = rclcpp::Time(msg->header.stamp).seconds();
        
        OdometryData odom;
        odom.timestamp = time;
        odom.v = msg->twist.twist.linear.x;
        odom.w = msg->twist.twist.angular.z;
        
        try {
            odom.robot_id = std::stoi(msg->child_frame_id);
        } catch(...) {
            RCLCPP_WARN(get_logger(), "Invalid robot ID in odometry message, using ID 1");
            odom.robot_id = 1;
        }
        
        if(!has_time_) {
            last_time_ = time;
            has_time_ = true;
            RCLCPP_INFO(get_logger(), "First odometry received from robot %d", odom.robot_id);
            return;
        }
        
        double dt = time - last_time_;
        if (dt > 0.0 && dt < 1.0) { // Sanity check
            ekf_->predict(odom, dt);
            
            RCLCPP_DEBUG(get_logger(), "Prediction: Robot %d, v=%.3f, w=%.3f, dt=%.3f", 
                        odom.robot_id, odom.v, odom.w, dt);
            
            measurements_since_print_++;
        }
        
        last_time_ = time;
    }
    
    void landmarkCallback(const cooperative_localization::msg::Measurement::SharedPtr msg) {
        MeasurementData meas;
        meas.timestamp = rclcpp::Time(msg->stamp).seconds();
        meas.observer_id = msg->observer_id;
        meas.subject_id = msg->subject_id;
        meas.range = msg->range;
        meas.bearing = msg->bearing;
        
        ekf_->correct(meas);
        
        RCLCPP_DEBUG(get_logger(), "Landmark correction: Robot %d -> Landmark %d, range=%.3f, bearing=%.3f", 
                    meas.observer_id, meas.subject_id, meas.range, meas.bearing);
        
        landmark_measurements_++;
        measurements_since_print_++;
    }
    
    void robotCallback(const cooperative_localization::msg::Measurement::SharedPtr msg) {
        MeasurementData meas;
        meas.timestamp = rclcpp::Time(msg->stamp).seconds();
        meas.observer_id = msg->observer_id;
        meas.subject_id = msg->subject_id;
        meas.range = msg->range;
        meas.bearing = msg->bearing;
        
        ekf_->correct(meas);
        
        RCLCPP_DEBUG(get_logger(), "Robot-robot correction: Robot %d -> Robot %d, range=%.3f, bearing=%.3f", 
                    meas.observer_id, meas.subject_id, meas.range, meas.bearing);
        
        robot_measurements_++;
        measurements_since_print_++;
    }
    
    void printState() {
        if (measurements_since_print_ == 0) {
            RCLCPP_INFO(get_logger(), "No new measurements received in the last %.1f seconds", print_interval_);
            return;
        }
        
        RCLCPP_INFO(get_logger(), "\n=== EKF STATE UPDATE ===");
        RCLCPP_INFO(get_logger(), "Measurements processed since last print: %d", measurements_since_print_);
        RCLCPP_INFO(get_logger(), "Total landmark measurements: %d", landmark_measurements_);
        RCLCPP_INFO(get_logger(), "Total robot-robot measurements: %d", robot_measurements_);
        
        const auto& state = ekf_->getState();
        const auto& P = ekf_->getCovariance();
        
        int num_robots = state.size() / 3;
        for (int i = 0; i < num_robots; ++i) {
            int idx = i * 3;
            RCLCPP_INFO(get_logger(), "Robot %d: x=%.3f, y=%.3f, θ=%.3f (σx=%.3f, σy=%.3f, σθ=%.3f)",
                       i + 1,
                       state[idx], state[idx+1], state[idx+2],
                       sqrt(P(idx,idx)), sqrt(P(idx+1,idx+1)), sqrt(P(idx+2,idx+2)));
        }
        
        measurements_since_print_ = 0;
    }
    
    void statusCallback(const cooperative_localization::msg::DatasetStatus::SharedPtr msg) {
        if (msg->finished) {
            finished_robots_.insert(msg->robot_id);
            RCLCPP_INFO(get_logger(), "Robot %d finished its dataset", msg->robot_id);
            
            if (finished_robots_.size() == num_robots_) {
                RCLCPP_INFO(get_logger(), "All robots finished! Final EKF state:");
                printFinalState();
                
                // Shutdown the node
                rclcpp::shutdown();
            }
        }
    }
    
    void printFinalState() {
        const auto& state = ekf_->getState();
        const auto& P = ekf_->getCovariance();
        
        RCLCPP_INFO(get_logger(), "\n=== FINAL EKF STATE ===");
        RCLCPP_INFO(get_logger(), "Total landmark measurements processed: %d", landmark_measurements_);
        RCLCPP_INFO(get_logger(), "Total robot-robot measurements processed: %d", robot_measurements_);
        
        int num_robots = state.size() / 3;
        for (int i = 0; i < num_robots; ++i) {
            int idx = i * 3;
            RCLCPP_INFO(get_logger(), "Robot %d FINAL: x=%.3f, y=%.3f, θ=%.3f (σx=%.3f, σy=%.3f, σθ=%.3f)",
                       i + 1,
                       state[idx], state[idx+1], state[idx+2],
                       sqrt(P(idx,idx)), sqrt(P(idx+1,idx+1)), sqrt(P(idx+2,idx+2)));
        }
    }
    
    std::unique_ptr<EkfCentralized> ekf_;
    double last_time_;
    bool has_time_;
    double print_interval_;
    int num_robots_;
    std::set<int> finished_robots_;
    
    int measurements_since_print_ = 0;
    int landmark_measurements_ = 0;
    int robot_measurements_ = 0;
    
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Subscription<cooperative_localization::msg::Measurement>::SharedPtr landmark_sub_;
    rclcpp::Subscription<cooperative_localization::msg::Measurement>::SharedPtr robot_sub_;
    rclcpp::Subscription<cooperative_localization::msg::DatasetStatus>::SharedPtr status_sub_;
    rclcpp::TimerBase::SharedPtr print_timer_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<CentralizedEkfNode>();
    rclcpp::spin(node);
    
    rclcpp::shutdown();
    return 0;
}