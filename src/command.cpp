#include "command.h"

double offset_cmd = 0.0;
double theta_cmd = PI / 2 + offset_cmd;
double error = 0.0;

void initializeCommandIT()
{
    REG_PMC_PCER0 |= PMC_PCER0_PID31;
    REG_TC1_IDR1 = 0xFFFFFFFF;
    REG_TC1_SR1;
    REG_TC1_CMR1 = TC_CMR_TCCLKS_TIMER_CLOCK4 | TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC;     
    REG_TC1_RC1 = COMMAND_TICKS_IT;
    REG_TC1_IER1 = TC_IER_CPCS;
    NVIC_EnableIRQ(TC4_IRQn);
    REG_TC1_CCR1 = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

void TC4_Handler()
{

    // static float speed = 0;
    // static int sign = 1;

    // error = theta_cmd - robotConfiguration.theta;

    // speed = abs(error) * Kp + OFFSET_MOTOR;
    // if(speed > 84) speed = 84.0;
    // sign = (error > 0) ? 1 : -1;

    // Serial.println(speed);
    // servo.write_right(ZERO_MOTEUR - (speed * sign));
    // servo.write_left(ZERO_MOTEUR + (speed * sign));   
}
