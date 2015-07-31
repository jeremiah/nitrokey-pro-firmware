/**
  ******************************************************************************
  * @file TIM/DMA/main.c 
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
    
/** @addtogroup TIM_DMA
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
#define TIM1_CCR3_Address    0x40012C3C
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;


{
0, 0, 0};



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
    
        /* GPIO Configuration */ 
        GPIO_Configuration ();
    
        /* DMA Configuration */ 
        DMA_Configuration ();
    
        /* TIM1 DMA Transfer example -------------------------------------------------
           = SystemCoreClock
           MHz for Low-Density Value line and
           complementary PWM
           that is changed by the DMA after a specific number of
           Repetion counter,
           ----------------------------------------------------------------------------- */ 
        /* Compute the value to be set in ARR regiter to generate signal frequency at 17.57 Khz */ 
        TimerPeriod = (SystemCoreClock / 17570) - 1;
    
        /* Compute CCR1 value to generate a duty cycle at 50% */ 
        SRC_Buffer[0] = (uint16_t) (((uint32_t) 5 * (TimerPeriod - 1)) / 10);
    
        /* Compute CCR1 value to generate a duty cycle at 37.5% */ 
        SRC_Buffer[1] = (uint16_t) (((uint32_t) 375 * (TimerPeriod - 1)) / 1000);
    
        /* Compute CCR1 value to generate a duty cycle at 25% */ 
        SRC_Buffer[2] = (uint16_t) (((uint32_t) 25 * (TimerPeriod - 1)) / 100);
    
        /* TIM1 Peripheral Configuration -------------------------------------------- */ 
        /* Time Base configuration */ 
        TIM_TimeBaseStructure.TIM_Prescaler = 0;
    
    
    
    
    
    
        /* Channel 3 Configuration in PWM mode */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    
    
    
    
    
    
    
    
    
        /* TIM1 Update DMA Request enable */ 
        TIM_DMACmd (TIM1, TIM_DMA_Update, ENABLE);
    
        /* TIM1 counter enable */ 
        TIM_Cmd (TIM1, ENABLE);
    
        /* Main Output Enable */ 
        TIM_CtrlPWMOutputs (TIM1, ENABLE);
    
        
    {
    }



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* TIM1, GPIOA and GPIOB clock enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_TIM1 | RCC_APB2Periph_GPIOA | 
    
        /* DMA clock enable */ 
        RCC_AHBPeriphClockCmd (RCC_AHBPeriph_DMA1, ENABLE);


/**
  * @brief  Configure the TIM1 Pins.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* GPIOA Configuration: Channel 3 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    
    
    
    
        /* GPIOB Configuration: Channel 3N as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
    


/**
  * @brief  Configures the DMA.
  * @param  None
  * @retval None
  */ 
void DMA_Configuration (void) 
{
    
    
        /* DMA1 Channel5 Config */ 
        DMA_DeInit (DMA1_Channel5);
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* DMA1 Channel5 enable */ 
        DMA_Cmd (DMA1_Channel5, ENABLE);


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