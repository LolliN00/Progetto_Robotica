#include "data_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

struct GroundtruthData {
    double timestamp;
    double x, y, theta;
};

std::vector<GroundtruthData> loadGroundtruthFile(const std::string& filename) {
    std::vector<GroundtruthData> gt_data;
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
        GroundtruthData gt;
        ss >> gt.timestamp >> gt.x >> gt.y >> gt.theta;
        gt_data.push_back(gt);
    } while (std::getline(file, line));
    
    return gt_data;
}

Eigen::VectorXd getInitialStateFromGroundtruth(const std::string& dataset_path, int num_robots) {
    Eigen::VectorXd initial_state(num_robots * 3);
    
    for (int i = 1; i <= num_robots; ++i) {
        std::string gt_file = dataset_path + "Robot" + std::to_string(i) + "_Groundtruth.dat";
        auto gt_data = loadGroundtruthFile(gt_file);
        
        if (!gt_data.empty()) {
            int idx = (i - 1) * 3;
            initial_state[idx] = gt_data[0].x;     // x
            initial_state[idx + 1] = gt_data[0].y; // y  
            initial_state[idx + 2] = gt_data[0].theta; // theta
            
            std::cout << "Robot " << i << " initial groundtruth: x=" << gt_data[0].x 
                      << " y=" << gt_data[0].y << " θ=" << gt_data[0].theta << std::endl;
        } else {
            std::cerr << "Warning: No groundtruth data for Robot " << i << ", using default (0,0,0)" << std::endl;
            int idx = (i - 1) * 3;
            initial_state[idx] = 0.0;
            initial_state[idx + 1] = 0.0; 
            initial_state[idx + 2] = 0.0;
        }
    }
    
    return initial_state;
}