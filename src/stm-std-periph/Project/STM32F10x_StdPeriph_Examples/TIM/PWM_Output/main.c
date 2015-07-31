/* 
    
    // Load CMSIS and peripheral library and configuration
#include "stm32f10x.h"
    
    // Peripheral configuration functions
void GPIO_Config ();






    // uint16_t CCR1_Val = 333;
    uint16_t CCR2_Val = 249;

    // uint16_t CCR3_Val = 166;
    // uint16_t CCR4_Val = 83;
    uint16_t PrescalerValue = 0;

{
    
        // Setup STM32 system (clock, PLL and Flash configuration)
        SystemInit ();
    
        // Set up the system clocks
        RCC_Config ();
    
        // Setup the GPIOs
        GPIO_Config ();
    
    {
    



{
    
        /* TIM3 clock enable */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM3, ENABLE);
    
        /* GPIOA and GPIOB clock enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

{
    
    
        /* GPIOA Configuration:TIM3 Channel 2 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    
    
    

{
    
        /* Compute the prescaler value */ 
        PrescalerValue = (uint16_t) 1;  // (72000000 / 24000000) - 1;
    
    
    
        /* Time base configuration */ 
        TIM_TimeBaseStructure.TIM_Period = 4576;    // 72mhz/15.73426 khz
    // line rate
    TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
    
    
    
    
        /* PWM1 Mode configuration: Channel2, because there is a broken wire stuck in the header for channel 1 */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    
    
    
    
    
