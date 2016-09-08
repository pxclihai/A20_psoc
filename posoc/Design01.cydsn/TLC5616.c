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
#include "device.h"
#include "TLC5616.h"

void Init_TLC5616(void)
{
	TLC5616_CS1_H;
	TLC5616_CS2_H;
	TLC5616_CLK_L;
}

/*
 *简要说明：写入电压值
 *操作流程：工作方式1 先后输入 10位有效位,2位填充位(任意值)
 *入口参数：chip：    芯片号
 *			voltage:  电压值
 *出口参数：
 *
**/
void TLC5616_Write(uint8 chip,uint16 voltage)
{
	uint8 i = 0;
	voltage <<= 6;
	if(chip)
	{
		TLC5616_CLK_L;
		TLC5616_CS2_H;
		TLC5616_CS1_L;
	}
	else
	{
		TLC5616_CLK_L;
		TLC5616_CS1_H;
		TLC5616_CS2_L;
	}
	
	for(i = 0;i < 12;i++)
	{
		if((voltage&0x8000) == 0x8000)
		{
			TLC5616_DAT_H;
		}
		else
		{
			TLC5616_DAT_L;
		}
		TLC5616_CLK_H;
		voltage <<= 1;
		CyDelayUs(1);
		TLC5616_CLK_L;
	}
	
	TLC5616_CLK_L;
	TLC5616_CS2_H;
	TLC5616_CS1_H;
}

/* [] END OF FILE */
