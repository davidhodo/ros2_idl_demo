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

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "idl_msgs/idl/timestamp.hpp"
#include "idl_msgs/idl/string_msg.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("idl_string_publisher")//, sec_(0)
  {
    publisher_ = this->create_publisher<idl_msgs::idl::StringMsg>("chatter", 10);
    //publisher_ = this->create_publisher<idl_msgs::idl::Timestamp>("timestamp", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    // auto message = idl_msgs::idl::Timestamp();
    // message.sec = sec_++;
    // message.ns = 23;
    // RCLCPP_INFO(this->get_logger(), "Publishing timestamp");

    auto message = idl_msgs::idl::StringMsg();
    message.var_string = "Hello";
    RCLCPP_INFO(this->get_logger(), "Publishing string");
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  //rclcpp::Publisher<idl_msgs::idl::Timestamp>::SharedPtr publisher_;
  rclcpp::Publisher<idl_msgs::idl::StringMsg>::SharedPtr publisher_;
  //long long sec_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}