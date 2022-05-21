#include "lidar.h"
                                     
RPLidar lidar;

void init_lidar()
{
  LIDAR_SERIAL.begin(LIDAR_BAUDRATE);
  lidar.begin(LIDAR_SERIAL);
}

void send_data() 
{
  if (IS_OK(lidar.waitPoint())) 
  {
    float distance = lidar.getCurrentPoint().distance; //distance value in mm unit
    float angle    = lidar.getCurrentPoint().angle; //angle value in degree
    
    //perform data processing here...
    if(distance > 0.0)
    {
      Serial.println(angle);
      BLUETOOTH_SERIAL.print((int) ((distance * cos(angle * PI / 180.0 - robotConfiguration.theta) + robotConfiguration.x) / 10.0));
      BLUETOOTH_SERIAL.print(":");
      BLUETOOTH_SERIAL.println((int) ((distance * sin(angle * PI / 180.0 - robotConfiguration.theta) + robotConfiguration.y) / 10.0));
      // BLUETOOTH_SERIAL.print(":");
      // BLUETOOTH_SERIAL.print((int) robotConfiguration.x);
      // BLUETOOTH_SERIAL.print(":");
      // BLUETOOTH_SERIAL.println((int) robotConfiguration.y);
    }
    
  } 
  else 
  {
    rplidar_response_device_info_t info;
    if (IS_OK(lidar.getDeviceInfo(info, 100))) 
    {
       lidar.startScan();
    }
  }
}