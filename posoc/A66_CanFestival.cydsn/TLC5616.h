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
#ifndef _TLC5616_H_
#define _TLC5616_H_
	
#include "device.h"
	
#define TLC5616_CLK_H   TLC5616_CLK_Write(1)
#define TLC5616_CLK_L   TLC5616_CLK_Write(0)
#define TLC5616_DAT_H   TLC5616_DAT_Write(1)
#define TLC5616_DAT_L   TLC5616_DAT_Write(0)
	
#define TLC5616_CS1_H   TLC5616_CS1_Write(1)
#define TLC5616_CS1_L   TLC5616_CS1_Write(0)	
#define TLC5616_CS2_H   TLC5616_CS2_Write(1)
#define TLC5616_CS2_L   TLC5616_CS2_Write(0)

void Init_TLC5616(void);
void TLC5616_Write(uint8 chip,uint16 voltage);

#endif

/* [] END OF FILE */
