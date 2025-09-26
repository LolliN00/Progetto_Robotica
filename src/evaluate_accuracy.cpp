#include "data_loader.h"
#include "ekf_centralized.h"
#include "groundtruth_loader.h"
#include <iostream>
#include <iomanip>
#include <cmath>

struct RobotGroundtruth {
    double timestamp;
    double x, y, theta;
};

std::vector<RobotGroundtruth> loadGroundtruth(const std::string& filename) {
    std::vector<RobotGroundtruth> gt_data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Cannot open groundtruth file: " << filename << std::endl;
        return gt_data;
    }
    
    std::string line;
    // Skip comments
    while (std::getline(file, line) && line.find('#') != std::string::npos);
    
    do {
        if (line.empty()) continue;
        std::stringstream ss(line);
        RobotGroundtruth gt;
        ss >> gt.timestamp >> gt.x >> gt.y >> gt.theta;
        gt_data.push_back(gt);
    } while (std::getline(file, line));
    
    return gt_data;
}

double normalizeAngle(double angle) {
    while (angle > M_PI) angle -= 2.0 * M_PI;
    while (angle < -M_PI) angle += 2.0 * M_PI;
    return angle;
}

int main() {
    DataLoader loader;
    std::string dataset_path = "MRCLAM1/MRCLAM_Dataset1/";
    
    // Load groundtruth data
    auto robot1_gt = loadGroundtruth(dataset_path + "Robot1_Groundtruth.dat");
    auto robot2_gt = loadGroundtruth(dataset_path + "Robot2_Groundtruth.dat");
    
    if (robot1_gt.empty() || robot2_gt.empty()) {
        std::cerr << "Failed to load groundtruth data" << std::endl;
        return -1;
    }
    
    std::cout << "Loaded " << robot1_gt.size() << " groundtruth points for Robot 1" << std::endl;
    std::cout << "Loaded " << robot2_gt.size() << " groundtruth points for Robot 2" << std::endl;
    
    // Load dataset for EKF simulation
    if (!loader.loadBarcodes(dataset_path + "Barcodes.dat") ||
        !loader.loadLandmarkGroundtruth(dataset_path + "Landmark_Groundtruth.dat") ||
        !loader.loadOdometry(dataset_path + "Robot1_Odometry.dat", 1) ||
        !loader.loadOdometry(dataset_path + "Robot2_Odometry.dat", 2) ||
        !loader.loadMeasurements(dataset_path + "Robot1_Measurement.dat", 1) ||
        !loader.loadMeasurements(dataset_path + "Robot2_Measurement.dat", 2)) {
        std::cerr << "Failed to load dataset" << std::endl;
        return -1;
    }
    
    // Initialize EKF with initial groundtruth positions using the new function
    Eigen::VectorXd initial_state = getInitialStateFromGroundtruth(dataset_path, 2);
    
    EkfCentralized ekf(2, initial_state);
    ekf.setLandmarks(loader.getLandmarks());
    
    std::cout << "\nInitial state from groundtruth:" << std::endl;
    std::cout << "Robot 1: x=" << robot1_gt[0].x << " y=" << robot1_gt[0].y << " θ=" << robot1_gt[0].theta << std::endl;
    std::cout << "Robot 2: x=" << robot2_gt[0].x << " y=" << robot2_gt[0].y << " θ=" << robot2_gt[0].theta << std::endl;
    
    // Process events
    const auto& events = loader.getEventQueue();
    double last_timestamp = 0.0;
    size_t events_processed = 0;
    
    // Process all events (can limit if too many)
    size_t max_events = std::min(events.size(), size_t(50000)); // Process 50k events for speed
    
    for (size_t i = 0; i < max_events; ++i) {
        const Event& event = events[i];
        
        std::visit([&](const auto& data) {
            using T = std::decay_t<decltype(data)>;
            if constexpr (std::is_same_v<T, OdometryData>) {
                double dt = (last_timestamp > 0) ? data.timestamp - last_timestamp : 0.1;
                ekf.predict(data, dt);
            } else if constexpr (std::is_same_v<T, MeasurementData>) {
                ekf.correct(data);
            }
            last_timestamp = data.timestamp;
        }, event);
        
        events_processed++;
        if (events_processed % 10000 == 0) {
            std::cout << "Processed " << events_processed << " events..." << std::endl;
        }
    }
    
    // Get final EKF state
    const auto& final_state = ekf.getState();
    const auto& final_cov = ekf.getCovariance();
    
    // Find closest groundtruth timestamps
    auto& robot1_final_gt = robot1_gt.back();
    auto& robot2_final_gt = robot2_gt.back();
    
    std::cout << "\n=== FINAL ACCURACY EVALUATION ===" << std::endl;
    std::cout << "Events processed: " << events_processed << " / " << events.size() << std::endl;
    std::cout << "Final timestamp: " << std::fixed << std::setprecision(3) << last_timestamp << std::endl;
    
    // Calculate errors
    double robot1_error_x = final_state[0] - robot1_final_gt.x;
    double robot1_error_y = final_state[1] - robot1_final_gt.y;
    double robot1_error_theta = normalizeAngle(final_state[2] - robot1_final_gt.theta);
    double robot1_error_pos = sqrt(robot1_error_x*robot1_error_x + robot1_error_y*robot1_error_y);
    
    double robot2_error_x = final_state[3] - robot2_final_gt.x;
    double robot2_error_y = final_state[4] - robot2_final_gt.y;
    double robot2_error_theta = normalizeAngle(final_state[5] - robot2_final_gt.theta);
    double robot2_error_pos = sqrt(robot2_error_x*robot2_error_x + robot2_error_y*robot2_error_y);
    
    std::cout << "\nROBOT 1 ACCURACY:" << std::endl;
    std::cout << "Groundtruth: x=" << robot1_final_gt.x << " y=" << robot1_final_gt.y << " θ=" << robot1_final_gt.theta << std::endl;
    std::cout << "EKF estimate: x=" << final_state[0] << " y=" << final_state[1] << " θ=" << final_state[2] << std::endl;
    std::cout << "Errors: Δx=" << robot1_error_x << "m, Δy=" << robot1_error_y << "m, Δθ=" << robot1_error_theta << "rad" << std::endl;
    std::cout << "Position error: " << robot1_error_pos << "m" << std::endl;
    std::cout << "Angular error: " << fabs(robot1_error_theta) << "rad (" << fabs(robot1_error_theta) * 180/M_PI << "°)" << std::endl;
    std::cout << "Uncertainty: σx=" << sqrt(final_cov(0,0)) << " σy=" << sqrt(final_cov(1,1)) << " σθ=" << sqrt(final_cov(2,2)) << std::endl;
    
    std::cout << "\nROBOT 2 ACCURACY:" << std::endl;
    std::cout << "Groundtruth: x=" << robot2_final_gt.x << " y=" << robot2_final_gt.y << " θ=" << robot2_final_gt.theta << std::endl;
    std::cout << "EKF estimate: x=" << final_state[3] << " y=" << final_state[4] << " θ=" << final_state[5] << std::endl;
    std::cout << "Errors: Δx=" << robot2_error_x << "m, Δy=" << robot2_error_y << "m, Δθ=" << robot2_error_theta << "rad" << std::endl;
    std::cout << "Position error: " << robot2_error_pos << "m" << std::endl;
    std::cout << "Angular error: " << fabs(robot2_error_theta) << "rad (" << fabs(robot2_error_theta) * 180/M_PI << "°)" << std::endl;
    std::cout << "Uncertainty: σx=" << sqrt(final_cov(3,3)) << " σy=" << sqrt(final_cov(4,4)) << " σθ=" << sqrt(final_cov(5,5)) << std::endl;
    
    // Overall performance metrics
    double avg_pos_error = (robot1_error_pos + robot2_error_pos) / 2.0;
    double avg_ang_error = (fabs(robot1_error_theta) + fabs(robot2_error_theta)) / 2.0;
    
    std::cout << "\n=== OVERALL PERFORMANCE ===" << std::endl;
    std::cout << "Average position error: " << avg_pos_error << "m" << std::endl;
    std::cout << "Average angular error: " << avg_ang_error << "rad (" << avg_ang_error * 180/M_PI << "°)" << std::endl;
    
    // Performance evaluation
    std::cout << "\n=== PERFORMANCE EVALUATION ===" << std::endl;
    if (avg_pos_error < 0.5) {
        std::cout << "EXCELLENT position accuracy (< 0.5m)" << std::endl;
    } else if (avg_pos_error < 1.0) {
        std::cout << " GOOD position accuracy (< 1.0m)" << std::endl;
    } else if (avg_pos_error < 2.0) {
        std::cout << "  ACCEPTABLE position accuracy (< 2.0m)" << std::endl;
    } else {
        std::cout << " POOR position accuracy (> 2.0m)" << std::endl;
    }
    
    if (avg_ang_error * 180/M_PI < 10.0) {
        std::cout << " EXCELLENT angular accuracy (< 10°)" << std::endl;
    } else if (avg_ang_error * 180/M_PI < 20.0) {
        std::cout << " GOOD angular accuracy (< 20°)" << std::endl;
    } else if (avg_ang_error * 180/M_PI < 45.0) {
        std::cout << "  ACCEPTABLE angular accuracy (< 45°)" << std::endl;
    } else {
        std::cout << " POOR angular accuracy (> 45°)" << std::endl;
    }
    
    return 0;

}
