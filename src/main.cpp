#include <Arduino.h>

#include "bluetooth.h"
#include "motor.h"

void setup() {
  init_bt();
  init_motors();
}

void loop() {
  static int dir = FWD, val = 0;

  parseSerial(&dir, &val);
  commander(dir, val);
}
