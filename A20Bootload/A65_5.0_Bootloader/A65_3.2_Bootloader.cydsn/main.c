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
#include <device.h>
#include "Key.h"

int main()
{
	uint16 i;
	Init_key();
	Control_Reg_1_Write(1);
    CyDelay(100);
    Init_key();
    CyDelay(5);
    for(i=0;i<1000;i++)
    {
    	if(Read_KeyValue() == Key_Negative)
    	{
            Control_Reg_1_Write(1);
            Bootloader_1_SET_RUN_TYPE(Bootloader_1_START_BTLDR);
            i=1000;
            break;
    	}
        //CyDelayUs(100);
    }
	/* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CyBtldr_Start();
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
		
    }
}
/* [] END OF FILE */
