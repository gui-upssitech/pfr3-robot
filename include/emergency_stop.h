#ifndef EMERGENCY_STOP_H
#define EMERGENCY_STOP_H

// -------------

#include <Arduino.h>
#include "pinout.h"
#include "servo.h"
#include "motor.h"

// -------------

#define DISTANCE_VALUE 400

// -------------

extern char emergency_flag;

// -------------

void init_emergency_stop();
void emergency_routine(int joy_y);

// -------------

#endif