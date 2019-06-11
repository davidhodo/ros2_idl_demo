// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "idl_msgs/idl/timestamp.hpp"
#include "idl_msgs/idl/string_msg.hpp"
#include "rclcpp/qos.hpp"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("idl_string_subscriber")
  {
    rclcpp::QoS qos_profile(10);
    qos_profile.avoid_ros_namespace_conventions(true);

    // subscription_ = this->create_subscription<idl_msgs::idl::Timestamp>(
    //   "/timestamp", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

    subscription_ = this->create_subscription<idl_msgs::idl::StringMsg>(
      "/chatter", qos_profile, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const idl_msgs::idl::StringMsg::SharedPtr msg)
  {
    //RCLCPP_INFO(this->get_logger(), "Time: '%i'", msg->sec);
    RCLCPP_INFO(this->get_logger(), "String: '%s'", msg->var_string.c_str());

  }
  //rclcpp::Subscription<idl_msgs::idl::Timestamp>::SharedPtr subscription_;
  rclcpp::Subscription<idl_msgs::idl::StringMsg>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}