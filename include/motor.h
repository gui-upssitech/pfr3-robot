#include "servo.h"

#ifndef H_MOTOR
#define H_MOTOR

// -------------

#define ZERO_MOTEUR 95
#define DIFF_GAP 32

// -------------

typedef struct {
    int dir;
    int speed;
} Command;

class MotorHandler 
{
    private:
    Servo servoHandler;
    Command left, right;

    int getAmpl(Command cmd);
    void diffSteer(int x, int y, int speed);
    int calc_speed(int speed, int x, int condition);
    
    public:
    MotorHandler();
    void command(int x, int y, int val);
};

// -------------

#endif
