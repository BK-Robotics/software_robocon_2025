#include <rclcpp/rclcpp.hpp>
#include "shooter_control/msg/control.hpp"
#include "shooter_control/msg/encoder.hpp"
#include "can_comm.hpp"
#include "odrive_motor.hpp"
#include <thread>
#include <cstring>
#include <memory>
#include <vector>

using shooter_control::msg::Control;
using shooter_control::msg::Encoder;

class ShooterNode : public rclcpp::Node
{
public:
  ShooterNode()
      : Node("shooter")
  {
    // Mở CAN
    can_if_ = std::make_shared<CANInterface>();
    if (!can_if_->openInterface("can0"))
    {
      RCLCPP_ERROR(get_logger(), "Cannot open can0");
      rclcpp::shutdown();
      return;
    }

    // Initial motors
    for (uint8_t id = 0; id < 8; ++id)
    {
      auto mode = (id < 5)
                      ? OdriveMotor::ControlMode::VELOCITY
                      : OdriveMotor::ControlMode::POSITION;
      motors_.push_back(
          std::make_shared<OdriveMotor>(id, mode, can_if_.get()));
    }

    // Subscribe lệnh từ topic
    sub_ = create_subscription<Control>(
        "control_topic", 10,
        std::bind(&ShooterNode::onControl, this, std::placeholders::_1));

    // Đăng callback phân phối feedback
    pub_enc_ = create_publisher<Encoder>("encoder_topic", 10);

    can_if_->registerFeedbackCallback(
        [this](uint32_t frame_id, const uint8_t *data)
        {
          uint8_t cmd = frame_id & 0x1F;
          if (cmd != OdriveMotor::FEEDBACK_CMD_ID)
            return;
          this->onFeedback(frame_id, data);
        });
    std::thread([this]
                { can_if_->receiveLoop(); })
        .detach();

    RCLCPP_INFO(get_logger(), "Shooter node started.");
  }

private:
  std::shared_ptr<CANInterface> can_if_;
  rclcpp::Subscription<Control>::SharedPtr sub_;
  rclcpp::Publisher<Encoder>::SharedPtr pub_enc_;
  std::vector<std::shared_ptr<OdriveMotor>> motors_;

  void onControl(const Control::SharedPtr msg)
  {
    auto id = msg->device_id;
    if (id >= motors_.size())
    {
      RCLCPP_WARN(get_logger(), "Invalid device_id %u", id);
      return;
    }
    auto m = motors_[id];
    switch (msg->mode)
    {
    case 0:
      m->fullCalibration();
      break; // FULL_CALIBRATION
    case 1:
      m->idle();
      break; // IDLE
    case 2:
      m->closeLoopControl();
      break; // CLOSE_LOOP_CONTROL
    case 3:
      m->clearError();
      break; // CLEAR_ERROR
    case 4:
      m->setHoming();
      break; // SET_HOMING
    case 5:
      m->setTarget(msg->value);
      break; // SET_TARGET
    default:
      RCLCPP_WARN(get_logger(), "Unknown mode %u", msg->mode);
    }
  }

  void onFeedback(uint32_t frane_id, const uint8_t *data)
  {
    uint8_t device_id = frane_id >> 5;

    float pos, vel;
    std::memcpy(&pos, data, 4);
    std::memcpy(&vel, data + 4, 4);

    if (device_id < motors_.size())
      motors_[device_id]->setFeedback(pos, vel);

    Encoder msg;
    msg.device_id = device_id;
    msg.position = pos;
    msg.velocity = vel;
    pub_enc_->publish(msg);
  }
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ShooterNode>());
  rclcpp::shutdown();
  return 0;
}
