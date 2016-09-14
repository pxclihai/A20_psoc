/*******************************************************************************
* File Name: KeyScanTimer_1.h
* Version 2.50
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_30_KeyScanTimer_1_H)
#define CY_Timer_v2_30_KeyScanTimer_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 KeyScanTimer_1_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define KeyScanTimer_1_Resolution                 8u
#define KeyScanTimer_1_UsingFixedFunction         0u
#define KeyScanTimer_1_UsingHWCaptureCounter      0u
#define KeyScanTimer_1_SoftwareCaptureMode        0u
#define KeyScanTimer_1_SoftwareTriggerMode        0u
#define KeyScanTimer_1_UsingHWEnable              0u
#define KeyScanTimer_1_EnableTriggerMode          0u
#define KeyScanTimer_1_InterruptOnCaptureCount    0u
#define KeyScanTimer_1_RunModeUsed                0u
#define KeyScanTimer_1_ControlRegRemoved          0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!KeyScanTimer_1_UsingFixedFunction)
        #if (CY_UDB_V0)
            uint8 TimerUdb;                 /* Timer internal counter value */
            uint8 TimerPeriod;              /* Timer Period value       */
            uint8 InterruptMaskValue;       /* Timer Compare Value */
            #if (KeyScanTimer_1_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;  /* Timer Capture Counter Value */
            #endif /* variable declaration for backing up Capture Counter value*/
        #endif /* variables for non retention registers in CY_UDB_V0 */

        #if (CY_UDB_V1)
            uint8 TimerUdb;
            uint8 InterruptMaskValue;
            #if (KeyScanTimer_1_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;
            #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */
        #endif /* (CY_UDB_V1) */

        #if (!KeyScanTimer_1_ControlRegRemoved)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */
}KeyScanTimer_1_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    KeyScanTimer_1_Start(void) ;
void    KeyScanTimer_1_Stop(void) ;

void    KeyScanTimer_1_SetInterruptMode(uint8 interruptMode) ;
uint8   KeyScanTimer_1_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define KeyScanTimer_1_GetInterruptSource() KeyScanTimer_1_ReadStatusRegister()

#if(!KeyScanTimer_1_ControlRegRemoved)
    uint8   KeyScanTimer_1_ReadControlRegister(void) ;
    void    KeyScanTimer_1_WriteControlRegister(uint8 control) \
        ;
#endif /* (!KeyScanTimer_1_ControlRegRemoved) */

uint8  KeyScanTimer_1_ReadPeriod(void) ;
void    KeyScanTimer_1_WritePeriod(uint8 period) \
    ;
uint8  KeyScanTimer_1_ReadCounter(void) ;
void    KeyScanTimer_1_WriteCounter(uint8 counter) \
    ;
uint8  KeyScanTimer_1_ReadCapture(void) ;
void    KeyScanTimer_1_SoftwareCapture(void) ;


#if(!KeyScanTimer_1_UsingFixedFunction) /* UDB Prototypes */
    #if (KeyScanTimer_1_SoftwareCaptureMode)
        void    KeyScanTimer_1_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!KeyScanTimer_1_UsingFixedFunction) */

    #if (KeyScanTimer_1_SoftwareTriggerMode)
        void    KeyScanTimer_1_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (KeyScanTimer_1_SoftwareTriggerMode) */
    #if (KeyScanTimer_1_EnableTriggerMode)
        void    KeyScanTimer_1_EnableTrigger(void) ;
        void    KeyScanTimer_1_DisableTrigger(void) ;
    #endif /* (KeyScanTimer_1_EnableTriggerMode) */

    #if(KeyScanTimer_1_InterruptOnCaptureCount)
        #if(!KeyScanTimer_1_ControlRegRemoved)
            void    KeyScanTimer_1_SetInterruptCount(uint8 interruptCount) \
                ;
        #endif /* (!KeyScanTimer_1_ControlRegRemoved) */
    #endif /* (KeyScanTimer_1_InterruptOnCaptureCount) */

    #if (KeyScanTimer_1_UsingHWCaptureCounter)
        void    KeyScanTimer_1_SetCaptureCount(uint8 captureCount) \
            ;
        uint8   KeyScanTimer_1_ReadCaptureCount(void) ;
    #endif /* (KeyScanTimer_1_UsingHWCaptureCounter) */

    void KeyScanTimer_1_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void KeyScanTimer_1_Init(void)          ;
