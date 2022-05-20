#ifndef H_LIDAR
#define H_LIDAR

// -------------

#include <RPLidar.h>
#include "encoder.h"

// -------------

#define LIDAR_SERIAL    Serial2
#define LIDAR_BAUDRATE  115200

// -------------

class Lidar 
{

    private:
    RPLidar lidar;

    public:
    Lidar(HardwareSerial& serial_port, int baudrate);
    void parse(int *lidar_x, int *lidar_y);

};

// -------------

#endif