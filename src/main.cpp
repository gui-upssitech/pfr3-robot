#include <Arduino.h>
#include "debug.h"

#include "bluetooth.h"
#include "lidar.h"
#include "motor.h"
#include "encoder.h"

#include "pinout.h"
#define BAUDRATE 115200

void setup()
{

}

void loop() 
{
  // Variables

  static BTHandler bt(SERIAL_BT, BAUDRATE);
  static Lidar lidar(SERIAL_LIDAR, BAUDRATE, PIN_MOTOR_LIDAR);
  static MotorHandler motor(PIN_MOTOR_G, PIN_MOTOR_D);
  static Encoder encoder;

  static int joy_x = 0, joy_y = 0, speed = 0,
             lidar_x = 0, lidar_y = 0,
             encoder_left = 0, encoder_right = 0;

  // Start

  bt.parse(&joy_x, &joy_y, &speed);
  motor.command(joy_x, joy_y, speed);

  lidar.parse(&lidar_x, &lidar_y);
  encoder.parse(&encoder_left, &encoder_right);
  bt.send(lidar_x, lidar_y, encoder_left, encoder_right);

  // End
}
