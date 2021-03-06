#ifndef ENCODER_H
#define ENCODER_H

// -------------

#include <Arduino.h>

// -------------

#define ENCODER_LEFT_1 2
#define ENCODER_LEFT_2 13
#define ENCODER_RIGHT_1 5
#define ENCODER_RIGHT_2 4
#define ENCODER_RESOLUTION (2.0*PI/12000.0)

#define CLK4_RESOLUTION (128.0/84000000.0)
#define TICKS_IT 100.0
#define SPEED_DT (CLK4_RESOLUTION*TICKS_IT)

#define RADIUS_WHEEL_MM 60.0
#define L 290.0

// -------------

typedef struct 
{
    double x;
    double y;
    double theta;
} robot_config_t;

// -------------

extern robot_config_t robotConfiguration;

// -------------

void init_encoder();
void init_data_struct_encoder();
void init_pins_encoder();
void init_quadrature_encoder();
void init_periodic_IT_encoder();

// -------------

#endif