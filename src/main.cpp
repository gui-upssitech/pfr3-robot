#include <Arduino.h>
// #include "debug.h"
// #include "bluetooth.h"
// #include "lidar.h"
// #include "motor.h"
#include "encoder.h"
#include "servo.h"

// #include "pinout.h"
#define BAUDRATE 115200

void setup()
{
  Serial.begin(BAUDRATE);
}

void loop() 
{
  // Variables

  // static BTHandler bt(SERIAL_BT, BAUDRATE);
  // static Lidar lidar(SERIAL_LIDAR, BAUDRATE, PIN_MOTOR_LIDAR);
  // static MotorHandler motor(PIN_MOTOR_G, PIN_MOTOR_D);
  // static Encoder encoder;

  // static int joy_x = 0, joy_y = 0, speed = 0,
  //            lidar_x = 0, lidar_y = 0,
  //            encoder_left = 0, encoder_right = 0;

  static Encoder encoder;
  static Servo servo;

  for(int i = 0; i < 180; i++)
  {
    servo.write_left(i);
    servo.write_right(180 - i);
    delay(50);
  }
}
