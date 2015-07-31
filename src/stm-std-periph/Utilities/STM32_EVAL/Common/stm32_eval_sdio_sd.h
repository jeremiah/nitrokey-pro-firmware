/**
  ******************************************************************************
  * @file    stm32_eval_sdio_sd.h
  * @author  MCD Application Team
  * @version V4.2.0
  * @date    04/16/2010
  * @brief   This file contains all the functions prototypes for the SD Card 
  *          stm32_eval_sdio_sd driver firmware library.
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
#ifndef __STM32_EVAL_SDIO_SD_H
#define __STM32_EVAL_SDIO_SD_H
    
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
    
/** @addtogroup STM32_EVAL_SDIO_SD
  * @{
  */ 
    
/** @defgroup STM32_EVAL_SDIO_SD_Exported_Types
  * @{
  */ 
    typedef enum 
    { 
/** 
  * @brief  SDIO specific error defines  
  */ 
            SD_CMD_CRC_FAIL = (1), /* !< Command response received (but CRC check failed) */ 
            SD_DATA_CRC_FAIL = (2), /* !< Data bock sent/received (CRC check Failed) */ 
            SD_CMD_RSP_TIMEOUT = (3), /* !< Command response timeout */ 
            SD_DATA_TIMEOUT = (4), /* !< Data time out */ 
            SD_TX_UNDERRUN = (5), /* !< Transmit FIFO under-run */ 
            SD_RX_OVERRUN = (6), /* !< Receive FIFO over-run */ 
            SD_START_BIT_ERR = (7), /* !< Start bit not detected on all data signals in widE bus mode */ 
            SD_CMD_OUT_OF_RANGE = (8), /* !< CMD's argument was out of range. */ 
            SD_ADDR_MISALIGNED = (9), /* !< Misaligned address */ 
            SD_BLOCK_LEN_ERR = (10),    /* !< Transferred block length is not allowed for the card or the number of transferred bytes does not match
                                           the block length */ 
            SD_ERASE_SEQ_ERR = (11), /* !< An error in the sequence of erase command occurs. */ 
            SD_BAD_ERASE_PARAM = (12), /* !< An Invalid selection for erase groups */ 
            SD_WRITE_PROT_VIOLATION = (13), /* !< Attempt to program a write protect block */ 
            SD_LOCK_UNLOCK_FAILED = (14),   /* !< Sequence or password error has been detected in unlock command or if there was an attempt to access
                                               a locked card */ 
            SD_COM_CRC_FAILED = (15), /* !< CRC check of the previous command failed */ 
            SD_ILLEGAL_CMD = (16), /* !< Command is not legal for the card state */ 
            SD_CARD_ECC_FAILED = (17), /* !< Card internal ECC was applied but failed to correct the data */ 
            SD_CC_ERROR = (18), /* !< Internal card controller error */ 
            SD_GENERAL_UNKNOWN_ERROR = (19), /* !< General or Unknown error */ 
            SD_STREAM_READ_UNDERRUN = (20), /* !< The card could not sustain data transfer in stream read operation. */ 
            SD_STREAM_WRITE_OVERRUN = (21), /* !< The card could not sustain data programming in stream mode */ 
            SD_CID_CSD_OVERWRITE = (22), /* !< CID/CSD overwrite error */ 
            SD_WP_ERASE_SKIP = (23), /* !< only partial address space was erased */ 
            SD_CARD_ECC_DISABLED = (24), /* !< Command has been executed without using internal ECC */ 
            SD_ERASE_RESET = (25), /* !< Erase sequence was cleared before executing because an out of erase sequence command was received */ 
            SD_AKE_SEQ_ERROR = (26), /* !< Error in sequence of authentication. */ 
            SD_INVALID_VOLTRANGE = (27), 
            (28), 
            (30), 
/** 
  * @brief  Standard error defines   
  */ 
            SD_INTERNAL_ERROR, 
        
        
    } SD_Error;
    
/** 
  * @brief  SDIO Transfer state  
  */ 
    typedef enum 
    { 
    } SDTransferState;
    
/** 
  * @brief  SD Card States 
  */ 
    typedef enum 
    { 
            ((uint32_t) 0x00000002), 
            ((uint32_t) 0x00000003), 
            ((uint32_t) 0x00000004), 
            ((uint32_t) 0x00000005), 
            ((uint32_t) 0x00000006), 
            ((uint32_t) 0x00000007), 
    } SDCardState;
    
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
     
