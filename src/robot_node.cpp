#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "cooperative_localization/msg/measurement.hpp"
#include "cooperative_localization/msg/dataset_status.hpp"
#include "data_loader.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class RobotNode : public rclcpp::Node {
public:
    RobotNode(int robot_id) : Node("robot_" + std::to_string(robot_id) + "_node"), 
                              robot_id_(robot_id) {
        
        // Publishers
        odom_pub_ = create_publisher<nav_msgs::msg::Odometry>("/odom", 10);
        landmark_pub_ = create_publisher<cooperative_localization::msg::Measurement>("/landmark", 10); 
        robot_pub_ = create_publisher<cooperative_localization::msg::Measurement>("/robot", 10);
        status_pub_ = create_publisher<cooperative_localization::msg::DatasetStatus>("/dataset_status", 10);
        
        // Parameters
        declare_parameter("dataset_path", std::string("MRCLAM1/MRCLAM_Dataset1/"));
        declare_parameter("playback_speed", 1.0);
        
        std::string dataset_path;
        get_parameter("dataset_path", dataset_path);
        get_parameter("playback_speed", playback_speed_);
        
        // Load dataset
        if (!loadRobotData(dataset_path)) {
            RCLCPP_ERROR(get_logger(), "Failed to load dataset for robot %d", robot_id_);
            return;
        }
        
        RCLCPP_INFO(get_logger(), "Robot %d loaded %zu events", robot_id_, events_.size());
        
        // Start publishing
        timer_ = create_wall_timer(10ms, std::bind(&RobotNode::publishData, this));
        
        current_event_ = 0;
        start_time_ = now();
        if (!events_.empty()) {
            auto first_timestamp = std::visit([](const auto& event) { return event.timestamp; }, events_[0]);
            dataset_start_time_ = first_timestamp;
        }
    }

private:
    bool loadRobotData(const std::string& dataset_path) {
        DataLoader loader;
        
        // Load barcode mapping
        if (!loader.loadBarcodes(dataset_path + "Barcodes.dat")) {
            return false;
        }
        
        // Load this robot's data
        std::string odom_file = dataset_path + "Robot" + std::to_string(robot_id_) + "_Odometry.dat";
        std::string meas_file = dataset_path + "Robot" + std::to_string(robot_id_) + "_Measurement.dat";
        
        if (!loader.loadOdometry(odom_file, robot_id_)) {
            RCLCPP_ERROR(get_logger(), "Failed to load odometry from %s", odom_file.c_str());
            return false;
        }
        
        if (!loader.loadMeasurements(meas_file, robot_id_)) {
            RCLCPP_WARN(get_logger(), "Failed to load measurements from %s", meas_file.c_str());
            // Continue anyway, some robots might not have measurements
        }
        
        events_ = loader.getEventQueue();
        return true;
    }
    
    void publishData() {
        if (current_event_ >= events_.size()) {
            return; // All events published
        }
        
        auto current_ros_time = now();
        double elapsed_real_time = (current_ros_time - start_time_).seconds() * playback_speed_;
        
        // Publish all events that should have happened by now
        while (current_event_ < events_.size()) {
            const auto& event = events_[current_event_];
            
            double event_timestamp = std::visit([](const auto& e) { return e.timestamp; }, event);
            double event_offset = event_timestamp - dataset_start_time_;
            
            if (event_offset > elapsed_real_time) {
                break; // This event is in the future
            }
            
            // Publish the event
            std::visit([this, &current_ros_time](const auto& data) {
                using T = std::decay_t<decltype(data)>;
                
                if constexpr (std::is_same_v<T, OdometryData>) {
                    publishOdometry(data, current_ros_time);
                } else if constexpr (std::is_same_v<T, MeasurementData>) {
                    publishMeasurement(data, current_ros_time);
                }
            }, event);
            
            current_event_++;
        }
        
        if (current_event_ >= events_.size()) {
            RCLCPP_INFO(get_logger(), "Robot %d finished publishing all %zu events", 
                       robot_id_, events_.size());
            
            // Publish finished status
            auto status_msg = cooperative_localization::msg::DatasetStatus();
            status_msg.robot_id = robot_id_;
            status_msg.finished = true;
            status_pub_->publish(status_msg);
            
            timer_->cancel();
            
            // Small delay to ensure message is sent, then shutdown
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            rclcpp::shutdown();
        }
    }
    
    void publishOdometry(const OdometryData& odom, rclcpp::Time stamp) {
        auto msg = nav_msgs::msg::Odometry();
        msg.header.stamp = stamp;
        msg.header.frame_id = "odom";
        msg.child_frame_id = std::to_string(robot_id_);
        
        msg.twist.twist.linear.x = odom.v;
        msg.twist.twist.angular.z = odom.w;
        
        odom_pub_->publish(msg);
        
        RCLCPP_DEBUG(get_logger(), "Robot %d published odometry: v=%.3f, w=%.3f", 
                     robot_id_, odom.v, odom.w);
    }
    
    void publishMeasurement(const MeasurementData& meas, rclcpp::Time stamp) {
        auto msg = cooperative_localization::msg::Measurement();
        msg.stamp = stamp;
        msg.observer_id = meas.observer_id;
        msg.subject_id = meas.subject_id;
        msg.range = meas.range;
        msg.bearing = meas.bearing;
        
        // Determine if this is a landmark or robot measurement
        // Typically robots have IDs 1-5, landmarks have higher IDs
        if (meas.subject_id <= 5) {
            robot_pub_->publish(msg);
            RCLCPP_DEBUG(get_logger(), "Robot %d published robot measurement: robot %d at range=%.3f, bearing=%.3f", 
                         robot_id_, meas.subject_id, meas.range, meas.bearing);
        } else {
            landmark_pub_->publish(msg);
            RCLCPP_DEBUG(get_logger(), "Robot %d published landmark measurement: landmark %d at range=%.3f, bearing=%.3f", 
                         robot_id_, meas.subject_id, meas.range, meas.bearing);
        }
    }
    
    int robot_id_;
    std::vector<Event> events_;
    size_t current_event_;
    double playback_speed_;
    double dataset_start_time_;
    rclcpp::Time start_time_;
    
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Publisher<cooperative_localization::msg::Measurement>::SharedPtr landmark_pub_;
    rclcpp::Publisher<cooperative_localization::msg::Measurement>::SharedPtr robot_pub_;
    rclcpp::Publisher<cooperative_localization::msg::DatasetStatus>::SharedPtr status_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <robot_id>" << std::endl;
        return -1;
    }
    
    int robot_id = std::atoi(argv[1]);
    if (robot_id < 1 || robot_id > 5) {
        std::cerr << "Robot ID must be between 1 and 5" << std::endl;
        return -1;
    }
    
    auto node = std::make_shared<RobotNode>(robot_id);
    rclcpp::spin(node);
    rclcpp::shutdown();
    
    return 0;
}