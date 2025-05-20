// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/Control.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__CONTROL__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Control_Request_velocity
{
public:
  explicit Init_Control_Request_velocity(::robot_interfaces::srv::Control_Request & msg)
  : msg_(msg)
  {}
  ::robot_interfaces::srv::Control_Request velocity(::robot_interfaces::srv::Control_Request::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::Control_Request msg_;
};

class Init_Control_Request_action
{
public:
  Init_Control_Request_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Control_Request_velocity action(::robot_interfaces::srv::Control_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return Init_Control_Request_velocity(msg_);
  }

private:
  ::robot_interfaces::srv::Control_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::Control_Request>()
{
  return robot_interfaces::srv::builder::Init_Control_Request_action();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_Control_Response_success
{
public:
  Init_Control_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::Control_Response success(::robot_interfaces::srv::Control_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::Control_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::Control_Response>()
{
  return robot_interfaces::srv::builder::Init_Control_Response_success();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__CONTROL__BUILDER_HPP_