/** @defgroup STM32_EVAL_SDIO_SD_Exported_Constants
  * @{
  */ 
     
/** 
  * @brief SDIO Commands  Index 
  */ 
#define SD_CMD_GO_IDLE_STATE                       ((uint8_t)0)
#define SD_CMD_SEND_OP_COND                        ((uint8_t)1)
#define SD_CMD_ALL_SEND_CID                        ((uint8_t)2)
#define SD_CMD_SET_REL_ADDR                        ((uint8_t)3) /*!< SDIO_SEND_REL_ADDR for SD Card */
#define SD_CMD_SET_DSR                             ((uint8_t)4)
#define SD_CMD_SDIO_SEN_OP_COND                    ((uint8_t)5)
#define SD_CMD_HS_SWITCH                           ((uint8_t)6)
#define SD_CMD_SEL_DESEL_CARD                      ((uint8_t)7)
#define SD_CMD_HS_SEND_EXT_CSD                     ((uint8_t)8)
#define SD_CMD_SEND_CSD                            ((uint8_t)9)
#define SD_CMD_SEND_CID                            ((uint8_t)10)
#define SD_CMD_READ_DAT_UNTIL_STOP                 ((uint8_t)11) /*!< SD Card doesn't support it */
#define SD_CMD_STOP_TRANSMISSION                   ((uint8_t)12)
#define SD_CMD_SEND_STATUS                         ((uint8_t)13)
#define SD_CMD_HS_BUSTEST_READ                     ((uint8_t)14)
#define SD_CMD_GO_INACTIVE_STATE                   ((uint8_t)15)
#define SD_CMD_SET_BLOCKLEN                        ((uint8_t)16)
#define SD_CMD_READ_SINGLE_BLOCK                   ((uint8_t)17)
#define SD_CMD_READ_MULT_BLOCK                     ((uint8_t)18)
#define SD_CMD_HS_BUSTEST_WRITE                    ((uint8_t)19)
#define SD_CMD_WRITE_DAT_UNTIL_STOP                ((uint8_t)20) /*!< SD Card doesn't support it */
#define SD_CMD_SET_BLOCK_COUNT                     ((uint8_t)23) /*!< SD Card doesn't support it */
#define SD_CMD_WRITE_SINGLE_BLOCK                  ((uint8_t)24)
#define SD_CMD_WRITE_MULT_BLOCK                    ((uint8_t)25)
#define SD_CMD_PROG_CID                            ((uint8_t)26) /*!< reserved for manufacturers */
#define SD_CMD_PROG_CSD                            ((uint8_t)27)
#define SD_CMD_SET_WRITE_PROT                      ((uint8_t)28)
#define SD_CMD_CLR_WRITE_PROT                      ((uint8_t)29)
#define SD_CMD_SEND_WRITE_PROT                     ((uint8_t)30)
#define SD_CMD_SD_ERASE_GRP_START                  ((uint8_t)32) /*!< To set the address of the first write
                                                                  block to be erased. (For SD card only) */
#define SD_CMD_SD_ERASE_GRP_END                    ((uint8_t)33) /*!< To set the address of the last write block of the
                                                                  continuous range to be erased. (For SD card only) */
#define SD_CMD_ERASE_GRP_START                     ((uint8_t)35) /*!< To set the address of the first write block to be erased.
                                                                  (For MMC card only spec 3.31) */
     
#define SD_CMD_ERASE_GRP_END                       ((uint8_t)36) /*!< To set the address of the last write block of the
                                                                  continuous range to be erased. (For MMC card only spec 3.31) */
     
#define SD_CMD_ERASE                               ((uint8_t)38)
#define SD_CMD_FAST_IO                             ((uint8_t)39) /*!< SD Card doesn't support it */
#define SD_CMD_GO_IRQ_STATE                        ((uint8_t)40) /*!< SD Card doesn't support it */
#define SD_CMD_LOCK_UNLOCK                         ((uint8_t)42)
#define SD_CMD_APP_CMD                             ((uint8_t)55)
#define SD_CMD_GEN_CMD                             ((uint8_t)56)
#define SD_CMD_NO_CMD                              ((uint8_t)64)
     
/** 
  * @brief Following commands are SD Card Specific commands.
  *        SDIO_APP_CMD should be sent before sending these commands. 
  */ 
