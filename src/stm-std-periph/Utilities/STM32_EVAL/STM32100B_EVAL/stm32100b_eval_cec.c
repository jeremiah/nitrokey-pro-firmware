/**
  ******************************************************************************
  * @file    stm32100b_eval_cec.c
  * @author  MCD Application Team
  * @version V4.2.0
  * @date    04/16/2010
  * @brief   This file provides all the STM32100B-EVAL HDMI-CEC firmware functions.
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
#include "stm32100b_eval_cec.h"
    
/** @addtogroup Utilities
  * @{
  */ 
    
/** @addtogroup STM32_EVAL
  * @{
  */ 
    
/** @addtogroup STM32100B_EVAL
  * @{
  */ 
    
/** @defgroup STM32100B_EVAL_CEC
  * @brief This file includes the CEC Stack driver for HDMI-CEC Module
  *        of STM32100B-EVAL board.
  * @{
  */ 
    
/** @defgroup STM32100B_EVAL_CEC_Private_Types
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup STM32100B_EVAL_CEC_Private_Defines
  * @{
  */ 
    
/**
  * @}
  */ 
    
/** @defgroup STM32100B_EVAL_CEC_Private_Macros
  * @{
  */ 
/**
  * @}
  */ 
    
/** @defgroup STM32100B_EVAL_CEC_Private_Variables
  * @{
  */ 
    











#ifdef HDMI_CEC_USE_DDC
    __IO uint8_t pBuffer[256];


