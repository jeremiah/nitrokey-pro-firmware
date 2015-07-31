/**
  ******************************************************************************
  * @file    Lib_DEBUG/lib_dbg.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   This file provides all peripherals pointers initialization.
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
#include "lib_dbg.h"
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup Lib_DEBUG
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
    TIM_TypeDef * TIM2_DBG;





































































    /* Private function prototypes ----------------------------------------------- */ 
    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief  This function initialize peripherals pointers.
  * @param  None
  * @retval None
  */ 
void debug (void) 
{
    
/************************************* ADC ************************************/ 
        ADC1_DBG = (ADC_TypeDef *) ADC1_BASE;
    
    
    
/************************************* BKP ************************************/ 
        BKP_DBG = (BKP_TypeDef *) BKP_BASE;
    
/************************************* CAN ************************************/ 
        CAN1_DBG = (CAN_TypeDef *) CAN1_BASE;
    
/************************************* CEC ************************************/ 
        CEC_DBG = (CEC_TypeDef *) CEC_BASE;
    
/************************************* CRC ************************************/ 
        CRC_DBG = (CRC_TypeDef *) CRC_BASE;
    
/************************************* DAC ************************************/ 
        DAC_DBG = (DAC_TypeDef *) DAC_BASE;
    
/************************************* DBGMCU**********************************/ 
        DBGMCU_DBG = (DBGMCU_TypeDef *) DBGMCU_BASE;
    
/************************************* DMA ************************************/ 
        DMA1_DBG = (DMA_TypeDef *) DMA1_BASE;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
/************************************* EXTI ***********************************/ 
        EXTI_DBG = (EXTI_TypeDef *) EXTI_BASE;
    
/************************************* FLASH and Option Bytes *****************/ 
        FLASH_DBG = (FLASH_TypeDef *) FLASH_R_BASE;
    
    
/************************************* FSMC ***********************************/ 
        FSMC_Bank1_DBG = (FSMC_Bank1_TypeDef *) FSMC_Bank1_R_BASE;
    
    
    
    
    
/************************************* GPIO ***********************************/ 
        GPIOA_DBG = (GPIO_TypeDef *) GPIOA_BASE;
    
    
    
    
    
    
    
    
/************************************* I2C ************************************/ 
        I2C1_DBG = (I2C_TypeDef *) I2C1_BASE;
    
    
/************************************* IWDG ***********************************/ 
        IWDG_DBG = (IWDG_TypeDef *) IWDG_BASE;
    
/************************************* NVIC ***********************************/ 
        NVIC_DBG = (NVIC_Type *) NVIC_BASE;
    
    
/************************************* PWR ************************************/ 
        PWR_DBG = (PWR_TypeDef *) PWR_BASE;
    
/************************************* RCC ************************************/ 
        RCC_DBG = (RCC_TypeDef *) RCC_BASE;
    
/************************************* RTC ************************************/ 
        RTC_DBG = (RTC_TypeDef *) RTC_BASE;
    
/************************************* SDIO ***********************************/ 
        SDIO_DBG = (SDIO_TypeDef *) SDIO_BASE;
    
/************************************* SPI ************************************/ 
        SPI1_DBG = (SPI_TypeDef *) SPI1_BASE;
    
    
    
/************************************* SysTick ********************************/ 
        SysTick_DBG = (SysTick_Type *) SysTick_BASE;
    
/************************************* TIM ************************************/ 
        TIM1_DBG = (TIM_TypeDef *) TIM1_BASE;
    
    
    
    
    
    
    
    
    
    
    
/************************************* USART **********************************/ 
        USART1_DBG = (USART_TypeDef *) USART1_BASE;
    
    
    
    
    
/************************************* WWDG ***********************************/ 
        WWDG_DBG = (WWDG_TypeDef *) WWDG_BASE;


/**
  * @}
  */ 
    
/**
  * @}
  */ 
    
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/ 