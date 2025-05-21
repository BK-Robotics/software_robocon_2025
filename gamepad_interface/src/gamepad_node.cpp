#include <rclcpp/rclcpp.hpp>
#include <robot_interfaces/msg/base_cmd.hpp>
#include <robot_interfaces/srv/base_control.hpp>
#include <robot_interfaces/srv/request_action.hpp>
#include <gamepad_interface/gamepad.hpp>
#include <gamepad_interface/mapper.hpp>

using namespace std;

class GamepadNode : public rclcpp::Node
{
public:
  GamepadNode() : Node("gamepad_node"), driver_(declare_parameter<string>("device_path", DualSenseDriver::auto_detect())), mapper_(4.0f)
  {
    base_cmd_pub_ = create_publisher<robot_interfaces::msg::BaseCMD>("base_cmd", 10);
    timer_ = create_wall_timer(chrono::milliseconds(2), bind(&GamepadNode::loop, this));
  }

private:
  void loop()
  {
    GamepadState st;
    if (!driver_.read(st))
      return;

    MapperOutput mo = mapper_.update(st);

    if (mo.has_base_cmd)
      base_cmd_pub_->publish(mo.base_cmd);

    if (mo.has_base_control_cmd)
    {
      auto cli = get_base_control_client();
      if (cli->service_is_ready())
      {
        auto req = std::make_shared<robot_interfaces::srv::BaseControl::Request>();
        req->cmd = mo.base_control_cmd;
        cli->async_send_request(req);
      }
    }
    if (mo.has_request_action)
    {
      auto cli = get_request_action_client();
      if (cli->service_is_ready())
      {
        auto req = std::make_shared<robot_interfaces::srv::RequestAction::Request>();
        req->action = mo.request_action;
        cli->async_send_request(req);
      }
    }
  }

  /* lazy-init clients */
  rclcpp::Client<robot_interfaces::srv::BaseControl>::SharedPtr
  get_base_control_client()
  {
    if (!base_ctrl_cli_)
      base_ctrl_cli_ = create_client<robot_interfaces::srv::BaseControl>("base_control");
    return base_ctrl_cli_;
  }

  rclcpp::Client<robot_interfaces::srv::RequestAction>::SharedPtr
  get_request_action_client()
  {
    if (!req_act_cli_)
      req_act_cli_ = create_client<robot_interfaces::srv::RequestAction>("request_action");
    return req_act_cli_;
  }

  // -------------- members ----------------
  DualSenseDriver driver_;
  RobotInputMapper mapper_;

  rclcpp::Publisher<robot_interfaces::msg::BaseCMD>::SharedPtr base_cmd_pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Client<robot_interfaces::srv::BaseControl>::SharedPtr base_ctrl_cli_;
  rclcpp::Client<robot_interfaces::srv::RequestAction>::SharedPtr req_act_cli_;
};
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GamepadNode>());
  rclcpp::shutdown();
  return 0;
}
