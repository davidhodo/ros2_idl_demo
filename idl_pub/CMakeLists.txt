cmake_minimum_required(VERSION 3.5)
project(idl_pub)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(idl_msgs REQUIRED)

add_executable(idl_pub src/idl_pub.cpp)
ament_target_dependencies(idl_pub rclcpp idl_msgs)


install(TARGETS
  idl_pub
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()