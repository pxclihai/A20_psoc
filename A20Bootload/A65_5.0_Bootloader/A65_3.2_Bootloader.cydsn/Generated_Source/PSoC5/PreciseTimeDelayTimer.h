/*******************************************************************************
* File Name: PreciseTimeDelayTimer.h
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

#if !defined(CY_Timer_v2_30_PreciseTimeDelayTimer_H)
#define CY_Timer_v2_30_PreciseTimeDelayTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 PreciseTimeDelayTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define PreciseTimeDelayTimer_Resolution                 8u
#define PreciseTimeDelayTimer_UsingFixedFunction         1u
#define PreciseTimeDelayTimer_UsingHWCaptureCounter      0u
#define PreciseTimeDelayTimer_SoftwareCaptureMode        0u
#define PreciseTimeDelayTimer_SoftwareTriggerMode        0u
#define PreciseTimeDelayTimer_UsingHWEnable              0u
#define PreciseTimeDelayTimer_EnableTriggerMode          0u
#define PreciseTimeDelayTimer_InterruptOnCaptureCount    0u
#define PreciseTimeDelayTimer_RunModeUsed                0u
#define PreciseTimeDelayTimer_ControlRegRemoved          0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!PreciseTimeDelayTimer_UsingFixedFunction)
        #if (CY_UDB_V0)
            uint8 TimerUdb;                 /* Timer internal counter value */
            uint8 TimerPeriod;              /* Timer Period value       */
            uint8 InterruptMaskValue;       /* Timer Compare Value */
            #if (PreciseTimeDelayTimer_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;  /* Timer Capture Counter Value */
            #endif /* variable declaration for backing up Capture Counter value*/
        #endif /* variables for non retention registers in CY_UDB_V0 */

        #if (CY_UDB_V1)
            uint8 TimerUdb;
            uint8 InterruptMaskValue;
            #if (PreciseTimeDelayTimer_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;
            #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */
        #endif /* (CY_UDB_V1) */

        #if (!PreciseTimeDelayTimer_ControlRegRemoved)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */
}PreciseTimeDelayTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    PreciseTimeDelayTimer_Start(void) ;
void    PreciseTimeDelayTimer_Stop(void) ;

void    PreciseTimeDelayTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   PreciseTimeDelayTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define PreciseTimeDelayTimer_GetInterruptSource() PreciseTimeDelayTimer_ReadStatusRegister()

#if(!PreciseTimeDelayTimer_ControlRegRemoved)
    uint8   PreciseTimeDelayTimer_ReadControlRegister(void) ;
    void    PreciseTimeDelayTimer_WriteControlRegister(uint8 control) \
        ;
#endif /* (!PreciseTimeDelayTimer_ControlRegRemoved) */

uint8  PreciseTimeDelayTimer_ReadPeriod(void) ;
void    PreciseTimeDelayTimer_WritePeriod(uint8 period) \
    ;
uint8  PreciseTimeDelayTimer_ReadCounter(void) ;
void    PreciseTimeDelayTimer_WriteCounter(uint8 counter) \
    ;
uint8  PreciseTimeDelayTimer_ReadCapture(void) ;
void    PreciseTimeDelayTimer_SoftwareCapture(void) ;


#if(!PreciseTimeDelayTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (PreciseTimeDelayTimer_SoftwareCaptureMode)
        void    PreciseTimeDelayTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!PreciseTimeDelayTimer_UsingFixedFunction) */

    #if (PreciseTimeDelayTimer_SoftwareTriggerMode)
        void    PreciseTimeDelayTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (PreciseTimeDelayTimer_SoftwareTriggerMode) */
    #if (PreciseTimeDelayTimer_EnableTriggerMode)
        void    PreciseTimeDelayTimer_EnableTrigger(void) ;
        void    PreciseTimeDelayTimer_DisableTrigger(void) ;
    #endif /* (PreciseTimeDelayTimer_EnableTriggerMode) */

    #if(PreciseTimeDelayTimer_InterruptOnCaptureCount)
        #if(!PreciseTimeDelayTimer_ControlRegRemoved)
            void    PreciseTimeDelayTimer_SetInterruptCount(uint8 interruptCount) \
                ;
        #endif /* (!PreciseTimeDelayTimer_ControlRegRemoved) */
    #endif /* (PreciseTimeDelayTimer_InterruptOnCaptureCount) */

    #if (PreciseTimeDelayTimer_UsingHWCaptureCounter)
        void    PreciseTimeDelayTimer_SetCaptureCount(uint8 captureCount) \
            ;
        uint8   PreciseTimeDelayTimer_ReadCaptureCount(void) ;
    #endif /* (PreciseTimeDelayTimer_UsingHWCaptureCounter) */

    void PreciseTimeDelayTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void PreciseTimeDelayTimer_Init(void)          ;
