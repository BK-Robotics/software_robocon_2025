#include <rclcpp/rclcpp.hpp>
#include "shooter_control/msg/control.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using shooter_control::msg::Control;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("shooter_manual");
  auto pub = node->create_publisher<Control>("control_topic", 10);

  std::cout << "Manual mode: [id] [cmd] [value?]\n"
               "  cmd=calib|idle|clc|clear|home|target\n";

  while (rclcpp::ok())
  {
    uint32_t id;
    std::string cmd;
    float v = 0.0f;
    if (!(std::cin >> id >> cmd))
      break;
    std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

    Control msg;
    msg.device_id = id;

    if (cmd == "target")
    {
      if (!(std::cin >> v))
      {
        std::cerr << "Need value\n";
        continue;
      }
      msg.mode = 5; // SET_TARGET
      msg.value = v;
    }
    else
    {
      msg.value = 0.0f;
      if (cmd == "calib")
        msg.mode = 0;
      else if (cmd == "idle")
        msg.mode = 1;
      else if (cmd == "clc")
        msg.mode = 2;
      else if (cmd == "clear")
        msg.mode = 3;
      else if (cmd == "home")
        msg.mode = 4;
      else
      {
        std::cerr << "Unknown cmd\n";
        continue;
      }
    }

    pub->publish(msg);
    rclcpp::spin_some(node);
  }

  rclcpp::shutdown();
  return 0;
}
