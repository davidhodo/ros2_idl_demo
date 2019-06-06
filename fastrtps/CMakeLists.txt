
cmake_minimum_required(VERSION 2.8.12)

project("rtps_timestamp")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)


message(STATUS "Configuring Timestamp...")
add_library(Timestamp_lib Timestamp.cxx)
target_link_libraries(Timestamp_lib fastcdr fastrtps)

add_executable(Timestamp TimestampPubSubTypes.cxx TimestampPublisher.cxx TimestampSubscriber.cxx TimestampPubSubMain.cxx)
target_link_libraries(Timestamp fastcdr fastrtps
        Timestamp_lib )