void PreciseTimeDelayTimer_Enable(void)        ;
void PreciseTimeDelayTimer_SaveConfig(void)    ;
void PreciseTimeDelayTimer_RestoreConfig(void) ;
void PreciseTimeDelayTimer_Sleep(void)         ;
void PreciseTimeDelayTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define PreciseTimeDelayTimer__B_TIMER__CM_NONE 0
#define PreciseTimeDelayTimer__B_TIMER__CM_RISINGEDGE 1
#define PreciseTimeDelayTimer__B_TIMER__CM_FALLINGEDGE 2
#define PreciseTimeDelayTimer__B_TIMER__CM_EITHEREDGE 3
#define PreciseTimeDelayTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define PreciseTimeDelayTimer__B_TIMER__TM_NONE 0x00u
#define PreciseTimeDelayTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define PreciseTimeDelayTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define PreciseTimeDelayTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define PreciseTimeDelayTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define PreciseTimeDelayTimer_INIT_PERIOD             99u
#define PreciseTimeDelayTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << PreciseTimeDelayTimer_CTRL_CAP_MODE_SHIFT))
#define PreciseTimeDelayTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << PreciseTimeDelayTimer_CTRL_TRIG_MODE_SHIFT))
#if (PreciseTimeDelayTimer_UsingFixedFunction)
    #define PreciseTimeDelayTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << PreciseTimeDelayTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << PreciseTimeDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define PreciseTimeDelayTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << PreciseTimeDelayTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << PreciseTimeDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << PreciseTimeDelayTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (PreciseTimeDelayTimer_UsingFixedFunction) */
