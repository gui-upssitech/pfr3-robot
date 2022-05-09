#include <Arduino.h>
#include "bluetooth.h"

void init_bt() {
  BT.begin(9600);

  Serial.begin(9600);
  Serial.println("\n\n===\nReady\n===");
}

void parseSerial(int *dir, int *val) {
  if(BT.available() == 6) {
    *dir = BT.parseInt();
    *val = BT.parseInt();

    Serial.println(*dir);
    Serial.println(*val);
    Serial.println("");
  }
}