#ifndef COMMAND_H
#define COMMAND_H

// -------------

#include <Arduino.h>
#include "encoder.h"
#include "servo.h"
#include "motor.h"

// -------------

#define CLK4_RESOLUTION (128.0/84000000.0)
#define COMMAND_TICKS_IT 1400

#define OFFSET_MOTOR 35

#define Kp 30

// -------------

extern double theta_cmd;
extern double error;

// -------------

void initializeCommandIT();

// -------------

#endif