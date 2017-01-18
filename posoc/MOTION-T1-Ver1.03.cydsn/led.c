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

void Control_LED_Write(uint8 led_sta)
{
    LED1_Write((led_sta >> 0) & 0x01);
    LED2_Write((led_sta >> 1) & 0x01);
    LED3_Write((led_sta >> 2) & 0x01);
}
/* [] END OF FILE */
