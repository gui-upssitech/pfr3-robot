#include <Arduino.h>
#include "bluetooth.h"

void init_bluetooth()
{
  BLUETOOTH_SERIAL.begin(BLUETOOTH_BAUDRATE);
}

void parse_bluetooth(int *joy_x, int *joy_y, int *speed) 
{
  // Message format: joy_x:joy_y:speed
  if(BLUETOOTH_SERIAL.available() >= CMD_LENGTH) {

    *joy_x = joy_map(BLUETOOTH_SERIAL.parseInt());
    *joy_y = joy_map(BLUETOOTH_SERIAL.parseInt());
    *speed = BLUETOOTH_SERIAL.parseInt();
  }
}

void send_bluetooth(int lidar_x, int lidar_y, int robot_x, int robot_y) 
{
  char cmd[50];
  sprintf(cmd, "%d:%d:%d:%d", lidar_x, lidar_y, robot_x, robot_y);
  BLUETOOTH_SERIAL.println(cmd);
}