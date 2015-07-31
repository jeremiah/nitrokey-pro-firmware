/**
  ******************************************************************************
  * @file    stm3210c_eval.c
  * @author  MCD Application Team
  * @version V4.2.0
  * @date    04/16/2010
  * @brief   This file provides
  *            - set of firmware functions to manage Leds, push-button and COM ports
  *            - low level initialization functions for SD card (on SPI) and I2C
  *              serial EEPROM (sEE)
  *          available on STM3210C-EVAL evaluation board from STMicroelectronics.   
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
#include "stm3210c_eval.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_i2c.h"
#include "stm32f10x_dma.h"
    
/** @addtogroup Utilities
  * @{
  */ 
    
/** @addtogroup STM32_EVAL
  * @{
  */ 
    
/** @addtogroup STM3210C_EVAL
  * @{
  */ 
    
/** @defgroup STM3210C_EVAL_LOW_LEVEL 
  * @brief This file provides firmware functions to manage Leds, push-buttons, 
  *        COM ports, SD card on SPI and EEPROM (sEE) available on STM3210C-EVAL 
  *        evaluation board from STMicroelectronics.
  * @{
  */ 
    
/** @defgroup STM3210C_EVAL_LOW_LEVEL_Private_TypesDefinitions
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210C_EVAL_LOW_LEVEL_Private_Defines
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210C_EVAL_LOW_LEVEL_Private_Macros
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210C_EVAL_LOW_LEVEL_Private_Variables
  * @{
  */ 
    GPIO_TypeDef * GPIO_PORT[LEDn] =
{
LED1_GPIO_PORT, LED2_GPIO_PORT, LED3_GPIO_PORT, 


};


};


{
WAKEUP_BUTTON_GPIO_PORT, TAMPER_BUTTON_GPIO_PORT, 


};


};


};


    
};


    
};


};


{
EVAL_COM1};


{
EVAL_COM1_TX_GPIO_PORT};


{
EVAL_COM1_RX_GPIO_PORT};








/**
  * @}
  */ 
    
/** @defgroup STM3210C_EVAL_LOW_LEVEL_Private_FunctionPrototypes
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210C_EVAL_LOW_LEVEL_Private_Functions
  * @{
  */ 
    
/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4
  * @retval None
  */ 
