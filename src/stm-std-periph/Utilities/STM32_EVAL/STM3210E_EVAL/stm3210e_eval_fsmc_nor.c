/**
  ******************************************************************************
  * @file    stm3210e_eval_fsmc_nor.c
  * @author  MCD Application Team
  * @version V4.2.0
  * @date    04/16/2010
  * @brief   This file provides a set of functions needed to drive the M29W128FL, 
  *          M29W128GL and S29GL128P NOR memories mounted on STM3210E-EVAL board.
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
#include "stm3210e_eval_fsmc_nor.h"
    
/** @addtogroup Utilities
  * @{
  */ 
    
/** @addtogroup STM32_EVAL
  * @{
  */ 
    
/** @addtogroup STM3210E_EVAL
  * @{
  */ 
    
/** @addtogroup STM3210E_EVAL_FSMC_NOR
  * @brief      This file provides a set of functions needed to drive the M29W128FL, 
  *             M29W128GL and S29GL128P NOR memories mounted on STM3210E-EVAL board.
  * @{
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_NOR_Private_Types
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_NOR_Private_Defines
  * @{
  */ 
/** 
  * @brief  FSMC Bank 1 NOR/SRAM2  
  */ 
#define Bank1_NOR2_ADDR       ((uint32_t)0x64000000)
    
    /* Delay definition */ 
