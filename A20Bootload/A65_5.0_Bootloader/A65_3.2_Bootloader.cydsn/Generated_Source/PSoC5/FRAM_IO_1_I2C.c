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
#include "FRAM_IO_1_I2C.h"


#define FM_PageSize 256
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
void FRAM_IO_1_I2C_delay(void)
{	
   uint16 i=500; //��������Ż��ٶ�	����������͵�5����д�� 500
   while(i) 
   { 
     i--; 
   } 
}
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
uint8 FRAM_IO_1_I2C_Start(void)
{
	//set_out_sda();
	FRAM_IO_1_SDA_H();
	FRAM_IO_1_SCL_H();
	FRAM_IO_1_I2C_delay();
	//set_in_sda();
	if(!FRAM_IO_1_SDA_read())return 0;	//SDA��Ϊ�͵�ƽ������æ,�˳�
	FRAM_IO_1_SDA_L();
	FRAM_IO_1_I2C_delay();
	if(FRAM_IO_1_SDA_read()) return 0;	//SDA��Ϊ�ߵ�ƽ�����߳���,�˳�
	FRAM_IO_1_SDA_L();
	FRAM_IO_1_I2C_delay();
	return 1;
}
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
void FRAM_IO_1_I2C_Stop(void)
{
	FRAM_IO_1_SCL_L();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SDA_L();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SCL_H();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SDA_H();
	FRAM_IO_1_I2C_delay();
}
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
void FRAM_IO_1_I2C_Ack(void)
{	
	FRAM_IO_1_SCL_L();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SDA_L();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SCL_H();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SCL_L();
	FRAM_IO_1_I2C_delay();
}
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
void FRAM_IO_1_I2C_NoAck(void)
{	
	FRAM_IO_1_SCL_L();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SDA_H();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SCL_H();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SCL_L();
	FRAM_IO_1_I2C_delay();
}
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
uint8 FRAM_IO_1_I2C_WaitAck(void) 	 //����Ϊ:=1��ACK,=0��ACK
{
	FRAM_IO_1_SCL_L();
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SDA_H();			
	FRAM_IO_1_I2C_delay();
	FRAM_IO_1_SCL_H();
	FRAM_IO_1_I2C_delay();
	if(FRAM_IO_1_SDA_read())
	{
      FRAM_IO_1_SCL_L();
      return 0;
	}
	FRAM_IO_1_SCL_L();
	return 1;
}
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
void FRAM_IO_1_I2C_SendByte(uint8 SendByte) //���ݴӸ�λ����λ//
{
    uint8 i=8;
    while(i--)
    {
        FRAM_IO_1_SCL_L();
        FRAM_IO_1_I2C_delay();
		if(SendByte&0x80)
			FRAM_IO_1_SDA_H();  
		else 
			FRAM_IO_1_SDA_L();   
        SendByte<<=1;
        FRAM_IO_1_I2C_delay();
		FRAM_IO_1_SCL_H();
        FRAM_IO_1_I2C_delay();
    }
    FRAM_IO_1_SCL_L();
}
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
uint8 FRAM_IO_1_I2C_ReceiveByte(void)  //���ݴӸ�λ����λ//
{ 
    uint8 i=8;
    uint8 ReceiveByte=0;

    FRAM_IO_1_SDA_H();				
    while(i--)
    {
      ReceiveByte<<=1;      
      FRAM_IO_1_SCL_L();
      FRAM_IO_1_I2C_delay();
	  FRAM_IO_1_SCL_H();
      FRAM_IO_1_I2C_delay();	
      if(FRAM_IO_1_SDA_read())
      {
        ReceiveByte|=0x01;
      }
    }
    FRAM_IO_1_SCL_L();
    return ReceiveByte;
}
/*------------------FRAM�洢����----------------------*/
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
void FRAM_IO_1_Init_FRAM(void)
{
	
}
/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
//uint8 FRAM_IO_1_WriteData_To_FRAM(uint8 decive_addr,uint16 data_addr,uint8 *dat,uint16 datnum)
uint8 FRAM_IO_1_WriteData_To_FRAM(uint16 data_addr,uint8 *dat,uint16 datnum)
{
	uint8 i = 0;
	uint8 Row_address;//��256byte
	uint8 Segment_address;//8�Σ�8ҳ
	
	Segment_address = data_addr/FM_PageSize;
	Row_address = data_addr%FM_PageSize;
	
	if(!FRAM_IO_1_I2C_Start()) return 0x01;
	FRAM_IO_1_I2C_SendByte(DeviceType|((Segment_address<<1) & 0x0f));//д������ַ
	if(!FRAM_IO_1_I2C_WaitAck())
	{
		FRAM_IO_1_I2C_Stop();
		return 0x02;
	}
	
	FRAM_IO_1_I2C_SendByte(Row_address);
	if(!FRAM_IO_1_I2C_WaitAck())	return 0x02;

	for(i=0;i<datnum;i++)
	{
		FRAM_IO_1_I2C_SendByte(*dat);
		*dat++;
		if(!FRAM_IO_1_I2C_WaitAck()) return 0x04;
	}
	FRAM_IO_1_I2C_Stop();	
}

