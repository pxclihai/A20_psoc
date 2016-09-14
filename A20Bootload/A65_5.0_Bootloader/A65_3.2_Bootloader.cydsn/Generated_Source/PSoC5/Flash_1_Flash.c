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

/***************SPI协议***************/

static uint8 FlashCmdHeader[10];
/*******READ COMMAND********/
/**
    读状态
**/

uint8 Flash_1_SPI_SendByte(uint8 byte)
{
  //uint8 status = 0;
  Flash_1_SPIM_1_WriteTxData(byte);
  while(!(Flash_1_SPIM_1_ReadTxStatus() & Flash_1_SPIM_1_STS_SPI_DONE));
  return Flash_1_SPIM_1_ReadRxData();
  
  //return status;
}
uint8 Flash_1_SPI_ReadByte(void)
{
  return (Flash_1_SPI_SendByte(Dummy_Byte));
}

static unsigned char Flash_1_SpiReadByte()
/*SCK falling edage:Slave output data*/
{
	return Flash_1_SPI_ReadByte();
}
static void Flash_1_SpiWriteByte(unsigned char byte_data)
/*SCK rasing edage:Master output data,Slave input data*/
{
	Flash_1_SPI_SendByte(byte_data);
}

void Flash_1_Write_Cmd(uint8 *buffer,uint8 length)
{
	uint8 i = 0;
	for(i=0;i<length;i++)
	{
        Flash_1_SpiWriteByte(buffer[i]);
	}
}
uint8 Flash_1_Read_Status(void)
{
	uint8 status;
    CS_L;
 	Flash_1_SpiWriteByte(Read_State);
    status=Flash_1_SpiReadByte();
    CS_H;
	return status;
}
/*********
    SPI连续数组读取数据
*****/
void Flash_1_ContinusArrayRead(uint16 page_address,uint16 start_byte_address,uint8 *buffer,uint16 read_bytes)
{//528byte
	uint8 len = 0;
    uint16 i;
	FlashCmdHeader[len++] = Read_Continuous_Array;	/*0xE8*/
	FlashCmdHeader[len++] = (uint8)(page_address >> 6);
	FlashCmdHeader[len++] = (uint8)(page_address << 2) | (start_byte_address >> 8);
	FlashCmdHeader[len++] = (uint8)(start_byte_address & 0xFF);
	FlashCmdHeader[len++] = 0;
    FlashCmdHeader[len++] = 0;
    FlashCmdHeader[len++] = 0;
    FlashCmdHeader[len++] = 0;

    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
	for(i=0;i<read_bytes;i++)
	{
        *buffer = Flash_1_SpiReadByte();
		buffer ++;
	}
    CS_H;
}

/********
    SPI页读
************/
void Flash_1_PageRead(uint16 page_address,uint16 start_byte_address,uint16 *buffer)
/*OK*/
{
	int len = 0;
	FlashCmdHeader[len++] = Read_Main_Page;	/*0xD2*/
	FlashCmdHeader[len++] = (uint8)(page_address >> 6);
	FlashCmdHeader[len++] = (uint8)(page_address << 2) | (start_byte_address >> 8);
	FlashCmdHeader[len++] = (uint8)(start_byte_address & 0xFF);
	FlashCmdHeader[len++] = 0;
	FlashCmdHeader[len++] = 0;
	FlashCmdHeader[len++] = 0;
	FlashCmdHeader[len++] = 0;

    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
	while(start_byte_address < Flash_Page_Size)
	{
        *buffer = Flash_1_SpiReadByte();
		buffer ++;
		start_byte_address ++;
	}
    CS_H;
}
/***读缓冲器***********/
void Flash_1_BufferRead(uint8 buf_number,uint16 start_byte_address,uint8 *buffer)
{
	uint8 len = 0;
	if(buf_number == 0)
		FlashCmdHeader[len++] = Read_Buffer1;	/*0xD4,buffer 1*/
	else
		FlashCmdHeader[len++] = Read_Buffer2;	/*0xD6,buffer 2*/
	FlashCmdHeader[len++] = 0;
	FlashCmdHeader[len++] = (uint8)(start_byte_address >> 8);
	FlashCmdHeader[len++] = (uint8)(start_byte_address & 0xFF);
	FlashCmdHeader[len++] = 0;
	
	//SPI_FLASH_CS_LOW();
    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
	while(start_byte_address < Flash_Page_Size)
	//while(start_byte_address < 100)
	{
        *buffer = Flash_1_SpiReadByte();
    	buffer ++;
    	start_byte_address ++;
	}
    CS_H;
}

void Flash_1_MMP_Transfer_Buffer(uint8 buf_number,uint16 page_address)
{
	uint8 len = 0;
	uint8 status;
	if(buf_number == 0)
		FlashCmdHeader[len++] = 0X53;
	else
		FlashCmdHeader[len++] = 0X55; 
	FlashCmdHeader[len++] = (uint8)(page_address >> 6);
	FlashCmdHeader[len++] = (uint8)(page_address << 2);
	FlashCmdHeader[len++] = 0;
	
    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
    CS_H;
	do
    {
		status = Flash_1_Read_Status();	
    }
    while((status & 0x80) == 0);	/*busy*/
}
/*******READ COMMAND END********/

