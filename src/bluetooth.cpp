#include <Arduino.h>
#include "bluetooth.h"

void init_bluetooth()
{
  BLUETOOTH_SERIAL.begin(BLUETOOTH_BAUDRATE);
}

void parse_bluetooth(int* joy_x, int* joy_y, int* speed) 
{
  // Message format: joy_x:joy_y:speed
  static char data[CMD_LENGTH];
  static char idx = 0;
  static char* strtokIdx;

  // get the message byte by byte until we read a '\n'
  if(BLUETOOTH_SERIAL.available())
  {
    data[idx] = BLUETOOTH_SERIAL.read();
    Serial.print(data[idx]);
    idx++;
  }

  // evaluate trame when we find the end char
  if(data[idx - 1] == '\n')
  {
    // set end of array
    data[idx - 1] = '\0';

    // check if the trame is completed
    if(idx == CMD_LENGTH)
    {
      // split trame to find data
      strtokIdx = strtok(data, ":");
      *joy_x = joy_map(atoi(strtokIdx));

      strtokIdx = strtok(NULL, ":");
      *joy_y = joy_map(atoi(strtokIdx));

      strtokIdx = strtok(NULL, ":");
      *speed = joy_map(atoi(strtokIdx));
    }
    else
    {
      *joy_x = 50;
      *joy_y = 50;
      *speed = 0;
    }

    // reset the counter
    idx = 0;
  }
}

void send_bluetooth(int lidar_x, int lidar_y, int robot_x, int robot_y) 
{
  char cmd[50];
  sprintf(cmd, "%d:%d:%d:%d", lidar_x, lidar_y, robot_x, robot_y);
  BLUETOOTH_SERIAL.println(cmd);
}