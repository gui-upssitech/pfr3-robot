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
    /* robot routine */
}

void manual_system()
{
    /* variable declarations */
    static int joy_x = 0, joy_y = 0, speed = 0;
    
    /* get bluetooth command */
    parse_bluetooth(&joy_x, &joy_y, &speed);

    // Serial.print(joy_x);
    // Serial.print(":");
    // Serial.print(joy_y);
    // Serial.print(":");
    // Serial.println(speed);

    /* command motors using bluetooth data */
    command_motor(joy_x, joy_y, speed);
    
    /* emergency routine */
    emergency_routine();
}