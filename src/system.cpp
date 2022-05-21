#include "system.h"

void automatic_system()
{
    /* robot routine */
}

void manual_system()
{
    /* variable declarations */
    static int joy_x = 0, joy_y = 0, speed = 0;
    
    /* get bluetooth command */
    parse_bluetooth(&joy_x, &joy_y, &speed);

    /* command motors using bluetooth data */
    command_motor(joy_x, joy_y, speed);
    
    /* emergency routine */
    emergency_routine();
}