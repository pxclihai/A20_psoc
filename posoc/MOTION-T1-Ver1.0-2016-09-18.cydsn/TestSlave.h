
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef TESTSLAVE_H
#define TESTSLAVE_H

#include "data.h"
    
extern UNS8 TPDO_IN_Status;
extern UNS8 TPDO_PROCESS_Status;
extern UNS8 System_enable;
struct Config_para
{
   
    UNS8 Config_VFast ; 
    UNS8 Config_VSlow ;  
    UNS8 Config_VKeep ; 
    UNS8 Config_VUnload;
    UNS8 Config_VBack  ;
    UNS8 Config_VStop  ;
    UNS16 Config_KeepTime;
    UNS16 Config_UnloadTime;
    UNS8 isConfig_para_state;
    UNS8 isConfig_para_state_2;
};
extern struct Config_para config_para;
/* Prototypes of function provided by object dictionnary */
UNS32 TestSlave_valueRangeTest (UNS8 typeValue, void * value);
const indextable * TestSlave_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks);

/* Master node data struct */
extern CO_Data TestSlave_Data;
extern UNS8 SlaveMap1;		/* Mapped at index 0x2000, subindex 0x00*/
extern UNS8 SlaveMap2;		/* Mapped at index 0x2001, subindex 0x00*/
extern UNS8 SlaveMap3;		/* Mapped at index 0x2002, subindex 0x00*/
extern UNS8 SlaveMap4;		/* Mapped at index 0x2003, subindex 0x00*/
extern UNS8 SlaveMap5;		/* Mapped at index 0x2004, subindex 0x00*/
extern UNS8 SlaveMap6;		/* Mapped at index 0x2005, subindex 0x00*/
extern UNS8 SlaveMap7;		/* Mapped at index 0x2006, subindex 0x00*/
extern UNS8 SlaveMap8;		/* Mapped at index 0x2007, subindex 0x00*/
extern UNS8 SlaveMap9;		/* Mapped at index 0x2008, subindex 0x00*/
extern UNS32 SlaveMap10;		/* Mapped at index 0x2009, subindex 0x00*/
extern UNS16 SlaveMap11;		/* Mapped at index 0x200A, subindex 0x00*/
extern INTEGER16 SlaveMap12;		/* Mapped at index 0x200B, subindex 0x00*/
extern INTEGER16 SlaveMap13;		/* Mapped at index 0x200C, subindex 0x00*/

#endif // TESTSLAVE_H
