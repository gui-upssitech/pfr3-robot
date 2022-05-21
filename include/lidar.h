#ifndef H_LIDAR
#define H_LIDAR

// -------------

#include <RPLidar.h>
#include "encoder.h"
#include "bluetooth.h"

// -------------

#define LIDAR_SERIAL    Serial2
#define LIDAR_BAUDRATE  115200

// -------------

void init_lidar(); 
void sendData();

// -------------

#endif