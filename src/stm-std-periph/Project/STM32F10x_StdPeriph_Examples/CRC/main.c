/**
  ******************************************************************************
  * @file    Examples/CRC/main.c 
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
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup CRC_Example
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
#define BUFFER_SIZE    114
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
static const uint32_t DataBuffer[BUFFER_SIZE] = 
    
    
    0x34430420, 0x64e674c7, 0x44a45485, 
    0xd58d3653, 0x26721611, 0x063076d7,
    
    
    0xe98ef9af, 0x89489969, 0xa90ab92b, 
    0x2a12dbfd, 0xfbbfeb9e, 0x9b798b58,
    
    
    0x5ed54ef4, 0x2e321e51, 0x0e70ff9f, 
    0x918881a9, 0xb1caa1eb, 0xd10cc12d,
    
    
    0x32d24235, 0x52146277, 0x7256b5ea, 
    0x34e224c3, 0x04817466, 0x64475424,
    
    
    0xe92f99c8, 0xb98aa9ab, 0x58444865, 
    0xdb5ceb3f, 0xfb1e8bf9, 0x9bd8abbb,
    
    
    0x3ca22c83, 0x1ce00cc1, 0xef1fff3e, 
    0x7e364e55, 0x2e933eb2, 0x0ed11ef0 
};



    /* Private function prototypes ----------------------------------------------- */ 
void Delay (__IO uint32_t nCount);


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
        
        /* Enable CRC clock */ 
        RCC_AHBPeriphClockCmd (RCC_AHBPeriph_CRC, ENABLE);
    
        /* Compute the CRC of "DataBuffer" */ 
        CRCValue = CRC_CalcBlockCRC ((uint32_t *) DataBuffer, BUFFER_SIZE);
    
        
    {
    



/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */ 
void Delay (__IO uint32_t nCount) 
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