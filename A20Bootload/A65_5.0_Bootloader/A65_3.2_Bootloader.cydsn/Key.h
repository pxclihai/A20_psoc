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
#ifndef CH452_H
#define CH452_H
#include <device.h>
#define CH452_SDA_SET 		Key_SDA_Write(1)
#define CH452_SCL_SET 		Key_SCL_Write(1)
#define CH452_SDA_CLR 		Key_SDA_Write(0)
#define CH452_SCL_CLR 		Key_SCL_Write(0)

#define CH452_SDA_Read() 	Key_SDA_Read()

#define CH452_SDA_D_OUT 	{}
#define CH452_SDA_D_IN  	{}
#define CH452_SCL_D_OUT 	{}
#define CH452_I2C_MASK		0x3E
#define	CH452_I2C_ADDR1		0x60
#define CH452_GET_KEY		0x0700

enum KEY_VALUE
{
	Key_0 = 0,
	Key_1,
	Key_2,
	Key_3,
	Key_4,
	Key_5,
	Key_6,
	Key_7,
	Key_8,
	Key_9,
	Key_Point,
	Key_Negative,
	Key_Up,
	Key_Down,
	Key_Left,
	Key_Right,
	Key_Set,
	Key_Clear,
	Key_Enter,
	Key_Run,
	Key_Stop,
	Key_Speed,
	Key_Null
};

void CH452_Write(uint16 cmd);
uint8 CH452_Read(void);
uint8 Read_KeyValue(void);
void Init_key(void);


#endif
//[] END OF FILE
