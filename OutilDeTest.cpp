#include "Driver_PortCOM.cpp"
#include <cstring>


int main() {
    DriverPort serial("/dev/ttyS0");

    uint8_t cmd[6] = {0x11,0x05,0x01,0x01,0x28,0x12};
    serial.writePort(cmd, sizeof(cmd));

    uint8_t buffer[1024];
    ssize_t n = serial.readPort(buffer, sizeof(buffer));
    if (n > 0) {
        std::cout << "Reçu: ";
        for(ssize_t i = 0; i < n; ++i) {
            std::cout << std::hex << static_cast<int>(buffer[i]) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
