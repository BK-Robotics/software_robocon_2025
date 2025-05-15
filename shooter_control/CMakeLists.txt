cmake_minimum_required(VERSION 3.8)
project(shooter_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ---------------------------------------------------------------------------
# 1. dependency
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# ---------------------------------------------------------------------------
# 2. khai báo message
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Control.msg"
  "msg/Encoder.msg"
)

add_library(can_comm STATIC src/can_comm.cpp)
ament_target_dependencies(can_comm rclcpp)   

add_library(odrive_motor STATIC src/odrive_motor.cpp)
target_link_libraries(odrive_motor can_comm) 
ament_target_dependencies(odrive_motor rclcpp)

# ---------------------------------------------------------------------------
# 3. executable
add_executable(shooter        src/shooter.cpp)
add_executable(shooter_manual src/shooter_manual.cpp)
add_executable(shooter_auto   src/shooter_auto.cpp)

ament_target_dependencies(shooter        rclcpp)
ament_target_dependencies(shooter_manual rclcpp)
ament_target_dependencies(shooter_auto   rclcpp)

target_link_libraries(shooter odrive_motor can_comm)

# ----- ***DÒNG BẮT BUỘC để CMake thêm đường dẫn header interface*** -----
rosidl_target_interfaces(shooter        ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(shooter_manual ${PROJECT_NAME} "rosidl_typesupport_cpp")
rosidl_target_interfaces(shooter_auto   ${PROJECT_NAME} "rosidl_typesupport_cpp")
# ---------------------------------------------------------------------------

install(TARGETS
  shooter
  shooter_manual
  shooter_auto
  DESTINATION lib/${PROJECT_NAME}
)

# đặt ở cuối, sau khi đã có rosidl_generate_interfaces
ament_export_dependencies(rosidl_default_runtime)
ament_package()
