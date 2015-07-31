/**
  ******************************************************************************
  * @file    USART/Synchronous/main.c 
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
    
/** @addtogroup USART_Synchronous
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    typedef enum
{ FAILED = 0, PASSED = !FAILED } TestStatus;


    /* Private define ------------------------------------------------------------ */ 
#define TxBufferSize1   (countof(TxBuffer1) - 1)
#define TxBufferSize2   (countof(TxBuffer2) - 1)
#define DYMMY_BYTE      0x00
    
    /* Private macro ------------------------------------------------------------- */ 
#define countof(a)   (sizeof(a) / sizeof(*(a)))
    
    /* Private variables --------------------------------------------------------- */ 
    USART_InitTypeDef USART_InitStructure;












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
    
        /* Configure the SPI */ 
        SPI_Configuration ();
    
        /* USARTy configuration ------------------------------------------------------ */ 
        /* USARTy configured as follow:
           disabled (RTS and CTS signals)
           Data is captured on the second edge 
        USART_ClockInitStructure.USART_Clock = USART_Clock_Enable;
    
    
    
    
    
    
    
    
    
    
    
    
        /* Configure the USARTy */ 
        USART_Init (USARTy, &USART_InitStructure);
    
        /* Enable the USARTy */ 
        USART_Cmd (USARTy, ENABLE);
    
        
    {
        
            /* Write one byte in the USARTy Transmit Data Register */ 
            USART_SendData (USARTy, TxBuffer1[TxCounter1++]);
        
            /* Wait until end of transmit */ 
            while (USART_GetFlagStatus (USARTy, USART_FLAG_TC) == RESET)
            
        {
        
        
            /* Wait the byte is entirtly received by SPIy */ 
            while (SPI_I2S_GetFlagStatus (SPIy, SPI_I2S_FLAG_RXNE) == RESET)
            
        {
        
        
            /* Store the received byte in the RxBuffer2 */ 
            RxBuffer2[RxCounter2++] = SPI_I2S_ReceiveData (SPIy);
    
    
        /* Clear the USARTy Data Register */ 
        USART_ReceiveData (USARTy);
    
        
    {
        
            /* Wait until end of transmit */ 
            while (SPI_I2S_GetFlagStatus (SPIy, SPI_I2S_FLAG_TXE) == RESET)
            
        {
        
        
            /* Write one byte in the SPIy Transmit Data Register */ 
            SPI_I2S_SendData (SPIy, TxBuffer2[TxCounter2++]);
        
            /* Send a Dummy byte to generate clock to slave */ 
            USART_SendData (USARTy, DYMMY_BYTE);
        
            /* Wait until end of transmit */ 
            while (USART_GetFlagStatus (USARTy, USART_FLAG_TC) == RESET)
            
        {
        
        
            /* Wait the byte is entirtly received by USARTy */ 
            while (USART_GetFlagStatus (USARTy, USART_FLAG_RXNE) == RESET)
            
        {
        
        
            /* Store the received byte in the RxBuffer1 */ 
            RxBuffer1[RxCounter1++] = USART_ReceiveData (USARTy);
    
    
        /* Check the received data with the send ones */ 
        TransferStatus1 = Buffercmp (TxBuffer1, RxBuffer2, TxBufferSize1);
    
        /* TransferStatus = PASSED, if the data transmitted from USARTy and 
        /* TransferStatus = FAILED, if the data transmitted from USARTy and 
        TransferStatus2 = Buffercmp (TxBuffer2, RxBuffer1, TxBufferSize2);
    
        /* TransferStatus = PASSED, if the data transmitted from SPIy and 
        /* TransferStatus = FAILED, if the data transmitted from SPIy and 
        
        
    {
    



/**
  * @brief  Configures the different system clocks.
  * @param  None
  * @retval None
  */ 
void RCC_Configuration (void) 
{
    
        /* Enable GPIO clock */ 
        RCC_APB2PeriphClockCmd (USARTy_GPIO_CLK | SPIy_GPIO_CLK | RCC_APB2Periph_AFIO, ENABLE);
    
        /* Enable USARTy Clock */ 
        RCC_APB2PeriphClockCmd (USARTy_CLK, ENABLE);
    
        /* Enable SPIy Clock */ 
        RCC_APB2PeriphClockCmd (SPIy_CLK, ENABLE);


/**
  * @brief  Configures the different GPIO ports.
  * @param  None
  * @retval None
  */ 
void GPIO_Configuration (void) 
{
    
    
        /* Configure USARTy TX and USARTy CK pins as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Pin = USARTy_TxPin | USARTy_ClkPin;
    
    
    
    
        /* Configure SPI1 pins: SCK, MISO and MOSI */ 
        GPIO_InitStructure.GPIO_Pin = SPIy_SCKPin | SPIy_MISOPin | SPIy_MOSIPin;
    
    
        /* Configure USARTy RX as input floating */ 
        GPIO_InitStructure.GPIO_Pin = USARTy_RxPin;
    
    


/**
  * @brief  Configures the SPI.
  * @param  None
  * @retval None
  */ 
void SPI_Configuration (void) 
{
    
    
    
    
        /* SPIy Config */ 
        SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    
    
    
    
    
    
    
        /* Configure SPIy */ 
        SPI_Init (SPIy, &SPI_InitStructure);
    
        /* SPIy enable */ 
        SPI_Cmd (SPIy, ENABLE);


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
    



#endif /* 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 