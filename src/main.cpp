#include <Arduino.h>
#include "debug.h"
#include "bluetooth.h"
#include "motor.h"
#include "encoder.h"
#include "servo.h"

void print_time(const char* msg);

void setup() 
{
  Serial.begin(115200);
}

void loop() 
{
  // static BTHandler bt;
  // static MotorHandler motor(PIN_MOTOR_G, PIN_MOTOR_D);

  // static int joy_x = 0, joy_y = 0, speed = 0;

  // bt.parse(&joy_x, &joy_y, &speed);
  // motor.command(joy_x, joy_y, speed);

  static Encoder encoder;
  static Servo servo;
    
}