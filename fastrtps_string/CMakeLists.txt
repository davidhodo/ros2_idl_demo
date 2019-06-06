
cmake_minimum_required(VERSION 2.8.12)

project("rtps_string")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)


message(STATUS "Configuring StringMsg...")
add_library(StringMsg_lib StringMsg.cxx)
target_link_libraries(StringMsg_lib fastcdr fastrtps)

add_executable(StringMsg StringMsgPubSubTypes.cxx StringMsgPublisher.cxx StringMsgSubscriber.cxx StringMsgPubSubMain.cxx)
target_link_libraries(StringMsg fastcdr fastrtps
        StringMsg_lib )



