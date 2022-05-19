#include <Arduino.h>
#include "bluetooth.h"
#include "lidar.h"
#include "motor.h"
#include "encoder.h"
#include "servo.h"
#include "pinout.h"


void setup() 
{
  BLUETOOTH_SERIAL.begin(BLUETOOTH_BAUDRATE);
  LIDAR_SERIAL.begin(LIDAR_BAUDRATE);
}

void loop() 
{
  // static objects 
  static BTHandler bt(BLUETOOTH_SERIAL, BLUETOOTH_BAUDRATE);
  static Lidar lidar(LIDAR_SERIAL, LIDAR_BAUDRATE);
  static MotorHandler motor;
  static Encoder encoder;

  // static variables
  static int joy_x = 0, joy_y = 0, speed = 0;
  static int lidar_x = 0, lidar_y = 0;

  // read controller data (manual mode)
  bt.parse(&joy_x, &joy_y, &speed);

  // apply the command to the motors
  motor.command(joy_x, joy_y, speed);

  // read lidar data
  lidar.parse(&lidar_x, &lidar_y);

  // send lidar data + robot position
  bt.send(lidar_x, lidar_y, robotConfiguration.x, robotConfiguration.y);
}
