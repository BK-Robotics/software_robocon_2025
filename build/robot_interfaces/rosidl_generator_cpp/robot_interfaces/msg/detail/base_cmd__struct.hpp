// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_interfaces:msg/BaseCmd.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__MSG__DETAIL__BASE_CMD__STRUCT_HPP_
#define ROBOT_INTERFACES__MSG__DETAIL__BASE_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_interfaces__msg__BaseCmd __attribute__((deprecated))
#else
# define DEPRECATED__robot_interfaces__msg__BaseCmd __declspec(deprecated)
#endif

namespace robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BaseCmd_
{
  using Type = BaseCmd_<ContainerAllocator>;

  explicit BaseCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0f;
      this->angle = 0.0f;
      this->rotate = 0;
    }
  }

  explicit BaseCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->velocity = 0.0f;
      this->angle = 0.0f;
      this->rotate = 0;
    }
  }

  // field types and members
  using _velocity_type =
    float;
  _velocity_type velocity;
  using _angle_type =
    float;
  _angle_type angle;
  using _rotate_type =
    uint8_t;
  _rotate_type rotate;

  // setters for named parameter idiom
  Type & set__velocity(
    const float & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__rotate(
    const uint8_t & _arg)
  {
    this->rotate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_interfaces::msg::BaseCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_interfaces::msg::BaseCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_interfaces::msg::BaseCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_interfaces::msg::BaseCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::BaseCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::BaseCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_interfaces::msg::BaseCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_interfaces::msg::BaseCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_interfaces::msg::BaseCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_interfaces::msg::BaseCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_interfaces__msg__BaseCmd
    std::shared_ptr<robot_interfaces::msg::BaseCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_interfaces__msg__BaseCmd
    std::shared_ptr<robot_interfaces::msg::BaseCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BaseCmd_ & other) const
  {
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    if (this->rotate != other.rotate) {
      return false;
    }
    return true;
  }
  bool operator!=(const BaseCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BaseCmd_

// alias to use template instance with default allocator
using BaseCmd =
  robot_interfaces::msg::BaseCmd_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_interfaces

#endif  // ROBOT_INTERFACES__MSG__DETAIL__BASE_CMD__STRUCT_HPP_
