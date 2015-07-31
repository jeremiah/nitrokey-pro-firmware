/**
  ******************************************************************************
  * @file TIM/OnePulse/main.c 
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
    
/** @addtogroup TIM_OnePulse
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;




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
    
        /* TIM4 configuration: One Pulse mode ------------------------
           is used as active edge,
           TIM_Pulse) defines the One Pulse value.
           TIM2 counter clock) - 1
           24000000/65535 = 300 Hz.
           = 682.6 us. 
           (TIM_Period - TIM_Pulse) / TIM4 counter clock = 2.048 ms.
           High-density
           ------------------------------------------------------------ */ 
        
        /* Compute the prescaler value */ 
        PrescalerValue = (uint16_t) (SystemCoreClock / 24000000) - 1;
    
        /* Time base configuration */ 
        TIM_TimeBaseStructure.TIM_Period = 65535;
    
    
    
    
    
        /* TIM4 PWM2 Mode configuration: Channel1 */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    
    
    
    
    
        /* TIM4 configuration in Input Capture Mode */ 
        
    
    
    
    
    
    
    
        /* One Pulse Mode selection */ 
        TIM_SelectOnePulseMode (TIM4, TIM_OPMode_Single);
    
        /* Input Trigger selection */ 
        TIM_SelectInputTrigger (TIM4, TIM_TS_TI2FP2);
    
        /* Slave Mode selection: Trigger Mode */ 
        TIM_SelectSlaveMode (TIM4, TIM_SlaveMode_Trigger);
    
        
    {
    }



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* TIM4 clock enable */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM4, ENABLE);
    
        /* GPIOB clock enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOB, ENABLE);


/**
  * @brief  Configure the GPIOD Pins.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* TIM4_CH1 pin (PB.06) configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    
    
    
    
        /* TIM4_CH2 pin (PB.07) configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    
    


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
        
        
    {
    }



#endif /* 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 