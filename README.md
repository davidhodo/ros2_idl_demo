# idl_msgs
Test package for ROS2 idl message generation.

This package demonstrates the ability to generate ROS messages directly from an IDL file.  An example IDL from the [rosidl](https://github.com/ros2/rosidl/tree/dashing/rosidl_parser) repository is used as a test.  The MyMessage.idl file was modified from the original to remove the long double and wchar entries.  The two example includes were also removed.  Finally the module names were changed to match the package name and message type.  i.e. rosidl_parser -> idl_msgs and msg -> idl.

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

Run the publisher:

  ros2 run idl_pub idl_pub

Run the subscriber:

  ros2 run idl_sub idl_sub