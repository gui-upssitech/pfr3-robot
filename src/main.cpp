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
#include "ir_sensor.h"


void setup()
{
  Serial.begin(115200);
  init_bluetooth();
  init_servo();
  init_encoder();
  init_motor();
  // init_emergency_stop();
  init_ir_sensor();

  Serial.println("Initializing...");
  delay(1000);
}

void loop() 
{
  // manual_system();
  // Serial.println("Starting...");
  // rotate_command(PI);
  // rotate_command(-PI);
  automatic_system();
}