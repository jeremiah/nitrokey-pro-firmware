/**
  ******************************************************************************
  * @file    DMA/ADC_TIM1/main.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   Main program body
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */  
    
    /* Includes ------------------------------------------------------------------ */ 
#include "stm32f10x.h"
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup DMA_ADC_TIM1
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
#define ADC1_DR_Address     0x4001244C
#define TIM1_CCR1_Address   0x40012C34
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    ADC_InitTypeDef ADC_InitStructure;




    /* Private function prototypes ----------------------------------------------- */ 
void RCC_Configuration (void);




    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief   Main program
  * @param  None
  * @retval None
  */ 
int main (void) 
{
    
        /* !< At this stage the microcontroller clock setting is already configured, 
           from startup
           function, refer to
        
        /* System Clocks Configuration */ 
        RCC_Configuration ();
    
        /* Configure the GPIO ports */ 
        GPIO_Configuration ();
    
        /* DMA1 Channel5 configuration ---------------------------------------------- */ 
        DMA_DeInit (DMA1_Channel5);
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* Enable DMA1 Channel5 */ 
        DMA_Cmd (DMA1_Channel5, ENABLE);
    
        /* ADC1 configuration ------------------------------------------------------ */ 
        ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    
    
    
    
    
    
    
        /* ADC1 RegularChannelConfig Test */ 
        ADC_RegularChannelConfig (ADC1, ADC_Channel_14, 1, ADC_SampleTime_55Cycles5);
    
        /* TIM1 configuration ------------------------------------------------------ */ 
        /* Time Base configuration */ 
        TIM_TimeBaseStructInit (&TIM_TimeBaseStructure);
    
    
    
    
    
    
        /* Channel1 Configuration in PWM mode */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    
    
    
    
        /* Enable TIM1 */ 
        TIM_Cmd (TIM1, ENABLE);
    
        /* Enable TIM1 outputs */ 
        TIM_CtrlPWMOutputs (TIM1, ENABLE);
    
        /* Enable TIM1 DMA interface */ 
        TIM_DMACmd (TIM1, TIM_DMA_Update, ENABLE);
    
        /* Enable ADC1 */ 
        ADC_Cmd (ADC1, ENABLE);
    
        /* Enable ADC1 reset calibaration register */ 
        ADC_ResetCalibration (ADC1);
    
        /* Check the end of ADC1 reset calibration register */ 
        while (ADC_GetResetCalibrationStatus (ADC1));
    
        /* Start ADC1 calibaration */ 
        ADC_StartCalibration (ADC1);
    
        /* Check the end of ADC1 calibration */ 
        while (ADC_GetCalibrationStatus (ADC1));
    
        /* Start ADC1 conversion */ 
        ADC_SoftwareStartConvCmd (ADC1, ENABLE);
    
        
    {
    



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* ADCCLK = PCLK2/8 */ 
        RCC_ADCCLKConfig (RCC_PCLK2_Div8);
    
        /* Enable peripheral clocks ------------------------------------------------ */ 
        /* Enable DMA1 clock */ 
        RCC_AHBPeriphClockCmd (RCC_AHBPeriph_DMA1, ENABLE);
    
        /* Enable GPIOA, GPIOC, ADC1 and TIM1 Periph clock */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | 


/**
  * @brief  Configures the different GPIO ports.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* Configure TIM1 Channel1 output */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    
    
    
    
        /* Configure ADC Channel14 as analog input */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    
    


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */ 
void assert_failed (uint8_t * file, uint32_t line) 
{
    
        /* User can add his own implementation to report the file name and line number,
           file, line) */ 
        
        /* Infinite loop */ 
        while (1)
        
    {
    



#endif /* 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 