#include <Servo.h>

#ifndef H_MOTOR
#define H_MOTOR

// -------------

#define PIN_SERVO_G 5
#define PIN_SERVO_D 6

#define FWD 0
#define BCK 1
#define LFT 2
#define RGT 3
#define ZERO_MOTEUR 95

// -------------

void init_motors();
void commander(int dir, int val);
void commandAmpl(Servo m, int dir, int val);

// -------------

#endif
