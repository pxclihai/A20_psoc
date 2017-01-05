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
uint8 test_count;
uint8 test_pin ;
uint8 mode_dis_cur;
uint8 mode_dis_pre;
extern uint8 Dis_time_flag;
extern int Dis_Step ;
extern uint8 Dis_time_flag;
extern int Dis_content ;
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
    LCD_Char_1_Init();
    LCD_Char_1_LoadCustomFonts(LCD_Char_1_customFonts) ; 
    CyDelay(20); 
    /* Enable global interrupts. */
    LCD_Char_1_Position(0,0) ;
    LCD_Char_1_PrintString("StartUp");
    LCD_Char_1_Position(1,0) ;
    LCD_Char_1_PrintString("Ver-1.02");
    CyDelay(800); 
    LCD_Char_1_WriteData(0x01);
    CyGlobalIntEnable; 
    
    CAN_1_Start();   
    CanopenInit();
    CyDelay(100); 
    CutReg.SToDotFlag = 0;
    
    Control_LED_Write(5);
    ValveOut(CutReg.Action[VStop]);
    LED_WRITE(LED_Status[VStop]);
   
//    TLC5616_Write(1,1023);

///////////////////ceshi fucha//////////////
//    CutReg.Action[VFast]   =   0x01;
//    CutReg.Action[VSlow]   =   0x01;
//    CutReg.Action[VKeep]   =   0x01;
//    CutReg.Action[VUnload] =   0x00;
//    CutReg.Action[VBack]   =   0x02;
//    CutReg.Action[VStop]   =   0x00;
//    CutReg.KeepTime        =   600;
//    CutReg.UnloadTime      =   500;  
/////////////////////////////////////////////
    config_para.isConfig_para_state = 0;
    
  //   System_enable = Enter_Start;
    for(;;)
    {    
        //增加了 配置回复模式 如果开始没有在上止点就进入此模式
        if(config_para.isConfig_para_state ==  EnterConfig )
         { 
            Write_config();
            config_para.isConfig_para_state =  FinsihConfig;
            mode_dis_pre = 0;
         }

        if(!PumpSignal())
		{
			ISR_Stroke_Timer_states = 0x01;
			CutReg.CutStatus = StrokeStart;
			CutReg.ModeRunFlag = 0;
            
            LED_WRITE(LED_Status[VStop]);
            
            CutReg.Cnt = 0;
			CutReg.CutTimeStatus = VFast;   //结束  
              mode_dis_pre = 1;
		}
		else if((System_enable == Enter_Start ||System_enable == Enter_CUTJMODE || CutReg.OneWorkFinshState == One_Work_Runing)&& System_enable != Enter_QUIT)
		{
			Stroke_Process();
             mode_dis_pre = 2;
		}
        
        if(System_enable == Enter_QUIT) //停止一切活动20160825*/
        {
            ValveOut(CutReg.Action[VStop]); 
            CutReg.OneWorkFinshState = One_Work_Finish;
            FootStart_state=0x01;
            CutReg.CutStatus = StrokeStart;
            CutReg.CutTimeStatus = VStop;
            ISR_Stroke_Timer_states = 0x01;
            mode_dis_pre = 3;
     
        }
        if(System_enable == Enter_return)/*20160825进入回复模式*/
        {
           FootStart_state = 0x00;                   //不允许往下只能回到上止点
           CutReg.CutTimeStatus = VStop;
           CutReg.CutStatus = JOGMODE;
           CutReg.OneWorkFinshState = One_Work_Runing;
           mode_dis_pre = 4;
        }
        if(System_enable == Enter_Start)
        {
            FootStart_state = 0x01;
            mode_dis_pre = 5;
        }
        if(System_enable == Enter_Config_Test)
        {
            ValveOut(Config_Test_Value);  
            mode_dis_pre = 6;
        }
        else if(System_enable == Quit_Config_Test)
        {
            Config_Test_Value = 0x00;
            ValveOut(Config_Test_Value);
            mode_dis_pre = 7;
        }
   //     test_pin = test_Read();
//        
//        if(test_pin == 0 )
//        {
//            CyDelay(500);
//            if(test_count == 0)
//            {
//                
//                System_enable = Enter_Start;
//                test_count = 1;
//                LCD_Char_1_Position(1,0) ;
//                LCD_Char_1_PrintString("ON");
//                CyDelay(500);
//            }
//            else
//            {
//                test_count =0;
//                System_enable = Enter_QUIT;
//                    test_count = 1;
//                LCD_Char_1_Position(1,0) ;
//               LCD_Char_1_PrintString("OF");
//             CyDelay(500);
//            }
//           
  //      }
        ///
        if(mode_dis_pre != mode_dis_cur)
        {
           switch(mode_dis_pre)
           {
            case 0 :            {LCD_Char_1_Position(1,0) ; LCD_Char_1_PrintString("0");break;}
            case 1 :            {LCD_Char_1_Position(1,0) ; LCD_Char_1_PrintString("1");break;}
            case 2 :            {LCD_Char_1_Position(1,0) ; LCD_Char_1_PrintString("2");break;}
            case 3 :            {LCD_Char_1_Position(1,0) ; LCD_Char_1_PrintString("3");break;}
            case 4 :            {LCD_Char_1_Position(1,0) ; LCD_Char_1_PrintString("4");break;}
            case 5 :            {LCD_Char_1_Position(1,0) ; LCD_Char_1_PrintString("5");break;}
            case 6 :            {LCD_Char_1_Position(1,0) ; LCD_Char_1_PrintString("6");break;}
            case 7 :            {LCD_Char_1_Position(1,0) ; LCD_Char_1_PrintString("7");break;}
           }
            mode_dis_cur = mode_dis_pre;
        }
        if(Dis_time_flag == 1)
        {       Dis_Step++;
            switch(Dis_Step)
        {
            case 0:Dis_content = LCD_Char_1_CUSTOM_0; break;
            case 1:Dis_content = LCD_Char_1_CUSTOM_1; break;
            case 2:Dis_content = LCD_Char_1_CUSTOM_2; break;
            case 3:Dis_content = LCD_Char_1_CUSTOM_3; break;
            case 4:Dis_content = LCD_Char_1_CUSTOM_4; break;
            case 5:Dis_content = LCD_Char_1_CUSTOM_5; break;
            case 6:Dis_content = LCD_Char_1_CUSTOM_6; break;
            case 7:Dis_content = LCD_Char_1_CUSTOM_7; Dis_Step = 0;break;
        }
        LCD_Char_1_Position(0,0);                                                                //Row = 0,Col = 6
        LCD_Char_1_PutChar(Dis_content) ;  
        LCD_DISPLAY_MODE();
       Dis_time_flag = 0;
        }
     
    }
}


/* [] END OF FILE */
