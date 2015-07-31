/**
  ******************************************************************************
  * @file TIM/TIM1_Synchro/main.c 
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
    
/** @addtogroup TIM_TIM1_Synchro
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
    
        /* TIM1 and Timers(TIM3 and TIM4) synchronisation in parallel mode -----------
           The TIM1 Update event is used as Trigger Output
           input trigger for both slaves
           signal(update event).
           Prescaler = 0 so the TIM1 counter clock is 72 MHz.
           (TIM1_Period + 1) = 281.250 KHz
           frequency)/ ((TIM3 period +1)* (Repetion_Counter+1)) = 18.750 KHz and
           is running at:
           1) = 50%
           counter clock is 24 MHz.
           --------------------------------------------------------------------------- */ 
        
        /* TIM3 Peripheral Configuration ---------------------------------------- */ 
        /* TIM3 Slave Configuration: PWM1 Mode */ 
        TIM_TimeBaseStructure.TIM_Period = 2;
    
    
    
    
    
    
    
    
    
        /* Slave Mode selection: TIM3 */ 
        TIM_SelectSlaveMode (TIM3, TIM_SlaveMode_Gated);
    
    
        /* TIM4 Peripheral Configuration ---------------------------------------- */ 
        /* TIM4 Slave Configuration: PWM1 Mode */ 
        TIM_TimeBaseStructure.TIM_Period = 1;
    
    
    
    
    
    
    
    
    
        /* Slave Mode selection: TIM4 */ 
        TIM_SelectSlaveMode (TIM4, TIM_SlaveMode_Gated);
    
    
        /* TIM1 Peripheral Configuration ---------------------------------------- */ 
        /* Time Base configuration */ 
        TIM_TimeBaseStructure.TIM_Prescaler = 0;
    
    
    
    
    
    
        /* Channel 1 Configuration in PWM mode */ 
        TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    
    
    
    
    
    
    
    
    
        /* Automatic Output enable, Break, dead time and lock configuration */ 
        TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;
    
    
    
    
    
    
    
    
        /* Master Mode selection */ 
        TIM_SelectOutputTrigger (TIM1, TIM_TRGOSource_Update);
    
        /* Select the Master Slave Mode */ 
        TIM_SelectMasterSlaveMode (TIM1, TIM_MasterSlaveMode_Enable);
    
        /* TIM1 counter enable */ 
        TIM_Cmd (TIM1, ENABLE);
    
        /* TIM enable counter */ 
        TIM_Cmd (TIM3, ENABLE);
    
    
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
                                RCC_APB2Periph_GPIOE | 
    
        /* TIM3 and TIM4 clock enable */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4, ENABLE);


/**
  * @brief  Configures TIM1, TIM3 and TIM4 Pins.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
#ifdef STM32F10X_CL
        /* GPIOC Configuration: TIM3 channel1 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    
    
    
    
    
        /* GPIOE Configuration: TIM1 channel1 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    
    
    
#else /* 
        
        /* GPIOA Configuration: TIM1 Channel1 and TIM3 Channel1 as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_8;
    
    
    
    
#endif /* 
        
        /* GPIOB Configuration: TIM4 Channel1 as alternate function push-pull */ 
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