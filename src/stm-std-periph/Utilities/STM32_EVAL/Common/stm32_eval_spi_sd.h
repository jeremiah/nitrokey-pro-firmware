/**
  ******************************************************************************
  * @file    stm32_eval_spi_sd.h
  * @author  MCD Application Team
  * @version V4.2.0
  * @date    04/16/2010
  * @brief   This file contains all the functions prototypes for the stm32_eval_spi_sd
  *          firmware driver.
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
    
    /* Define to prevent recursive inclusion ------------------------------------- */ 
#ifndef __STM32_EVAL_SPI_SD_H
#define __STM32_EVAL_SPI_SD_H
    
#ifdef __cplusplus
extern "C"
{
    
#endif                          /* 
    
        /* Includes ------------------------------------------------------------------ */ 
#include "stm32_eval.h"
    
/** @addtogroup Utilities
  * @{
  */ 
    
/** @addtogroup STM32_EVAL
  * @{
  */ 
    
/** @addtogroup Common
  * @{
  */ 
    
/** @addtogroup STM32_EVAL_SPI_SD
  * @{
  */ 
    
/** @defgroup STM32_EVAL_SPI_SD_Exported_Types
  * @{
  */ 
    
    { 
/**
  * @brief  SD reponses and error flags
  */ 
            SD_RESPONSE_NO_ERROR = (0x00), 
            (0x01), 
            (0x04), 
            (0x10), 
/**
  * @brief  Data response error
  */ 
        SD_DATA_OK = (0x05), 
    } SD_Error;
    
/** 
  * @brief  Card Specific Data: CSD Register   
  */ 
    typedef struct 
    {
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
    
/** 
  * @brief  Card Identification Data: CID Register   
  */ 
    typedef struct 
    {
        
        
        
        
        
        
        
        
        
        
    
    
/** 
  * @brief SD Card information 
  */ 
    typedef struct 
    {
        
        
        
        
    
    
/**
  * @}
  */ 
     
/** @defgroup STM32_EVAL_SPI_SD_Exported_Constants
  * @{
  */ 
     
/**
  * @brief  Block Size
  */ 
#define SD_BLOCK_SIZE    0x200
     
/**
  * @brief  Dummy byte
  */ 
#define SD_DUMMY_BYTE   0xFF
     
/**
  * @brief  Start Data tokens:
  *         Tokens (necessary because at nop/idle (and CS active) only 0xff is 
  *         on the data/command line)  
  */ 
#define SD_START_DATA_SINGLE_BLOCK_READ    0xFE  /*!< Data token start byte, Start Single Block Read */
#define SD_START_DATA_MULTIPLE_BLOCK_READ  0xFE  /*!< Data token start byte, Start Multiple Block Read */
#define SD_START_DATA_SINGLE_BLOCK_WRITE   0xFE  /*!< Data token start byte, Start Single Block Write */
#define SD_START_DATA_MULTIPLE_BLOCK_WRITE 0xFD  /*!< Data token start byte, Start Multiple Block Write */
#define SD_STOP_DATA_MULTIPLE_BLOCK_WRITE  0xFD  /*!< Data toke stop byte, Stop Multiple Block Write */
     
/**
  * @brief  SD detection on its memory slot
  */ 
#define SD_PRESENT        ((uint8_t)0x01)
#define SD_NOT_PRESENT    ((uint8_t)0x00)
    
/**
  * @brief  Commands: CMDxx = CMD-number | 0x40
  */ 
#define SD_CMD_GO_IDLE_STATE          0   /*!< CMD0 = 0x40 */
#define SD_CMD_SEND_OP_COND           1   /*!< CMD1 = 0x41 */
#define SD_CMD_SEND_CSD               9   /*!< CMD9 = 0x49 */
#define SD_CMD_SEND_CID               10  /*!< CMD10 = 0x4A */
#define SD_CMD_STOP_TRANSMISSION      12  /*!< CMD12 = 0x4C */
#define SD_CMD_SEND_STATUS            13  /*!< CMD13 = 0x4D */
#define SD_CMD_SET_BLOCKLEN           16  /*!< CMD16 = 0x50 */
#define SD_CMD_READ_SINGLE_BLOCK      17  /*!< CMD17 = 0x51 */
#define SD_CMD_READ_MULT_BLOCK        18  /*!< CMD18 = 0x52 */
#define SD_CMD_SET_BLOCK_COUNT        23  /*!< CMD23 = 0x57 */
#define SD_CMD_WRITE_SINGLE_BLOCK     24  /*!< CMD24 = 0x58 */
#define SD_CMD_WRITE_MULT_BLOCK       25  /*!< CMD25 = 0x59 */
#define SD_CMD_PROG_CSD               27  /*!< CMD27 = 0x5B */
#define SD_CMD_SET_WRITE_PROT         28  /*!< CMD28 = 0x5C */
#define SD_CMD_CLR_WRITE_PROT         29  /*!< CMD29 = 0x5D */
#define SD_CMD_SEND_WRITE_PROT        30  /*!< CMD30 = 0x5E */
#define SD_CMD_SD_ERASE_GRP_START     32  /*!< CMD32 = 0x60 */
#define SD_CMD_SD_ERASE_GRP_END       33  /*!< CMD33 = 0x61 */
#define SD_CMD_UNTAG_SECTOR           34  /*!< CMD34 = 0x62 */
#define SD_CMD_ERASE_GRP_START        35  /*!< CMD35 = 0x63 */
#define SD_CMD_ERASE_GRP_END          36  /*!< CMD36 = 0x64 */
#define SD_CMD_UNTAG_ERASE_GROUP      37  /*!< CMD37 = 0x65 */
#define SD_CMD_ERASE                  38  /*!< CMD38 = 0x66 */
     
/**
  * @}
  */ 
     
/** @defgroup STM32_EVAL_SPI_SD_Exported_Macros
  * @{
  */ 
/** 
  * @brief  Select SD Card: ChipSelect pin low   
  */ 
#define SD_CS_LOW()     GPIO_ResetBits(SD_CS_GPIO_PORT, SD_CS_PIN)
/** 
  * @brief  Deselect SD Card: ChipSelect pin high   
  */ 
#define SD_CS_HIGH()    GPIO_SetBits(SD_CS_GPIO_PORT, SD_CS_PIN)
/**
  * @}
  */ 
     
/** @defgroup STM32_EVAL_SPI_SD_Exported_Functions
  * @{
  */ 
    void SD_DeInit (void);
     
     
     
     
     
     
     
     
     
    
     
     
     
     
    
     
    
#ifdef __cplusplus
} 
#endif                          /* 
 
#endif  /* __STM32_EVAL_SPI_SD_H */
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