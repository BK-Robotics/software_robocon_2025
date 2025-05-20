#include "gamepad_interface/gamepad.hpp"
#include <linux/input.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <stdexcept>
#include <cmath>

/*------------------ ctor -------------------------------------------------*/
DualSenseDriver::DualSenseDriver(const std::string &dev)
    : fd_(-1)
{
    fd_ = ::open(dev.c_str(), O_RDONLY | O_NONBLOCK);
    if (fd_ < 0)
        throw std::runtime_error("Cannot open " + dev + ": " + std::strerror(errno));
}

/*------------------ auto_detect -----------------------------------------*/
std::string DualSenseDriver::auto_detect()
{
    DIR *dir = opendir("/dev/input");
    if (!dir)
        throw std::runtime_error("Cannot open /dev/input: " + std::string(std::strerror(errno)));

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL)
    {
        if (std::strncmp(ent->d_name, "event", 5) != 0)
            continue;

        std::string path = std::string("/dev/input/") + ent->d_name;
        int fd = ::open(path.c_str(), O_RDONLY | O_NONBLOCK);
        if (fd < 0)
            continue;

        struct input_id id;
        if (ioctl(fd, EVIOCGID, &id) == 0)
        {
            if (id.vendor == 0x054C && id.product == 0x0CE6) // Sony DualSense
            {
                ::close(fd);
                closedir(dir);
                return path;
            }
        }
        ::close(fd);
    }
    closedir(dir);
    throw std::runtime_error("DualSense event device not found");
}

/*------------------ read() ----------------------------------------------*/
bool DualSenseDriver::read(GamepadState &out)
{
    if (fd_ < 0)
        return false;

    bool updated = false;
    struct input_event ev;
    while (::read(fd_, &ev, sizeof(ev)) == sizeof(ev))
    {
        updated = true;

        if (ev.type == EV_ABS)
        {
            switch (ev.code)
            {
            case ABS_X:
                state_.axes[0] = (ev.value - 128) / 128.f; 
                break; // L-Joy X
            case ABS_Y:
                state_.axes[1] = (ev.value - 128) / 128.f;
                break; // L-Joy Y
            case ABS_RX:
                state_.axes[2] = (ev.value - 128) / 128.f;
                break; // R-Joy X
            case ABS_RY:
                state_.axes[3] = (ev.value - 128) / 128.f;
                break; // R-Jot Y
            case ABS_Z:
                state_.axes[4] = ev.value / 255.f;
                break; // L2
            case ABS_RZ:
                state_.axes[5] = ev.value / 255.f;
                break; // R2
            case ABS_HAT0X:
                state_.axes[6] = static_cast<float>(ev.value);
                break; // D-Pad X
            case ABS_HAT0Y:
                state_.axes[7] = static_cast<float>(ev.value);
                break; // D-Pad Y
            default:
                break;
            }
        }
        else if (ev.type == EV_KEY)
        {
            int idx = ev.code - BTN_SOUTH; // BTN_SOUTH = 304
            if (idx >= 0 && idx < 13)
                state_.buttons[idx] = static_cast<uint8_t>(ev.value);
        }
    }

    if (updated)
        out = state_;
    return updated;
}