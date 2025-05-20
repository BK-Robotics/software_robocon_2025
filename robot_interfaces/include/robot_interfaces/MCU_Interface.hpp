#pragma once

#include <rclcpp/rclcpp.hpp>
#include <vector>
#include <queue>
#include <mutex>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include "robot_interfaces/msg/imu.hpp"
#include "robot_interfaces/msg/base_cmd.hpp"
#include "robot_interfaces/srv/rotate_base.hpp"
#include "robot_interfaces/srv/push_ball.hpp"
#include <thread>

/**
 * @brief UARTNode giao tiếp UART với vi điều khiển qua USB-TTL, nhận và gửi dữ liệu định dạng 12 byte.
 */
class UARTNode : public rclcpp::Node {
public:
    UARTNode(); ///< Hàm khởi tạo node ROS2

private:
    // ==== Cổng UART ====
    void configure_port(int fd, speed_t baudrate); ///< Cấu hình tốc độ truyền UART

    // ==== Mã hóa dữ liệu ====
    void float32_to_little_endian_8byte(float value, uint8_t out[8]); ///< Chuyển float32 thành 8 byte little endian

    // ==== Hàng đợi gửi UART ====
    void enqueue_uart_packet(uint8_t cmd, const uint8_t* data8);
    void Senqueue_uart_packet(uint8_t cmd, const uint8_t* data8); ///< Đóng gói frame UART và đưa vào hàng đợi
    void process_uart_queue(); ///< Gửi từng frame từ hàng đợi qua UART

    // ==== Gửi lệnh khởi tạo ====
    void send_initialization_commands(); ///< Gửi các gói cấu hình ban đầu đến MCU

    // ==== Giao tiếp ROS ====
    void handle_base_cmd(const robot_interfaces::msg::BaseCMD::SharedPtr msg); ///< Xử lý base_cmd (subscriber)
    void handle_rotate_service(const std::shared_ptr<robot_interfaces::srv::RotateBase::Request> request,
                               std::shared_ptr<robot_interfaces::srv::RotateBase::Response> response); ///< Gửi góc quay từ service
    void handle_push_ball_service(const std::shared_ptr<robot_interfaces::srv::PushBall::Request> request,
                                  std::shared_ptr<robot_interfaces::srv::PushBall::Response> response); ///< Gửi tín hiệu đẩy bóng khi được yêu cầu

    // ==== Nhận dữ liệu UART ====
    float convert_to_angle(uint8_t low, uint8_t high); ///< Giải mã góc từ 2 byte
    void uart_read_loop(); ///< Đọc UART, ghép frame và publish topic IMU

    // ==== Biến thành viên ====
    int uart_fd_;
    std::vector<uint8_t> buffer_;
    bool syncing_ = false;
    std::mutex uart_mutex_;
    std::mutex uart_queue_mutex_;
    std::queue<std::vector<uint8_t>> uart_queue_; // thang nay se luu gia tri cua tu topic base_cmd
    std::queue<std::vector<uint8_t>> Suart_queue_; // thang nay se luu gia tri cua 2 service kia va thang nay se duoc uu tien hon do no gui it

    // ==== ROS2 ====
    rclcpp::Publisher<robot_interfaces::msg::IMU>::SharedPtr pub_imu_;
    rclcpp::Service<robot_interfaces::srv::RotateBase>::SharedPtr service_rotate_;
    rclcpp::Service<robot_interfaces::srv::PushBall>::SharedPtr service_push_ball_;
    rclcpp::Subscription<robot_interfaces::msg::BaseCMD>::SharedPtr sub_base_cmd_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::TimerBase::SharedPtr uart_tx_timer_;
    std::thread uart_read_thread_;
};
