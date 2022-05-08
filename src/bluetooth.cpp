#include <Arduino.h>
#include "bluetooth.h"

void init_bt() {
  BT.begin(9600);
  Serial.begin(9600);

  Serial.println("Ready");
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

// Unused (for now)
void parseSerialChar(int *dir, int *val) {
  static char message[MAX_MESSAGE_LENGTH];
  static int message_position = 0;
    
  while(BT.available()) {
    char inByte = BT.read();

    if(inByte != '\n' && (message_position < MAX_MESSAGE_LENGTH - 1)) {
      message[message_position] = inByte;
      message_position++;
    } else {
      message[message_position] = '\0';
      Serial.println(message);
      message_position = 0;
    }
  }
}