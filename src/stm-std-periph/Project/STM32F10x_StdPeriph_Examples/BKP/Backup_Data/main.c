/**
  ******************************************************************************
  * @file    BKP/Backup_Data/main.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    04/16/2010
  * @brief   Main program body.
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
#include "stm32_eval.h"
    
/** @addtogroup STM32F10x_StdPeriph_Examples
  * @{
  */ 
    
/** @addtogroup BKP_Backup_Data
  * @{
  */ 
    
    /* Private typedef ----------------------------------------------------------- */ 
    /* Private define ------------------------------------------------------------ */ 
#if defined USE_STM3210B_EVAL || defined USE_STM32100B_EVAL
#define BKP_DR_NUMBER              10   
#else /* 
#define BKP_DR_NUMBER              42
#endif  /* USE_STM3210B_EVAL or USE_STM32100B_EVAL */
    
    /* Private macro ------------------------------------------------------------- */ 
    /* Private variables --------------------------------------------------------- */ 
#if defined USE_STM3210B_EVAL || defined USE_STM32100B_EVAL
    uint16_t BKPDataReg[BKP_DR_NUMBER] = 
{



#else /* 
    uint16_t BKPDataReg[BKP_DR_NUMBER] = 
{

        
        BKP_DR15, BKP_DR16, 
        BKP_DR21, BKP_DR22, BKP_DR23, BKP_DR24, 
        BKP_DR27, BKP_DR28, BKP_DR29, BKP_DR30, BKP_DR31, BKP_DR32,
        

#endif  /* USE_STM3210B_EVAL or USE_STM32100B_EVAL */
    
    /* Private function prototypes ----------------------------------------------- */ 
void WriteToBackupReg (uint16_t FirstBackupData);



    /* Private functions --------------------------------------------------------- */ 
    
/**
  * @brief   Main program.
  * @param  None
  * @retval None
  */ 
int main (void) 
{
    
        /* !< At this stage the microcontroller clock setting is already configured, 
           from startup
           function, refer to
        
        /* Initialize Leds mounted on STM3210X-EVAL board */ 
        STM_EVAL_LEDInit (LED1);
    
    
    
    
        /* Enable PWR and BKP clock */ 
        RCC_APB1PeriphClockCmd (RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
    
        /* Enable write access to Backup domain */ 
        PWR_BackupAccessCmd (ENABLE);
    
        /* Clear Tamper pin Event(TE) pending flag */ 
        BKP_ClearFlag ();
    
        /* Check if the Power On Reset flag is set */ 
        if (RCC_GetFlagStatus (RCC_FLAG_PORRST) != RESET)
        
    {
        
            /* Clear reset flags */ 
            RCC_ClearFlag ();
        
            /* Turn on LED3 */ 
            STM_EVAL_LEDOn (LED3);
        
            /* Check if Backup data registers are programmed */ 
            if (CheckBackupReg (0x3210) == 0x00)
            
        {   /* Backup data registers values are correct */
            
                /* Turn on LED1 */ 
                STM_EVAL_LEDOn (LED1);
        
        
        else
            
        {   /* Backup data registers values are not correct or they are not yet
            
                /* Write data to Backup data registers */ 
                WriteToBackupReg (0x3210);
            
                /* Turn on LED2 */ 
                STM_EVAL_LEDOn (LED2);
        
    
    
        /* Turn on LED4 */ 
        STM_EVAL_LEDOn (LED4);
    
        
    {
    



/**
  * @brief  Writes data Backup DRx registers.
  * @param  FirstBackupData: data to be written to Backup data registers.
  * @retval None
  */ 
void WriteToBackupReg (uint16_t FirstBackupData) 
{
    
    
        
    {
        
    



/**
  * @brief  Checks if the Backup DRx registers values are correct or not.
  * @param  FirstBackupData: data to be compared with Backup data registers.
  * @retval 
  *          - 0: All Backup DRx registers values are correct
  *          - Value different from 0: Number of the first Backup register
  *            which value is not correct
  */ 
    uint8_t CheckBackupReg (uint16_t FirstBackupData) 
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