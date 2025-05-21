// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/BaseCmd.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__BASE_CMD__BUILDER_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__BASE_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/msg/detail/base_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_BaseCmd_rotate
{
public:
  explicit Init_BaseCmd_rotate(::robot_interfaces::msg::BaseCmd & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::BaseCmd rotate(::robot_interfaces::msg::BaseCmd::_rotate_type arg)
  {
    msg_.rotate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::BaseCmd msg_;
};

class Init_BaseCmd_angle
{
public:
  explicit Init_BaseCmd_angle(::robot_interfaces::msg::BaseCmd & msg)
  : msg_(msg)
  {}
  Init_BaseCmd_rotate angle(::robot_interfaces::msg::BaseCmd::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_BaseCmd_rotate(msg_);
  }

private:
  ::robot_interfaces::msg::BaseCmd msg_;
};

class Init_BaseCmd_velocity
{
public:
  Init_BaseCmd_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BaseCmd_angle velocity(::robot_interfaces::msg::BaseCmd::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_BaseCmd_angle(msg_);
  }

private:
  ::robot_interfaces::msg::BaseCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::BaseCmd>()
{
  return robot_interfaces::msg::builder::Init_BaseCmd_velocity();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__BASE_CMD__BUILDER_HPP_
