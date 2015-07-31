/**
  ******************************************************************************
  * @file TIM/OCToggle/main.c 
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
    
/** @addtogroup TIM_OCToggle
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
    
        /* NVIC Configuration */ 
        NVIC_Configuration ();
    
        /* GPIO Configuration */ 
        GPIO_Configuration ();
    
        /* ---------------------------------------------------------------------------
           SystemCoreClock / 2,
           rate = TIM3 counter clock / CCR1_Val = 366.2 Hz
           counter clock / CCR3_Val = 1464.8 Hz
           ---------------------------------------------------------------------------- */ 
        /* Compute the prescaler value */ 
        PrescalerValue = (uint16_t) (SystemCoreClock / 24000000) - 1;
    
        /* Time base configuration */ 
        TIM_TimeBaseStructure.TIM_Period = 65535;
    
    
    
    
    
        /* Output Compare Toggle Mode configuration: Channel1 */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle;
    
    
    
    
    
    
        /* Output Compare Toggle Mode configuration: Channel2 */ 
        TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    
    
    
    
        /* Output Compare Toggle Mode configuration: Channel3 */ 
        TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    
    
    
    
        /* Output Compare Toggle Mode configuration: Channel4 */ 
        TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    
    
    
    
        /* TIM enable counter */ 
        TIM_Cmd (TIM3, ENABLE);
    
        /* TIM IT enable */ 
        TIM_ITConfig (TIM3, TIM_IT_CC1 | TIM_IT_CC2 | TIM_IT_CC3 | TIM_IT_CC4, ENABLE);
    
        
    {
    }



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* PCLK1 = HCLK/4 */ 
        RCC_PCLK1Config (RCC_HCLK_Div4);
    
        /* TIM3 clock enable */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM3, ENABLE);
    
        /* GPIOA clock enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | 


/**
  * @brief  Configure the TIM3 Pins.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
#ifdef STM32F10X_CL
        /* GPIOB Configuration: TIM3 channel1, 2, 3 and 4 */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
    
    
    
    
    
#else /* 
        /* GPIOA Configuration:TIM3 Channel1, 2, 3 and 4 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
    
    
    
    
    
    
#endif /* 
} 

/**
  * @brief  Configure the nested vectored interrupt controller.
  * @param  None
  * @retval None
  */ 
void NVIC_Configuration (void) 
{
    
    
        /* Enable the TIM3 global Interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    
    
    
    


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