#endif /* 
    __IO uint8_t CECDevicesNumber = 0;









    /* CEC follower addresses */ 
    uint8_t * HDMI_CEC_Follower_String[13][2] = 
{
    
    {
    "         TV         ", "0"}
    , 
    {
    "Recording Device 1  ", "0"}
    , 
    {
    "Recording Device 2  ", "0"}
    , 
    {
    "    Tuner 1         ", "0"}
    , 
    {
    " Playback Device 1  ", "0"}
    , 
    {
    "   Audio System     ", "0"}
    , 
    {
    "    Tuner 2         ", "0"}
    , 
    {
    "    Tuner 3         ", "0"}
    , 
    {
    " Playback Device 2  ", "0"}
    , 
    {
    "Recording Device 3  ", "0"}
    , 
    {
    "      Tuner 4       ", "0"}
    , 
    {
    " Playback Device 3  ", "0"}
    , 
    {
    "     Broadcast      ", "1"}



/**
  * @}
  */ 
    
/** @defgroup STM32100B_EVAL_CEC_Private_Function_Prototypes
  * @{
  */ 
static HDMI_CEC_Error PhysicalAddressDiscovery (void);




/**
  * @}
  */ 
    
/** @defgroup STM32100B_EVAL_CEC_Private_Functions
  * @{
  */ 
    
/**
  * @brief  Initializes the HDMI CEC.
  * @param  None
  * @retval HDMI_CEC_Error: CEC Error code
  */ 
    HDMI_CEC_Error HDMI_CEC_Init (void) 
{
    
    
    
    
    
#ifdef HDMI_CEC_USE_DDC
        I2C_InitTypeDef I2C_InitStructure;
    
        /* Enable CEC_I2C clocks */ 
        RCC_APB1PeriphClockCmd (HDMI_CEC_I2C_CLK, ENABLE);
    
        /* Enable CEC_I2C_GPIO and CEC_HPD_GPIO clocks */ 
        RCC_APB2PeriphClockCmd (HDMI_CEC_I2C_GPIO_CLK | HDMI_CEC_HPD_GPIO_CLK, ENABLE);
    
#endif /* 
        
        /* Enable CEC clocks */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_CEC, ENABLE);
    
        /* Enable CEC_LINE_GPIO clocks */ 
        RCC_APB2PeriphClockCmd (HDMI_CEC_LINE_GPIO_CLK, ENABLE);
    
        /* Configure CEC_LINE_GPIO as Output open drain */ 
        GPIO_InitStructure.GPIO_Pin = HDMI_CEC_LINE_PIN;
    
    
    
    
#ifdef HDMI_CEC_USE_DDC
        /* Configure CEC_I2C_SCL_PIN and CEC_I2C_SDA_PIN as Output open drain */ 
        GPIO_InitStructure.GPIO_Pin = HDMI_CEC_I2C_SCL_PIN | HDMI_CEC_I2C_SDA_PIN;
    
    
        /* This configuration is only when the HDMI CEC is configured as source.
           On STM32100B-EVAL borad, you have to solder the SB4 Solder bridge.
           sink.
        /* Configure CEC_HPD_GPIO as Input pull down */ 
        GPIO_InitStructure.GPIO_Pin = HDMI_CEC_HPD_PIN;
    
    
    
        /* This configuration is only when the HDMI CEC is configured as sink.
           On STM32100B-EVAL borad, SB4 Solder bridge should be open (default configuration).
           source that the EDID
        /* GPIO_InitStructure.GPIO_Pin = HDMI_CEC_HPD_PIN;
           &GPIO_InitStructure);
        
        /* Enable CEC_I2C */ 
        I2C_Cmd (HDMI_CEC_I2C, ENABLE);
    
        /* I2C configuration */ 
        I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
    
    
    
    
    
    
    
#endif /* 
        
        /* Physical Address discovery */ 
        errorstatus = PhysicalAddressDiscovery ();
    
        
    {
        
            /* Device not connected (Physical Address lost) */ 
            return (errorstatus);
    
    
        /* CEC DeInit */ 
        CEC_DeInit ();
    
        /* Configure CEC */ 
        CEC_InitStructure.CEC_BitTimingMode = CEC_BitTimingStdMode;
    
    
    
        /* Set Prescaler value for APB1 clock = 24MHz */ 
        CEC_SetPrescaler (0x4AF);
    
        /* Enable CEC */ 
        CEC_Cmd (ENABLE);
    
        /* Logical Address Allocation */ 
        sendcount = 0;
    
    
        
    {
        
        
    
    
        
    {
        
            /* Device Unregistred */ 
            return (errorstatus);
    
    
    
        /* Set the CEC initiator address */ 
        CEC_OwnAddressConfig (MyLogicalAddress);
    
        /* Activate CEC interrupts associated to the set of RBTF,RERR, TBTF, TERR flags */ 
        CEC_ITConfig (ENABLE);
    
        /* Report physical address */ 
        errorstatus = HDMI_CEC_ReportPhysicalAddress ();
    
    
        
    {
        
        
    
    
        
    {
        
            /* Device Unregistred */ 
            return (errorstatus);
    
    



/**
  * @brief  Transmit message by taking  data from typedef struct CEC_Meassage
  * @param  CEC_TX_MessageStructure: pointer to an CEC_Message structure that contains
  *         the message to be sent.
  * @retval HDMI_CEC_Error: CEC Error code
  */ 
    HDMI_CEC_Error HDMI_CEC_TransmitMessage (HDMI_CEC_Message * HDMI_CEC_TX_MessageStructure) 
{
    
    
    
    
    
    
    
    
        /* Initialize BufferPointer */ 
        for (j = 0; j < 15; j++)
        
    {
        
    
    
    
        
    {
        
    
    
    
        /* Write single Data in the TX Buffer to Transmit through the CEC peripheral */ 
        CEC_SendDataByte (HDMI_CEC_TX_MessageStructPrivate.Header);
    
        /* Initiate Message Transmission */ 
        CEC_StartOfMessage ();
    
        
    {
        
    
    
        
    {
        
        
    
    
        
    {
        
    
    



/**
  * @brief  Get the ESR register status.
  * @param  None
  * @retval HDMI_CEC_Error: CEC Error code
  */ 
    HDMI_CEC_Error HDMI_CEC_GetErrorStatus (void) 
{
    
    
        /* Bit timing error case */ 
        if (CEC_GetFlagStatus (CEC_FLAG_BTE) != RESET)
        
    {
        
    
    
        /* Bit period error case */ 
        if (CEC_GetFlagStatus (CEC_FLAG_BPE) != RESET)
        
    {
        
    
    
        /* Recieve error case */ 
        if (CEC_GetFlagStatus (CEC_FLAG_RBTFE) != RESET)
        
    {
        
    
    
        /* Start bit error case */ 
        if (CEC_GetFlagStatus (CEC_FLAG_SBE) != RESET)
        
    {
        
    
    
        /* Acknowledge error case */ 
        if (CEC_GetFlagStatus (CEC_FLAG_ACKE) != RESET)
        
    {
        
    
    
        /* Line error case */ 
        if (CEC_GetFlagStatus (CEC_FLAG_LINE) != RESET)
        
    {
        
    
    
        /* Transfert error case */ 
        if (CEC_GetFlagStatus (CEC_FLAG_TBTFE) != RESET)
        
    {
        
    
    
        /* Clear All errors */ 
        CEC_ClearFlag (CEC_FLAG_RERR);
    
    



/**
  * @brief  Allows to process all the interrupts that are high.
  * @param  None
  * @retval None
  */ 
void HDMI_CEC_ProcessIRQSrc (void) 
{
    
  /********************** Reception *********************************************/ 
        /* Check if a reception error occured */ 
        if (CEC_GetFlagStatus (CEC_FLAG_RERR))
        
    {
        
            /* Set receive status bit (Error) */ 
            ReceiveStatus = 0;
        
        
        
    
    
    else if (CEC_GetFlagStatus (CEC_FLAG_RBTF))
        
    {
        
            /* Check if the byte received is the last one of the message */ 
            if (CEC_GetFlagStatus (CEC_FLAG_REOM))
            
        {
            
            
            
            
        
        
            /* Check if the byte received is a Header */ 
            else if (CEC_GetFlagStatus (CEC_FLAG_RSOM))
            
        {
            
            
            
        
        
            /* Receive each byte except header in the reception buffer */ 
            else
            
        {
            
                
            {
                
                
            
            
            else
                
            {
                
                
            
        
        
            /* Clear all reception flags */ 
            CEC_ClearFlag (CEC_FLAG_RSOM | CEC_FLAG_REOM | CEC_FLAG_RBTF);
    
    
  /********************** Transmission ******************************************/ 
        /* Check if a transmission error occured */ 
        if (CEC_GetFlagStatus (CEC_FLAG_TERR))
        
    {
        
        
        
        
    
    
        /* Check if end of message bit is set in the data to be transmitted */ 
        else if (CEC_GetFlagStatus (CEC_FLAG_TEOM))
        
    {
        
        
        
        
    
    
        /* Check if data byte has been sent */ 
        else if (CEC_GetFlagStatus (CEC_FLAG_TBTRF))
        
    {
        
            /* Set EOM bit if the byte to be transmitted is the last one of the TransmitBuffer */ 
            if (TxCounter == (HDMI_CEC_TX_MessageStructPrivate.TxMessageLength))
            
        {
            
            
            
            
        
        
        else
            
        {
            
                /* Put the byte in the TX Buffer */ 
                CEC_SendDataByte (BufferPointer[TxCounter]);
            
            
        
    



/**
  * @brief  Report physical address to all other devices thus allowing any
            device to create a map of the network.
  * @param  None
  * @retval HDMI_CEC_Error: CEC Error code.
  */ 
    HDMI_CEC_Error HDMI_CEC_ReportPhysicalAddress (void) 
{
    
    
    
    
    
    
    
    
    
    



/**
  * @brief  Handle CEC command receive callback.
  *         When receiving the STANDBY Opcode commande, the system is entred in
  *         Stop mode and when wakeup, the PLL is configured as system clock and
  *         the HSI is selected as PLL source.      
  * @param  None
  * @retval None
  */ 
void HDMI_CEC_CommandCallBack (void) 
{
    
    
    
    
        
    {
        
            
            
            
            
            
            
            
            
            
            
        
            
                /* CEC Line */ 
                GPIO_EXTILineConfig (GPIO_PortSourceGPIOB, GPIO_PinSource8);
            
                /* Configure the CEC Line as EXTI Line on Falling Edge */ 
                EXTI_ClearITPendingBit (EXTI_Line8);
            
            
            
            
            
            
                /* Request to enter Stop mode */ 
                PWR_EnterSTOPMode (PWR_Regulator_ON, PWR_STOPEntry_WFI);
            
                /* Disable the CEC EXTI Line */ 
                EXTI_InitStructure.EXTI_LineCmd = DISABLE;
            
            
                /* Configure the PLL Source */ 
                RCC_PLLConfig (RCC_PLLSource_HSI_Div2, RCC_PLLMul_6);
            
                /* Enable PLL */ 
                RCC_PLLCmd (ENABLE);
            
                /* Wait till PLL is ready */ 
                while (RCC_GetFlagStatus (RCC_FLAG_PLLRDY) == RESET)
                
            {
            
            
                /* Select PLL as system clock source */ 
                RCC_SYSCLKConfig (RCC_SYSCLKSource_PLLCLK);
            
                /* Wait till PLL is used as system clock source */ 
                while (RCC_GetSYSCLKSource () != 0x08)
                
            {
            
            
        
            
                /* Send the Used CEC version */ 
                HDMI_CEC_TX_MessageStructPrivate.Header = ((MyLogicalAddress << 4) | HDMI_CEC_RX_MessageStructPrivate.Header >> 4);
            
            
            
            
            
                /* Retransmit message until 5 time */ 
                while ((errorstatus != HDMI_CEC_OK) && sendcount < 0x5)
                
            {
                
                
            
            
        
            
                /* Send the Physical address */ 
                errorstatus = HDMI_CEC_ReportPhysicalAddress ();
            
            
                /* Retransmit message until 5 time */ 
                while ((errorstatus != HDMI_CEC_OK) && sendcount < 0x5)
                
            {
                
                
            
            
        
            
                /* The device doesn't support the requested message type, or that it cannot
                FeatureOpcode = HDMI_CEC_RX_MessageStructPrivate.Operande[0];
            
            
        
            
                /* Send the OSD name = STM32100B CEC */ 
                HDMI_CEC_TX_MessageStructPrivate.Header = ((MyLogicalAddress << 4) | HDMI_CEC_RX_MessageStructPrivate.Header >> 4);
            
            
                /* STM32100B */ 
                HDMI_CEC_TX_MessageStructPrivate.Operande[0] = 0x53;
            
            
            
            
            
            
            
            
            
            
                /* CEC */ 
                HDMI_CEC_TX_MessageStructPrivate.Operande[10] = 0x43;
            
            
            
            
            
            
                /* Retransmit message until 5 time */ 
                while ((errorstatus != HDMI_CEC_OK) && sendcount < 0x5)
                
            {
                
                
            
            
        
            
                
            {
                
                      HDMI_CEC_RX_MessageStructPrivate.Operande[1] >> 4)
                     && 
                          HDMI_CEC_RX_MessageStructPrivate.Operande[1] & 0x0F)
                     && 
                          HDMI_CEC_RX_MessageStructPrivate.Operande[0] >> 4)
                     && 
                    
                {
                    
                    
                    
                
            
            
        
            
                /* Send Abort feature */ 
                HDMI_CEC_TX_MessageStructPrivate.Header = ((MyLogicalAddress << 4) | HDMI_CEC_RX_MessageStructPrivate.Header >> 4);
            
            
            
            
            
            
            
                /* Retransmit message until 5 time */ 
                while ((errorstatus != HDMI_CEC_OK) && sendcount < 0x5)
                
            {
                
                
            
            
    



/**
  * @brief  Check the connected CEC devices.
  * @param  None
  * @retval HDMI_CEC_Error
  */ 
    HDMI_CEC_Error HDMI_CEC_CheckConnectedDevices (void) 
{
    
    
    
  /*----------------------------- TV device  ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Recording device 1 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Recording device 2 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Tuner 1 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Playback device 1 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Audio system ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Tuner 2 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Tuner 3 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Playback device 2 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Recording device 3 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Tuner 4 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
  /*----------------------------- Playback device 3 ---------------------------*/ 
        CEC_OwnAddressConfig (MyLogicalAddress);    /* Own address = MyLogicalAddress */
    
    
    
        /* Start of message */ 
        CEC_StartOfMessage ();
    
        /* Wait till the header message is sent */ 
        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
        
    {
        
    
    
        
    {
        
        
    
    
    
        
    {
        
        
        
    
    
        /* Clear CEC CSR register */ 
        CEC_ClearFlag (CEC_FLAG_TBTRF);
    
    
    



/**
  * @brief  Physical address discovery.
  * @param  None
  * @retval HDMI_CEC_Error: CEC Error code.
  */ 
static HDMI_CEC_Error PhysicalAddressDiscovery (void) 
{
    
    
#ifdef HDMI_CEC_USE_DDC
        uint32_t index = 0, i = 0;
    
#endif /* 
        
  /*------------------------------ Physical address discovery -----------------*/ 
        if (HDMI_CEC_ROOT == 0x1)
        
    {
        
        
            /* The HDMI-CEC here is configured as sink or as a repeater. The configuration
               configured.
               specification. 
    }
    
    else
        
    {
        
#ifdef HDMI_CEC_USE_DDC  
            /* The HDMI-CEC here is configured as source or as a repeater. The configuration
               configured.
            while (GPIO_ReadInputDataBit (HDMI_CEC_HPD_GPIO_PORT, HDMI_CEC_HPD_PIN) == RESET)
            
        {
        
        
            /* Wait for 100 ms after HPD was received */ 
            for (i = 0; i < 0x5FFFF; i++)
            
        {
        
        
            /* Return the physical address using the I2C by reading the 2 bytes 24 and
            /* Read the EDID Block 0 and EDID Block 1 at address 0xA0 */ 
            /* !< While the bus is busy */ 
            while (I2C_GetFlagStatus (HDMI_CEC_I2C, I2C_FLAG_BUSY))
            
        {
        
        
            /* !< Send START condition */ 
            I2C_GenerateSTART (HDMI_CEC_I2C, ENABLE);
        
            /* !< Test on EV5 and clear it */ 
            while (!I2C_CheckEvent (HDMI_CEC_I2C, I2C_EVENT_MASTER_MODE_SELECT))
            
        {
        
        
            /* !< Send EEPROM address for write */ 
            I2C_Send7bitAddress (HDMI_CEC_I2C, 0xA0, I2C_Direction_Transmitter);
        
            /* !< Test on EV6 and clear it */ 
            while (!I2C_CheckEvent (HDMI_CEC_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
            
        {
        
        
            /* !< Send the EEPROM's internal address to read from: Only one byte address */ 
            I2C_SendData (HDMI_CEC_I2C, 0x00);
        
            /* !< Test on EV8 and clear it */ 
            while (!I2C_CheckEvent (HDMI_CEC_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
            
        {
        
        
            /* !< Send STRAT condition a second time */ 
            I2C_GenerateSTART (HDMI_CEC_I2C, ENABLE);
        
            /* !< Test on EV5 and clear it */ 
            while (!I2C_CheckEvent (HDMI_CEC_I2C, I2C_EVENT_MASTER_MODE_SELECT))
            
        {
        
        
            /* !< Send EEPROM address for read */ 
            I2C_Send7bitAddress (HDMI_CEC_I2C, 0xA1, I2C_Direction_Receiver);
        
            /* !< Test on EV6 and clear it */ 
            while (!I2C_CheckEvent (HDMI_CEC_I2C, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
            
        {
        
        
            /* While there is data to be read */ 
            while (NumByteToRead-- > 1)
            
        {
            
                
            {
            
            
                
            {
            
            
        
        
            /* Disable Acknowledgement */ 
            I2C_AcknowledgeConfig (HDMI_CEC_I2C, DISABLE);
        
            /* Send STOP Condition */ 
            I2C_GenerateSTOP (HDMI_CEC_I2C, ENABLE);
        
        
        
            /* Enable Acknowledgement to be ready for another reception */ 
            I2C_AcknowledgeConfig (HDMI_CEC_I2C, ENABLE);
        
        
#else /* 
            MyPhysicalAddress = 0x1000;
        
#endif /* 
    }
    



/**
  * @brief  Allocate the logical address.
  * @param  None
  * @retval HDMI_CEC_Error: CEC Error code.
  */ 
static HDMI_CEC_Error LogicalAddressAllocation (void) 
{
    
    
    
  /*------------------ Logical address allocation -----------------------------*/ 
        /* Get the device type */ 
        /* Device type = CEC_TV */ 
        if (DeviceType == HDMI_CEC_TV)
        
    {
        
            
        {
            
        
        
        else
            
        {
            
            
            
            
                /* Start of message */ 
                CEC_StartOfMessage ();
            
                /* Wait till the polling message is sent */ 
                while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET)
                       && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
                
            {
                
            
            
                
            {
                
                
            
            
            
                
            {
                
                
            
            
            else if (errorstatus == HDMI_CEC_OK)
                
            {
                
                
            
        
        
            /* Clear CEC CSR register */ 
            CEC_ClearFlag (CEC_FLAG_TBTRF);
        
    
    
        /* Device type = CEC_RECORDING */ 
        if (DeviceType == HDMI_CEC_RECORDING)
        
    {
        
        
        
        
            /* Start of message */ 
            CEC_StartOfMessage ();
        
            /* Wait till the header message is sent */ 
            while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
            
        {
            
        
        
            
        {
            
            
        
        
        
            
        {
            
            
        
        
        else if (errorstatus == HDMI_CEC_OK)
            
        {
            
                /* Clear CEC CSR register */ 
                CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
            
            
            
            
            
                /* Start of message */ 
                CEC_StartOfMessage ();
            
            
                /* Wait till the header message is sent */ 
                while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET)
                       && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
                
            {
                
            
            
                
            {
                
                
            
            
            
                
            {
                
                
            
            
            else if (errorstatus == HDMI_CEC_OK)
                
            {
                
                    /* Clear CEC CSR register */ 
                    CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
                
                
                
                
                
                    /* Start of message */ 
                    CEC_StartOfMessage ();
                
                
                    /* Wait till the header message is sent */ 
                    while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET)
                           && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
                    
                {
                    
                
                
                    
                {
                    
                    
                
                
                
                    
                {
                    
                    
                
                
                else if (errorstatus == HDMI_CEC_OK)
                    
                {
                    
                    
                
            
        
        
            /* Clear CEC CSR register */ 
            CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
        
    
    
        /* Device type = CEC_TUNER */ 
        if (DeviceType == HDMI_CEC_TUNER)
        
    {
        
        
        
        
            /* Start of message */ 
            CEC_StartOfMessage ();
        
        
            /* Wait till the header message is sent */ 
            while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
            
        {
            
        
        
            
        {
            
            
        
        
        
            
        {
            
            
        
        
        else if (errorstatus == HDMI_CEC_OK)
            
        {
            
                /* Clear CEC CSR register */ 
                CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
            
            
            
            
            
                /* Start of message */ 
                CEC_StartOfMessage ();
            
            
                /* Wait till the header message is sent */ 
                while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET)
                       && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
                
            {
                
            
            
                
            {
                
                
            
            
            
                
            {
                
                
            
            
            else if (errorstatus == HDMI_CEC_OK)
                
            {
                
                    /* Clear CEC CSR register */ 
                    CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
                
                
                
                
                
                    /* Start of message */ 
                    CEC_StartOfMessage ();
                
                
                    /* Wait till the header message is sent */ 
                    while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET)
                           && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
                    
                {
                    
                
                
                    
                {
                    
                    
                
                
                
                    
                {
                    
                    
                
                
                else if (errorstatus == HDMI_CEC_OK)
                    
                {
                    
                        /* Clear CEC CSR register */ 
                        CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
                    
                    
                    
                    
                    
                        /* Start of message */ 
                        CEC_StartOfMessage ();
                    
                    
                        /* Wait till the header message is sent */ 
                        while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET)
                               && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
                        
                    {
                        
                    
                    
                        
                    {
                        
                        
                    
                    
                    
                        
                    {
                        
                        
                    
                    
                    else if (errorstatus == HDMI_CEC_OK)
                        
                    {
                        
                        
                    
                
            
        
        
            /* Clear CEC CSR register */ 
            CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
        
    
    
        /* Device type = CEC_PLAYBACK */ 
        if (DeviceType == HDMI_CEC_PLAYBACK)
        
    {
        
        
        
        
            /* Start of message */ 
            CEC_StartOfMessage ();
        
        
            /* Wait till the header message is sent */ 
            while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
            
        {
            
        
        
            
        {
            
            
        
        
        
            
        {
            
            
        
        
        else if (errorstatus == HDMI_CEC_OK)
            
        {
            
                /* Clear CEC CSR register */ 
                CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
            
            
            
            
            
                /* Start of message */ 
                CEC_StartOfMessage ();
            
            
                /* Wait till the header message is sent */ 
                while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET)
                       && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
                
            {
                
            
            
                
            {
                
                
            
            
            
                
            {
                
                
            
            
            else if (errorstatus == HDMI_CEC_OK)
                
            {
                
                    /* Clear CEC CSR register */ 
                    CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
                
                
                
                
                
                    /* Start of message */ 
                    CEC_StartOfMessage ();
                
                
                    /* Wait till the header message is sent */ 
                    while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET)
                           && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
                    
                {
                    
                
                
                    
                {
                    
                    
                
                
                
                    
                {
                    
                    
                
                
                else if (errorstatus == HDMI_CEC_OK)
                    
                {
                    
                    
                
            
        
        
            /* Clear CEC CSR register */ 
            CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
        
    
    
        /* Device type = CEC Audio System */ 
        if (DeviceType == HDMI_CEC_AUDIOSYSTEM)
        
    {
        
        
        
        
            /* Start of message */ 
            CEC_StartOfMessage ();
        
        
            /* Wait till the header message is sent */ 
            while ((CEC_GetFlagStatus (CEC_FLAG_TBTRF) == RESET) && (CEC_GetFlagStatus (CEC_FLAG_TERR) == RESET) && (count < HDMI_CEC_TIMEOUT_VALUE))
            
        {
            
        
        
            
        {
            
            
        
        
        
            
        {
            
            
        
        
        else if (errorstatus == HDMI_CEC_OK)
            
        {
            
            
        
        
            /* Clear CEC CSR register */ 
            CEC_ClearFlag (CEC_FLAG_TBTRF | CEC_FLAG_TERR);
        
    
    



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
    