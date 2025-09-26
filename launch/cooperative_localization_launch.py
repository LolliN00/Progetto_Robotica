from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Package directory
    pkg_dir = get_package_share_directory('cooperative_localization')
    
    # Launch arguments
    dataset_path_arg = DeclareLaunchArgument(
        'dataset_path',
        default_value='MRCLAM1/MRCLAM_Dataset1/',
        description='Path to the UTIAS dataset'
    )
    
    playback_speed_arg = DeclareLaunchArgument(
        'playback_speed',
        default_value='2.0',  # 2x speed for faster demo
        description='Dataset playback speed multiplier'
    )
    
    print_interval_arg = DeclareLaunchArgument(
        'print_interval',
        default_value='3.0',  # Print every 3 seconds
        description='Interval for printing EKF state (seconds)'
    )
    
    # Centralized EKF node
    centralized_node = Node(
        package='cooperative_localization',
        executable='coop_localization_node',
        name='centralized_ekf_node',
        output='screen',
        parameters=[{
            'num_robots': 2,
            'dataset_path': LaunchConfiguration('dataset_path'),
            'print_interval': LaunchConfiguration('print_interval'),
            'use_groundtruth_init': True  # Use groundtruth initial positions
        }]
    )
    
    # Robot 1 node
    robot1_node = Node(
        package='cooperative_localization',
        executable='robot_node',
        name='robot_1_node',
        output='screen',
        arguments=['1'],  # Robot ID
        parameters=[{
            'dataset_path': LaunchConfiguration('dataset_path'),
            'playback_speed': LaunchConfiguration('playback_speed')
        }]
    )
    
    # Robot 2 node
    robot2_node = Node(
        package='cooperative_localization',
        executable='robot_node',
        name='robot_2_node',
        output='screen',
        arguments=['2'],  # Robot ID
        parameters=[{
            'dataset_path': LaunchConfiguration('dataset_path'),
            'playback_speed': LaunchConfiguration('playback_speed')
        }]
    )
    
    return LaunchDescription([
        dataset_path_arg,
        playback_speed_arg,
        print_interval_arg,
        centralized_node,
        robot1_node,
        robot2_node
    ])