/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
//uint8 FRAM_IO_1_ReadData_From_FRAM(uint8 decive_addr,uint16 data_addr,uint8 *dat,uint16 datnum)
uint8 FRAM_IO_1_ReadData_From_FRAM(uint16 data_addr,uint8 *dat,uint16 datnum)
{
	uint8 i = 0;
	uint8 Row_address;//��256byte
	uint8 Segment_address;//8�Σ�8ҳ
	
	Segment_address = data_addr/FM_PageSize;
	Row_address = data_addr%FM_PageSize;
	
	if(!FRAM_IO_1_I2C_Start()) return 0x01;
	FRAM_IO_1_I2C_SendByte(DeviceType|((Segment_address<<1) & 0x0f));//д��ַ
	
	if(!FRAM_IO_1_I2C_WaitAck())
	{
		FRAM_IO_1_I2C_Stop();
		return 0x02;//����Ϊ:=1��ACK,=0��ACK
	}
	
	FRAM_IO_1_I2C_SendByte(Row_address);
	if(!FRAM_IO_1_I2C_WaitAck())	return 0x03;//
	
	/*********************************************************/
	FRAM_IO_1_I2C_Start();
	FRAM_IO_1_I2C_SendByte(DeviceType|((Segment_address<<1) & 0x0f)|0x01);//д������
	if(!FRAM_IO_1_I2C_WaitAck())
	{
		FRAM_IO_1_I2C_Stop();
		return 0x04;//
	}
	
	for(i=0;i<datnum-1;i++)
	{
		*dat = FRAM_IO_1_I2C_ReceiveByte();
		dat++;
		FRAM_IO_1_I2C_Ack();
		//if(!FRAM_IO_1_I2C_WaitAck()) return 0x04;
	}
	*dat = FRAM_IO_1_I2C_ReceiveByte();
	FRAM_IO_1_I2C_NoAck();
	FRAM_IO_1_I2C_Stop();	
}

/************************************************
��������
��  �ܣ�
��  ������
����ֵ����
***********************************************/
uint8 FRAM_IO_1_ReadByteData_From_FRAM(uint16 data_addr)
{
	uint8 bytedata = 0;
	FRAM_IO_1_I2C_Start();
	FRAM_IO_1_I2C_SendByte(Device_Write);//д��ַ
	if(!FRAM_IO_1_I2C_WaitAck())	return 0x01;//����Ϊ:=1��ACK,=0��ACK
	FRAM_IO_1_I2C_SendByte((data_addr << 8) & 0x1F);
	if(!FRAM_IO_1_I2C_WaitAck())	return 0x02;//
	FRAM_IO_1_I2C_SendByte(data_addr);
	if(!FRAM_IO_1_I2C_WaitAck())	return 0x03;//
	/*********************************************************/
	FRAM_IO_1_I2C_Start();
	FRAM_IO_1_I2C_SendByte(Device_Read);//д������
	if(!FRAM_IO_1_I2C_WaitAck())	return 0x04;//
	/***********************************************/
	bytedata = FRAM_IO_1_I2C_ReceiveByte();
	FRAM_IO_1_I2C_Ack();
	//FRAM_IO_1_I2C_NoAck();
	FRAM_IO_1_I2C_Stop();
	return bytedata;
}


/********************************************/
/* [] END OF FILE */
