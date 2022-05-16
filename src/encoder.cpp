#include "encoder.h"

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

    /* init left encoder data */
    leftEncoderData.angular_rotation = 0.0;
    leftEncoderData.linear_speed = 0.0;

    /* init right encoder data */
    rightEncoderData.angular_rotation = 0.0;
    rightEncoderData.linear_speed = 0.0;
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

    // select XC2 as clock source 
    REG_TC2_CMR0 = TC_CMR_TCCLKS_XC0; 

    // activate quadrature encoder and position measure mode, no filters
    REG_TC2_BMR = TC_BMR_QDEN | TC_BMR_POSEN | TC_BMR_EDGPHA;

    // enable the clock (CLKEN=1) and reset the counter (SWTRG=1)
    REG_TC2_CCR0 = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

void Encoder::initializePeriodicIT()
{
    REG_PMC_PCER0 |= PMC_PCER0_PID29;
    REG_TC0_IDR2 = 0xFFFFFFFF;
    REG_TC0_SR2;
    REG_TC0_CMR2 = TC_CMR_TCCLKS_TIMER_CLOCK4 | TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC;     
    REG_TC0_RC2 = TICKS_IT;
    REG_TC0_IER2 = TC_IER_CPCS;
    NVIC_EnableIRQ(TC2_IRQn);
    REG_TC0_CCR2 = TC_CCR_CLKEN | TC_CCR_SWTRG;
}

void Encoder::TC2_Handler() 
{
    REG_TC0_SR2;
    
}