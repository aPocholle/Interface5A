#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>

class DriverPort {
private:
    int serial_fd;

public:
    DriverPort(const std::string& port) {
        serial_fd = open(port.c_str(), O_RDWR | O_NOCTTY);
        if (serial_fd < 0) {
            std::perror("Erreur lors de l'ouverture du port série");
            exit(EXIT_FAILURE);
        }

        struct termios tty;
        if (tcgetattr(serial_fd, &tty) != 0) {
            std::perror("Erreur lors de l'obtention des attributs du port série");
            close(serial_fd);
            exit(EXIT_FAILURE);
        }

        cfsetospeed(&tty, B9600);
        cfsetispeed(&tty, B9600);

        tty.c_cflag &= ~PARENB; //Parité
        tty.c_cflag &= ~CSTOPB; //bit STOP
        tty.c_cflag &= ~CSIZE; //efface les bits de taille
        tty.c_cflag |= CS8; // data de 8 bits

        if (tcsetattr(serial_fd, TCSANOW, &tty) != 0) {
            std::perror("Erreur lors de la configuration du port série");
            close(serial_fd);
            exit(EXIT_FAILURE);
        }
    }

    void CloseSerial(){
        close(serial_fd);
    }

    ~DriverPort() {
        close(serial_fd);
    }

    ssize_t writePort(const void* buffer, size_t size) {
        return write(serial_fd, buffer, size);
    }

    ssize_t readPort(void* buffer, size_t size) {
        return read(serial_fd, buffer, size);
    }
};


