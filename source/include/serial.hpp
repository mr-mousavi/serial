#ifndef SERIAL_HPP
#define SERIAL_HPP

#include <cstring>
#include <string>
#include <stdint.h>
#include <termios.h>

class Serial {
public:

    /**
     * Default constructor.
     */
    Serial();

    /**
     * It will close serial if it was opened.
     */
    ~Serial();

    /**
     * This method opens given serial device; 
     *  
     * param devPath path to serial device (e.g /dev/ttyS0)
     * param flags flags passed to Linux open system call (e.g O_O_RDWR)
     * @return can not open return -1
     */
    int open(const std::string &devPath, int flags);

    /**
     * initialize serial attribute.
     * @param baudrate 
     * @return zero on success otherwise return less than zero
     */
    int init(speed_t baudrate);

    /**
     * return true if device is already opened otherwise false
     */
    bool isOpen() const;

    /**
     * close serial port.
     */
    int close();

    /**
     * return file descriptor.
     */
    int & getFileDescriptor();

    /**
     *clear serial buffer.
     */
    void clearBuffer();

    /**
     * close serial port.
     */
    int read(char *buffer, int len);

    /**
     * close serial port.
     */
    int write(char *buffer, int len);

private:
    /**
     * Associated file descriptor to serial
     */
    int fd;

    /**
     * Path of serial device
     */
    std::string devPath;
};
#endif /* SERIAL_HPP */
