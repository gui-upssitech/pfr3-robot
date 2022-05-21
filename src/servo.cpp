#include "servo.h"


void init_servo()
{
    REG_PMC_PCER0 |= PMC_PCER0_PID29;
    REG_PMC_PCER1 |= (PMC_PCER1_PID34 | PMC_PCER1_PID35);

    PIOD->PIO_PDR |= (PIO_PDR_P7 | PIO_PDR_P8);
    PIOD->PIO_ABSR |= (PIO_ABSR_P7 | PIO_ABSR_P8);

    REG_TC2_SR2;

    REG_TC2_CMR2 =  TC_CMR_TCCLKS_TIMER_CLOCK4 | 
                    TC_CMR_WAVE | 
                    TC_CMR_WAVSEL_UP_RC | 
                    TC_CMR_ACPA_CLEAR | 
                    TC_CMR_ACPC_SET |
                    TC_CMR_BCPB_CLEAR |
                    TC_CMR_BCPC_SET |
                    TC_CMR_EEVT_XC0;
    
    REG_TC2_RC2 = RC;
    REG_TC2_RA2 = R_MIN;
    REG_TC2_RB2 = R_MIN;

    REG_TC2_CCR2 = TC_CCR_CLKEN | TC_CCR_SWTRG;

    write_left_servo(ZERO_MOTEUR);
    write_right_servo(ZERO_MOTEUR);
}

void write_left_servo(float angle)
{
    if(emergency_flag == 0x01)
    {
        angle = ZERO_MOTEUR;
    }

    float duration = angle / 180.0 + PERIOD_MS / 2.0;
    int value = duration / (CLK_RES_MS);
    value = (value < R_MIN) ? (R_MIN) : ((value > R_MAX) ? (R_MAX) : value);
    REG_TC2_RA2 = value;
}

void write_right_servo(float angle)
{
    if(emergency_flag == 0x01)
    {
        angle = ZERO_MOTEUR;
    }
    
    float duration = angle / 180.0 + PERIOD_MS / 2.0;
    int value = duration / (CLK_RES_MS);
    value = (value < R_MIN) ? (R_MIN) : ((value > R_MAX) ? (R_MAX) : value);
    REG_TC2_RB2 = value;
}