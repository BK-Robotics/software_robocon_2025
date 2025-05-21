// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_interfaces:srv/RequestOdrive.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__REQUEST_ODRIVE__BUILDER_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__REQUEST_ODRIVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_interfaces/srv/detail/request_odrive__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_RequestOdrive_Request_action
{
public:
  Init_RequestOdrive_Request_action()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::RequestOdrive_Request action(::robot_interfaces::srv::RequestOdrive_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::RequestOdrive_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::RequestOdrive_Request>()
{
  return robot_interfaces::srv::builder::Init_RequestOdrive_Request_action();
}

}  // namespace robot_interfaces


namespace robot_interfaces
{

namespace srv
{

namespace builder
{

class Init_RequestOdrive_Response_success
{
public:
  Init_RequestOdrive_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_interfaces::srv::RequestOdrive_Response success(::robot_interfaces::srv::RequestOdrive_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_interfaces::srv::RequestOdrive_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_interfaces::srv::RequestOdrive_Response>()
{
  return robot_interfaces::srv::builder::Init_RequestOdrive_Response_success();
}

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__SRV__DETAIL__REQUEST_ODRIVE__BUILDER_HPP_
