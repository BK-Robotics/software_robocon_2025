#include <rclcpp/rclcpp.hpp>
#include "shooter_control/msg/control.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <atomic>
#include <mutex>

using namespace std::chrono_literals;
using shooter_control::msg::Control;

// === CONFIGURABLE CONSTANTS ===
#define DEVICE_TRIGGER_ID       6
#define TRIGGER_ON_SPEED        70.0f
#define TRIGGER_OFF_SPEED       5.0f

#define CAGE_MOTOR_IDS          {uint8_t(3), uint8_t(4)}
#define CAGE_FORWARD_SPEED      -12.0f
#define CAGE_REVERSE_SPEED      7.0f
#define CAGE_STOP_SPEED         0.0f
#define CAGE_FORWARD_DURATION   200   // milliseconds
#define CAGE_REVERSE_DURATION   2     // seconds

#define SHOOTER_MOTOR_IDS       {uint8_t(3), uint8_t(4), uint8_t(0)}
#define IDLE_MODE               1
#define SET_TARGET_MODE         5
#define MAX_DEVICE_ID           8

rclcpp::Node::SharedPtr node;
rclcpp::Publisher<Control>::SharedPtr pub;
rclcpp::TimerBase::SharedPtr forward_timer = nullptr;
rclcpp::TimerBase::SharedPtr stop_timer = nullptr;
bool shooter_on = false;

void idle_all() {
  for (uint8_t id = 0; id < MAX_DEVICE_ID; ++id) {
    Control m;
    m.device_id = id;
    m.mode = IDLE_MODE;
    m.value = 0.0f;
    pub->publish(m);
  }
  std::cout << "→ All IDLE\n";
}

void start_cage_sequence() {
  if (forward_timer) forward_timer->cancel();
  if (stop_timer) stop_timer->cancel();

  // Timer chuyển từ -20 → 10 sau 0.2s
  forward_timer = node->create_wall_timer(
    std::chrono::milliseconds(CAGE_FORWARD_DURATION),
    []() {
      for (auto id : CAGE_MOTOR_IDS) {
        Control m;
        m.device_id = id;
        m.mode = SET_TARGET_MODE;
        m.value = CAGE_REVERSE_SPEED;
        pub->publish(m);
      }
      std::cout << "Cage reverse at " << CAGE_REVERSE_SPEED << "\n";
      forward_timer->cancel();

      // Timer dừng sau 2s
      stop_timer = node->create_wall_timer(
        std::chrono::seconds(CAGE_REVERSE_DURATION),
        []() {
          for (auto id : CAGE_MOTOR_IDS) {
            Control m;
            m.device_id = id;
            m.mode = SET_TARGET_MODE;
            m.value = CAGE_STOP_SPEED;
            pub->publish(m);
          }
          std::cout << "Cage stop at " << CAGE_STOP_SPEED << "\n";
          stop_timer->cancel();
        });
    });
}

void input_thread_func() {
  std::string line;
  while (rclcpp::ok()) {
    std::cout << "Command (float / s / i / c / q): ";
    if (!std::getline(std::cin, line) || line.empty()) continue;

    if (line == "q") {
      rclcpp::shutdown();
      return;
    } else if (line == "i") {
      idle_all();
    } else if (line == "s") {
      shooter_on = !shooter_on;
      float v = shooter_on ? TRIGGER_ON_SPEED : TRIGGER_OFF_SPEED;
      Control m;
      m.device_id = DEVICE_TRIGGER_ID;
      m.mode = SET_TARGET_MODE;
      m.value = v;
      pub->publish(m);
      std::cout << "Trigger " << (shooter_on ? "ON\n" : "OFF\n");
    } else if (line == "c") {
      for (auto id : CAGE_MOTOR_IDS) {
        Control m;
        m.device_id = id;
        m.mode = SET_TARGET_MODE;
        m.value = CAGE_FORWARD_SPEED;
        pub->publish(m);
      }
      std::cout << "Cage forward at " << CAGE_FORWARD_SPEED << "\n";
      start_cage_sequence();
    } else {
      std::istringstream iss(line);
      float v;
      if (iss >> v) {
        for (auto id : SHOOTER_MOTOR_IDS) {
          Control m;
          m.device_id = id;
          m.mode = SET_TARGET_MODE;
          m.value = v;
          pub->publish(m);
        }
        std::cout << "Shooters set to " << v << "\n";
      } else {
        std::cout << "Unknown command\n";
      }
    }
  }
}

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  node = rclcpp::Node::make_shared("shooter_auto");
  pub = node->create_publisher<Control>("control_topic", 10);

  std::thread input_thread(input_thread_func);
  rclcpp::spin(node);

  input_thread.join();
  idle_all();
  return 0;
}