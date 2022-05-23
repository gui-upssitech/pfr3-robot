#ifndef SERVO_H
#define SERVO_H

// -------------

#include <Arduino.h>
#include "motor.h"
#include "emergency_stop.h"

// -------------

#define CLK_RES_MS (128.0/84000.0)
#define PERIOD_MS 2
#define RC 1312
#define R_MIN (RC/2)
#define R_MAX RC

// -------------

void init_servo();
void write_left_servo(float angle);
void write_right_servo(float angle);

// -------------

#endif