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
#include "canfestival.h"


unsigned int TimeCNT=0;//时间计数
unsigned int NextTime=0;//下一次触发时间计数
unsigned int TIMER_MAX_COUNT=70000;//最大时间计数
static TIMEVAL last_time_set = TIMEVAL_MAX;//上一次的时间计数



#define CAN_RTR_DATA     ((unsigned int )0x00000000)
#define CAN_RTR_REMOTE   ((unsigned int )0x00000002)
#define CAN_ID_STD       ((unsigned int)0x00000000)


void setTimer(TIMEVAL value)
{
    NextTime=TimeCNT+value;
}
TIMEVAL getElapsedTime(void)
{
        int ret=0;
      //  ret = TimeCNT> last_time_set ? TimeCNT - last_time_set : TimeCNT + TIMER_MAX_COUNT - last_time_set;
        ret = TimeCNT> last_time_set ? TimeCNT - last_time_set :   last_time_set - TimeCNT ;
        last_time_set = TimeCNT;
        return ret;
}
void timerForCan()
{
        
        if (TimeCNT>=TIMER_MAX_COUNT)
        {
                TimeCNT=0;
        }
        if (TimeCNT==NextTime)
        {
                TimeDispatch();
        }
        TimeCNT++;
}