#define SD_CMD_APP_SD_SET_BUSWIDTH                 ((uint8_t)6)  /*!< For SD Card only */
#define SD_CMD_SD_APP_STAUS                        ((uint8_t)13) /*!< For SD Card only */
#define SD_CMD_SD_APP_SEND_NUM_WRITE_BLOCKS        ((uint8_t)22) /*!< For SD Card only */
#define SD_CMD_SD_APP_OP_COND                      ((uint8_t)41) /*!< For SD Card only */
#define SD_CMD_SD_APP_SET_CLR_CARD_DETECT          ((uint8_t)42) /*!< For SD Card only */
#define SD_CMD_SD_APP_SEND_SCR                     ((uint8_t)51) /*!< For SD Card only */
#define SD_CMD_SDIO_RW_DIRECT                      ((uint8_t)52) /*!< For SD I/O Card only */
#define SD_CMD_SDIO_RW_EXTENDED                    ((uint8_t)53) /*!< For SD I/O Card only */
     
/** 
  * @brief Following commands are SD Card Specific security commands.
  *        SDIO_APP_CMD should be sent before sending these commands. 
  */ 
#define SD_CMD_SD_APP_GET_MKB                      ((uint8_t)43) /*!< For SD Card only */
#define SD_CMD_SD_APP_GET_MID                      ((uint8_t)44) /*!< For SD Card only */
#define SD_CMD_SD_APP_SET_CER_RN1                  ((uint8_t)45) /*!< For SD Card only */
#define SD_CMD_SD_APP_GET_CER_RN2                  ((uint8_t)46) /*!< For SD Card only */
#define SD_CMD_SD_APP_SET_CER_RES2                 ((uint8_t)47) /*!< For SD Card only */
#define SD_CMD_SD_APP_GET_CER_RES1                 ((uint8_t)48) /*!< For SD Card only */
#define SD_CMD_SD_APP_SECURE_READ_MULTIPLE_BLOCK   ((uint8_t)18) /*!< For SD Card only */
#define SD_CMD_SD_APP_SECURE_WRITE_MULTIPLE_BLOCK  ((uint8_t)25) /*!< For SD Card only */
#define SD_CMD_SD_APP_SECURE_ERASE                 ((uint8_t)38) /*!< For SD Card only */
#define SD_CMD_SD_APP_CHANGE_SECURE_AREA           ((uint8_t)49) /*!< For SD Card only */
#define SD_CMD_SD_APP_SECURE_WRITE_MKB             ((uint8_t)48) /*!< For SD Card only */
     
#define SD_DMA_MODE                                ((uint32_t)0x00000000)
#define SD_INTERRUPT_MODE                          ((uint32_t)0x00000001)
#define SD_POLLING_MODE                            ((uint32_t)0x00000002)
     
/**
  * @brief  SD detection on its memory slot
  */ 
#define SD_PRESENT                                 ((uint8_t)0x01)
#define SD_NOT_PRESENT                             ((uint8_t)0x00)
     
/** 
  * @brief Supported SD Memory Cards 
  */ 
#define SDIO_STD_CAPACITY_SD_CARD_V1_1             ((uint32_t)0x00000000)
#define SDIO_STD_CAPACITY_SD_CARD_V2_0             ((uint32_t)0x00000001)
#define SDIO_HIGH_CAPACITY_SD_CARD                 ((uint32_t)0x00000002)
#define SDIO_MULTIMEDIA_CARD                       ((uint32_t)0x00000003)
#define SDIO_SECURE_DIGITAL_IO_CARD                ((uint32_t)0x00000004)
#define SDIO_HIGH_SPEED_MULTIMEDIA_CARD            ((uint32_t)0x00000005)
#define SDIO_SECURE_DIGITAL_IO_COMBO_CARD          ((uint32_t)0x00000006)
#define SDIO_HIGH_CAPACITY_MMC_CARD                ((uint32_t)0x00000007)
     
/**
  * @}
  */ 
     
/** @defgroup STM32_EVAL_SDIO_SD_Exported_Macros
  * @{
  */ 
/**
  * @}
  */ 
     
/** @defgroup STM32_EVAL_SDIO_SD_Exported_Functions
  * @{
  */ 
    void SD_DeInit (void);
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
    
#ifdef __cplusplus
} 
#endif                          /* 
 
#endif  /* __STM32_EVAL_SDIO_SD_H */
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