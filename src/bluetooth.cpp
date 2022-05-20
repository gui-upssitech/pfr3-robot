#include <Arduino.h>
#include "bluetooth.h"

BTHandler::BTHandler(HardwareSerial& serial_port, int baudrate) : bt(serial_port) 
{
  // bt.begin(baudrate);
}

void BTHandler::parse(int *joy_x, int *joy_y, int *speed) {
  // Message format: joy_x:joy_y:speed
  if(bt.available() >= CMD_LENGTH) {
    *joy_x = joy_map(bt.parseInt());
    *joy_y = joy_map(bt.parseInt());
    *speed = bt.parseInt();
  }
}

void BTHandler::send(int lidar_x, int lidar_y, int robot_x, int robot_y) 
{
  char cmd[50];
  sprintf(cmd, "%d:%d:%d:%d", lidar_x, lidar_y, robot_x, robot_y);
  bt.println(cmd);
}