#include <Arduino.h>
#include "debug.h"

#include "bluetooth.h"
#include "lidar.h"
#include "motor.h"
#include "encoder.h"
#include "servo.h"

#include "pinout.h"
#define BAUDRATE 115200

void setup()
{
  debug_init();
}

void loop() 
{
  // Variables

  static BTHandler bt(SERIAL_BT, 9600);
  static Lidar lidar(SERIAL_LIDAR, BAUDRATE);
  static MotorHandler motor;
  static Encoder encoder;

  static int joy_x = 0, joy_y = 0, speed = 0,
             lidar_x = 0, lidar_y = 0,
             encoder_left = 0, encoder_right = 0;

  static char debug_str[1024];

  bt.parse(&joy_x, &joy_y, &speed);
  motor.command(joy_x, joy_y, speed);

  //lidar.parse(&lidar_x, &lidar_y);
  bt.send(lidar_x, lidar_y, encoder_left, encoder_right);

  sprintf(debug_str, "x: %d, y: %d", lidar_x, lidar_y);
  debugln(debug_str);
}
