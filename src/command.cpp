#include "command.h"

void blind_rotate_command(int wise)
{
    if(wise == 1)
    {
        write_right_servo(ZERO_MOTEUR + 65);
        write_left_servo(ZERO_MOTEUR -65);
    }
    else if(wise == -1)
    {
        write_right_servo(ZERO_MOTEUR - 65);
        write_left_servo(ZERO_MOTEUR + 65);
    }

    delay(650);

    write_right_servo(ZERO_MOTEUR);
    write_left_servo(ZERO_MOTEUR);
}

void rotate_command(float command_angle)
{
    /* variables */
    float speed;
    int sign;
    float error;

    /* init variables */
    speed = 0.0;
    sign = 1;
    error = command_angle - robotConfiguration.theta;

    while(abs(error) > 0.050)
    {
        error = command_angle - robotConfiguration.theta;

        speed = abs(error) * Kp + OFFSET_MOTOR;

        if(speed > 84) 
        {
            speed = 84.0;
        }
        sign = (error > 0) ? 1 : -1;

        write_right_servo(ZERO_MOTEUR + (speed * sign));
        write_left_servo(ZERO_MOTEUR - (speed * sign));
    }
    write_right_servo(ZERO_MOTEUR);
    write_left_servo(ZERO_MOTEUR);
}

void forward_command(int right_sensor)
{
    // TODO
    static float speed = 0;
    static int error = 0;
    static int COMMAND = 500;
    static int MAX_CMD = 140;
    static float KP = 0.2;

    error = COMMAND - right_sensor;
    speed = abs(error) * KP;
    if(speed > (140 - ZERO_MOTEUR)) speed = (140 - ZERO_MOTEUR);

    // Serial.println(speed);
    
    if(error < 0)
    {
        write_left_servo(MAX_CMD);
        write_right_servo(MAX_CMD - speed);
    }

    if(error >= 0)
    {
        write_left_servo(MAX_CMD - speed);
        write_right_servo(MAX_CMD);
    }
}
