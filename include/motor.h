#include <Servo.h>

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

class MotorHandler {
    private:
    Servo motor_g, motor_d;
    Command left, right;

    void commandAmpl(Servo m, Command cmd);
    void diffSteer(int x, int y, int speed);
    int calc_speed(int speed, int x, int condition);
    
    public:
    MotorHandler(int motor_g_pin, int motor_d_pin);
    void command(int x, int y, int val);
};

// -------------

#endif
