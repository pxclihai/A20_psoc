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
/****************ÔªÆ÷¼þÐÍºÅ**************/
//#define AT45DB081D
//
//#ifdef	AT45DB081D
//
//#endif
/* Read */
#define Read_Continuous_Array     0xE8
#define Read_Continuous_Array_High 0x0B
#define Read_Continuous_Array_Low  0x03
#define Read_Main_Page 0xD2
#define Read_Buffer1   0xD4
#define Read_Buffer2   0xD6
#define Read_State     0xD7

/* Write */
#define Write_Buffer1  0x84
#define Write_Buffer2  0x87

/* Erase */
#define Erase_Block    0x50
#define Erase_Page     0x81
#define Erase_Sector   0x7C
#define Flash_Page_Size 528
//Flash
#define WP_H    Flash_1_FWP_Write(0X01)
#define WP_L    Flash_1_FWP_Write(0X00)

#define CS_H    Flash_1_FCS_Write(0X01)
#define CS_L    Flash_1_FCS_Write(0X00)
#define Dummy_Byte 0x25

uint8 Flash_1_SPI_SendByte(uint8 byte);
uint8 Flash_1_SPI_ReadByte(void);
//static unsigned char Flash_1_SpiReadByte();
//static void Flash_1_SpiWriteByte(unsigned char byte_data);
void Flash_1_Write_Cmd(uint8 *buffer,uint8 length);
uint8 Flash_1_Read_Status(void);
void Flash_1_ContinusArrayRead(uint16 page_address,uint16 start_byte_address,uint8 *buffer,uint16 read_bytes);
void Flash_1_PageRead(uint16 page_address,uint16 start_byte_address,uint16 *buffer);
void Flash_1_BufferRead(uint8 buf_number,uint16 start_byte_address,uint8 *buffer);
void Flash_1_MMP_Transfer_Buffer(uint8 buf_number,uint16 page_address);
void Flash_1_BufferWrite(uint8 buf_number,uint16 start_byte_address,uint8 *buffer,uint8 length);
void Flash_1_Buffer_Main_Erase(uint8 buf_number,uint16 page_address);
void Flash_1_Buffer_Main_notErase(uint8 buf_number,uint16 page_address);
void Flash_1_Auto_Page_Rewrite(uint8 buf_number,uint16 page_address);
void Flash_1_MMP_Progam_ThroughBuffer(uint8 buf_number,uint16 page_address,uint16 start_byte_address,uint8 *buffer,uint8 length);
void Flash_1_Page_Erase(uint16 page_address);
void Flash_1_Block_Erase(uint16 page_address);
void Flash_1_Randomly_Modifying_Data(uint8 buf_number,uint16 page_address,uint16 start_byte_address,uint8 *buffer,uint8 length);
void Flash_1_Initial(void);

//[] END OF FILE
