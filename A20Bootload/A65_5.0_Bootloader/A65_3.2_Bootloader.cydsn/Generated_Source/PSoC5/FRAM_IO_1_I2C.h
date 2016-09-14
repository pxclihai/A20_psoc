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


#define DeviceType			0xa0
#define DeviceSelectAddr	0x00
#define Device_Write		(DeviceType | (DeviceSelectAddr << 1))//0xa0
#define Device_Read			((DeviceType | (DeviceSelectAddr << 1)) + 0x01)//0xa1

#define Device_select_addr		0x00

#define FRAM_IO_1_SDA_H()	FRAM_IO_1_SDA_Write(0X01)
#define FRAM_IO_1_SDA_L()	FRAM_IO_1_SDA_Write(0X00)
#define FRAM_IO_1_SCL_H()	FRAM_IO_1_SCL_Write(0X01)
#define FRAM_IO_1_SCL_L()	FRAM_IO_1_SCL_Write(0X00)

#define FRAM_IO_1_SDA_read()	(FRAM_IO_1_SDA_PS & FRAM_IO_1_SDA_MASK) >> FRAM_IO_1_SDA_SHIFT//FRAM_IO_1_SDA_Read()
									//(FRAM_IO_1_SDA_PS & FRAM_IO_1_SDA_MASK) >> FRAM_IO_1_SDA_SHIFT;

void FRAM_IO_1_I2C_delay(void);
uint8 FRAM_IO_1_I2C_Start(void);
void FRAM_IO_1_I2C_Stop(void);
void FRAM_IO_1_I2C_Ack(void);
void FRAM_IO_1_I2C_NoAck(void);
uint8 FRAM_IO_1_I2C_WaitAck(void) ;	 //����Ϊ:=1��ACK,=0��ACK
void FRAM_IO_1_I2C_SendByte(uint8 SendByte); //���ݴӸ�λ����λ//
uint8 FRAM_IO_1_I2C_ReceiveByte(void);  //���ݴӸ�λ����λ//

//uint8 FRAM_IO_1_WriteData_To_FRAM(uint8 decive_addr,uint16 data_addr,uint8 *dat,uint16 datnum);
//uint8 FRAM_IO_1_ReadData_From_FRAM(uint8 decive_addr,uint16 data_addr,uint8 *dat,uint16 datnum);

uint8 FRAM_IO_1_WriteData_To_FRAM(uint16 data_addr,uint8 *dat,uint16 datnum);
uint8 FRAM_IO_1_ReadData_From_FRAM(uint16 data_addr,uint8 *dat,uint16 datnum);
uint8 FRAM_IO_1_ReadByteData_From_FRAM(uint16 data_addr);

void FRAM_IO_1_Init_FRAM(void);

//[] END OF FILE
