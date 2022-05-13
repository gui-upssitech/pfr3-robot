#include <Arduino.h>
#include "bluetooth.h"
#include "debug.h"

#define joy_map(x) ((x) * 2) - 100

BTHandler::BTHandler() {
  BT.begin(9600);
}

void BTHandler::parse(int *joy_x, int *joy_y, int *speed) {
  // Message format: joy_x:joy_y:speed
  if(BT.available() >= CMD_LENGTH) {
    *joy_x = joy_map(BT.parseInt());
    *joy_y = joy_map(BT.parseInt());
    *speed = BT.parseInt();
  }
}