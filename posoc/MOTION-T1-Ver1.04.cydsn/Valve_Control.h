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
#ifndef _VALVE_CONTROL_H
#define _VALVE_CONTROL_H
#include "product.h"
extern uint8 LED_Status[];
extern unsigned char TPDO_PROCESS_Status;
extern unsigned char TPDO_OUT_Status;
#define LED_WRITE(a)		{TPDO_PROCESS_Status = a ;LCD_DISPLAY(a);LCD_DISPLAY_MODE();}
//#define RunLED_OFF()	Control_Reg_2_Write(0X00)
//#define RunLED_FLASH()	Control_Reg_2_Write(0X02)
	
//#define StopLED_ON()	Control_Reg_3_Write(0X01)
//#define StopLED_OFF()	Control_Reg_3_Write(0X00)
//#define StopLED_FLASH()	Control_Reg_3_Write(0X02)
 /*参数配置*/
#define EnterConfig 0xAA
#define FinsihConfig 0xA0

#define Enter_Start    0xAA
#define Enter_Stop     0x55
#define Enter_CUTSMODE 0x11
#define Enter_QUIT     0xA0
#define Enter_return   0x88
#define Enter_Config_Test 0x30
#define Quit_Config_Test  0x31

#define Enter_CUTJMODE 0x40

#define One_Work_Finish 0xFF
#define One_Work_Runing 0x11


#define ValveOut(odat)		{Control_Reg_1_Write(odat);TPDO_OUT_Status = odat;}// 阀组输出 和写入TPDO输出
#define LEVLE_HIGH
#ifdef  LEVLE_HIGH
/**********************************************************************/
#define FootStart()			!(Status_Reg_1_Read()&0x08)//读脚踏开关信号  IN1
#define FootUp()	    	!(Status_Reg_1_Read()&0x04)//脚踏上  IN2
/*********************运行模式:单次,连续,点动**********************/
#define CUTSMODE			0x20//单次模式  IN4
#define CUTCMODE			0x40//连续模式  IN3
#define CUTJMODE			0x60//点动模式
#define CUTEMODE			0x00//单次连续都有效，错误模式
#define CutMode()			 (Status_Reg_1_Read()&0x60)//剪切方式 on 连续 off 单次
#define UpperPoint()		!(Status_Reg_1_Read()&0X02)//上死点信号输入 on 位于上死点 IN5
#define DownPoint()			!(Status_Reg_1_Read()&0X01)// IN6
#define PumpSignal()		!(Status_Reg_1_Read()&0X10)//油泵启动信号 IN7
#else

#define FootStart()			!(Status_Reg_1_Read()&0x01)//读脚踏开关信号  IN1
#define FootUp()	    	!(Status_Reg_1_Read()&0x02)//脚踏上  IN2
/*********************运行模式:单次,连续,点动**********************/
#define CUTSMODE			~(0x08)//单次模式  IN4
#define CUTCMODE			~(0x04)//连续模式  IN3
#define CUTJMODE			~(0x0C)//点动模式
#define CUTEMODE			~(0x00)//单次连续都有效，错误模式
#define CutMode()			 ~(Status_Reg_1_Read()&0x0C)//剪切方式 on 连续 off 单次
#define UpperPoint()		!(~Status_Reg_1_Read()&0X10)//上死点信号输入 on 位于上死点 IN5
#define DownPoint()			!(~Status_Reg_1_Read()&0X20)// IN6
#define PumpSignal()		!(~Status_Reg_1_Read()&0X40)//油泵启动信号 IN7   
    
    
#endif
#define Read_Status_Reg     ~(Status_Reg_1_Read() | 0x80)
//#define Read_Status_Reg    Status_Reg_1_Read()
/**************************************************************************************/

enum MEMORY_PARA_ADDR
{
	SUTACTION_ADDR  = 180,	
	XP_ADDR			= 300,
	YP_ADDR			= 304
};

enum VALVE_ACTION_ENUM
{
	VFast = 0,
	VSlow,
	VKeep,
	VUnload,
	VBack,
	VStop,
	JogVFast = 0,
	JogVSlow,
	JogVKeep,
	JogVUnload,
	JogVBack,
	JogVStop
};

enum VALVE_PROCESS
{
	StrokeStart = 0,
	JOGMODE,
	WaitNoFoot,
	WaitFoot,
	CutStart,
	Cutting,
	JudgMode
};

struct CUTPARA//运行时的参数
{
	/************************************/
	volatile uint16	KeepTime;//延时
	volatile uint16	UnloadTime;//延时
	volatile uint16	VATime[2];//延时
	volatile uint8	Action[6];//动作
	/*************************************/
	volatile uint16	Cnt;//剪切时间计数
	volatile uint8 CutStatus;//剪切流程状态
	volatile uint8 CutTimeStatus;//剪切定时状态
	volatile uint16 Version;//点动模式计数
	volatile uint8 ModeRunFlag;
    volatile uint8 ValveNum;
    volatile uint8 SToDotFlag;//单步切换至点动标志
    
    volatile uint8 OneWorkFinshState;
    volatile uint8 PreCutMode;
};

/*************************************************/
extern struct CUTPARA	CutReg;
extern uint8 FootStart_state;
extern uint8 FootUP_state;
extern uint8 Config_Test_Value;
/*************************************************/

void Init_Stroke_Timer(void);
uint8 Stroke_Process(void);
//void MoveLED(uint8 ledtype);
//void EEPROM_Byte_Write(uint16 StartAddr,uint8 byte);
void EEPROM_Array_Write(uint8 *eepromPtr,uint8 *buf,uint16 len);
void EEPROM_Array_Read(uint8 *eepromPtr,uint8 *buf,uint16 len);
uint16 Get_ADvalue(uint8 timetype);
void Wrtie_config(void);
void Valve_config(uint8 valve_config_flag);             //阀组配置
void Sys_Test(void);
void LCD_DISPLAY_MODE();

#endif

/* [] END OF FILE */

/* [] END OF FILE */

/* [] END OF FILE */
