#ifndef ENCODER_H
#define ENCODER_H

// -------------

#include <Arduino.h>

// -------------

#define ENCODER_LEFT_1 2
#define ENCODER_LEFT_2 13
#define ENCODER_RIGHT_1 5
#define ENCODER_RIGHT_2 4

#define CLK4_RESOLUTION_US 128.0/84.0
#define TICKS_IT 10
#define SPEED_DT (CLK4_RESOLUTION_US*TICKS_IT)

#define ENCODER_RESOLUTION (360.0 / 12000.0)


#define RADIUS_WHEEL_MM 60


#define CLOCK4_RESOLUTION_US (128.0 / 84.0)
#define TICKS 10.0
#define SPEED_DT_US (TICKS * CLOCK4_RESOLUTION_US)

// -------------

typedef struct 
{
    double x;
    double y;
    double theta;
} robot_config_t;

typedef struct 
{
    double angular_rotation;
    double linear_speed;
} encoder_data_t;

// -------------

class Encoder 
{
    public:
        Encoder();
        void initialize();

    private:
        robot_config_t robotConfiguration;
        encoder_data_t leftEncoderData;
        encoder_data_t rightEncoderData;

        void initializeDataStruct();
        void initializePins();
        void initializeQuadratureEncoders();
        void initializePeriodicIT();
};

// -------------

#endif