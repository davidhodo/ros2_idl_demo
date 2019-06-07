# idl_msgs
Test package for ROS2 idl message generation.

This package demonstrates the ability to generate ROS messages directly from an IDL file.  An example IDL from the [rosidl](https://github.com/ros2/rosidl/tree/dashing/rosidl_parser) repository is used as a test.  The MyMessage.idl file was modified from the original to remove the long double and wchar entries.  The two example includes were also removed.  Finally the module names were changed to match the package name and message type.  i.e. rosidl\_parser -> idl\_msgs and msg -> idl.

    module idl_msgs{. // matches package name
      module idl {. // Must be 'idl'
      // Message Contents
    }
    }


## Building

Build the package by running:

    mkdir -p idl_demo_ws/src
    cd idl_demo_ws/src
    git clone https://github.com/davidhodo/ros2_idl_demo.git
    cd ../
    colcon build

## Running

Run the ROS2 publisher:

    ros2 run idl_pub idl_pub

Run the ROS2 subscriber:

    ros2 run idl_sub idl_sub

Run the eProsima publisher:

    ./install/rtps_string/lib/rtps_string/StringMsg publisher

Run the eProsima subscriber:

    ./install/rtps_string/lib/rtps_string/StringMsg subscriber

## eProsima Code Modifications

The example code in the fastrtps_string folder was generated using eProsima's fastrtps gen by running:

    fastrtpsgen -example CMake ../idl_msgs/idl/StringMsg.idl

In order to interoperate with the ROS2 publisher/subscriber the following changes must be made to the generated code.

* Change the topic name to "rt/chatter"
* Change the type name to idl_msgs::idl::dds_::StringMsg_