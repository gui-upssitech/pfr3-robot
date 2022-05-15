#ifndef ENCODER_H
#define ENCODER_H

// -------------

#include <Arduino.h>

// -------------

#define ENCODER_LEFT_1 2
#define ENCODER_LEFT_2 13

#define ENCODER_RIGHT_1 5
#define ENCODER_RIGHT_2 4

#define RADIUS_WHEEL_MM 60

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
        robot_config_t getConfiguration();

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