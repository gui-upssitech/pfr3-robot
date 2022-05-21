#include "emergency_stop.h"

char emergency_flag = 0x00;

void init_emergency_stop()
{
    pinMode(EMERGENCY_STOP, INPUT); // TODO register access
}

void emergency_routine()
{
    unsigned int value = analogRead(EMERGENCY_STOP); // TODO register access
    if(value > DISTANCE_VALUE)
    {
        emergency_flag = 0x01;
        write_left_servo(ZERO_MOTEUR);
        write_right_servo(ZERO_MOTEUR);
    }
    else
    {
        emergency_flag = 0x00;
    }
}