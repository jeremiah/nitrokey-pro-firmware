/**
  ******************************************************************************
  * @file    CAN/Networking/main.c 
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
#include "platform_config.h"
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup CAN_Networking
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private define ------------------------------------------------------------ */ 
#define Key_Pressed   0x01
#define Key_NoPressed 0x00
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    CAN_InitTypeDef CAN_InitStructure;





    /* Private function prototypes ----------------------------------------------- */ 
void RCC_Configuration (void);














    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */ 
int main (void) 
{
    
        /* !< At this stage the microcontroller clock setting is already configured, 
           from startup
           function, refer to
        
        /* System clocks configuration --------------------------------------------- */ 
        RCC_Configuration ();
    
        /* GPIO configuration ------------------------------------------------------ */ 
        GPIO_Configuration ();
    
        /* NVIC configuration ------------------------------------------------------ */ 
        NVIC_Configuration ();
    
        /* Configures LED 1..4 */ 
        STM_EVAL_LEDInit (LED1);
    
    
    
    
    
        /* Configure Push buttion key */ 
        STM_EVAL_PBInit (BUTTON_KEY, BUTTON_MODE_GPIO);
    
        /* CAN configuration */ 
        CAN_Config ();
    
    
        /* turn off all leds */ 
        STM_EVAL_LEDOff (LED1);
    
    
    
    
        /* Infinite loop */ 
        while (1)
        
    {
        
            
        {
            
                
            {
                
            
            
            else
                
            {
                
                
                
                
                
                    
                {
                
            
        
    



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* GPIO clock enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIO_CAN, ENABLE);
    
        /* CAN1 Periph clock enable */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_CAN1, ENABLE);


/**
  * @brief  Configures the GPIO.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* Configure CAN pin: RX */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CAN_RX;
    
    
    
        /* Configure CAN pin: TX */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_CAN_TX;
    
    
    
    


/**
  * @brief  Configures the NVIC for CAN.
  * @param  None
  * @retval None
  */ 
void NVIC_Configuration (void) 
{
    
    
    
#ifndef STM32F10X_CL
        NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
    
#else /* 
        NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
    
#endif  /* STM32F10X_CL*/
        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0;
    
    
    


/**
  * @brief  Turn ON/OFF the dedicate led
  * @param  Ledstatus: Led number from 0 to 3 
  * @retval None
  */ 
void LED_Display (uint8_t Ledstatus) 
{
    
        /* turn off all leds */ 
        STM_EVAL_LEDOff (LED1);
    
    
    
    
        
    {
        
            STM_EVAL_LEDOn (LED1);
            
        
            STM_EVAL_LEDOn (LED2);
            
        
            STM_EVAL_LEDOn (LED3);
            
        
            STM_EVAL_LEDOn (LED4);
            
        
            
    



/**
  * @brief  Configures the CAN.
  * @param  None
  * @retval None
  */ 
void CAN_Config (void) 
{
    
        /* CAN register init */ 
        CAN_DeInit (CAN1);
    
    
        /* CAN cell init */ 
        CAN_InitStructure.CAN_TTCM = DISABLE;
    
    
    
    
    
    
    
    
    
    
    
    
        /* CAN filter init */ 
        CAN_FilterInitStructure.CAN_FilterNumber = 0;
    
    
    
    
    
    
    
    
    
    
        /* transmit */ 
        TxMessage.StdId = 0x321;
    
    
    
    


/**
  * @brief  Delay
  * @param  None
  * @retval None
  */ 
void Delay () 
{
    
    



/**
  * @brief  Initializes a Rx Message.
  * @param  CanRxMsg *RxMessage
  * @retval None
  */ 
void Init_RxMes (CanRxMsg * RxMessage) 
{
    
    
    
    
    
    
    
        



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