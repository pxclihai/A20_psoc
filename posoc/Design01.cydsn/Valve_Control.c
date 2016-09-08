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
#include "product.h"
#include "TestSlave.h"

#define BIT1 0X01       //KA1
#define BIT2 0X02       //KA2
#define BIT3 0X04       //KA3
#define BIT4 0X08       //KA4
#define BIT5 0X10       //KA5
#define BIT6 0X20       //KA6
#define BIT7 0X40
#define BIT8 0X80

#define KA1_bit     0
#define KA2_bit     1
#define KA3_bit     2
#define KA4_bit     3
#define KA5_bit     4
#define KA6_bit     5

#define INITIAL        0x01
static const uint8 CYCODE Test_Array[1]={0XFF};
static const uint8 CYCODE eepromArray[]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x00,0x00};  //阀组配置初始化值
//static const uint8 CYCODE eepromUnlodeTime = 0;  //阀组配置初始化值
//static const uint8 CYCODE eepromKeepTime   = 0;  //阀组配置初始化值

struct CUTPARA	CutReg;

uint8 LED_Status[]={0x01,0x02,0x04,0x08,0x10,0x20};
uint8 FootStart_state = 0x01;
uint8 FootUP_State    = 0x01;
CY_ISR_PROTO(Stroke_ISRHandle);
uint16 Get_ADvalue(uint8 timetype);

extern int ISR_Stroke_Timer_states;
/**********************************************************
函数名：
功  能：
参  数：无
返回值：无
说明  ：触发中断时间10ms
************************************************************/
void timer_10ms(void)
{
	//Stroke_Timer_STATUS;
//	ISR_Stroke_Timer_ClearPending();
//	if(CutReg.ModeRunFlag == 0x01)
//	{
   ISR_Stroke_Timer_states = 0x00; 
 
   if(((Enter_Start == System_enable)  || ( One_Work_Runing == CutReg.OneWorkFinshState )) && Enter_QUIT != System_enable)   /* 增加动作完成标志20160820 20160825 增加退出停止标志*/
    {
        
		if(CutMode() == CUTSMODE && CutReg.CutTimeStatus < VUnload && (!FootStart()))
		{
			CyDelay(5);
			if(!FootStart())
			{
				ValveOut(CutReg.Action[VBack]);
                LED_WRITE(LED_Status[VBack]);
				CutReg.CutTimeStatus = VBack;
              //CutReg.OneWorkFinshState = One_Work_Runing;   /* 增加动作完成标志20160820*/
			}
		} 
       // 
		switch(CutReg.CutTimeStatus)
		{
		case VFast:
           CutReg.OneWorkFinshState = One_Work_Runing;   /* 增加动作完成标志20160820*/
			if(DownPoint())
			{
				ValveOut(CutReg.Action[VSlow]);
                LED_WRITE(LED_Status[VSlow]);
				CutReg.CutTimeStatus = VSlow;
			}
			else
			{
				ValveOut(CutReg.Action[VFast]);
                LED_WRITE(LED_Status[VFast]);
				CutReg.CutTimeStatus = VFast;
			}
			break;
		case VSlow:
            //  CutReg.OneWorkFinshState = One_Work_Runing;   /* 增加动作完成标志20160820*/
			if(DownPoint())
			{
				ValveOut(CutReg.Action[VKeep]);
                LED_WRITE(LED_Status[VKeep]);
				CutReg.CutTimeStatus = VKeep;
				CutReg.Cnt = 0;
			}
			else
			{
				ValveOut(CutReg.Action[VFast]);
                LED_WRITE(LED_Status[VFast]);
				CutReg.CutTimeStatus = VFast;
			}
			break;
		case VKeep:
           //  CutReg.OneWorkFinshState = One_Work_Runing;   /* 增加动作完成标志20160820*/
			CutReg.Cnt++;
			if(CutReg.Cnt >= CutReg.KeepTime)
			{
				CutReg.Cnt = 0;
				ValveOut(CutReg.Action[VUnload]);
                LED_WRITE(LED_Status[VUnload]);
				CutReg.CutTimeStatus = VUnload;
			}
			else
			{
				ValveOut(CutReg.Action[VKeep]);
                LED_WRITE(LED_Status[VKeep]);
				CutReg.CutTimeStatus = VKeep;
			}
			break;
		case VUnload:
          //    CutReg.OneWorkFinshState = One_Work_Runing;   /* 增加动作完成标志20160820*/
			CutReg.Cnt++;
			if(CutReg.Cnt >= CutReg.UnloadTime)
			{
				CutReg.Cnt = 0;
				ValveOut(CutReg.Action[VBack]);
                LED_WRITE(LED_Status[VBack]);
				CutReg.CutTimeStatus = VBack;
			}
			else
			{
				ValveOut(CutReg.Action[VUnload]);
                LED_WRITE(LED_Status[VUnload]);
				CutReg.CutTimeStatus = VUnload;
			}
			break;
		case VBack:
         //   CutReg.OneWorkFinshState = One_Work_Runing;   /* 增加动作完成标志20160820*/
			if(UpperPoint())
			{
				if(UpperPoint())
				{
					ValveOut(CutReg.Action[VStop]);
                    LED_WRITE(LED_Status[VStop]);
					CutReg.CutTimeStatus = VStop;
					CutReg.Cnt = 0;
                    CutReg.OneWorkFinshState = One_Work_Finish;//完成一次动作标志 20160829移动这里。回到上止点为一次完成标志
				}
			}
			else
			{
				ValveOut(CutReg.Action[VBack]);
                LED_WRITE(LED_Status[VBack]);
				CutReg.CutTimeStatus = VBack;
			}
			break;
		case VStop:
			CutReg.Cnt++;
			if(CutReg.Cnt >= 100  )//
			{
				CutReg.Cnt = 0;
				ISR_Stroke_Timer_states =0x01;
          
				CutReg.CutTimeStatus = VFast;  //结束
            
                CutReg.CutTimeStatus = VStop;
				CutReg.CutStatus = JudgMode;
             
			}
			else
			{
				ValveOut(CutReg.Action[VStop]);
                LED_WRITE(LED_Status[VStop]);
				CutReg.CutTimeStatus = VStop;
                
			}
           
			break;
		default : break;
		}
    }
//	}
//	else if(CutReg.ModeRunFlag == 0x02)//点动
//	{
//		CutReg.Cnt++;
//	}
//	else
//	{
//		CutReg.Cnt++;
//	}

}