#define BlockErase_Timeout    ((uint32_t)0x00A00000)
#define ChipErase_Timeout     ((uint32_t)0x30000000) 
#define Program_Timeout       ((uint32_t)0x00001400)     
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_NOR_Private_Macros
  * @{
  */ 
#define ADDR_SHIFT(A) (Bank1_NOR2_ADDR + (2 * (A)))
#define NOR_WRITE(Address, Data)  (*(__IO uint16_t *)(Address) = (Data))  
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_NOR_Private_Variables
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroupSTM3210E_EVAL_FSMC_NOR_Private_Function_Prototypes
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM3210E_EVAL_FSMC_NOR_Private_Functions
  * @{
  */ 
    
/**
  * @brief  Configures the FSMC and GPIOs to interface with the NOR memory.
  *         This function must be called before any write/read operation
  *         on the NOR.
  * @param  None
  * @retval None
  */ 
void NOR_Init (void) 
{
    
    
    
    
    
  /*-- GPIO Configuration ------------------------------------------------------*/ 
        /* !< NOR Data lines configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | 
    
    
    
    
        GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
    
    
        /* !< NOR Address lines configuration */ 
        GPIO_InitStructure.GPIO_Pin =
        GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | 
    
    
    
    
    
    
    
    
        /* !< NOE and NWE configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
    
    
        /* !< NE2 configuration */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    
    
        /* !< Configure PD6 for NOR memory Ready/Busy signal */ 
        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    
    
    
  /*-- FSMC Configuration ----------------------------------------------------*/ 
        p.FSMC_AddressSetupTime = 0x02;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* !< Enable FSMC Bank1_NOR Bank */ 
        FSMC_NORSRAMCmd (FSMC_Bank1_NORSRAM2, ENABLE);


/**
  * @brief  Reads NOR memory's Manufacturer and Device Code.
  * @param  NOR_ID: pointer to a NOR_IDTypeDef structure which will hold the 
  *         Manufacturer and Device Code.  
  * @retval None
  */ 
void NOR_ReadID (NOR_IDTypeDef * NOR_ID) 
{
    
    
    
    
    
    
    


/**
  * @brief  Erases the specified Nor memory block.
  * @param  BlockAddr: address of the block to erase.
  * @retval NOR_Status: The returned value can be: NOR_SUCCESS, NOR_ERROR
  *         or NOR_TIMEOUT
  */ 
    NOR_Status NOR_EraseBlock (uint32_t BlockAddr) 
{
    
    
    
    
    
    
    



/**
  * @brief  Erases the entire chip.
  * @param  None                      
  * @retval NOR_Status: The returned value can be: NOR_SUCCESS, NOR_ERROR
  *         or NOR_TIMEOUT
  */ 
    NOR_Status NOR_EraseChip (void) 
{
    
    
    
    
    
    
    



/**
  * @brief  Writes a half-word to the NOR memory.
  * @param  WriteAddr: NOR memory internal address to write to.
  * @param  Data: Data to write. 
  * @retval NOR_Status: The returned value can be: NOR_SUCCESS, NOR_ERROR
  *         or NOR_TIMEOUT
  */ 
    NOR_Status NOR_WriteHalfWord (uint32_t WriteAddr, uint16_t Data) 
{
    
    
    
    
    



/**
  * @brief  Writes a half-word buffer to the FSMC NOR memory. 
  * @param  pBuffer: pointer to buffer. 
  * @param  WriteAddr: NOR memory internal address from which the data will be 
  *         written.
  * @param  NumHalfwordToWrite: number of Half words to write. 
  * @retval NOR_Status: The returned value can be: NOR_SUCCESS, NOR_ERROR
  *         or NOR_TIMEOUT
  */ 
    NOR_Status NOR_WriteBuffer (uint16_t * pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite) 
{
    
    
    do
        
    {
        
            /* !< Transfer data to the memory */ 
            status = NOR_WriteHalfWord (WriteAddr, *pBuffer++);
        
        
    
    



/**
  * @brief  Writes a half-word buffer to the FSMC NOR memory. This function 
  *         must be used only with S29GL128P NOR memory.
  * @param  pBuffer: pointer to buffer. 
  * @param  WriteAddr: NOR memory internal address from which the data will be 
  *         written.
  * @param  NumHalfwordToWrite: number of Half words to write.
  *         The maximum allowed value is 32 Half words (64 bytes).
  * @retval NOR_Status: The returned value can be: NOR_SUCCESS, NOR_ERROR
  *         or NOR_TIMEOUT
  */ 
    NOR_Status NOR_ProgramBuffer (uint16_t * pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite) 
{
    
    
    
    
        /* !< Initialize variables */ 
        currentaddress = WriteAddr;
    
    
    
        /* !< Issue unlock command sequence */ 
        NOR_WRITE (ADDR_SHIFT (0x00555), 0x00AA);
    
    
        /* !< Write Write Buffer Load Command */ 
        NOR_WRITE (ADDR_SHIFT (WriteAddr), 0x0025);
    
    
        /* !< Load Data into NOR Buffer */ 
        while (currentaddress <= endaddress)
        
    {
        
            /* !< Store last loaded address & data value (for polling) */ 
            lastloadedaddress = currentaddress;
        
        
    
    
    



/**
  * @brief  Reads a half-word from the NOR memory. 
  * @param  ReadAddr: NOR memory internal address to read from.
  * @retval Half-word read from the NOR memory
  */ 
    uint16_t NOR_ReadHalfWord (uint32_t ReadAddr) 
{
    
    
    
    



/**
  * @brief  Reads a block of data from the FSMC NOR memory.
  * @param  pBuffer: pointer to the buffer that receives the data read from the 
  *         NOR memory.
  * @param  ReadAddr: NOR memory internal address to read from.
  * @param  NumHalfwordToRead : number of Half word to read.
  * @retval None
  */ 
void NOR_ReadBuffer (uint16_t * pBuffer, uint32_t ReadAddr, uint32_t NumHalfwordToRead) 
{
    
    
    
    
        
    {
        
            /* !< Read a Halfword from the NOR */ 
            *pBuffer++ = *(__IO uint16_t *) ((Bank1_NOR2_ADDR + ReadAddr));
        
    



/**
  * @brief  Returns the NOR memory to Read mode.
  * @param  None
  * @retval NOR_SUCCESS
  */ 
    NOR_Status NOR_ReturnToReadMode (void) 
{
    
    



/**
  * @brief  Returns the NOR memory to Read mode and resets the errors in the NOR 
  *         memory Status Register.  
  * @param  None
  * @retval NOR_SUCCESS
  */ 
    NOR_Status NOR_Reset (void) 
{
    
    
    
    



/**
  * @brief  Returns the NOR operation status.
  * @param  Timeout: NOR progamming Timeout
  * @retval NOR_Status: The returned value can be: NOR_SUCCESS, NOR_ERROR
  *         or NOR_TIMEOUT
  */ 
    NOR_Status NOR_GetStatus (uint32_t Timeout) 
{
    
    
    
    
        /* !< Poll on NOR memory Ready/Busy signal ---------------------------------- */ 
        while ((GPIO_ReadInputDataBit (GPIOD, GPIO_Pin_6) != RESET) && (timeout > 0))
        
    {
        
    
    
    
        
    {
        
    
    
        /* !< Get the NOR memory operation status ----------------------------------- */ 
        while ((Timeout != 0x00) && (status != NOR_SUCCESS))
        
    {
        
        
            /* !< Read DQ6 and DQ5 */ 
            val1 = *(__IO uint16_t *) (Bank1_NOR2_ADDR);
        
        
            /* !< If DQ6 did not toggle between the two reads then return NOR_Success */ 
            if ((val1 & 0x0040) == (val2 & 0x0040))
            
        {
            
        
        
            
        {
            
        
        
        
        
            
        {
            
        
        
        else if ((val1 & 0x0020) == 0x0020)
            
        {
            
        
    
    
        
    {
        
    
    
        /* !< Return the operation status */ 
        return (status);



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