#define PreciseTimeDelayTimer_INIT_CAPTURE_COUNT      (2u)
#define PreciseTimeDelayTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << PreciseTimeDelayTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (PreciseTimeDelayTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define PreciseTimeDelayTimer_STATUS         (*(reg8 *) PreciseTimeDelayTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define PreciseTimeDelayTimer_STATUS_MASK    (*(reg8 *) PreciseTimeDelayTimer_TimerHW__SR0 )
    #define PreciseTimeDelayTimer_CONTROL        (*(reg8 *) PreciseTimeDelayTimer_TimerHW__CFG0)
    #define PreciseTimeDelayTimer_CONTROL2       (*(reg8 *) PreciseTimeDelayTimer_TimerHW__CFG1)
    #define PreciseTimeDelayTimer_CONTROL2_PTR   ( (reg8 *) PreciseTimeDelayTimer_TimerHW__CFG1)
    #define PreciseTimeDelayTimer_RT1            (*(reg8 *) PreciseTimeDelayTimer_TimerHW__RT1)
    #define PreciseTimeDelayTimer_RT1_PTR        ( (reg8 *) PreciseTimeDelayTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define PreciseTimeDelayTimer_CONTROL3       (*(reg8 *) PreciseTimeDelayTimer_TimerHW__CFG2)
        #define PreciseTimeDelayTimer_CONTROL3_PTR   ( (reg8 *) PreciseTimeDelayTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define PreciseTimeDelayTimer_GLOBAL_ENABLE  (*(reg8 *) PreciseTimeDelayTimer_TimerHW__PM_ACT_CFG)
    #define PreciseTimeDelayTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) PreciseTimeDelayTimer_TimerHW__PM_STBY_CFG)

    #define PreciseTimeDelayTimer_CAPTURE_LSB         (* (reg16 *) PreciseTimeDelayTimer_TimerHW__CAP0 )
    #define PreciseTimeDelayTimer_CAPTURE_LSB_PTR       ((reg16 *) PreciseTimeDelayTimer_TimerHW__CAP0 )
    #define PreciseTimeDelayTimer_PERIOD_LSB          (* (reg16 *) PreciseTimeDelayTimer_TimerHW__PER0 )
    #define PreciseTimeDelayTimer_PERIOD_LSB_PTR        ((reg16 *) PreciseTimeDelayTimer_TimerHW__PER0 )
    #define PreciseTimeDelayTimer_COUNTER_LSB         (* (reg16 *) PreciseTimeDelayTimer_TimerHW__CNT_CMP0 )
    #define PreciseTimeDelayTimer_COUNTER_LSB_PTR       ((reg16 *) PreciseTimeDelayTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define PreciseTimeDelayTimer_BLOCK_EN_MASK                     PreciseTimeDelayTimer_TimerHW__PM_ACT_MSK
    #define PreciseTimeDelayTimer_BLOCK_STBY_EN_MASK                PreciseTimeDelayTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define PreciseTimeDelayTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define PreciseTimeDelayTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define PreciseTimeDelayTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define PreciseTimeDelayTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define PreciseTimeDelayTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define PreciseTimeDelayTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define PreciseTimeDelayTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define PreciseTimeDelayTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define PreciseTimeDelayTimer_CTRL_MODE_SHIFT                     0x01u
        #define PreciseTimeDelayTimer_CTRL_MODE_MASK                     ((uint8)((uint8)0x07u << PreciseTimeDelayTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define PreciseTimeDelayTimer_CTRL_RCOD_SHIFT        0x02u
        #define PreciseTimeDelayTimer_CTRL_ENBL_SHIFT        0x00u
        #define PreciseTimeDelayTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define PreciseTimeDelayTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << PreciseTimeDelayTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define PreciseTimeDelayTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << PreciseTimeDelayTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define PreciseTimeDelayTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << PreciseTimeDelayTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define PreciseTimeDelayTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << PreciseTimeDelayTimer_CTRL_RCOD_SHIFT))
        #define PreciseTimeDelayTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << PreciseTimeDelayTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define PreciseTimeDelayTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define PreciseTimeDelayTimer_RT1_MASK                        ((uint8)((uint8)0x03u << PreciseTimeDelayTimer_RT1_SHIFT))
    #define PreciseTimeDelayTimer_SYNC                            ((uint8)((uint8)0x03u << PreciseTimeDelayTimer_RT1_SHIFT))
    #define PreciseTimeDelayTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define PreciseTimeDelayTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << PreciseTimeDelayTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define PreciseTimeDelayTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << PreciseTimeDelayTimer_SYNCDSI_SHIFT))

    #define PreciseTimeDelayTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_CTRL_MODE_SHIFT))
    #define PreciseTimeDelayTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << PreciseTimeDelayTimer_CTRL_MODE_SHIFT))
    #define PreciseTimeDelayTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << PreciseTimeDelayTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define PreciseTimeDelayTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define PreciseTimeDelayTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define PreciseTimeDelayTimer_STATUS_TC_INT_MASK_SHIFT        (PreciseTimeDelayTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define PreciseTimeDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (PreciseTimeDelayTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define PreciseTimeDelayTimer_STATUS_TC                       ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_TC_SHIFT))
    #define PreciseTimeDelayTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define PreciseTimeDelayTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define PreciseTimeDelayTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define PreciseTimeDelayTimer_STATUS              (* (reg8 *) PreciseTimeDelayTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define PreciseTimeDelayTimer_STATUS_MASK         (* (reg8 *) PreciseTimeDelayTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define PreciseTimeDelayTimer_STATUS_AUX_CTRL     (* (reg8 *) PreciseTimeDelayTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define PreciseTimeDelayTimer_CONTROL             (* (reg8 *) PreciseTimeDelayTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(PreciseTimeDelayTimer_Resolution <= 8u) /* 8-bit Timer */
        #define PreciseTimeDelayTimer_CAPTURE_LSB         (* (reg8 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define PreciseTimeDelayTimer_CAPTURE_LSB_PTR       ((reg8 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define PreciseTimeDelayTimer_PERIOD_LSB          (* (reg8 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define PreciseTimeDelayTimer_PERIOD_LSB_PTR        ((reg8 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define PreciseTimeDelayTimer_COUNTER_LSB         (* (reg8 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define PreciseTimeDelayTimer_COUNTER_LSB_PTR       ((reg8 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(PreciseTimeDelayTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define PreciseTimeDelayTimer_CAPTURE_LSB         (* (reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define PreciseTimeDelayTimer_CAPTURE_LSB_PTR       ((reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define PreciseTimeDelayTimer_PERIOD_LSB          (* (reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define PreciseTimeDelayTimer_PERIOD_LSB_PTR        ((reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define PreciseTimeDelayTimer_COUNTER_LSB         (* (reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define PreciseTimeDelayTimer_COUNTER_LSB_PTR       ((reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define PreciseTimeDelayTimer_CAPTURE_LSB         (* (reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define PreciseTimeDelayTimer_CAPTURE_LSB_PTR       ((reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define PreciseTimeDelayTimer_PERIOD_LSB          (* (reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define PreciseTimeDelayTimer_PERIOD_LSB_PTR        ((reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define PreciseTimeDelayTimer_COUNTER_LSB         (* (reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define PreciseTimeDelayTimer_COUNTER_LSB_PTR       ((reg16 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(PreciseTimeDelayTimer_Resolution <= 24u)/* 24-bit Timer */
        #define PreciseTimeDelayTimer_CAPTURE_LSB         (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define PreciseTimeDelayTimer_CAPTURE_LSB_PTR       ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define PreciseTimeDelayTimer_PERIOD_LSB          (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define PreciseTimeDelayTimer_PERIOD_LSB_PTR        ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define PreciseTimeDelayTimer_COUNTER_LSB         (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define PreciseTimeDelayTimer_COUNTER_LSB_PTR       ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define PreciseTimeDelayTimer_CAPTURE_LSB         (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define PreciseTimeDelayTimer_CAPTURE_LSB_PTR       ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define PreciseTimeDelayTimer_PERIOD_LSB          (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define PreciseTimeDelayTimer_PERIOD_LSB_PTR        ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define PreciseTimeDelayTimer_COUNTER_LSB         (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define PreciseTimeDelayTimer_COUNTER_LSB_PTR       ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define PreciseTimeDelayTimer_CAPTURE_LSB         (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define PreciseTimeDelayTimer_CAPTURE_LSB_PTR       ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define PreciseTimeDelayTimer_PERIOD_LSB          (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define PreciseTimeDelayTimer_PERIOD_LSB_PTR        ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define PreciseTimeDelayTimer_COUNTER_LSB         (* (reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define PreciseTimeDelayTimer_COUNTER_LSB_PTR       ((reg32 *) PreciseTimeDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #if (PreciseTimeDelayTimer_UsingHWCaptureCounter)
        #define PreciseTimeDelayTimer_CAP_COUNT              (*(reg8 *) PreciseTimeDelayTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define PreciseTimeDelayTimer_CAP_COUNT_PTR          ( (reg8 *) PreciseTimeDelayTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define PreciseTimeDelayTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) PreciseTimeDelayTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define PreciseTimeDelayTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) PreciseTimeDelayTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (PreciseTimeDelayTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define PreciseTimeDelayTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define PreciseTimeDelayTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define PreciseTimeDelayTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define PreciseTimeDelayTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define PreciseTimeDelayTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define PreciseTimeDelayTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << PreciseTimeDelayTimer_CTRL_INTCNT_SHIFT))
    #define PreciseTimeDelayTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << PreciseTimeDelayTimer_CTRL_TRIG_MODE_SHIFT))
    #define PreciseTimeDelayTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_CTRL_TRIG_EN_SHIFT))
    #define PreciseTimeDelayTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << PreciseTimeDelayTimer_CTRL_CAP_MODE_SHIFT))
    #define PreciseTimeDelayTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define PreciseTimeDelayTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define PreciseTimeDelayTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define PreciseTimeDelayTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define PreciseTimeDelayTimer_STATUS_TC_INT_MASK_SHIFT       PreciseTimeDelayTimer_STATUS_TC_SHIFT
    #define PreciseTimeDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT  PreciseTimeDelayTimer_STATUS_CAPTURE_SHIFT
    #define PreciseTimeDelayTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define PreciseTimeDelayTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define PreciseTimeDelayTimer_STATUS_FIFOFULL_INT_MASK_SHIFT PreciseTimeDelayTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define PreciseTimeDelayTimer_STATUS_TC                      ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define PreciseTimeDelayTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define PreciseTimeDelayTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define PreciseTimeDelayTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define PreciseTimeDelayTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define PreciseTimeDelayTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define PreciseTimeDelayTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << PreciseTimeDelayTimer_STATUS_FIFOFULL_SHIFT))

    #define PreciseTimeDelayTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define PreciseTimeDelayTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define PreciseTimeDelayTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define PreciseTimeDelayTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define PreciseTimeDelayTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define PreciseTimeDelayTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_PreciseTimeDelayTimer_H */


/* [] END OF FILE */
