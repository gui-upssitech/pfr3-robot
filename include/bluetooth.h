#include <Arduino.h>

#ifndef H_BT
#define H_BT

// -------------

HardwareSerial BT(19, 18);
#define MAX_MESSAGE_LENGTH 50

// -------------

void init_bt();

void parseSerial(int *dir, int *val);
void parseSerialChar(int *dir, int *val);

// -------------

#endif