/**
  ******************************************************************************
  * @file    TIM/TIM9_OCToggle/main.c 
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
    
/** @addtogroup TIM9_OCToggle
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;





    /* Private function prototypes ----------------------------------------------- */ 
void GPIO_Configuration (void);




    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */ 
int main (void) 
{
    
        /* !< At this stage the microcontroller clock setting is already configured, 
           from startup
           function, refer to
        
        /* Configure TIM9 pins */ 
        GPIO_Configuration ();
    
        /* NVIC Configuration */ 
        NVIC_Configuration ();
    
        /* ---------------------------------------------------------------------------
           SystemCoreClock (72MHz),
           update rate = TIM9 counter clock / CCR1Val = 732.4 Hz
           ---------------------------------------------------------------------------- */ 
        /* Compute the prescaler value */ 
        PrescalerValue = (uint16_t) (SystemCoreClock / 24000000) - 1;
    
        /* Time base configuration */ 
        TIM_TimeBaseStructure.TIM_Period = 65535;
    
    
    
    
    
        /* Output Compare Toggle Mode configuration: Channel1 */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle;
    
    
    
    
    
    
        /* Output Compare Toggle Mode configuration: Channel2 */ 
        TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    
    
    
    
        /* TIM enable counter */ 
        TIM_Cmd (TIM9, ENABLE);
    
        /* TIM IT enable */ 
        TIM_ITConfig (TIM9, TIM_IT_CC1 | TIM_IT_CC2, ENABLE);
    
        
    {
    



/**
  * @brief  Configure TIM9 pins.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* Enable TIM9 and GPIOA clock */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_TIM9 | RCC_APB2Periph_GPIOA, ENABLE);
    
        /* GPIOA Configuration:TIM9 Channel1 and 2 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    
    
    


/**
  * @brief  Configure the nested vectored interrupt controller.
  * @param  None
  * @retval None
  */ 
void NVIC_Configuration (void) 
{
    
    
        /* Enable the TIM9 global Interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = TIM1_BRK_TIM9_IRQn;
    
    
    
    


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