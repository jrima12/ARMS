#include <iostream>
#include <fstream>
#include <termios.h>
#include <unistd.h>

int main() {
    std::fstream serial_port;
    serial_port.open("/dev/ttyACM0", std::ios::in);

    if (serial_port.is_open()) {
        // Set baud rate
        struct termios options;
        tcgetattr(fileno(serial_port.rdbuf()), &options);
        cfsetispeed(&options, B9600); // set input baud rate to 9600
        cfsetospeed(&options, B9600); // set output baud rate to 9600
        tcsetattr(fileno(serial_port.rdbuf()), TCSANOW, &options);

        std::string line;

        while (true) {
            if (std::getline(serial_port, line)) {
                std::cout << line << std::endl;
            }
        }

        serial_port.close();
    } else {
        std::cerr << "Error: Unable to open serial port" << std::endl;
        return 1;
    }

    return 0;
}
