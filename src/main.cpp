#include <Arduino.h>
#include "bluetooth.h"
#include "lidar.h"
#include "motor.h"
#include "encoder.h"
#include "servo.h"
#include "pinout.h"

#define BAUDRATE 115200

void setup()
{
  Serial.begin(115200);
  LIDAR_SERIAL.begin(LIDAR_BAUDRATE);
  BLUETOOTH_SERIAL.begin(BLUETOOTH_BAUDRATE);
  // debug_init();
}

void loop() 
{
  // Variables
  static BTHandler bt(BLUETOOTH_SERIAL, BLUETOOTH_BAUDRATE);
  static Lidar lidar(LIDAR_SERIAL, LIDAR_BAUDRATE);
  static MotorHandler motor;
  static Encoder encoder;

  static int joy_x = 0, joy_y = 0, speed = 0;
  static int lidar_x = 0, lidar_y = 0;

  bt.parse( &joy_x, 
            &joy_y, 
            &speed);

  motor.command(joy_x, 
                joy_y, 
                speed);

  lidar.parse(&lidar_x, 
              &lidar_y);

  bt.send(lidar_x + robotConfiguration.x, 
          lidar_y + robotConfiguration.y, 
          robotConfiguration.x, 
          robotConfiguration.y);

  Serial.println(lidar_x);
}