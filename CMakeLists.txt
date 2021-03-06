cmake_minimum_required(VERSION 2.8.3)
project(multi_sensor_tracker)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  pcl_conversions
  pcl_ros
  roscpp
  sensor_msgs
  # for octomap

  grid_map_core
  grid_map_ros
  grid_map_cv
  grid_map_filters
  grid_map_loader
  grid_map_msgs
  grid_map_octomap
  grid_map_rviz_plugin
  geometry_msgs
    cv_bridge
    octomap_msgs
    filters
    tf_conversions
    eigen_conversions
#from Rob's code
#  compressed_image_transport
#  cv_bridge
#  image_transport
#  rospy
#  std_msgs
#  apriltags
#  tf_conversions
#  message_filters # for callback with both inputs
)
find_package(Eigen3 REQUIRED) # from Rob's code


catkin_package(
    CATKIN_DEPENDS roscpp sensor_msgs
)
# FOR OCTO MAP
find_package(octomap REQUIRED)
include_directories(${OCTOMAP_INCLUDE_DIRS})
#target_link_libraries(${OCTOMAP_LIBRARIES})
#link_directories(${OCTOMAP_LIBRARY_DIRS})
#############################################

include_directories(
  src/include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
  ${PROJECT_NAME}
  # for Octomap
  ${OCTOMAP_INCLUDE_DIR}

  ${EIGEN3_INCLUDE_DIRS} # from Rob's code
  INCLUDE_DIRS include
)

## Declare a C++ library
 add_library(${PROJECT_NAME}
   src/kalman_filter.cpp
   src/tracklet.cpp
   src/realsense_detector.py
   #   src/old_files/tracker.cpp
   #   src/centroid_estimator.cpp
   #   src/pairing.cpp
 )

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (mo_tracker_node src/mo_tracker_node.cpp src/mo_tracker.cpp)
target_link_libraries (mo_tracker_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${PROJECT_NAME})

#add_executable(pcd_read src/pcd_read.cpp)
#target_link_libraries(pcd_read ${catkin_LIBRARIES} ${PCL_LIBRARIES})

#add_executable (voxel_grid src/voxel_grid.cpp)
#target_link_libraries (voxel_grid ${catkin_LIBRARIES} ${PCL_LIBRARIES})

#add_executable (passthrough src/passthrough.cpp)
#target_link_libraries (passthrough ${catkin_LIBRARIES} ${PCL_LIBRARIES})


#add_executable (clustering src/clustering.cpp)
#target_link_libraries (clustering ${catkin_LIBRARIES} ${PCL_LIBRARIES})

#add_executable (velodyne_tracker src/velodyne_tracker.cpp)
#target_link_libraries (velodyne_tracker ${catkin_LIBRARIES} ${PCL_LIBRARIES})

#add_executable (average_tracker src/average_tracker.cpp)
#target_link_libraries (average_tracker ${catkin_LIBRARIES} ${PCL_LIBRARIES})

#add_executable (kalman_test src/kalman_test.cpp)
#target_link_libraries (kalman_test ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${PROJECT_NAME})

#add_executable (kalman_filter_tracker src/kalman_filter_tracker.cpp)
#target_link_libraries (kalman_filter_tracker ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${PROJECT_NAME})

#add_executable (nearest_cluster_tracker src/nearest_cluster_tracker.cpp)
#target_link_libraries (nearest_cluster_tracker ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${PROJECT_NAME})

#add_executable (tracker_node src/old_files/tracker_node.cpp src/old_files/tracker.cpp)
#target_link_libraries (tracker_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${PROJECT_NAME})

#add_executable (mo_tracker_node src/mo_tracker_node.cpp src/mo_tracker.cpp)
#target_link_libraries (mo_tracker_node ${catkin_LIBRARIES} ${PCL_LIBRARIES} ${PROJECT_NAME})
### CDT Navigation Demo
#add_executable(
#  challenge_node
#  src/challenge_node.cpp
#  src/Challenge.cpp
#)
#target_link_libraries(
#  challenge_node
#  ${catkin_LIBRARIES}
#)