/*****************************************************
函数名：uint8 Stroke_Process(void)
功  能：剪切行程控制流程
参  数：无
返回值：无
*****************************************************/
uint8 Stroke_Process(void)
{
	uint8 ModeFlag = 0;
	static int16 UnloadTime = 0;
	ModeFlag = 0;
	
	switch(CutReg.CutStatus)
	{
	case StrokeStart:
		if(CutMode() == CUTCMODE || CutMode() == CUTSMODE)//连续 单次
		{
            CutReg.CutStatus = WaitNoFoot;
		}
		else if(CutMode() == CUTJMODE)//点动
		{
			CutReg.CutStatus = JOGMODE;
		}
        
		break;
	case JOGMODE:
        
		if(CutMode() != CUTJMODE)
		{
			ValveOut(CutReg.Action[VStop]);
            LED_WRITE(LED_Status[VStop]);
			CutReg.CutStatus = StrokeStart;
		}
		else if(FootStart() && FootStart_state)//下
		{
            /* 增加动作完成标志20160820*/
            CutReg.OneWorkFinshState = One_Work_Runing;
			while(FootStart())
			{
//				MoveLED(1);
				if(DownPoint())
				{
					ValveOut(CutReg.Action[VSlow]);
                    LED_WRITE(LED_Status[VSlow]);
					UnloadTime = CutReg.UnloadTime;
				}
				else
				{
					ValveOut(CutReg.Action[VFast]);
                    LED_WRITE(LED_Status[VFast]);
				}
				if(CutMode() != CUTJMODE)
				{
					ValveOut(CutReg.Action[VStop]);
                    LED_WRITE(LED_Status[VStop]);
					CutReg.CutStatus = StrokeStart;
					break;
				}
			}
			ValveOut(CutReg.Action[VStop]);
            LED_WRITE(LED_Status[VStop]);
//			MoveLED(0);
		}
		else if(FootUp() && FootUP_State)//上
		{
			UnloadTime = 0;
			while(FootUp())
			{
//				MoveLED(1);
				if(UpperPoint())
				{
					ValveOut(CutReg.Action[VStop]);
                    LED_WRITE(LED_Status[VStop]);
				}
				else
				{
					ValveOut(CutReg.Action[VBack]);
                    LED_WRITE(LED_Status[VBack]);
				}
				if(CutMode() != CUTJMODE)
				{
					ValveOut(CutReg.Action[VStop]);
                    LED_WRITE(LED_Status[VStop]);
					CutReg.CutStatus = StrokeStart;
					break;
				}
			}
			ValveOut(CutReg.Action[VStop]);
            LED_WRITE(LED_Status[VStop]);
//			MoveLED(0);
		}
			
		if(CutMode() == CUTJMODE && !FootStart() && CutReg.Action[VUnload] != 0 && UnloadTime > 0)
		{
			ValveOut(CutReg.Action[VUnload]);//卸荷			
			UnloadTime -= 1;
			CyDelay(10);
		}
		else
        {
			 ValveOut(CutReg.Action[VStop]);//停止
            /* 增加动作完成标志20160820*/
             CutReg.OneWorkFinshState = One_Work_Finish;
        }
		
		break;
	case WaitNoFoot://读剪切数据
		if(!FootStart())
        {
			CyDelay(5);
			if(!FootStart())
			{
            	CutReg.CutStatus = WaitFoot;
			}
        }
        else
        {
            CutReg.CutStatus = WaitNoFoot;	
        }
		break;
	case WaitFoot: //等待脚踏开关有效信号
		if(FootStart())
		{
			CyDelay(5);
			if(FootStart())
			{                
				CutReg.CutStatus  = CutStart;
                CutReg.SToDotFlag = 0;
			}
		}
		else
		{
			CutReg.CutStatus = WaitFoot;   
            if( CutReg.SToDotFlag && CutMode() == CUTJMODE)
            {
                CutReg.CutStatus = JOGMODE;
            }
		}
		break;
	case CutStart:
//		CutReg.KeepTime = (Get_ADvalue(0) - 900)/2;
//       CutReg.KeepTime = Get_ADvalue(0) - 900;
//		CutReg.UnloadTime = Get_ADvalue(1) - 900;
		CutReg.CutStatus = Cutting;
		CutReg.Cnt = 0;
		CutReg.CutTimeStatus = VFast;
		ISR_Stroke_Timer_states =0x00;
//		MoveLED(1);
		break;
	case Cutting: break;
	case JudgMode://判断 单次/连续
//		MoveLED(0);
		if(CutMode() == CUTCMODE)//连续
		{
			CutReg.CutStatus = CutStart;//回
		}
		else if(CutMode() == CUTSMODE)//单次
		{
			CutReg.CutStatus = WaitNoFoot;
            CutReg.SToDotFlag = 1;
           
		}
		else if(CutMode() == CUTJMODE)//点动
		{
			CutReg.CutStatus = JOGMODE;
            ModeFlag = 1;
		}
		break;
	default : break;
	}
	return ModeFlag;
}

