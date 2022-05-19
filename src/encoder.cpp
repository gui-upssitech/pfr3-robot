#include "encoder.h"

robot_config_t robotConfiguration;

Encoder::Encoder()
{
    initialize();
}

void Encoder::initialize()
{
    initializeDataStruct();
    initializePins();
    initializeQuadratureEncoders();
    initializePeriodicIT();
}

void Encoder::initializePins()
{
    PIO_Configure(PIOC, PIO_PERIPH_B, PIO_PC25B_TIOA6, PIO_DEFAULT);
    PIO_Configure(PIOC, PIO_PERIPH_B, PIO_PC26B_TIOB6, PIO_DEFAULT);
}

void Encoder::initializeDataStruct()
{
    /* init robot configuration */
    robotConfiguration.x = 0.0;
    robotConfiguration.y = 0.0;
    robotConfiguration.theta = 0.0;
}

void Encoder::initializeQuadratureEncoders()
{
    /* Setup the left quadrature encoder on PB25 (digital pin 2) and PB27 (digital pin 13) */
    REG_PMC_PCER0 = PMC_PCER0_PID27; // activate clock for TC0  

    REG_TC0_CMR0 = TC_CMR_TCCLKS_XC0; // select XC0 as clock source 

    // activate quadrature encoder and position measure mode, no filters
    REG_TC0_BMR = TC_BMR_QDEN | TC_BMR_POSEN | TC_BMR_EDGPHA;

    // enable the clock (CLKEN=1) and reset the counter (SWTRG=1)
    REG_TC0_CCR0 = TC_CCR_CLKEN | TC_CCR_SWTRG;

    /* Setup the right quadrature encoder on PC25 (digital pin 5) and PC26 (digital pin 4) */
    REG_PMC_PCER0 = PMC_PCER0_PID27 | PMC_PCER0_PID28 | PMC_PCER0_PID29 | PMC_PCER0_PID30 | PMC_PCER0_PID31;
    REG_PMC_PCER1 = PMC_PCER1_PID32 | PMC_PCER1_PID33 | PMC_PCER1_PID34 | PMC_PCER1_PID35;  

    // select XC0 as clock source 
    REG_TC2_CMR0 = TC_CMR_TCCLKS_XC0; 

    // activate quadrature encoder and position measure mode, no filters
    REG_TC2_BMR = TC_BMR_QDEN | TC_BMR_POSEN | TC_BMR_EDGPHA;

    // enable the clock (CLKEN=1) and reset the counter (SWTRG=1)
    REG_TC2_CCR0 = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

void Encoder::initializePeriodicIT()
{
    REG_PMC_PCER0 |= PMC_PCER0_PID30;
    REG_TC1_IDR0 = 0xFFFFFFFF;
    REG_TC1_SR0;
    REG_TC1_CMR0 = TC_CMR_TCCLKS_TIMER_CLOCK4 | TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC;     
    REG_TC1_RC0 = TICKS_IT;
    REG_TC1_IER0 = TC_IER_CPCS;
    NVIC_EnableIRQ(TC3_IRQn);
    REG_TC1_CCR0 = TC_CCR_CLKEN | TC_CCR_SWTRG;
}


void TC3_Handler()
{
    REG_TC1_SR0;

    static double old_left_linear_speed = 0.0;
    static double old_right_linear_speed = 0.0;

    // get linear position
    double left_linear_pos = (int) REG_TC0_CV0 * ENCODER_RESOLUTION * RADIUS_WHEEL_MM;
    double right_linear_pos = (int) REG_TC2_CV0 * ENCODER_RESOLUTION * RADIUS_WHEEL_MM;
    
    // get position variation
    double delta_left_linear_pos = left_linear_pos - old_left_linear_speed;
    double delta_right_linear_pos = right_linear_pos - old_right_linear_speed;

    // average of position variations
    double average_delta_linear_pos = (delta_left_linear_pos + delta_right_linear_pos) / 2.0;

    // difference of position variations
    double diff_delta_linear_pos = delta_right_linear_pos - delta_left_linear_pos;

    // get robot configuration variation
    double delta_x = average_delta_linear_pos * cos(robotConfiguration.theta);
    double delta_y = average_delta_linear_pos * sin(robotConfiguration.theta);
    double delta_theta = diff_delta_linear_pos / L;

    // update robot configuration
    robotConfiguration.x += delta_x;
    robotConfiguration.y += delta_y;
    robotConfiguration.theta += delta_theta;
    
    // save linear position
    old_left_linear_speed = left_linear_pos;
    old_right_linear_speed = right_linear_pos;
}
