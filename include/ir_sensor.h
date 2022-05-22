#ifndef IR_SENSOR_H
#define IR_SENSOR_H

// -------------

#include <Arduino.h>
#include "pinout.h"

// -------------

void init_ir_sensor();
void update_ir_sensor(int* front_sensor, int* right_sensor);

// -------------

#endif