/**
  ******************************************************************************
  * @file    stm3210e_eval_fsmc_sram.c
  * @author  MCD Application Team
  * @version V4.2.0
  * @date    04/16/2010
  * @brief   This file provides a set of functions needed to drive the 
  *          IS61WV51216BLL SRAM memory mounted on STM3210E-EVAL board.
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
#include "stm3210e_eval_fsmc_sram.h"
    
/** @addtogroup Utilities
  * @{
  */ 
    
/** @addtogroup STM32_EVAL
  * @{
  */ 
    
/** @addtogroup STM3210E_EVAL
  * @{
  */ 
    
/** @addtogroup STM3210E_EVAL_FSMC_SRAM
  * @brief      This file provides a set of functions needed to drive the 
  *             IS61WV51216BLL SRAM memory mounted on STM3210E-EVAL board.
  * @{
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_SRAM_Private_Types
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_SRAM_Private_Defines
  * @{
  */ 
/** 
  * @brief  FSMC Bank 1 NOR/SRAM3  
  */ 
#define Bank1_SRAM3_ADDR    ((uint32_t)0x68000000)     
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_SRAM_Private_Macros
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_SRAM_Private_Variables
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_SRAM_Private_Function_Prototypes
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_SRAM_Private_Functions
  * @{
  */ 
    
/**
  * @brief  Configures the FSMC and GPIOs to interface with the SRAM memory.
  *         This function must be called before any write/read operation
  *         on the SRAM.
  * @param  None 
  * @retval None
  */ 
void SRAM_Init (void) 
{
    
    
    
    
    
/*-- GPIO Configuration ------------------------------------------------------*/ 
        /* !< SRAM Data lines configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | 
    
    
    
    
        GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
    
    
        /* !< SRAM Address lines configuration */ 
        GPIO_InitStructure.GPIO_Pin =
        GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | 
    
    
    
    
    
    
        /* !< NOE and NWE configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    
    
        /* !< NE3 configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    
    
        /* !< NBL0, NBL1 configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    
    
/*-- FSMC Configuration ------------------------------------------------------*/ 
        p.FSMC_AddressSetupTime = 0;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* !< Enable FSMC Bank1_SRAM Bank */ 
        FSMC_NORSRAMCmd (FSMC_Bank1_NORSRAM3, ENABLE);


/**
  * @brief  Writes a Half-word buffer to the FSMC SRAM memory. 
  * @param  pBuffer : pointer to buffer. 
  * @param  WriteAddr : SRAM memory internal address from which the data will be 
  *         written.
  * @param  NumHalfwordToWrite : number of half-words to write. 
  * @retval None
  */ 
void SRAM_WriteBuffer (uint16_t * pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite) 
{
    
        
    {
        
            /* !< Transfer data to the memory */ 
            *(uint16_t *) (Bank1_SRAM3_ADDR + WriteAddr) = *pBuffer++;
        
            /* !< Increment the address */ 
            WriteAddr += 2;
    



/**
  * @brief  Reads a block of data from the FSMC SRAM memory.
  * @param  pBuffer : pointer to the buffer that receives the data read from the 
  *         SRAM memory.
  * @param  ReadAddr : SRAM memory internal address to read from.
  * @param  NumHalfwordToRead : number of half-words to read.
  * @retval None
  */ 
void SRAM_ReadBuffer (uint16_t * pBuffer, uint32_t ReadAddr, uint32_t NumHalfwordToRead) 
{
    
        
    {
        
            /* !< Read a half-word from the memory */ 
            *pBuffer++ = *(__IO uint16_t *) (Bank1_SRAM3_ADDR + ReadAddr);
        
            /* !< Increment the address */ 
            ReadAddr += 2;
    



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