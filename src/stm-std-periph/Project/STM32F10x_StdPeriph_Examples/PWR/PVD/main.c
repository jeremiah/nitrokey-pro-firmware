/**
  ******************************************************************************
  * @file    PWR/PVD/main.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   Main program body.
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
#include "stm32_eval.h"
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup PWR_PVD
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    /* Private function prototypes ----------------------------------------------- */ 
void EXTI_Configuration (void);




    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief   Main program.
  * @param  None
  * @retval None
  */ 
int main (void) 
{
    
        /* !< At this stage the microcontroller clock setting is already configured, 
           from startup
           function, refer to
        
        /* Initialize LEDs and Key Button mounted on STM3210X-EVAL board */ 
        STM_EVAL_LEDInit (LED1);
    
        /* Enable PWR and BKP clock */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
    
        /* Configure EXTI Line to generate an interrupt on falling edge */ 
        EXTI_Configuration ();
    
        /* NVIC configuration */ 
        NVIC_Configuration ();
    
        /* Configure the PVD Level to 2.9V */ 
        PWR_PVDLevelConfig (PWR_PVDLevel_2V9);
    
        /* Enable the PVD Output */ 
        PWR_PVDCmd (ENABLE);
    
        
    {
    



/**
  * @brief  Configures EXTI Lines.
  * @param  None
  * @retval None
  */ 
void EXTI_Configuration (void) 
{
    
    
        /* Configure EXTI Line16(PVD Output) to generate an interrupt on rising and
        EXTI_ClearITPendingBit (EXTI_Line17);
    
    
    
    
    


/**
  * @brief  Configures NVIC and Vector Table base location.
  * @param  None
  * @retval None
  */ 
void NVIC_Configuration (void) 
{
    
    
        /* Configure one bit for preemption priority */ 
        NVIC_PriorityGroupConfig (NVIC_PriorityGroup_1);
    
        /* Enable the PVD Interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = PVD_IRQn;
    
    
    
    


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