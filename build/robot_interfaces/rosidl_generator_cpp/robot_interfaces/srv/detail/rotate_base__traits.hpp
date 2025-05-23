// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_interfaces:srv/RotateBase.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__ROTATE_BASE__TRAITS_HPP_
#define ROBOT_INTERFACES__SRV__DETAIL__ROTATE_BASE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_interfaces/srv/detail/rotate_base__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RotateBase_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: angle
  {
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateBase_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle: ";
    rosidl_generator_traits::value_to_yaml(msg.angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateBase_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::RotateBase_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::RotateBase_Request & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::RotateBase_Request>()
{
  return "robot_interfaces::srv::RotateBase_Request";
}

template<>
inline const char * name<robot_interfaces::srv::RotateBase_Request>()
{
  return "robot_interfaces/srv/RotateBase_Request";
}

template<>
struct has_fixed_size<robot_interfaces::srv::RotateBase_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::srv::RotateBase_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::srv::RotateBase_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const RotateBase_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RotateBase_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RotateBase_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robot_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_interfaces::srv::RotateBase_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_interfaces::srv::RotateBase_Response & msg)
{
  return robot_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_interfaces::srv::RotateBase_Response>()
{
  return "robot_interfaces::srv::RotateBase_Response";
}

template<>
inline const char * name<robot_interfaces::srv::RotateBase_Response>()
{
  return "robot_interfaces/srv/RotateBase_Response";
}

template<>
struct has_fixed_size<robot_interfaces::srv::RotateBase_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_interfaces::srv::RotateBase_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_interfaces::srv::RotateBase_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_interfaces::srv::RotateBase>()
{
  return "robot_interfaces::srv::RotateBase";
}

template<>
inline const char * name<robot_interfaces::srv::RotateBase>()
{
  return "robot_interfaces/srv/RotateBase";
}

template<>
struct has_fixed_size<robot_interfaces::srv::RotateBase>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_interfaces::srv::RotateBase_Request>::value &&
    has_fixed_size<robot_interfaces::srv::RotateBase_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_interfaces::srv::RotateBase>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_interfaces::srv::RotateBase_Request>::value &&
    has_bounded_size<robot_interfaces::srv::RotateBase_Response>::value
  >
{
};

template<>
struct is_service<robot_interfaces::srv::RotateBase>
  : std::true_type
{
};

template<>
struct is_service_request<robot_interfaces::srv::RotateBase_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_interfaces::srv::RotateBase_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_INTERFACES__SRV__DETAIL__ROTATE_BASE__TRAITS_HPP_
