/**
  ******************************************************************************
  * @file    stm32f10x_fsmc.c
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   This file provides all the FSMC firmware functions.
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
#include "stm32f10x_fsmc.h"
#include "stm32f10x_rcc.h"
    
/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */ 
    
/** @defgroup FSMC 
  * @brief FSMC driver modules
  * @{
  */ 
    
/** @defgroup FSMC_Private_TypesDefinitions
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup FSMC_Private_Defines
  * @{
  */ 
    
    /* --------------------- FSMC registers bit mask ---------------------------- */ 
    
    /* FSMC BCRx Mask */ 
#define BCR_MBKEN_Set                       ((uint32_t)0x00000001)
#define BCR_MBKEN_Reset                     ((uint32_t)0x000FFFFE)
#define BCR_FACCEN_Set                      ((uint32_t)0x00000040)
    
    /* FSMC PCRx Mask */ 
#define PCR_PBKEN_Set                       ((uint32_t)0x00000004)
#define PCR_PBKEN_Reset                     ((uint32_t)0x000FFFFB)
#define PCR_ECCEN_Set                       ((uint32_t)0x00000040)
#define PCR_ECCEN_Reset                     ((uint32_t)0x000FFFBF)
#define PCR_MemoryType_NAND                 ((uint32_t)0x00000008)
/**
  * @}
  */ 
    
/** @defgroup FSMC_Private_Macros
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup FSMC_Private_Variables
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup FSMC_Private_FunctionPrototypes
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup FSMC_Private_Functions
  * @{
  */ 
    
/**
  * @brief  Deinitializes the FSMC NOR/SRAM Banks registers to their default 
  *   reset values.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank1_NORSRAM1: FSMC Bank1 NOR/SRAM1  
  *     @arg FSMC_Bank1_NORSRAM2: FSMC Bank1 NOR/SRAM2 
  *     @arg FSMC_Bank1_NORSRAM3: FSMC Bank1 NOR/SRAM3 
  *     @arg FSMC_Bank1_NORSRAM4: FSMC Bank1 NOR/SRAM4 
  * @retval None
  */ 
