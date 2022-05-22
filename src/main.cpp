#include <Arduino.h>
#include "bluetooth.h"
#include "lidar.h"
#include "motor.h"
#include "encoder.h"
#include "servo.h"
#include "pinout.h"
#include "command.h"
#include "emergency_stop.h"
#include "system.h"


void setup()
{
  Serial.begin(115200);
  // 
  // 
  // initializeCommandIT();
  init_bluetooth();
  // init_lidar();
  init_servo();
  init_encoder();
  init_motor();
  init_emergency_stop();
}

void loop() 
{
  // static int joy_x = 0, joy_y = 0, speed = 0;
  // static int lidar_x = 0, lidar_y = 0;

  // bt.parse( &joy_x, 
  //           &joy_y, 
  //           &speed);

  // motor.command(joy_x, 
  //               joy_y, 
  //               speed);

  // lidar.sendData();



  // static float speed = 0;
  // static int sign = 1;

  // error = theta_cmd - robotConfiguration.theta;

  // speed = abs(error) * Kp + OFFSET_MOTOR;
  // if(speed > 84) speed = 84.0;
  // sign = (error > 0) ? 1 : -1;

  // Serial.println(speed);
  // write_right_servo(ZERO_MOTEUR - (speed * sign));
  // write_left_servo(ZERO_MOTEUR + (speed * sign));

  // emergency_routine();

  // manual_system();
  // hc05_configuration();

  write_left_servo(160);
  write_right_servo(40);
}