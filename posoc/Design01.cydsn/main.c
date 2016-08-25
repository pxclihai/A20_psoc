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


#define CAN_RTR_DATA     ((unsigned int )0x00000000)
#define CAN_RTR_REMOTE   ((unsigned int )0x00000002)
#define CAN_ID_STD       ((unsigned int)0x00000000)
extern int ISR_Stroke_Timer_states;

uint8  key_count = 0;
//typedef struct
//{
//  uint32_t StdId;  /*!< Specifies the standard identifier.
//                        This parameter can be a value between 0 to 0x7FF. */
//
//  uint32_t ExtId;  /*!< Specifies the extended identifier.
//                        This parameter can be a value between 0 to 0x1FFFFFFF. */
//
//  uint8_t IDE;     /*!< Specifies the type of identifier for the message that
//                        will be transmitted. This parameter can be a value
//                        of @ref CAN_identifier_type */
//
//  uint8_t RTR;     /*!< Specifies the type of frame for the message that will
//                        be transmitted. This parameter can be a value of
//                        @ref CAN_remote_transmission_request */
//
//  uint8_t DLC;     /*!< Specifies the length of the frame that will be
//                        transmitted. This parameter can be a value between
//                        0 to 8 */
//
//  uint8_t Data[8]; /*!< Contains the data to be transmitted. It ranges from 0
//                        to 0xFF. */
//} CanTxMsg;
//
//typedef struct
//{
//  uint32_t StdId;  /*!< Specifies the standard identifier.
//                        This parameter can be a value between 0 to 0x7FF. */
//
//  uint32_t ExtId;  /*!< Specifies the extended identifier.
//                        This parameter can be a value between 0 to 0x1FFFFFFF. */
//
//  uint8_t IDE;     /*!< Specifies the type of identifier for the message that
//                        will be received. This parameter can be a value of
//                        @ref CAN_identifier_type */
//
//  uint8_t RTR;     /*!< Specifies the type of frame for the received message.
//                        This parameter can be a value of
//                        @ref CAN_remote_transmission_request */
//
//  uint8_t DLC;     /*!< Specifies the length of the frame that will be received.
//                        This parameter can be a value between 0 to 8 */
//
//  uint8_t Data[8]; /*!< Contains the data to be received. It ranges from 0 to
//                        0xFF. */
//
//  uint8_t FMI;     /*!< Specifies the index of the filter the message stored in
//                        the mailbox passes through. This parameter can be a
//                        value between 0 to 0xFF */
//} CanRxMsg;

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
    
    /* Enable global interrupts. */
    CyGlobalIntEnable; 
    CAN_1_Start();    
//    
//    setNodeId(&TestSlave_Data, nodeID);	
//	setState(&TestSlave_Data, Initialisation);
//   CyGlobalIntEnable; 
    CanopenInit();
    
   
//    
//   /* 说明：原A2O上机初始化双击按键程序 */
 
    
    CyDelay(100);
   
   //  Valve_config(1);
    
   
    CutReg.SToDotFlag = 0;
    
    Control_LED_Write(5);
    
    ValveOut(CutReg.Action[VStop]);

    

    
    /////////////ceshi fucha//////////////
    CutReg.Action[VFast]   =   0x01;
    CutReg.Action[VSlow]   =   0x01;
    CutReg.Action[VKeep]   =   0x01;
    CutReg.Action[VUnload] =   0x00;
    CutReg.Action[VBack]   =   0x02;
    CutReg.Action[VStop]   =   0x00;
    CutReg.KeepTime        =   500;
    CutReg.UnloadTime      =   500;
    /////////////////////////////////////////
    for(;;)
    { 
         if(config_para.isConfig_para_state == EnterConfig &&!PumpSignal())
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

            LED_WRITE(0x20);
          
            
            CutReg.Cnt = 0;
			CutReg.CutTimeStatus = VFast;   //结束  
		}
        
		else if((System_enable == Enter_Start || CutReg.OneWorkFinshState == One_Work_Runing)&& System_enable != Enter_QUIT)
		{
			Stroke_Process();
		}
        
        if(System_enable == Enter_QUIT) //停止一切活动20160825*/
        {
           ValveOut(CutReg.Action[VStop]); 
            CutReg.OneWorkFinshState = One_Work_Finish;
           
        }
        if(System_enable == Enter_return)/*20160825进入回复模式*/
        {
           FootStart_state = 0x00;                   //不允许往下只能回到上止点
           CutReg.CutTimeStatus = VBack;
           CutReg.OneWorkFinshState = One_Work_Runing;
        }
        if(System_enable == Enter_Start)
        {
            FootStart_state = 0x01;
        }
    }
}

/* [] END OF FILE */