/*******WRITE COMMAND********/
void Flash_1_BufferWrite(uint8 buf_number,uint16 start_byte_address,uint8 *buffer,uint8 length)
/*OK*/
{
	uint8 len = 0;
	if(buf_number == 0)
		FlashCmdHeader[len++] = 0x84;
	else
		FlashCmdHeader[len++] = 0x87;
	FlashCmdHeader[len++] = 0;
	FlashCmdHeader[len++] = (uint8)(start_byte_address >> 8);
	FlashCmdHeader[len++] = (uint8)(start_byte_address & 0xFF);

    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
	length += start_byte_address;
	while(start_byte_address < length)
	{
        Flash_1_SpiWriteByte(*buffer);
		buffer ++;
		start_byte_address ++;
	}
    CS_H;
}
void Flash_1_Buffer_Main_Erase(uint8 buf_number,uint16 page_address)
/*OK*/
/*Buffer to Main Memory Page Program With Built-in Erase
 wait Tep = 20ms max=40ms
*/
{
	uint8 len = 0;
    uint8 status;
	if(buf_number == 0)
		FlashCmdHeader[len++] = 0x83;
	else
		FlashCmdHeader[len++] = 0x86;
	FlashCmdHeader[len++] = (uint8)(page_address >> 6);
	FlashCmdHeader[len++] = (uint8)(page_address << 2);
	FlashCmdHeader[len++] = 0;

    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
    CS_H;
	do
    {
		status = Flash_1_Read_Status();
	}
    while((status & 0x80) == 0);	/*busy*/
	
}

void Flash_1_Buffer_Main_notErase(uint8 buf_number,uint16 page_address)
/*OK*/
/*Buffer to Main Memory Page Program Without Built-in Erase
 wait Tp = 14ms
*/
{
	uint8 len = 0;
    uint8 status;
	if(buf_number == 0)
		FlashCmdHeader[len++] = 0x88;
	else
		FlashCmdHeader[len++] = 0x89;
	FlashCmdHeader[len++] = (uint8)(page_address >> 6);
	FlashCmdHeader[len++] = (uint8)(page_address << 2);
	FlashCmdHeader[len++] = 0;
    
    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
    CS_H;
	do
    {
		status = Flash_1_Read_Status();
	}
    while((status & 0x80) == 0);	/*busy*/
}

void Flash_1_Auto_Page_Rewrite(uint8 buf_number,uint16 page_address)
/*OK*/
/*Buffer to Main Memory Page Program Without Built-in Erase
 wait Tep = 20ms max=40ms
*/
{
	uint8 len = 0;
    uint8 status;
	if(buf_number == 0)
		FlashCmdHeader[len++] = 0x58;
	else
		FlashCmdHeader[len++] = 0x59;
	FlashCmdHeader[len++] = (uint8)(page_address >> 6);
	FlashCmdHeader[len++] = (uint8)(page_address << 2);
	FlashCmdHeader[len++] = 0;

    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
    CS_H;
	do
    {
		status = Flash_1_Read_Status();
	}
    while((status & 0x80) == 0);	/*busy*/
}
void Flash_1_MMP_Progam_ThroughBuffer(uint8 buf_number,uint16 page_address,uint16 start_byte_address,uint8 *buffer,uint8 length)
{
	uint8 len = 0;
    uint8 status;
	if(buf_number == 0)
		FlashCmdHeader[len++] = 0x82;
	else
		FlashCmdHeader[len++] = 0x85;
	FlashCmdHeader[len++] = (uint8)(page_address >> 6);
	FlashCmdHeader[len++] = (uint8)(page_address << 2) | (start_byte_address >> 8);
	FlashCmdHeader[len++] = (uint8)(start_byte_address & 0xFF);

    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
	length += start_byte_address;
	while(start_byte_address < length)
	{
        Flash_1_SpiWriteByte(*buffer);
		buffer ++;
		start_byte_address ++;
	}
    CS_H;
    do
    {
		status = Flash_1_Read_Status();
	}
    while((status & 0x80) == 0);	/*busy*/
}

void Flash_1_Page_Erase(uint16 page_address)
{
	uint8 len = 0;
    uint8 status;
    page_address &= 0x7FF;
    FlashCmdHeader[len++] = Erase_Page;
	FlashCmdHeader[len++] = (uint8)(page_address >> 6);
	FlashCmdHeader[len++] = (uint8)(page_address << 2);
	FlashCmdHeader[len++] = 0;

    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
    CS_H;
	do
    {
		status = Flash_1_Read_Status();
	}
    while((status & 0x80) == 0);	/*busy*/
}
void Flash_1_Block_Erase(uint16 page_address)
{
	uint8 len = 0;
    uint8 status;
    page_address &= 0x3FF;
    FlashCmdHeader[len++] = Erase_Block;
	FlashCmdHeader[len++] = (uint8)(page_address >> 3);
	FlashCmdHeader[len++] = (uint8)(page_address << 5);
	FlashCmdHeader[len++] = 0;

    CS_L;
	Flash_1_Write_Cmd(FlashCmdHeader,len);
    CS_H;
	do
    {
		status = Flash_1_Read_Status();
	}
    while((status & 0x80) == 0);	/*busy*/
}
/*******WRITE COMMAND END********/
void Flash_1_Randomly_Modifying_Data(uint8 buf_number,uint16 page_address,uint16 start_byte_address,uint8 *buffer,uint8 length)
{
    Flash_1_MMP_Transfer_Buffer(buf_number,page_address);
    Flash_1_MMP_Progam_ThroughBuffer(buf_number,page_address,start_byte_address,buffer,length);
    Flash_1_Auto_Page_Rewrite(buf_number,page_address);
}
/**************************/
void Flash_1_Initial(void)
{
    WP_H;
    CS_H;
    Flash_1_SPIM_1_Start();
    CyDelay(80u);  
}
/* [] END OF FILE */
