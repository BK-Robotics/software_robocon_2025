// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_interfaces:srv/RequestMcu.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_INTERFACES__SRV__DETAIL__REQUEST_MCU__STRUCT_H_
#define ROBOT_INTERFACES__SRV__DETAIL__REQUEST_MCU__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RequestMcu in the package robot_interfaces.
typedef struct robot_interfaces__srv__RequestMcu_Request
{
  uint8_t action;
} robot_interfaces__srv__RequestMcu_Request;

// Struct for a sequence of robot_interfaces__srv__RequestMcu_Request.
typedef struct robot_interfaces__srv__RequestMcu_Request__Sequence
{
  robot_interfaces__srv__RequestMcu_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__RequestMcu_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/RequestMcu in the package robot_interfaces.
typedef struct robot_interfaces__srv__RequestMcu_Response
{
  bool success;
} robot_interfaces__srv__RequestMcu_Response;

// Struct for a sequence of robot_interfaces__srv__RequestMcu_Response.
typedef struct robot_interfaces__srv__RequestMcu_Response__Sequence
{
  robot_interfaces__srv__RequestMcu_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_interfaces__srv__RequestMcu_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_INTERFACES__SRV__DETAIL__REQUEST_MCU__STRUCT_H_
