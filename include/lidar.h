#include <RPLidar.h>

#ifndef H_LIDAR
#define H_LIDAR

// -------------

class Lidar {

    private:
    RPLidar lidar;

    public:
    Lidar(HardwareSerial& serial_port, int baudrate);
    void parse(int *lidar_x, int *lidar_y);

};

// -------------

#endif