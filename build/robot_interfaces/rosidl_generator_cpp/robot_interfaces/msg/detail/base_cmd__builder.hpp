// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:msg/BaseCMD.idl
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

class Init_BaseCMD_rotate
{
public:
  explicit Init_BaseCMD_rotate(::robot_interfaces::msg::BaseCMD & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::msg::BaseCMD rotate(::robot_interfaces::msg::BaseCMD::_rotate_type arg)
  {
    msg_.rotate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::msg::BaseCMD msg_;
};

class Init_BaseCMD_angle
{
public:
  explicit Init_BaseCMD_angle(::robot_interfaces::msg::BaseCMD & msg)
  : msg_(msg)
  {}
  Init_BaseCMD_rotate angle(::robot_interfaces::msg::BaseCMD::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_BaseCMD_rotate(msg_);
  }

private:
  ::robot_interfaces::msg::BaseCMD msg_;
};

class Init_BaseCMD_velocity
{
public:
  Init_BaseCMD_velocity()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BaseCMD_angle velocity(::robot_interfaces::msg::BaseCMD::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_BaseCMD_angle(msg_);
  }

private:
  ::robot_interfaces::msg::BaseCMD msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::msg::BaseCMD>()
{
  return robot_interfaces::msg::builder::Init_BaseCMD_velocity();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__BASE_CMD__BUILDER_HPP_