void FSMC_NORSRAMDeInit (uint32_t FSMC_Bank) 
{
    
        /* Check the parameter */ 
        assert_param (IS_FSMC_NORSRAM_BANK (FSMC_Bank));
    
        /* FSMC_Bank1_NORSRAM1 */ 
        if (FSMC_Bank == FSMC_Bank1_NORSRAM1)
        
    {
        
    
    
        /* FSMC_Bank1_NORSRAM2, FSMC_Bank1_NORSRAM3 or FSMC_Bank1_NORSRAM4 */ 
        else
        
    {
        
    
    
    



/**
  * @brief  Deinitializes the FSMC NAND Banks registers to their default reset values.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND 
  * @retval None
  */ 
void FSMC_NANDDeInit (uint32_t FSMC_Bank) 
{
    
        /* Check the parameter */ 
        assert_param (IS_FSMC_NAND_BANK (FSMC_Bank));
    
        
    {
        
            /* Set the FSMC_Bank2 registers to their reset values */ 
            FSMC_Bank2->PCR2 = 0x00000018;
        
        
        
    
    
        /* FSMC_Bank3_NAND */ 
        else
        
    {
        
            /* Set the FSMC_Bank3 registers to their reset values */ 
            FSMC_Bank3->PCR3 = 0x00000018;
        
        
        
    



/**
  * @brief  Deinitializes the FSMC PCCARD Bank registers to their default reset values.
  * @param  None                       
  * @retval None
  */ 
void FSMC_PCCARDDeInit (void) 
{
    
        /* Set the FSMC_Bank4 registers to their reset values */ 
        FSMC_Bank4->PCR4 = 0x00000018;
    
    
    
    


/**
  * @brief  Initializes the FSMC NOR/SRAM Banks according to the specified
  *   parameters in the FSMC_NORSRAMInitStruct.
  * @param  FSMC_NORSRAMInitStruct : pointer to a FSMC_NORSRAMInitTypeDef
  *   structure that contains the configuration information for 
  *   the FSMC NOR/SRAM specified Banks.                       
  * @retval None
  */ 
void FSMC_NORSRAMInit (FSMC_NORSRAMInitTypeDef * FSMC_NORSRAMInitStruct) 
{
    
        /* Check the parameters */ 
        assert_param (IS_FSMC_NORSRAM_BANK (FSMC_NORSRAMInitStruct->FSMC_Bank));
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* Bank1 NOR/SRAM control register configuration */ 
        FSMC_Bank1->BTCR[FSMC_NORSRAMInitStruct->FSMC_Bank] = 
        (uint32_t) FSMC_NORSRAMInitStruct->FSMC_DataAddressMux |
        
        
        
        
        
        
        
        
    
        
    {
        
    
    
        /* Bank1 NOR/SRAM timing register configuration */ 
        FSMC_Bank1->BTCR[FSMC_NORSRAMInitStruct->FSMC_Bank + 1] = 
        (uint32_t) FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AddressSetupTime |
        
        (FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_AddressHoldTime
         << 4) | 
        
        (FSMC_NORSRAMInitStruct->FSMC_ReadWriteTimingStruct->FSMC_BusTurnAroundDuration
         << 16) | 
        
          << 24) | 
    
        /* Bank1 NOR/SRAM timing register for write configuration, if extended mode is used */ 
        if (FSMC_NORSRAMInitStruct->FSMC_ExtendedMode == FSMC_ExtendedMode_Enable)
        
    {
        
        
        
        
        
        
        
            
            
            (FSMC_NORSRAMInitStruct->FSMC_WriteTimingStruct->FSMC_AddressHoldTime
             << 4) | 
            
              << 20) | 
            
    
    
    else
        
    {
        
    



/**
  * @brief  Initializes the FSMC NAND Banks according to the specified 
  *   parameters in the FSMC_NANDInitStruct.
  * @param  FSMC_NANDInitStruct : pointer to a FSMC_NANDInitTypeDef 
  *   structure that contains the configuration information for the FSMC NAND specified Banks.                       
  * @retval None
  */ 
void FSMC_NANDInit (FSMC_NANDInitTypeDef * FSMC_NANDInitStruct) 
{
    
    
        /* Check the parameters */ 
        assert_param (IS_FSMC_NAND_BANK (FSMC_NANDInitStruct->FSMC_Bank));
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* Set the tmppcr value according to FSMC_NANDInitStruct parameters */ 
        tmppcr =
        (uint32_t) FSMC_NANDInitStruct->FSMC_Waitfeature |
        
        
        
    
        /* Set tmppmem value according to FSMC_CommonSpaceTimingStructure parameters */ 
        tmppmem =
        (uint32_t) FSMC_NANDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_SetupTime | 
                                                                                         FSMC_CommonSpaceTimingStruct->FSMC_WaitSetupTime << 8) |
        
                                                                                           FSMC_HiZSetupTime << 24);
    
        /* Set tmppatt value according to FSMC_AttributeSpaceTimingStructure parameters */ 
        tmppatt =
        (uint32_t) FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_SetupTime |
        
        (FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_WaitSetupTime
         << 8) |
        
        (FSMC_NANDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_HoldSetupTime
         << 16) | 
    
        
    {
        
            /* FSMC_Bank2_NAND registers configuration */ 
            FSMC_Bank2->PCR2 = tmppcr;
        
        
    
    
    else
        
    {
        
            /* FSMC_Bank3_NAND registers configuration */ 
            FSMC_Bank3->PCR3 = tmppcr;
        
        
    



/**
  * @brief  Initializes the FSMC PCCARD Bank according to the specified 
  *   parameters in the FSMC_PCCARDInitStruct.
  * @param  FSMC_PCCARDInitStruct : pointer to a FSMC_PCCARDInitTypeDef
  *   structure that contains the configuration information for the FSMC PCCARD Bank.                       
  * @retval None
  */ 
void FSMC_PCCARDInit (FSMC_PCCARDInitTypeDef * FSMC_PCCARDInitStruct) 
{
    
        /* Check the parameters */ 
        assert_param (IS_FSMC_WAIT_FEATURE (FSMC_PCCARDInitStruct->FSMC_Waitfeature));
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        /* Set the PCR4 register value according to FSMC_PCCARDInitStruct parameters */ 
        FSMC_Bank4->PCR4 =
        (uint32_t) FSMC_PCCARDInitStruct->FSMC_Waitfeature |
        
    
        /* Set PMEM4 register value according to FSMC_CommonSpaceTimingStructure parameters */ 
        FSMC_Bank4->PMEM4 =
        (uint32_t) FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_SetupTime |
        
        (FSMC_PCCARDInitStruct->FSMC_CommonSpaceTimingStruct->FSMC_WaitSetupTime
         << 8) | 
        
    
        /* Set PATT4 register value according to FSMC_AttributeSpaceTimingStructure parameters */ 
        FSMC_Bank4->PATT4 =
        (uint32_t) FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_SetupTime |
        
        (FSMC_PCCARDInitStruct->FSMC_AttributeSpaceTimingStruct->FSMC_WaitSetupTime
         << 8) | 
        | 
    
        /* Set PIO4 register value according to FSMC_IOSpaceTimingStructure parameters */ 
        FSMC_Bank4->PIO4 =
        (uint32_t) FSMC_PCCARDInitStruct->FSMC_IOSpaceTimingStruct->FSMC_SetupTime | 
                                                                                       FSMC_IOSpaceTimingStruct->FSMC_WaitSetupTime << 8) |
        
                                                                                         FSMC_HiZSetupTime << 24);


/**
  * @brief  Fills each FSMC_NORSRAMInitStruct member with its default value.
  * @param  FSMC_NORSRAMInitStruct: pointer to a FSMC_NORSRAMInitTypeDef 
  *   structure which will be initialized.
  * @retval None
  */ 
void FSMC_NORSRAMStructInit (FSMC_NORSRAMInitTypeDef * FSMC_NORSRAMInitStruct) 
{
    
        /* Reset NOR/SRAM Init structure parameters values */ 
        FSMC_NORSRAMInitStruct->FSMC_Bank = FSMC_Bank1_NORSRAM1;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


/**
  * @brief  Fills each FSMC_NANDInitStruct member with its default value.
  * @param  FSMC_NANDInitStruct: pointer to a FSMC_NANDInitTypeDef 
  *   structure which will be initialized.
  * @retval None
  */ 
void FSMC_NANDStructInit (FSMC_NANDInitTypeDef * FSMC_NANDInitStruct) 
{
    
        /* Reset NAND Init structure parameters values */ 
        FSMC_NANDInitStruct->FSMC_Bank = FSMC_Bank2_NAND;
    
    
    
    
    
    
    
    
    
    
    
    
    
    


/**
  * @brief  Fills each FSMC_PCCARDInitStruct member with its default value.
  * @param  FSMC_PCCARDInitStruct: pointer to a FSMC_PCCARDInitTypeDef 
  *   structure which will be initialized.
  * @retval None
  */ 
void FSMC_PCCARDStructInit (FSMC_PCCARDInitTypeDef * FSMC_PCCARDInitStruct) 
{
    
        /* Reset PCCARD Init structure parameters values */ 
        FSMC_PCCARDInitStruct->FSMC_Waitfeature = FSMC_Waitfeature_Disable;
    
    
    
    
    
    
    
    
    
    
    
    
    
    


/**
  * @brief  Enables or disables the specified NOR/SRAM Memory Bank.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank1_NORSRAM1: FSMC Bank1 NOR/SRAM1  
  *     @arg FSMC_Bank1_NORSRAM2: FSMC Bank1 NOR/SRAM2 
  *     @arg FSMC_Bank1_NORSRAM3: FSMC Bank1 NOR/SRAM3 
  *     @arg FSMC_Bank1_NORSRAM4: FSMC Bank1 NOR/SRAM4 
  * @param  NewState: new state of the FSMC_Bank. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */ 
void FSMC_NORSRAMCmd (uint32_t FSMC_Bank, FunctionalState NewState) 
{
    
    
    
        
    {
        
            /* Enable the selected NOR/SRAM Bank by setting the PBKEN bit in the BCRx register */ 
            FSMC_Bank1->BTCR[FSMC_Bank] |= BCR_MBKEN_Set;
    
    
    else
        
    {
        
            /* Disable the selected NOR/SRAM Bank by clearing the PBKEN bit in the BCRx register */ 
            FSMC_Bank1->BTCR[FSMC_Bank] &= BCR_MBKEN_Reset;
    



/**
  * @brief  Enables or disables the specified NAND Memory Bank.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
  * @param  NewState: new state of the FSMC_Bank. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */ 
void FSMC_NANDCmd (uint32_t FSMC_Bank, FunctionalState NewState) 
{
    
    
    
        
    {
        
            /* Enable the selected NAND Bank by setting the PBKEN bit in the PCRx register */ 
            if (FSMC_Bank == FSMC_Bank2_NAND)
            
        {
            
        
        
        else
            
        {
            
        
    
    
    else
        
    {
        
            /* Disable the selected NAND Bank by clearing the PBKEN bit in the PCRx register */ 
            if (FSMC_Bank == FSMC_Bank2_NAND)
            
        {
            
        
        
        else
            
        {
            
        
    



/**
  * @brief  Enables or disables the PCCARD Memory Bank.
  * @param  NewState: new state of the PCCARD Memory Bank.  
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */ 
void FSMC_PCCARDCmd (FunctionalState NewState) 
{
    
    
        
    {
        
            /* Enable the PCCARD Bank by setting the PBKEN bit in the PCR4 register */ 
            FSMC_Bank4->PCR4 |= PCR_PBKEN_Set;
    
    
    else
        
    {
        
            /* Disable the PCCARD Bank by clearing the PBKEN bit in the PCR4 register */ 
            FSMC_Bank4->PCR4 &= PCR_PBKEN_Reset;
    



/**
  * @brief  Enables or disables the FSMC NAND ECC feature.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
  * @param  NewState: new state of the FSMC NAND ECC feature.  
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */ 
void FSMC_NANDECCCmd (uint32_t FSMC_Bank, FunctionalState NewState) 
{
    
    
    
        
    {
        
            /* Enable the selected NAND Bank ECC function by setting the ECCEN bit in the PCRx register */ 
            if (FSMC_Bank == FSMC_Bank2_NAND)
            
        {
            
        
        
        else
            
        {
            
        
    
    
    else
        
    {
        
            /* Disable the selected NAND Bank ECC function by clearing the ECCEN bit in the PCRx register */ 
            if (FSMC_Bank == FSMC_Bank2_NAND)
            
        {
            
        
        
        else
            
        {
            
        
    



/**
  * @brief  Returns the error correction code register value.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
  * @retval The Error Correction Code (ECC) value.
  */ 
    uint32_t FSMC_GetECC (uint32_t FSMC_Bank) 
{
    
    
        
    {
        
            /* Get the ECCR2 register value */ 
            eccval = FSMC_Bank2->ECCR2;
    
    
    else
        
    {
        
            /* Get the ECCR3 register value */ 
            eccval = FSMC_Bank3->ECCR3;
    
    
        /* Return the error correction code value */ 
        return (eccval);



/**
  * @brief  Enables or disables the specified FSMC interrupts.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
  * @param  FSMC_IT: specifies the FSMC interrupt sources to be enabled or disabled.
  *   This parameter can be any combination of the following values:
  *     @arg FSMC_IT_RisingEdge: Rising edge detection interrupt. 
  *     @arg FSMC_IT_Level: Level edge detection interrupt.
  *     @arg FSMC_IT_FallingEdge: Falling edge detection interrupt.
  * @param  NewState: new state of the specified FSMC interrupts.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */ 
void FSMC_ITConfig (uint32_t FSMC_Bank, uint32_t FSMC_IT, FunctionalState NewState) 
{
    
    
    
    
        
    {
        
            /* Enable the selected FSMC_Bank2 interrupts */ 
            if (FSMC_Bank == FSMC_Bank2_NAND)
            
        {
            
        
        
            /* Enable the selected FSMC_Bank3 interrupts */ 
            else if (FSMC_Bank == FSMC_Bank3_NAND)
            
        {
            
        
        
            /* Enable the selected FSMC_Bank4 interrupts */ 
            else
            
        {
            
        
    
    
    else
        
    {
        
            /* Disable the selected FSMC_Bank2 interrupts */ 
            if (FSMC_Bank == FSMC_Bank2_NAND)
            
        {
            
        
        
            /* Disable the selected FSMC_Bank3 interrupts */ 
            else if (FSMC_Bank == FSMC_Bank3_NAND)
            
        {
            
        
        
            /* Disable the selected FSMC_Bank4 interrupts */ 
            else
            
        {
            
        
    



/**
  * @brief  Checks whether the specified FSMC flag is set or not.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
  * @param  FSMC_FLAG: specifies the flag to check.
  *   This parameter can be one of the following values:
  *     @arg FSMC_FLAG_RisingEdge: Rising egde detection Flag.
  *     @arg FSMC_FLAG_Level: Level detection Flag.
  *     @arg FSMC_FLAG_FallingEdge: Falling egde detection Flag.
  *     @arg FSMC_FLAG_FEMPT: Fifo empty Flag. 
  * @retval The new state of FSMC_FLAG (SET or RESET).
  */ 
    FlagStatus FSMC_GetFlagStatus (uint32_t FSMC_Bank, uint32_t FSMC_FLAG) 
{
    
    
    
        /* Check the parameters */ 
        assert_param (IS_FSMC_GETFLAG_BANK (FSMC_Bank));
    
    
        
    {
        
    
    
    else if (FSMC_Bank == FSMC_Bank3_NAND)
        
    {
        
    
    
        /* FSMC_Bank4_PCCARD */ 
        else
        
    {
        
    
    
        /* Get the flag status */ 
        if ((tmpsr & FSMC_FLAG) != (uint16_t) RESET)
        
    {
        
    
    
    else
        
    {
        
    
    
        /* Return the flag status */ 
        return bitstatus;



/**
  * @brief  Clears the FSMC�s pending flags.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
  * @param  FSMC_FLAG: specifies the flag to clear.
  *   This parameter can be any combination of the following values:
  *     @arg FSMC_FLAG_RisingEdge: Rising egde detection Flag.
  *     @arg FSMC_FLAG_Level: Level detection Flag.
  *     @arg FSMC_FLAG_FallingEdge: Falling egde detection Flag.
  * @retval None
  */ 
void FSMC_ClearFlag (uint32_t FSMC_Bank, uint32_t FSMC_FLAG) 
{
    
        /* Check the parameters */ 
        assert_param (IS_FSMC_GETFLAG_BANK (FSMC_Bank));
    
    
        
    {
        
    
    
    else if (FSMC_Bank == FSMC_Bank3_NAND)
        
    {
        
    
    
        /* FSMC_Bank4_PCCARD */ 
        else
        
    {
        
    



/**
  * @brief  Checks whether the specified FSMC interrupt has occurred or not.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
  * @param  FSMC_IT: specifies the FSMC interrupt source to check.
  *   This parameter can be one of the following values:
  *     @arg FSMC_IT_RisingEdge: Rising edge detection interrupt. 
  *     @arg FSMC_IT_Level: Level edge detection interrupt.
  *     @arg FSMC_IT_FallingEdge: Falling edge detection interrupt. 
  * @retval The new state of FSMC_IT (SET or RESET).
  */ 
    ITStatus FSMC_GetITStatus (uint32_t FSMC_Bank, uint32_t FSMC_IT) 
{
    
    
    
        /* Check the parameters */ 
        assert_param (IS_FSMC_IT_BANK (FSMC_Bank));
    
    
        
    {
        
    
    
    else if (FSMC_Bank == FSMC_Bank3_NAND)
        
    {
        
    
    
        /* FSMC_Bank4_PCCARD */ 
        else
        
    {
        
    
    
    
    
        
    {
        
    
    
    else
        
    {
        
    
    



/**
  * @brief  Clears the FSMC�s interrupt pending bits.
  * @param  FSMC_Bank: specifies the FSMC Bank to be used
  *   This parameter can be one of the following values:
  *     @arg FSMC_Bank2_NAND: FSMC Bank2 NAND 
  *     @arg FSMC_Bank3_NAND: FSMC Bank3 NAND
  *     @arg FSMC_Bank4_PCCARD: FSMC Bank4 PCCARD
  * @param  FSMC_IT: specifies the interrupt pending bit to clear.
  *   This parameter can be any combination of the following values:
  *     @arg FSMC_IT_RisingEdge: Rising edge detection interrupt. 
  *     @arg FSMC_IT_Level: Level edge detection interrupt.
  *     @arg FSMC_IT_FallingEdge: Falling edge detection interrupt.
  * @retval None
  */ 
void FSMC_ClearITPendingBit (uint32_t FSMC_Bank, uint32_t FSMC_IT) 
{
    
        /* Check the parameters */ 
        assert_param (IS_FSMC_IT_BANK (FSMC_Bank));
    
    
        
    {
        
    
    
    else if (FSMC_Bank == FSMC_Bank3_NAND)
        
    {
        
    
    
        /* FSMC_Bank4_PCCARD */ 
        else
        
    {
        
    



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