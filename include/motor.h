#ifndef H_MOTOR
#define H_MOTOR

// -------------

#include "servo.h"

// -------------

#define ZERO_MOTEUR 95
#define DIFF_GAP 32

// -------------

typedef struct 
{
    int dir;
    int speed;
} Command;

// -------------

void init_motor();
int get_ampl_motor(Command cmd);
void diff_steer_motor(int x, int y, int speed);
int calc_speed_motor(int speed, int x, int condition);
void command_motor(int x, int y, int val);

// -------------

#endif
