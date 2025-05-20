cmake_minimum_required(VERSION 3.8)
project(robot_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)


include_directories(include)

# Generate interfaces in the 'msg' and 'srv' directories
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/BaseCMD.msg"
  "msg/IMU.msg"
  "srv/RotateBase.srv"
  "srv/PushBall.srv"
  "srv/Control.srv"
  "srv/RequestCalculation.srv"
  "srv/RequestAction.srv"
)

add_executable(uart_node src/MCU_Interface.cpp)

ament_target_dependencies(uart_node
  rclcpp
  std_msgs
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(uart_node ${cpp_typesupport_target})

install(TARGETS
  uart_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