/**********************************************************
函数名：
功  能：
参  数：无
返回值：无
************************************************************/
void EEPROM_Array_Read(uint8 *eepromPtr,uint8 *buf,uint16 len)
{
	reg8 * RegPointer;
	uint16 i;
	
//	RegPointer = (reg8 *)CYDEV_EE_BASE;
    
// RegPointer = eepromPtr;
	for(i = 0; i < len; i++)
	{
		buf[i] = EEPROM_1_ReadByte(i);
	}
}
void EEPROM_Array_Write(uint8 *eepromPtr,uint8 *buf,uint16 len) //没有做越界处理，超过16个字节要分开处理
{
    if(--len)
    EEPROM_1_Write(buf,eepromPtr[0]);
    
}
///**********************************************************
//函数名：
//功  能：
//参  数：无
//返回值：无
//************************************************************/
//void EEPROM_Byte_Write(uint16 StartAddr,uint8 byte)
//{
//	EEPROM_1_ByteWrite(byte, StartAddr/16,StartAddr%16);
//}
/**********************************************************
函数名：
功  能：
参  数：无
返回值：无
************************************************************/
/**********************************************************
函数名：
功  能：
参  数：无
返回值：无
************************************************************/
//void MoveLED(uint8 step)
//{
//	switch(step)
//	{
//	case 0: //快下
//        LED_WRITE(0x01);
//		break;
//	case 1:
//		StopLED_OFF(); 
//		RunLED_FLASH(); 
//		break;
//	default : break;
//	}
//}
/*****************************************************
函数名：void Init_Stroke_Timer(void)
功  能：初始化剪程行程控制时钟定时器
参  数：无
返回值：无
*****************************************************/
void Init_Stroke_Timer(void)
{	
	Clock_1_Start();   
    
    Timer_1_Start();
    
	EEPROM_1_Start();
    
	ISR_Stroke_Timer_Start();
    
    Read_config();

	CutReg.CutStatus = StrokeStart;
	CutReg.ModeRunFlag = 0;
    
    CutReg.ValveNum = 6;
	CutReg.Version = 2000;//V1.001

}