void STM_EVAL_LEDInit (Led_TypeDef Led) 
{
    
    
        /* Enable the GPIO_LED Clock */ 
        RCC_APB2PeriphClockCmd (GPIO_CLK[Led], ENABLE);
    
        /* Configure the GPIO_LED pin */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_PIN[Led];
    
    
    


/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4  
  * @retval None
  */ 
void STM_EVAL_LEDOn (Led_TypeDef Led) 
{
    


/**
  * @brief  Turns selected LED Off.
  * @param  Led: Specifies the Led to be set off. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4 
  * @retval None
  */ 
void STM_EVAL_LEDOff (Led_TypeDef Led) 
{
    


/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled. 
  *   This parameter can be one of following parameters:
  *     @arg LED1
  *     @arg LED2
  *     @arg LED3
  *     @arg LED4  
  * @retval None
  */ 
void STM_EVAL_LEDToggle (Led_TypeDef Led) 
{
    


/**
  * @brief  Configures Button GPIO and EXTI Line.
  * @param  Button: Specifies the Button to be configured.
  *   This parameter can be one of following parameters:   
  *     @arg BUTTON_WAKEUP: Wakeup Push Button
  *     @arg BUTTON_TAMPER: Tamper Push Button  
  *     @arg BUTTON_KEY: Key Push Button 
  *     @arg BUTTON_RIGHT: Joystick Right Push Button 
  *     @arg BUTTON_LEFT: Joystick Left Push Button 
  *     @arg BUTTON_UP: Joystick Up Push Button 
  *     @arg BUTTON_DOWN: Joystick Down Push Button
  *     @arg BUTTON_SEL: Joystick Sel Push Button
  * @param  Button_Mode: Specifies Button mode.
  *   This parameter can be one of following parameters:   
  *     @arg BUTTON_MODE_GPIO: Button will be used as simple IO 
  *     @arg BUTTON_MODE_EXTI: Button will be connected to EXTI line with interrupt
  *                     generation capability  
  * @retval None
  */ 
void STM_EVAL_PBInit (Button_TypeDef Button, ButtonMode_TypeDef Button_Mode) 
{
    
    
    
    
        /* Enable the BUTTON Clock */ 
        RCC_APB2PeriphClockCmd (BUTTON_CLK[Button] | RCC_APB2Periph_AFIO, ENABLE);
    
        /* Configure Button pin as input floating */ 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    
    
    
        
    {
        
            /* Connect Button EXTI Line to Button GPIO Pin */ 
            GPIO_EXTILineConfig (BUTTON_PORT_SOURCE[Button], BUTTON_PIN_SOURCE[Button]);
        
            /* Configure Button EXTI line */ 
            EXTI_InitStructure.EXTI_Line = BUTTON_EXTI_LINE[Button];
        
        
            
        {
            
        
        
        else
            
        {
            
        
        
        
        
            /* Enable and set Button EXTI Interrupt to the lowest priority */ 
            NVIC_InitStructure.NVIC_IRQChannel = BUTTON_IRQn[Button];
        
        
        
        
    



/**
  * @brief  Returns the selected Button state.
  * @param  Button: Specifies the Button to be checked.
  *   This parameter can be one of following parameters:    
  *     @arg BUTTON_WAKEUP: Wakeup Push Button
  *     @arg BUTTON_TAMPER: Tamper Push Button  
  *     @arg BUTTON_KEY: Key Push Button 
  *     @arg BUTTON_RIGHT: Joystick Right Push Button 
  *     @arg BUTTON_LEFT: Joystick Left Push Button 
  *     @arg BUTTON_UP: Joystick Up Push Button 
  *     @arg BUTTON_DOWN: Joystick Down Push Button
  *     @arg BUTTON_SEL: Joystick Sel Push Button    
  * @retval The Button GPIO pin value.
  */ 
    uint32_t STM_EVAL_PBGetState (Button_TypeDef Button) 
{
    



/**
  * @brief  Configures COM port.
  * @param  COM: Specifies the COM port to be configured.
  *   This parameter can be one of following parameters:    
  *     @arg COM1
  *     @arg COM2  
  * @param  USART_InitStruct: pointer to a USART_InitTypeDef structure that
  *   contains the configuration information for the specified USART peripheral.
  * @retval None
  */ 
void STM_EVAL_COMInit (COM_TypeDef COM, USART_InitTypeDef * USART_InitStruct) 
{
    
    
        /* Enable GPIO clock */ 
        RCC_APB2PeriphClockCmd (COM_TX_PORT_CLK[COM] | COM_RX_PORT_CLK[COM] | RCC_APB2Periph_AFIO, ENABLE);
    
        
    {
        
            /* Enable the USART2 Pins Software Remapping */ 
            GPIO_PinRemapConfig (GPIO_Remap_USART2, ENABLE);
        
    
    
        /* Configure USART Tx as alternate function push-pull */ 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    
    
    
    
        /* Configure USART Rx as input floating */ 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    
    
    
        /* USART configuration */ 
        USART_Init (COM_USART[COM], USART_InitStruct);
    
        /* Enable USART */ 
        USART_Cmd (COM_USART[COM], ENABLE);



/**
  * @brief  DeInitializes the SD/SD communication.
  * @param  None
  * @retval None
  */ 
void SD_LowLevel_DeInit (void) 
{
    
    
    
    
        /* !< SD_SPI Periph clock disable */ 
        RCC_APB1PeriphClockCmd (SD_SPI_CLK, DISABLE);
    
        /* !< DeRemap SPI3 Pins */ 
        GPIO_PinRemapConfig (GPIO_Remap_SPI3, DISABLE);
    
        /* !< Configure SD_SPI pins: SCK */ 
        GPIO_InitStructure.GPIO_Pin = SD_SPI_SCK_PIN;
    
    
    
        /* !< Configure SD_SPI pins: MISO */ 
        GPIO_InitStructure.GPIO_Pin = SD_SPI_MISO_PIN;
    
    
        /* !< Configure SD_SPI pins: MOSI */ 
        GPIO_InitStructure.GPIO_Pin = SD_SPI_MOSI_PIN;
    
    
        /* !< Configure SD_SPI_CS_PIN pin: SD Card CS pin */ 
        GPIO_InitStructure.GPIO_Pin = SD_CS_PIN;
    
    
        /* !< Configure SD_SPI_DETECT_PIN pin: SD Card detect pin */ 
        GPIO_InitStructure.GPIO_Pin = SD_DETECT_PIN;
    


/**
  * @brief  Initializes the SD_SPI and CS pins.
  * @param  None
  * @retval None
  */ 
void SD_LowLevel_Init (void) 
{
    
    
    
        /* !< SD_SPI_CS_GPIO, SD_SPI_MOSI_GPIO, SD_SPI_MISO_GPIO, SD_SPI_DETECT_GPIO 
        RCC_APB2PeriphClockCmd (SD_CS_GPIO_CLK | SD_SPI_MOSI_GPIO_CLK | SD_SPI_MISO_GPIO_CLK | 
    
        /* !< SD_SPI Periph clock enable */ 
        RCC_APB1PeriphClockCmd (SD_SPI_CLK, ENABLE);
    
        /* !< AFIO Periph clock enable */ 
        RCC_APB2PeriphClockCmd (RCC_APB2Periph_AFIO, ENABLE);
    
        /* !< Remap SPI3 Pins */ 
        GPIO_PinRemapConfig (GPIO_Remap_SPI3, ENABLE);
    
        /* !< Configure SD_SPI pins: SCK */ 
        GPIO_InitStructure.GPIO_Pin = SD_SPI_SCK_PIN;
    
    
    
    
        /* !< Configure SD_SPI pins: MISO */ 
        GPIO_InitStructure.GPIO_Pin = SD_SPI_MISO_PIN;
    
    
        /* !< Configure SD_SPI pins: MOSI */ 
        GPIO_InitStructure.GPIO_Pin = SD_SPI_MOSI_PIN;
    
    
        /* !< Configure SD_SPI_CS_PIN pin: SD Card CS pin */ 
        GPIO_InitStructure.GPIO_Pin = SD_CS_PIN;
    
    
    
        /* !< Configure SD_SPI_DETECT_PIN pin: SD Card detect pin */ 
        GPIO_InitStructure.GPIO_Pin = SD_DETECT_PIN;
    
    
    
        /* !< SD_SPI Config */ 
        SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    
    
    
    
    
    
    
    
    
    


/**
  * @brief  DeInitializes peripherals used by the I2C EEPROM driver.
  * @param  None
  * @retval None
  */ 
void sEE_LowLevel_DeInit (void) 
{
    
    
    
        /* sEE_I2C Peripheral Disable */ 
        I2C_Cmd (sEE_I2C, DISABLE);
    
        /* sEE_I2C DeInit */ 
        I2C_DeInit (sEE_I2C);
    
        /* !< sEE_I2C Periph clock disable */ 
        RCC_APB1PeriphClockCmd (sEE_I2C_CLK, DISABLE);
    
        /* !< GPIO configuration */ 
        /* !< Configure sEE_I2C pins: SCL */ 
        GPIO_InitStructure.GPIO_Pin = sEE_I2C_SCL_PIN;
    
    
    
        /* !< Configure sEE_I2C pins: SDA */ 
        GPIO_InitStructure.GPIO_Pin = sEE_I2C_SDA_PIN;
    
    
        /* Configure and enable I2C DMA TX Channel interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = sEE_I2C_DMA_TX_IRQn;
    
    
    
    
    
        /* Configure and enable I2C DMA RX Channel interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = sEE_I2C_DMA_RX_IRQn;
    
    
    
    
        /* Disable and Deinitialize the DMA channels */ 
        DMA_Cmd (sEE_I2C_DMA_CHANNEL_TX, DISABLE);
    
    
    


/**
  * @brief  Initializes peripherals used by the I2C EEPROM driver.
  * @param  None
  * @retval None
  */ 
void sEE_LowLevel_Init (void) 
{
    
    
    
        /* !< sEE_I2C_SCL_GPIO_CLK and sEE_I2C_SDA_GPIO_CLK Periph clock enable */ 
        RCC_APB2PeriphClockCmd (sEE_I2C_SCL_GPIO_CLK | sEE_I2C_SDA_GPIO_CLK, ENABLE);
    
        /* !< sEE_I2C Periph clock enable */ 
        RCC_APB1PeriphClockCmd (sEE_I2C_CLK, ENABLE);
    
        /* !< GPIO configuration */ 
        /* !< Configure sEE_I2C pins: SCL */ 
        GPIO_InitStructure.GPIO_Pin = sEE_I2C_SCL_PIN;
    
    
    
    
        /* !< Configure sEE_I2C pins: SDA */ 
        GPIO_InitStructure.GPIO_Pin = sEE_I2C_SDA_PIN;
    
    
        /* Configure and enable I2C DMA TX Channel interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = sEE_I2C_DMA_TX_IRQn;
    
    
    
    
    
        /* Configure and enable I2C DMA RX Channel interrupt */ 
        NVIC_InitStructure.NVIC_IRQChannel = sEE_I2C_DMA_RX_IRQn;
    
    
    
    
        /* !< I2C DMA TX and RX channels configuration */ 
        /* Enable the DMA clock */ 
        RCC_AHBPeriphClockCmd (sEE_I2C_DMA_CLK, ENABLE);
    
        /* I2C TX DMA Channel configuration */ 
        DMA_DeInit (sEE_I2C_DMA_CHANNEL_TX);
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* I2C RX DMA Channel configuration */ 
        DMA_DeInit (sEE_I2C_DMA_CHANNEL_RX);
    
    
        /* Enable the DMA Channels Interrupts */ 
        DMA_ITConfig (sEE_I2C_DMA_CHANNEL_TX, DMA_IT_TC, ENABLE);
    


/**
  * @brief  Initializes DMA channel used by the I2C EEPROM driver.
  * @param  None
  * @retval None
  */ 
void sEE_LowLevel_DMAConfig (uint32_t pBuffer, uint32_t BufferSize, uint32_t Direction) 
{
    
        /* Initialize the DMA with the new parameters */ 
        if (Direction == sEE_DIRECTION_TX)
        
    {
        
            /* Configure the DMA Tx Channel with the buffer address and the buffer size */ 
            sEEDMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t) pBuffer;
        
        
        
    
    
    else
        
    {
        
            /* Configure the DMA Rx Channel with the buffer address and the buffer size */ 
            sEEDMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t) pBuffer;
        
        
        
    



/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 