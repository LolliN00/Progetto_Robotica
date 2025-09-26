#ifndef GROUNDTRUTH_LOADER_H
#define GROUNDTRUTH_LOADER_H

#include <Eigen/Dense>
#include <string>

// Function to get initial state from groundtruth files
Eigen::VectorXd getInitialStateFromGroundtruth(const std::string& dataset_path, int num_robots);

#endif // GROUNDTRUTH_LOADER_H