void Valve_config(uint8 valve_config_flag)             //阀组配置
{
    uint8   key_com = 0x03; 
    uint16  key_time = 0;
    enum VALVE_ACTION_ENUM   step_flag  = VFast;            //默认选择“快下”功能
    uint8   valve_flag = 0;                                 //默认未选择阀组
    uint16  delay_num = 0;                                  //阀组指示灯闪烁延时变量
    uint16  delay_num_count = 500;                          //
    uint8     KA_valve = 0;                                   //阀组位状态变量
    uint8     KA_valve_temp = 0;                              //阀组位状态临时变量
    uint8   KA_state_temp = 0;                              //阀组状态临时变量
    uint8   KA_num = 0;                                     //阀组 位 位置
    uint8   valvech_flag = 0;                               //阀组 位 状态修改标志
    
    while(valve_config_flag)
    {
      //  key_com = Read_KeyValue();   //读取按键值
       if(1)                            // if((key_com != Key_Null) && (valvech_flag == 0))
        {
           // switch(key_com)
            {
               // case Key_step:
                {
                    key_time = 0;
                  //  while((Read_KeyValue() == Key_step) && (key_time < 40) )
                    {
                        key_time ++;
                        CyDelay(1);
                    }
                    if(key_time >= 39)                          //长按
                    {
                       
                        EEPROM_Array_Write(eepromArray,CutReg.Action,6);  //保存配置
                        LED_WRITE(0X00);
                        CyDelay(500);                                     //退出指示
                        ValveOut(0X3F);
                        CyDelay(500);
                        ValveOut(0X00);
                        CyDelay(500);
                        ValveOut(0X3F);
                        CyDelay(500);
                        ValveOut(0X00);
                        valve_config_flag = 0;                  //配置标志清零(保存退出)
//                        CySoftwareReset();                      //系统软复位            
                    }
                    else                                        //短按
                    {
                        if(valve_flag == 0)                     //未配置才进行功能步骤切换
                        {
                            if(++step_flag == (VStop+1))
                                step_flag = VFast;
                        }
                        else
                        {
                            valve_flag = 0;                     //清除显示状态标志
                        }
                        ValveOut(CutReg.Action[step_flag]);     //显示当前阀组配置状态      
                        switch(step_flag)
                        {
                            case    VFast:                      //快下
                            {
                                LED_WRITE(LED_Status[VFast]);
                            }
                            break;
                            case    VSlow:                      //工进
                            {
                                LED_WRITE(LED_Status[VSlow]);
                            }
                            break;
                            case    VKeep:                      //保压
                            {
                                LED_WRITE(LED_Status[VKeep]);
                            }
                            break;
                            case    VUnload:                    //卸荷
                            {
                                LED_WRITE(LED_Status[VUnload]);
                            }
                            break;
                            case    VBack:                      //回程
                            {
                                LED_WRITE(LED_Status[VBack]);
                            }
                            break;
                            case    VStop:                      //停止
                            {
                                LED_WRITE(LED_Status[VStop]);
                            }
                            break;
                            default:
                            break;
                        }
                    }
                }
                break;
             //   case Key_valve:
                {
                    key_time = 0;
               //     while((Read_KeyValue() == Key_valve) && (key_time < 40) )
                    {
                        key_time ++; 
                        CyDelay(1);
                    }              
                    if((key_time >= 39) && (valvech_flag == 0))                             //长按
                    {
                        if( (valve_flag >= 1) && (valve_flag <= 6) )
                        {
                            KA_valve = (~ KA_valve) & 0x01;
                            CutReg.Action[step_flag] = ((CutReg.Action[step_flag] & (~(1 << KA_num))) | (((uint8)KA_valve) << KA_num)) ;
                            ValveOut(CutReg.Action[step_flag]);
                            valvech_flag = 1;
                        } 
                        if(valve_flag == 0)                                                 //未选中状态下长按也进行选中切换
                        {
                            valvech_flag = 1;
                        }
                    }
                    
                    if((key_time < 49) || (valvech_flag == 1))                              //短按或者阀组值被修改时进行阀组位切换
                    {
                        if((++valve_flag) == 7)
                            valve_flag = 1;
                        
                        switch(valve_flag)
                        {
                            case    1:                  //KA1
                            {
                                KA_num = KA1_bit;
                                KA_valve = ((CutReg.Action[step_flag] >> KA_num) & 0X01);    //得到当前阀位状态
                                KA_valve_temp = KA_valve;
                                
                                ValveOut(CutReg.Action[step_flag] | BIT1);                   //点亮选中阀位置指示灯                             
                            }
                            break;
                            case    2:                  //KA2
                            {
                                KA_num = KA2_bit;
                                KA_valve = ((CutReg.Action[step_flag] >> KA_num) & 0X01);    //得到当前阀位状态;
                                KA_valve_temp = KA_valve;
                                
                                ValveOut(CutReg.Action[step_flag] | BIT2);
                            }
                            break;
                            case    3:                  //KA3
                            {
                                KA_num = KA3_bit;
                                KA_valve = ((CutReg.Action[step_flag] >> KA_num) & 0X01);    //得到当前阀位状态;
                                KA_valve_temp = KA_valve;
                                
                                ValveOut(CutReg.Action[step_flag] | BIT3);
                            }
                            break;
                            case    4:                  //KA4
                            {
                                KA_num = KA4_bit;
                                KA_valve = ((CutReg.Action[step_flag] >> KA_num) & 0X01);    //得到当前阀位状态;
                                KA_valve_temp = KA_valve;
                                
                                ValveOut(CutReg.Action[step_flag] | BIT4);
                            }
                            break;
                            case    5:                  //KA5
                            {
                                KA_num = KA5_bit;
                                KA_valve = ((CutReg.Action[step_flag] >> KA_num) & 0X01);    //得到当前阀位状态;
                                KA_valve_temp = KA_valve;
                                
                                ValveOut(CutReg.Action[step_flag] | BIT5);
                            }
                            break;
                            case    6:                  //KA6
                            {
                                KA_num = KA6_bit;
                                KA_valve = ((CutReg.Action[step_flag] >> KA_num) & 0X01);    //得到当前阀位状态;
                                KA_valve_temp = KA_valve;
                                
                                ValveOut(CutReg.Action[step_flag] | BIT6);
                            }
                            break;
                        }
                    }    
                }
                break;
            }
        }
        else
        {
            if(1)//if(key_com == Key_Null)             //无按键按下时将阀组修改标志清0
            {
                valvech_flag = 0;
                delay_num_count = 400;
            }    
            else
                delay_num_count = 8;

            if( (valve_flag >= 1) && (valve_flag <= 6) )//选中阀组时相应位指示灯闪烁控制
            {
                delay_num  ++;
                if(delay_num >= delay_num_count)
                {                            
                    delay_num = 0;
                    KA_valve_temp = (~ KA_valve_temp)&0x01;                                              //当前位置阀组指示灯取反
                    KA_state_temp = ((CutReg.Action[step_flag] & (~(1 << KA_num))) | (((uint8)KA_valve_temp) << KA_num)) ;
                    ValveOut(KA_state_temp);
                }  
                CyDelay(1);
            }
            else
            {
                delay_num = 0;
            }
            
        }      
    }
}
void Read_config(void)
{
        uint8 tempBuf[sizeof(config_para)-1] ;
        EEPROM_Array_Read(eepromArray,tempBuf,sizeof(tempBuf));//读阀组配置
        memcpy(&config_para,tempBuf,sizeof(tempBuf));//----注意大小
        CutReg.Action[VFast]   =   config_para.Config_VFast;
        CutReg.Action[VSlow]   =   config_para.Config_VSlow;
        CutReg.Action[VKeep]   =   config_para.Config_VKeep;
        CutReg.Action[VUnload] =   config_para.Config_VUnload;
        CutReg.Action[VBack]   =   config_para.Config_VBack;
        CutReg.Action[VStop]   =   config_para.Config_VStop;
        CutReg.KeepTime        =   config_para.Config_KeepTime;
        CutReg.UnloadTime      =   config_para.Config_UnloadTime;


}
void Write_config(void)
{
           uint8 tempBuf[sizeof(config_para)-1];
           memcpy(tempBuf,(&config_para),sizeof(config_para)-1);        
           EEPROM_Array_Write(eepromArray,tempBuf,sizeof(tempBuf));
        CutReg.Action[VFast]   =   config_para.Config_VFast;
        CutReg.Action[VSlow]   =   config_para.Config_VSlow;
        CutReg.Action[VKeep]   =   config_para.Config_VKeep;
        CutReg.Action[VUnload] =   config_para.Config_VUnload;
        CutReg.Action[VBack]   =   config_para.Config_VBack;
        CutReg.Action[VStop]   =   config_para.Config_VStop;
        CutReg.KeepTime        =   config_para.Config_KeepTime;
        CutReg.UnloadTime      =   config_para.Config_UnloadTime;
           
}
static lastValue = 0;
void LCD_DISPLAY(uint8 value)
{
    if(lastValue != value)
    {
        LCD_Char_1_WriteControl(0x01);
        lastValue = value;
    }
    if(value == LED_Status[VFast] )
    {
       LCD_Char_1_Position(0,2) ;
       LCD_Char_1_PrintString("Fast");
    }
    else if(value == LED_Status[VSlow] )
    {
          LCD_Char_1_Position(0,2) ;
       LCD_Char_1_PrintString("Slow");
    }
       else if(value == LED_Status[VKeep] )
    {
        LCD_Char_1_Position(0,2) ;
       LCD_Char_1_PrintString("Keep");
    }
       else if(value == LED_Status[VUnload] )
    {
          LCD_Char_1_Position(0,1) ;
       LCD_Char_1_PrintString("Unload");
    }
       else if(value == LED_Status[VStop] )
    {
          LCD_Char_1_Position(0,2) ;
          LCD_Char_1_PrintString("Stop");
    }
         else if(value == LED_Status[VBack] )
    {
          LCD_Char_1_Position(0,2) ;
          LCD_Char_1_PrintString("Back");
    }
    else
    {
        LCD_Char_1_Position(0,2) ;
          LCD_Char_1_PrintString("Error");
    }
    
}
/* [] END OF FILE */
