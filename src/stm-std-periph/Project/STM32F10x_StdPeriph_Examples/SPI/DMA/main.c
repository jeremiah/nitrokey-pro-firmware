/**
  ******************************************************************************
  * @file    SPI/DMA/main.c 
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
    
/** @addtogroup SPI_DMA
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    typedef enum
{ FAILED = 0, PASSED = !FAILED } TestStatus;


    /* Private define ------------------------------------------------------------ */ 
#define BufferSize       32
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    SPI_InitTypeDef SPI_InitStructure;



{
0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 
        





    /* Private function prototypes ----------------------------------------------- */ 
void RCC_Configuration (void);





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
        
        /* System clocks configuration --------------------------------------------- */ 
        RCC_Configuration ();
    
        /* GPIO configuration ------------------------------------------------------ */ 
        GPIO_Configuration ();
    
        /* SPI_SLAVE_Rx_DMA_Channel configuration --------------------------------------------- */ 
        DMA_DeInit (SPI_SLAVE_Rx_DMA_Channel);
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* SPI_MASTER configuration ------------------------------------------------------ */ 
        SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
    
    
    
    
    
    
    
    
    
    
        /* SPI_SLAVE configuration ------------------------------------------------------ */ 
        SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Rx;
    
    
    
        /* Enable SPI_MASTER NSS output for master mode */ 
        SPI_SSOutputCmd (SPI_MASTER, ENABLE);
    
        /* Enable SPI_SLAVE Rx request */ 
        SPI_I2S_DMACmd (SPI_SLAVE, SPI_I2S_DMAReq_Rx, ENABLE);
    
        /* Enable SPI_SLAVE */ 
        SPI_Cmd (SPI_SLAVE, ENABLE);
    
        /* Enable SPI_MASTER */ 
        SPI_Cmd (SPI_MASTER, ENABLE);
    
        /* Enable DMA1 Channel4 */ 
        DMA_Cmd (SPI_SLAVE_Rx_DMA_Channel, ENABLE);
    
        /* Transfer procedure */ 
        while (TxIdx < BufferSize)
        
    {
        
            /* Wait for SPI_MASTER Tx buffer empty */ 
            while (SPI_I2S_GetFlagStatus (SPI_MASTER, SPI_I2S_FLAG_TXE) == RESET);
        
            /* Send SPI_MASTER data */ 
            SPI_I2S_SendData (SPI_MASTER, SPI_MASTER_Buffer_Tx[TxIdx++]);
    
    
        /* Wait for DMA1 channel4 transfer complete */ 
        while (!DMA_GetFlagStatus (SPI_SLAVE_Rx_DMA_FLAG));
    
        /* Check the corectness of written data */ 
        TransferStatus = Buffercmp (SPI_SLAVE_Buffer_Rx, SPI_MASTER_Buffer_Tx, BufferSize);
    
        /* TransferStatus = PASSED, if the transmitted and received data
        /* TransferStatus = FAILED, if the transmitted and received data
        
        
    {
    }



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* PCLK2 = HCLK/2 */ 
        RCC_PCLK2Config (RCC_HCLK_Div2);
    
        /* Enable peripheral clocks -------------------------------------------------- */ 
        /* Enable SPI_SLAVE DMA clock */ 
        RCC_AHBPeriphClockCmd (SPI_SLAVE_DMA_CLK, ENABLE);
    
#ifdef USE_STM3210C_EVAL
        /* Enable GPIO clock for SPI_MASTER and SPI_SLAVE */ 
        RCC_APB2PeriphClockCmd (SPI_MASTER_GPIO_CLK | SPI_SLAVE_GPIO_CLK | 
    
        /* Enable SPI_MASTER Periph clock */ 
        RCC_APB1PeriphClockCmd (SPI_MASTER_CLK, ENABLE);
    
#else /* 
        /* Enable SPI_MASTER clock and GPIO clock for SPI_MASTER and SPI_SLAVE */ 
        RCC_APB2PeriphClockCmd (SPI_MASTER_GPIO_CLK | SPI_SLAVE_GPIO_CLK | 
    
#endif /* 
        /* Enable SPI_SLAVE Periph clock */ 
        RCC_APB1PeriphClockCmd (SPI_SLAVE_CLK, ENABLE);


/**
  * @brief  Configures the different GPIO ports.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
#ifdef USE_STM3210C_EVAL
        /* Enable SPI3 Pins Software Remapping */ 
        GPIO_PinRemapConfig (GPIO_Remap_SPI3, ENABLE);
    
        /* Configure SPI_MASTER pins: SCK and MOSI */ 
        GPIO_InitStructure.GPIO_Pin = SPI_MASTER_PIN_SCK | SPI_MASTER_PIN_MOSI;
    
    
    
    
        /* Configure SPI_MASTER NSS pin */ 
        GPIO_InitStructure.GPIO_Pin = SPI_MASTER_PIN_NSS;
    
    
    
    
#else /* 
        /* Configure SPI_MASTER pins: NSS, SCK and MOSI */ 
        GPIO_InitStructure.GPIO_Pin = SPI_MASTER_PIN_NSS | SPI_MASTER_PIN_SCK | SPI_MASTER_PIN_MOSI;
    
    
    
    
#endif /* 
        
        /* Configure SPI_SLAVE pins: NSS, SCK and MISO */ 
        GPIO_InitStructure.GPIO_Pin = SPI_SLAVE_PIN_NSS | SPI_SLAVE_PIN_SCK | SPI_SLAVE_PIN_MISO;
    


/**
  * @brief  Compares two buffers.
  * @param  pBuffer1, pBuffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval PASSED: pBuffer1 identical to pBuffer2
  *   FAILED: pBuffer1 differs from pBuffer2
  */ 
    TestStatus Buffercmp (uint8_t * pBuffer1, uint8_t * pBuffer2, uint16_t BufferLength) 
{
    
        
    {
        
            
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
    }



#endif /* 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 