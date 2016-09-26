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
#include <ISR_Stroke_Timer.h>
#include "TestSlave.h"
#include "canfestival.h"
#include "CanopenDictConfig.h"
#include "TLC5616.h"
#include "Valve_Control.h"
#define CAN_RTR_DATA     ((unsigned int )0x00000000)
#define CAN_RTR_REMOTE   ((unsigned int )0x00000002)
#define CAN_ID_STD       ((unsigned int) 0x00000000)
extern int ISR_Stroke_Timer_states;
extern uint8 const CYCODE LCD_Char_1_customFonts[];
uint8  key_count = 0;


unsigned char  receiveData[8]; 

CAN_1_TX_MSG CAN_message;     /* Declares Data as structure variable of type DATA_BYTES_MSG */  

CAN_1_DATA_BYTES_MSG Data;

unsigned char receiveData[8]; 



unsigned char canSend(CAN_PORT notused, Message *m)
{
    uint32_t i,index;
    CanTxMsg TxMessage;
    CanTxMsg *ptx_msg=&TxMessage;
    ptx_msg->StdId = m->cob_id;

    ptx_msg->RTR = CAN_RTR_DATA;

    ptx_msg->IDE = CAN_ID_STD;

    ptx_msg->DLC = m->len;
    for(i = 0; i < m->len; i++)
    ptx_msg->Data[i] = m->data[i];

    CAN_message.dlc = ptx_msg->DLC;
            
    CAN_message.id =  ptx_msg->StdId;
            
    CAN_message.ide= ptx_msg->IDE;
            
    for (index=0;index<CAN_message.dlc ;index++)
    {
       receiveData[index] =ptx_msg->Data[index]  ; 
    }
            
    for(index=0;index<CAN_message.dlc ;index++)
    {   
        Data.byte[index] = receiveData[index];
    }
    CAN_1_SendMsg(&CAN_message);
    
    return 0;           
}



int main()
{
    
    Init_Stroke_Timer(); 
    Init_TLC5616();
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
    
    LCD_Char_1_Init();
    LCD_Char_1_LoadCustomFonts(LCD_Char_1_customFonts) ; 
    
    CAN_1_Start();   
    CanopenInit();
    CyDelay(100); 
    CutReg.SToDotFlag = 0;
    
    Control_LED_Write(5);
    ValveOut(CutReg.Action[VStop]);
    LED_WRITE(LED_Status[VStop]);
    
    TLC5616_Write(1,1023);

    /////////////ceshi fucha//////////////
    CutReg.Action[VFast]   =   0x01;
    CutReg.Action[VSlow]   =   0x01;
    CutReg.Action[VKeep]   =   0x01;
    CutReg.Action[VUnload] =   0x00;
    CutReg.Action[VBack]   =   0x02;
    CutReg.Action[VStop]   =   0x00;
    CutReg.KeepTime        =   600;
    CutReg.UnloadTime      =   500;  
    /////////////////////////////////////////
 // while(1);
   config_para.isConfig_para_state = 0;
    for(;;)
    {    
        //增加了 配置回复模式 如果开始没有在上止点就进入此模式
         if(config_para.isConfig_para_state == EnterConfig )
         { 
       //    LED_WRITE(0X01);                          //进入阀组配置状态后默认显示“快下”模式下状态
       //     ValveOut(CutReg.Action[VFast]);     
            Write_config();
            config_para.isConfig_para_state =  FinsihConfig;
         }
        if(!PumpSignal())
		{
			ISR_Stroke_Timer_states = 0x01;
			CutReg.CutStatus = StrokeStart;
			CutReg.ModeRunFlag = 0;
            
            LED_WRITE(LED_Status[VStop]);
            
            CutReg.Cnt = 0;
			CutReg.CutTimeStatus = VFast;   //结束  
		}
        
		else if((System_enable == Enter_Start ||System_enable == Enter_CUTJMODE || CutReg.OneWorkFinshState == One_Work_Runing)&& System_enable != Enter_QUIT)
		{
			Stroke_Process();
		}
        
        if(System_enable == Enter_QUIT) //停止一切活动20160825*/
        {
            ValveOut(CutReg.Action[VStop]); 
            CutReg.OneWorkFinshState = One_Work_Finish;
            FootStart_state=0x01;
            CutReg.CutStatus = StrokeStart;
            CutReg.CutTimeStatus = VStop;
        }
        if(System_enable == Enter_return)/*20160825进入回复模式*/
        {
           FootStart_state = 0x00;                   //不允许往下只能回到上止点
           CutReg.CutTimeStatus = VStop;
           CutReg.CutStatus = JOGMODE;
           CutReg.OneWorkFinshState = One_Work_Runing; 
        }
        
        if(System_enable == Enter_Start)
        {
            FootStart_state = 0x01;
        }
        if(System_enable == Enter_Config_Test)
        {
            ValveOut(Config_Test_Value);
//            switch(Config_Test_Value)
//            {
//                case 0x31: ValveOut(Config_Test_Value); break;
//                case 0x32: ValveOut(Config_Test_Value); break;
//                case 0x33: ValveOut(Config_Test_Value); break;
//                case 0x34: ValveOut(Config_Test_Value); break;
//                case 0x35: ValveOut(Config_Test_Value); break;
//                case 0x36: ValveOut(Config_Test_Value); break;
//                case 0x36: ValveOut(Config_Test_Value); break;
//                default
//            }
            
        }
        else if(System_enable == Quit_Config_Test)
        {
            Config_Test_Value = 0x00;
            ValveOut(Config_Test_Value);
        }
        
    }
}


/* [] END OF FILE */
