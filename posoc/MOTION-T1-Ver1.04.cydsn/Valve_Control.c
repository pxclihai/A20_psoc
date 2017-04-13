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
static lastValue = 0xFF;
static lastMode  = 0xFF;
CY_ISR_PROTO(Stroke_ISRHandle);
uint16 Get_ADvalue(uint8 timetype);
void Read_config(void);
void LCD_DISPLAY(uint8 value);
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
 
   if(((Enter_Start == System_enable) ||(Enter_CUTJMODE != System_enable) || ( One_Work_Runing == CutReg.OneWorkFinshState && System_enable != Enter_return )) && Enter_QUIT != System_enable)   /* 增加动作完成标志20160820 20160825 增加退出停止标志*/
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
           Read_config();
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
		if((CutMode() == CUTCMODE || CutMode() == CUTSMODE) && Enter_CUTJMODE == System_enable)
		{
            CutReg.CutStatus = StrokeStart;
		}
        else if((CutMode() == CUTCMODE || CutMode() == CUTSMODE) && Enter_CUTJMODE != System_enable)//连续 单次
		{
            CutReg.CutStatus = WaitNoFoot;
		}
		else if(CutMode() == CUTJMODE)//点动
		{
			CutReg.CutStatus = JOGMODE;
		}
        if(System_enable == Enter_return)
        {
            CutReg.CutStatus = JOGMODE;
        }
		break;
	case JOGMODE:
        
		if((CutMode() != CUTJMODE)&& System_enable != Enter_return)
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
		}
		else if(FootUp() && FootUP_State)//上
		{
			UnloadTime = 0;
			while(FootUp())
			{
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
				if(CutMode() != CUTJMODE && System_enable != Enter_return)
				{
					ValveOut(CutReg.Action[VStop]);
                    LED_WRITE(LED_Status[VStop]);
					CutReg.CutStatus = StrokeStart;
					break;
				}
			}
			ValveOut(CutReg.Action[VStop]);
            LED_WRITE(LED_Status[VStop]);

		}
			
		if(CutMode() == CUTJMODE && !FootStart() && CutReg.Action[VUnload] != 0 && UnloadTime > 0)
		{
			ValveOut(CutReg.Action[VUnload]);//卸荷	
            LED_WRITE(LED_Status[VUnload]);
          
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
        
        if(CutMode() != CutReg.PreCutMode)
        {
            if(CutMode() == CUTJMODE )
            {
                CutReg.CutStatus = JOGMODE;//防止连续切换状态的时候
                break;
            }
        }
        CutReg.PreCutMode = CutMode();
        
    	if(!FootStart() || ( !FootUp()&& CutMode()!=CUTCMODE) )
        {
            
			CyDelay(5);
			if(!FootStart() || ( !FootUp()&& CutMode()!=CUTCMODE) )
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
        if(CutMode() != CutReg.PreCutMode)
        {
            if(CutMode() == CUTJMODE )
            {
                CutReg.CutStatus = JOGMODE;//防止连续切换状态的时候
                break;
            }
        }
        CutReg.PreCutMode = CutMode();
        
    
		if(FootStart()|| (FootUp()&& CutMode() ==CUTCMODE) )
		{
			CyDelay(5);
			if(FootStart()|| (FootUp()&& CutMode() ==CUTCMODE) )
			{   
                if(FootStart())  
                {
                    CutReg.CutTimeStatus = VFast;
                }
                else if(FootUp())
                {
                    CutReg.CutTimeStatus = VBack;
                }
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

		CutReg.CutStatus = Cutting;
		CutReg.Cnt = 0;
		//CutReg.CutTimeStatus = VFast;
		ISR_Stroke_Timer_states = 0x00;
        
		break;
	case Cutting: break;
        
	case JudgMode://判断 单次/连续

		if(CutMode() == CUTCMODE)//连续
		{
            CyDelay(5);
            if(CutMode() == CUTCMODE)//连续
		    {
		    	CutReg.CutStatus = CutStart;//回
            }
		
		}
		else if(CutMode() == CUTSMODE)//单次
		{
               CyDelay(5);
            if(CutMode() == CUTSMODE)//单次
            {
    			CutReg.CutStatus = WaitNoFoot;
                CutReg.SToDotFlag = 1;         
            }
           
		}
		else if(CutMode() == CUTJMODE)//点动
		{
            CyDelay(5);
            if(CutMode() == CUTJMODE)//单次
            {
    			CutReg.CutStatus = JOGMODE;
                ModeFlag = 1;
            }
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

void LCD_DISPLAY(uint8 value)
{
    
    if(lastValue != value)
    {
        //LCD_Char_1_WriteControl(0x01);
        lastValue = value;
    }

    else 
    {
        return;
    }
    if(value == LED_Status[VFast] )
    {
       LCD_Char_1_Position(1,0) ;
       LCD_Char_1_PrintString("  Fast  ");
    }
    else if(value == LED_Status[VSlow] )
    {
        LCD_Char_1_Position(1,0) ;
        LCD_Char_1_PrintString("  Slow  ");
    }
       else if(value == LED_Status[VKeep] )
    {
        LCD_Char_1_Position(1,0) ;
        LCD_Char_1_PrintString("  Keep  ");
    }
       else if(value == LED_Status[VUnload] )
    {
        LCD_Char_1_Position(1,0) ;
        LCD_Char_1_PrintString(" Unload");
    }
       else if(value == LED_Status[VStop] )
    {
        LCD_Char_1_Position(1,0) ;
        LCD_Char_1_PrintString("  Stop  ");
    }
         else if(value == LED_Status[VBack] )
    {
        LCD_Char_1_Position(1,0) ;
        LCD_Char_1_PrintString("  Back  ");
    }
    else
    {
        LCD_Char_1_Position(1,0) ;
        LCD_Char_1_PrintString("  Error ");
    } 

}
void LCD_DISPLAY_MODE()
{
    if(lastMode  != CutMode())
    {
    //LCD_Char_1_WriteControl(0x01);
      lastMode = CutMode();
    }
    else 
    {
        return;
    }
    if(CutMode() == CUTCMODE)
    {
        LCD_Char_1_Position(0,1) ;
        LCD_Char_1_PrintString("C-MODE");
    }
    else if(CutMode() == CUTJMODE)
    {
        LCD_Char_1_Position(0,1) ;
        LCD_Char_1_PrintString("J-MODE");
    }
    else if(CutMode() == CUTSMODE)
    {
        LCD_Char_1_Position(0,1) ;
        LCD_Char_1_PrintString("S-MODE");
    }
    else 
    {
        LCD_Char_1_Position(0,1);
        LCD_Char_1_PrintString("UNKNOWN");
    }
}
/* [] END OF FILE */
