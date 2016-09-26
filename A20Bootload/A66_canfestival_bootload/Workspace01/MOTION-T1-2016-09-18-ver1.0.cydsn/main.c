/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{  
    LCD_Char_1_Init();
    LCD_Char_1_LoadCustomFonts(LCD_Char_1_customFonts) ; 
//    Timer_1_Start();
//	isr_1_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */

 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
//  
    LCD_Char_1_Position(0,0) ;
    LCD_Char_1_PrintString("Wait USB");
    LCD_Char_1_Position(1,0) ;
    LCD_Char_1_PrintString(" UPDATA");
//    USBFS_1_Init();
//    USBFS_1_Dp_SetDriveMode(USBFS_1_Dp_DM_STRONG);
//    USBFS_1_Dm_SetDriveMode(USBFS_1_Dp_DM_STRONG);
    CyDelay(1000);
   
//    if(USBFS_1_Dm_Read() == 0 )
//    {
//        LCD_Char_1_Position(0,0);
//        LCD_Char_1_PrintString("1  pc");
//    }
//    
//    if(USBFS_1_Dm_Read() == 0)
//    {
//      LCD_Char_1_Position(1,0) ;
//      LCD_Char_1_PrintString("-----");
////          LCD_Char_1_Position(1,0) ;
////          LCD_Char_1_PrintString('0  pc');
//    }
    CyBtldr_Start();
 
    for(;;)
    {
        /* Place your application code here. */
  
    }
}

/* [] END OF FILE */
