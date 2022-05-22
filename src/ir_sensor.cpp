#include "ir_sensor.h"

void init_ir_sensor()
{
    pinMode(FRONT_CAPTOR, INPUT);
    pinMode(RIGHT_CAPTOR, INPUT);
}

void update_ir_sensor(int* front_sensor, int* right_sensor)
{
    (*front_sensor) = analogRead(FRONT_CAPTOR);
    (*right_sensor) = analogRead(RIGHT_CAPTOR);
}