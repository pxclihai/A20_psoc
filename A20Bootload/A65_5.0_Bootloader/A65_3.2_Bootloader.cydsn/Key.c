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



void CH452_I2c_Start(void)  // 操作起始
{
	CH452_SDA_SET;   /*发送起始条件的数据信号*/
	CH452_SCL_SET;
	CyDelayUs(1);
	CH452_SDA_CLR;   /*发送起始信号*/
	CyDelayUs(1);      
	CH452_SCL_CLR;   /*钳住I2C总线，准备发送或接收数据 */
	CyDelayUs(1);
}

void CH452_I2c_Stop(void)  // 操作结束
{
	CH452_SDA_CLR;
	CH452_SDA_D_OUT;   /* 设置SDA为输出方向 */
	CyDelayUs(1);
	CH452_SCL_SET;
	CyDelayUs(1);
	CH452_SDA_SET;  /*发送I2C总线结束信号*/
	CyDelayUs(1);
	CH452_SDA_D_IN;   /* 设置SDA为输入方向 */
	CyDelayUs(1);
}

void CH452_I2c_WrByte(uint8 dat)	//写一个字节数据
{
	uint8 i;
	for(i=0;i!=8;i++)  // 输出8位数据
	{
		if(dat&0x80) {CH452_SDA_SET;}
		else {CH452_SDA_CLR;}
		CyDelayUs(1);
		CH452_SCL_SET;
		dat<<=1;
		CyDelayUs(1);
		CH452_SCL_CLR;
		CyDelayUs(2);
	}
	CH452_SDA_SET;
	CyDelayUs(1);
	CH452_SCL_SET;  // 接收应答
	CyDelayUs(1);
	CH452_SCL_CLR;
	CyDelayUs(1);
}

unsigned char  CH452_I2c_RdByte(void)		//读一个字节数据
{
	uint8 dat,i;
	CH452_SDA_SET;
	dat=0;
	for(i=0;i!=8;i++)  // 输入8位数据
	{
		CH452_SCL_SET;
		CyDelayUs(2);
		dat<<=1;
	    if(CH452_SDA_Read()) dat++;  // 输入1位
		CH452_SCL_CLR;
		CyDelayUs(1);
	}
	CH452_SDA_SET;
	CyDelayUs(1);
	CH452_SCL_SET;  // 发出无效应答
	CyDelayUs(2);
	CH452_SCL_CLR;
	CyDelayUs(1);
	return(dat);
}

void CH452_Write( uint16 cmd)	//写命令
{
	CH452_I2c_Start();               /*启动总线*/
    CH452_I2c_WrByte(((uint8)(cmd>>7)&CH452_I2C_MASK) | CH452_I2C_ADDR1);
   	CH452_I2c_WrByte((uint8)cmd);     /*发送数据*/
  	CH452_I2c_Stop();                 /*结束总线*/ 
}

uint8 CH452_Read(void)
//读取按键
{	
	uint8 keycode;
   	CH452_I2c_Start();                /*启动总线*/
    CH452_I2c_WrByte(((uint8)(CH452_GET_KEY>>7)&CH452_I2C_MASK) | (0x01 | CH452_I2C_ADDR1)); 
   	keycode=CH452_I2c_RdByte();      /*读取数据*/
	CH452_I2c_Stop();                /*结束总线*/ 
	
	return(keycode);
}

uint8 Read_KeyValue(void)
{
	uint8 keyval = 21;
	uint8 keycode;
	CH452_I2c_Start();                /*启动总线*/
	CH452_I2c_WrByte(((uint8)(CH452_GET_KEY>>7)&CH452_I2C_MASK) | (0x01 | CH452_I2C_ADDR1)); 
	keycode=CH452_I2c_RdByte();      /*读取数据*/
	CH452_I2c_Stop();                /*结束总线*/ 
	switch(keycode)
	{
    	case 84: keyval = Key_0; break;
    	case 89: keyval = Key_7; break;
    	case 81: keyval = Key_8; break;
    	case 73: keyval = Key_9; break;
    	case 90: keyval = Key_4; break;
    	case 82: keyval = Key_5; break;
    	case 75: keyval = Key_6; break;
    	case 91: keyval = Key_1; break;
    	case 80: keyval = Key_2; break;
    	case 72: keyval = Key_3; break;
    	case 92: keyval = Key_Point; break;
    	case 76: keyval = Key_Negative; break;
    	/******************************************/
    	case 97: keyval = Key_Up; break;
    	case 96: keyval = Key_Down; break;
    	case 99: keyval = Key_Left; break;
    	case 98: keyval = Key_Right; break;
    //	case 97: keyval = Key_Set; break;
    	/***********************************/
    	case 67: keyval = Key_Clear; break;
    	case 68: keyval = Key_Enter; break;
    	case 66: keyval = Key_Run; break;
    	case 64: keyval = Key_Stop; break;
	
    	//case 99: keyval = Key_Speed; break;
    	default : keyval = Key_Null; break;
	}
	//keyval = keycode;
	return keyval;
}

void Init_key(void)
{
	CH452_Write(0x0402);
}
/* [] END OF FILE */
