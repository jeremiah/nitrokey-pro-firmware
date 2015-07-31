/**
  ******************************************************************************
  * @file TIM/Parallel_Synchro/main.c 
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
    
/** @addtogroup TIM_Parallel_Synchro
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
    
        /* GPIO Configuration */ 
        GPIO_Configuration ();
    
        /* Timers synchronisation in parallel mode ----------------------------
           TIM2 Update event is used as Trigger Output 
           trigger for both slaves
           signal(update event).
           the TIM2 counter clock is 72 MHz.
           running:
           running:
           Low-Density Value line and Medium-Density Value line devices:
           frequency = 93.750 KHz,
           -------------------------------------------------------------------- */ 
        
        /* Time base configuration */ 
        TIM_TimeBaseStructure.TIM_Period = 255;
    
    
    
    
    
    
    
    
    
        /* Master Configuration in PWM1 Mode */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    
    
    
    
    
        /* Select the Master Slave Mode */ 
        TIM_SelectMasterSlaveMode (TIM2, TIM_MasterSlaveMode_Enable);
    
        /* Master Mode selection */ 
        TIM_SelectOutputTrigger (TIM2, TIM_TRGOSource_Update);
    
        /* Slaves Configuration: PWM1 Mode */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    
    
    
    
    
        /* Slave Mode selection: TIM3 */ 
        TIM_SelectSlaveMode (TIM3, TIM_SlaveMode_Gated);
    
    
        /* Slave Mode selection: TIM4 */ 
        TIM_SelectSlaveMode (TIM4, TIM_SlaveMode_Gated);
    
    
        /* TIM enable counter */ 
        TIM_Cmd (TIM3, ENABLE);
    
    
    
        
    {
    }



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* TIM2, TIM3 and TIM4 clock enable */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | 
    
        /* GPIOA, GPIOB, GPIOC and AFIO clocks enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | 


/**
  * @brief  Configure the GPIOD Pins.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
#ifdef STM32F10X_CL
        /* GPIOB Configuration: PC6(TIM3 CH1) as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    
    
    
    
    
#else /* 
        /* GPIOA Configuration: PA6(TIM3 CH1) as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    
    
    
    
#endif /* 
        /* GPIOA Configuration: PA0(TIM2 CH1) as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    
    
    
    
        /* GPIOB Configuration: PB6(TIM4 CH1) as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    


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