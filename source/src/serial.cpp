#include "serial.hpp"
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>

Serial::Serial()
{
    fd = -1;
}

int Serial::open(const std::string& devPath, int flags)
{
    if (fd > 0) {
        return fd;
    }
    this->devPath = devPath;
    fd = ::open(devPath.c_str(), flags);
    if (fd <= 0)
        return -1;
    return fd;
}

Serial::~Serial()
{
    if (fd > 0)
        close();
}

int Serial::init(speed_t baudrate)
{
    termios newOption;
    memset(&newOption, 0, sizeof (newOption));
    if (cfsetispeed(&newOption, baudrate) < 0)
        return -1;
    if (cfsetospeed(&newOption, baudrate) < 0)
        return -2;
    newOption.c_cflag |= (CLOCAL | CREAD);
    newOption.c_cflag &= ~CSIZE;
    newOption.c_cflag |= CS8;
    newOption.c_cflag &= ~PARENB;
    newOption.c_cflag &= ~CSTOPB;
    newOption.c_cflag &= ~CRTSCTS;
    if (tcsetattr(fd, TCSANOW, &newOption) < 0)
        return -3;
    return 0;
}

int Serial::close()
{
    return ::close(fd);
}

int& Serial::getFileDescriptor()
{
    return fd;
}

bool Serial::isOpen() const
{
    return fd > 0;
}

void Serial::clearBuffer()
{
    char buf2[100];
    while(read(buf2, 100)>0){
    usleep(100);
    }
}

int Serial::read(char *buffer, int len)
{
    return ::read(fd, buffer, len);
}

int Serial::write(char *buffer, int len)
{
     return ::write(fd, buffer, len);
}

