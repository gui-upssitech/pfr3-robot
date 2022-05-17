#ifndef SERVO_H
#define SERVO_H

// -------------

#include <Arduino.h>

// -------------

#define LEFT_MOTOR_PIN 11
#define RIGHT_MOTOR_PIN 5   

# define CLK_RES_MS (128.0/84000.0)
#define PERIOD_MS 2
#define RC 1312
#define R_MIN (RC/2)
#define R_MAX RC

// -------------

class Servo 
{
    public:
    Servo();
    void write_left(float angle);
    void write_right(float angle);

    private:
    void initialize();
    
};

// -------------

#endif