void KeyScanTimer_1_Enable(void)        ;
void KeyScanTimer_1_SaveConfig(void)    ;
void KeyScanTimer_1_RestoreConfig(void) ;
void KeyScanTimer_1_Sleep(void)         ;
void KeyScanTimer_1_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define KeyScanTimer_1__B_TIMER__CM_NONE 0
#define KeyScanTimer_1__B_TIMER__CM_RISINGEDGE 1
#define KeyScanTimer_1__B_TIMER__CM_FALLINGEDGE 2
#define KeyScanTimer_1__B_TIMER__CM_EITHEREDGE 3
#define KeyScanTimer_1__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define KeyScanTimer_1__B_TIMER__TM_NONE 0x00u
#define KeyScanTimer_1__B_TIMER__TM_RISINGEDGE 0x04u
#define KeyScanTimer_1__B_TIMER__TM_FALLINGEDGE 0x08u
#define KeyScanTimer_1__B_TIMER__TM_EITHEREDGE 0x0Cu
#define KeyScanTimer_1__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define KeyScanTimer_1_INIT_PERIOD             255u
#define KeyScanTimer_1_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << KeyScanTimer_1_CTRL_CAP_MODE_SHIFT))
#define KeyScanTimer_1_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << KeyScanTimer_1_CTRL_TRIG_MODE_SHIFT))
#if (KeyScanTimer_1_UsingFixedFunction)
    #define KeyScanTimer_1_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << KeyScanTimer_1_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << KeyScanTimer_1_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define KeyScanTimer_1_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << KeyScanTimer_1_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << KeyScanTimer_1_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << KeyScanTimer_1_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (KeyScanTimer_1_UsingFixedFunction) */
