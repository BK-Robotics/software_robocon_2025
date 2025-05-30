// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/PushBall.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__PUSH_BALL__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__PUSH_BALL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/push_ball__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_PushBall_Request_wait_for_completion
{
public:
  Init_PushBall_Request_wait_for_completion()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::PushBall_Request wait_for_completion(::robot_interfaces::srv::PushBall_Request::_wait_for_completion_type arg)
  {
    msg_.wait_for_completion = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::PushBall_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::PushBall_Request>()
{
  return robot_interfaces::srv::builder::Init_PushBall_Request_wait_for_completion();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_PushBall_Response_success
{
public:
  Init_PushBall_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::PushBall_Response success(::robot_interfaces::srv::PushBall_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::PushBall_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::PushBall_Response>()
{
  return robot_interfaces::srv::builder::Init_PushBall_Response_success();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__PUSH_BALL__BUILDER_HPP_
