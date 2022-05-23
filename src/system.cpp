#include "system.h"

void hc05_configuration()
{
    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BLUETOOTH_SERIAL.available())
        Serial.write(BLUETOOTH_SERIAL.read());
    
    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
        BLUETOOTH_SERIAL.write(Serial.read());
}

void automatic_system()
{
    /* input variables */
    static int right_sensor = 0, front_sensor = 0;

    /* state machine variable */
    static int state = 0;

    /* update inputs */
    update_ir_sensor(&front_sensor, &right_sensor);

    Serial.print(state);
    Serial.print(",");
    Serial.print(front_sensor);
    Serial.print(",");
    Serial.println(right_sensor);

    switch(state)
    {
        case 0:
            forward_command(right_sensor);

            if(front_sensor > 500 && right_sensor > 500)
            {
                /* rotate in anti-clock wise */
                state = 1;
            }
            else if(right_sensor < 300)
            {
                /* rotate in clock wise */
                state = 2;
            }
            break;
        
        case 1:
            blind_rotate_command(-1);
            forward_command(500);
            delay(500);
            update_ir_sensor(&front_sensor, &right_sensor);

            if(front_sensor < 300 && right_sensor > 500)
            {
                state = 0;
            }
            break;
            
        case 2:
            forward_command(500);
            delay(100);
            blind_rotate_command(1);
            forward_command(500);
            delay(500);
            update_ir_sensor(&front_sensor, &right_sensor);

            if(right_sensor > 500)
            {
                state = 0;
            }
            break;
    }
}

void manual_system()
{
    /* variable declarations */
    static int joy_x = 0, joy_y = 0, speed = 0;
    
    /* get bluetooth command */
    parse_bluetooth(&joy_x, &joy_y, &speed);

    /* command motors using bluetooth data */
    command_motor(-joy_x, joy_y, speed);
    
    /* emergency routine */
    emergency_routine(joy_y);
}