#define KeyScanTimer_1_INIT_CAPTURE_COUNT      (2u)
#define KeyScanTimer_1_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << KeyScanTimer_1_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (KeyScanTimer_1_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define KeyScanTimer_1_STATUS         (*(reg8 *) KeyScanTimer_1_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define KeyScanTimer_1_STATUS_MASK    (*(reg8 *) KeyScanTimer_1_TimerHW__SR0 )
    #define KeyScanTimer_1_CONTROL        (*(reg8 *) KeyScanTimer_1_TimerHW__CFG0)
    #define KeyScanTimer_1_CONTROL2       (*(reg8 *) KeyScanTimer_1_TimerHW__CFG1)
    #define KeyScanTimer_1_CONTROL2_PTR   ( (reg8 *) KeyScanTimer_1_TimerHW__CFG1)
    #define KeyScanTimer_1_RT1            (*(reg8 *) KeyScanTimer_1_TimerHW__RT1)
    #define KeyScanTimer_1_RT1_PTR        ( (reg8 *) KeyScanTimer_1_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define KeyScanTimer_1_CONTROL3       (*(reg8 *) KeyScanTimer_1_TimerHW__CFG2)
        #define KeyScanTimer_1_CONTROL3_PTR   ( (reg8 *) KeyScanTimer_1_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define KeyScanTimer_1_GLOBAL_ENABLE  (*(reg8 *) KeyScanTimer_1_TimerHW__PM_ACT_CFG)
    #define KeyScanTimer_1_GLOBAL_STBY_ENABLE  (*(reg8 *) KeyScanTimer_1_TimerHW__PM_STBY_CFG)

    #define KeyScanTimer_1_CAPTURE_LSB         (* (reg16 *) KeyScanTimer_1_TimerHW__CAP0 )
    #define KeyScanTimer_1_CAPTURE_LSB_PTR       ((reg16 *) KeyScanTimer_1_TimerHW__CAP0 )
    #define KeyScanTimer_1_PERIOD_LSB          (* (reg16 *) KeyScanTimer_1_TimerHW__PER0 )
    #define KeyScanTimer_1_PERIOD_LSB_PTR        ((reg16 *) KeyScanTimer_1_TimerHW__PER0 )
    #define KeyScanTimer_1_COUNTER_LSB         (* (reg16 *) KeyScanTimer_1_TimerHW__CNT_CMP0 )
    #define KeyScanTimer_1_COUNTER_LSB_PTR       ((reg16 *) KeyScanTimer_1_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define KeyScanTimer_1_BLOCK_EN_MASK                     KeyScanTimer_1_TimerHW__PM_ACT_MSK
    #define KeyScanTimer_1_BLOCK_STBY_EN_MASK                KeyScanTimer_1_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define KeyScanTimer_1_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define KeyScanTimer_1_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define KeyScanTimer_1_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define KeyScanTimer_1_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define KeyScanTimer_1_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define KeyScanTimer_1_CTRL_ENABLE                        ((uint8)((uint8)0x01u << KeyScanTimer_1_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define KeyScanTimer_1_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define KeyScanTimer_1_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << KeyScanTimer_1_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define KeyScanTimer_1_CTRL_MODE_SHIFT                     0x01u
        #define KeyScanTimer_1_CTRL_MODE_MASK                     ((uint8)((uint8)0x07u << KeyScanTimer_1_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define KeyScanTimer_1_CTRL_RCOD_SHIFT        0x02u
        #define KeyScanTimer_1_CTRL_ENBL_SHIFT        0x00u
        #define KeyScanTimer_1_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define KeyScanTimer_1_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << KeyScanTimer_1_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define KeyScanTimer_1_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << KeyScanTimer_1_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define KeyScanTimer_1_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << KeyScanTimer_1_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define KeyScanTimer_1_CTRL_RCOD       ((uint8)((uint8)0x03u << KeyScanTimer_1_CTRL_RCOD_SHIFT))
        #define KeyScanTimer_1_CTRL_ENBL       ((uint8)((uint8)0x80u << KeyScanTimer_1_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define KeyScanTimer_1_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define KeyScanTimer_1_RT1_MASK                        ((uint8)((uint8)0x03u << KeyScanTimer_1_RT1_SHIFT))
    #define KeyScanTimer_1_SYNC                            ((uint8)((uint8)0x03u << KeyScanTimer_1_RT1_SHIFT))
    #define KeyScanTimer_1_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define KeyScanTimer_1_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << KeyScanTimer_1_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define KeyScanTimer_1_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << KeyScanTimer_1_SYNCDSI_SHIFT))

    #define KeyScanTimer_1_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << KeyScanTimer_1_CTRL_MODE_SHIFT))
    #define KeyScanTimer_1_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << KeyScanTimer_1_CTRL_MODE_SHIFT))
    #define KeyScanTimer_1_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << KeyScanTimer_1_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define KeyScanTimer_1_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define KeyScanTimer_1_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define KeyScanTimer_1_STATUS_TC_INT_MASK_SHIFT        (KeyScanTimer_1_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define KeyScanTimer_1_STATUS_CAPTURE_INT_MASK_SHIFT   (KeyScanTimer_1_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define KeyScanTimer_1_STATUS_TC                       ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_TC_SHIFT))
    #define KeyScanTimer_1_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define KeyScanTimer_1_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define KeyScanTimer_1_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define KeyScanTimer_1_STATUS              (* (reg8 *) KeyScanTimer_1_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define KeyScanTimer_1_STATUS_MASK         (* (reg8 *) KeyScanTimer_1_TimerUDB_rstSts_stsreg__MASK_REG)
    #define KeyScanTimer_1_STATUS_AUX_CTRL     (* (reg8 *) KeyScanTimer_1_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define KeyScanTimer_1_CONTROL             (* (reg8 *) KeyScanTimer_1_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(KeyScanTimer_1_Resolution <= 8u) /* 8-bit Timer */
        #define KeyScanTimer_1_CAPTURE_LSB         (* (reg8 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define KeyScanTimer_1_CAPTURE_LSB_PTR       ((reg8 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define KeyScanTimer_1_PERIOD_LSB          (* (reg8 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define KeyScanTimer_1_PERIOD_LSB_PTR        ((reg8 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define KeyScanTimer_1_COUNTER_LSB         (* (reg8 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define KeyScanTimer_1_COUNTER_LSB_PTR       ((reg8 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(KeyScanTimer_1_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define KeyScanTimer_1_CAPTURE_LSB         (* (reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define KeyScanTimer_1_CAPTURE_LSB_PTR       ((reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define KeyScanTimer_1_PERIOD_LSB          (* (reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define KeyScanTimer_1_PERIOD_LSB_PTR        ((reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define KeyScanTimer_1_COUNTER_LSB         (* (reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define KeyScanTimer_1_COUNTER_LSB_PTR       ((reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define KeyScanTimer_1_CAPTURE_LSB         (* (reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define KeyScanTimer_1_CAPTURE_LSB_PTR       ((reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define KeyScanTimer_1_PERIOD_LSB          (* (reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define KeyScanTimer_1_PERIOD_LSB_PTR        ((reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define KeyScanTimer_1_COUNTER_LSB         (* (reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define KeyScanTimer_1_COUNTER_LSB_PTR       ((reg16 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(KeyScanTimer_1_Resolution <= 24u)/* 24-bit Timer */
        #define KeyScanTimer_1_CAPTURE_LSB         (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define KeyScanTimer_1_CAPTURE_LSB_PTR       ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define KeyScanTimer_1_PERIOD_LSB          (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define KeyScanTimer_1_PERIOD_LSB_PTR        ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define KeyScanTimer_1_COUNTER_LSB         (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define KeyScanTimer_1_COUNTER_LSB_PTR       ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define KeyScanTimer_1_CAPTURE_LSB         (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define KeyScanTimer_1_CAPTURE_LSB_PTR       ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define KeyScanTimer_1_PERIOD_LSB          (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define KeyScanTimer_1_PERIOD_LSB_PTR        ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define KeyScanTimer_1_COUNTER_LSB         (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define KeyScanTimer_1_COUNTER_LSB_PTR       ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define KeyScanTimer_1_CAPTURE_LSB         (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define KeyScanTimer_1_CAPTURE_LSB_PTR       ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define KeyScanTimer_1_PERIOD_LSB          (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define KeyScanTimer_1_PERIOD_LSB_PTR        ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define KeyScanTimer_1_COUNTER_LSB         (* (reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define KeyScanTimer_1_COUNTER_LSB_PTR       ((reg32 *) KeyScanTimer_1_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #if (KeyScanTimer_1_UsingHWCaptureCounter)
        #define KeyScanTimer_1_CAP_COUNT              (*(reg8 *) KeyScanTimer_1_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define KeyScanTimer_1_CAP_COUNT_PTR          ( (reg8 *) KeyScanTimer_1_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define KeyScanTimer_1_CAPTURE_COUNT_CTRL     (*(reg8 *) KeyScanTimer_1_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define KeyScanTimer_1_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) KeyScanTimer_1_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (KeyScanTimer_1_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define KeyScanTimer_1_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define KeyScanTimer_1_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define KeyScanTimer_1_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define KeyScanTimer_1_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define KeyScanTimer_1_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define KeyScanTimer_1_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << KeyScanTimer_1_CTRL_INTCNT_SHIFT))
    #define KeyScanTimer_1_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << KeyScanTimer_1_CTRL_TRIG_MODE_SHIFT))
    #define KeyScanTimer_1_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << KeyScanTimer_1_CTRL_TRIG_EN_SHIFT))
    #define KeyScanTimer_1_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << KeyScanTimer_1_CTRL_CAP_MODE_SHIFT))
    #define KeyScanTimer_1_CTRL_ENABLE                    ((uint8)((uint8)0x01u << KeyScanTimer_1_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define KeyScanTimer_1_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define KeyScanTimer_1_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define KeyScanTimer_1_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define KeyScanTimer_1_STATUS_TC_INT_MASK_SHIFT       KeyScanTimer_1_STATUS_TC_SHIFT
    #define KeyScanTimer_1_STATUS_CAPTURE_INT_MASK_SHIFT  KeyScanTimer_1_STATUS_CAPTURE_SHIFT
    #define KeyScanTimer_1_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define KeyScanTimer_1_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define KeyScanTimer_1_STATUS_FIFOFULL_INT_MASK_SHIFT KeyScanTimer_1_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define KeyScanTimer_1_STATUS_TC                      ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define KeyScanTimer_1_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define KeyScanTimer_1_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define KeyScanTimer_1_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define KeyScanTimer_1_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define KeyScanTimer_1_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define KeyScanTimer_1_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << KeyScanTimer_1_STATUS_FIFOFULL_SHIFT))

    #define KeyScanTimer_1_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define KeyScanTimer_1_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define KeyScanTimer_1_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define KeyScanTimer_1_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define KeyScanTimer_1_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define KeyScanTimer_1_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_KeyScanTimer_1_H */


/* [] END OF FILE */
