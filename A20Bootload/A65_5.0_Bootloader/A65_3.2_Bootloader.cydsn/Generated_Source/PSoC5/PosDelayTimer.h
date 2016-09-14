/*******************************************************************************
* File Name: PosDelayTimer.h
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

#if !defined(CY_Timer_v2_30_PosDelayTimer_H)
#define CY_Timer_v2_30_PosDelayTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 PosDelayTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define PosDelayTimer_Resolution                 8u
#define PosDelayTimer_UsingFixedFunction         1u
#define PosDelayTimer_UsingHWCaptureCounter      0u
#define PosDelayTimer_SoftwareCaptureMode        0u
#define PosDelayTimer_SoftwareTriggerMode        0u
#define PosDelayTimer_UsingHWEnable              0u
#define PosDelayTimer_EnableTriggerMode          0u
#define PosDelayTimer_InterruptOnCaptureCount    0u
#define PosDelayTimer_RunModeUsed                0u
#define PosDelayTimer_ControlRegRemoved          0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!PosDelayTimer_UsingFixedFunction)
        #if (CY_UDB_V0)
            uint8 TimerUdb;                 /* Timer internal counter value */
            uint8 TimerPeriod;              /* Timer Period value       */
            uint8 InterruptMaskValue;       /* Timer Compare Value */
            #if (PosDelayTimer_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;  /* Timer Capture Counter Value */
            #endif /* variable declaration for backing up Capture Counter value*/
        #endif /* variables for non retention registers in CY_UDB_V0 */

        #if (CY_UDB_V1)
            uint8 TimerUdb;
            uint8 InterruptMaskValue;
            #if (PosDelayTimer_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;
            #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */
        #endif /* (CY_UDB_V1) */

        #if (!PosDelayTimer_ControlRegRemoved)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */
}PosDelayTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    PosDelayTimer_Start(void) ;
void    PosDelayTimer_Stop(void) ;

void    PosDelayTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   PosDelayTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define PosDelayTimer_GetInterruptSource() PosDelayTimer_ReadStatusRegister()

#if(!PosDelayTimer_ControlRegRemoved)
    uint8   PosDelayTimer_ReadControlRegister(void) ;
    void    PosDelayTimer_WriteControlRegister(uint8 control) \
        ;
#endif /* (!PosDelayTimer_ControlRegRemoved) */

uint8  PosDelayTimer_ReadPeriod(void) ;
void    PosDelayTimer_WritePeriod(uint8 period) \
    ;
uint8  PosDelayTimer_ReadCounter(void) ;
void    PosDelayTimer_WriteCounter(uint8 counter) \
    ;
uint8  PosDelayTimer_ReadCapture(void) ;
void    PosDelayTimer_SoftwareCapture(void) ;


#if(!PosDelayTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (PosDelayTimer_SoftwareCaptureMode)
        void    PosDelayTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!PosDelayTimer_UsingFixedFunction) */

    #if (PosDelayTimer_SoftwareTriggerMode)
        void    PosDelayTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (PosDelayTimer_SoftwareTriggerMode) */
    #if (PosDelayTimer_EnableTriggerMode)
        void    PosDelayTimer_EnableTrigger(void) ;
        void    PosDelayTimer_DisableTrigger(void) ;
    #endif /* (PosDelayTimer_EnableTriggerMode) */

    #if(PosDelayTimer_InterruptOnCaptureCount)
        #if(!PosDelayTimer_ControlRegRemoved)
            void    PosDelayTimer_SetInterruptCount(uint8 interruptCount) \
                ;
        #endif /* (!PosDelayTimer_ControlRegRemoved) */
    #endif /* (PosDelayTimer_InterruptOnCaptureCount) */

    #if (PosDelayTimer_UsingHWCaptureCounter)
        void    PosDelayTimer_SetCaptureCount(uint8 captureCount) \
            ;
        uint8   PosDelayTimer_ReadCaptureCount(void) ;
    #endif /* (PosDelayTimer_UsingHWCaptureCounter) */

    void PosDelayTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void PosDelayTimer_Init(void)          ;
void PosDelayTimer_Enable(void)        ;
void PosDelayTimer_SaveConfig(void)    ;
void PosDelayTimer_RestoreConfig(void) ;
void PosDelayTimer_Sleep(void)         ;
void PosDelayTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define PosDelayTimer__B_TIMER__CM_NONE 0
#define PosDelayTimer__B_TIMER__CM_RISINGEDGE 1
#define PosDelayTimer__B_TIMER__CM_FALLINGEDGE 2
#define PosDelayTimer__B_TIMER__CM_EITHEREDGE 3
#define PosDelayTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define PosDelayTimer__B_TIMER__TM_NONE 0x00u
#define PosDelayTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define PosDelayTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define PosDelayTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define PosDelayTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define PosDelayTimer_INIT_PERIOD             99u
#define PosDelayTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << PosDelayTimer_CTRL_CAP_MODE_SHIFT))
#define PosDelayTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << PosDelayTimer_CTRL_TRIG_MODE_SHIFT))
#if (PosDelayTimer_UsingFixedFunction)
    #define PosDelayTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << PosDelayTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << PosDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define PosDelayTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)1u << PosDelayTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << PosDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << PosDelayTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (PosDelayTimer_UsingFixedFunction) */
#define PosDelayTimer_INIT_CAPTURE_COUNT      (2u)
#define PosDelayTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << PosDelayTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (PosDelayTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define PosDelayTimer_STATUS         (*(reg8 *) PosDelayTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define PosDelayTimer_STATUS_MASK    (*(reg8 *) PosDelayTimer_TimerHW__SR0 )
    #define PosDelayTimer_CONTROL        (*(reg8 *) PosDelayTimer_TimerHW__CFG0)
    #define PosDelayTimer_CONTROL2       (*(reg8 *) PosDelayTimer_TimerHW__CFG1)
    #define PosDelayTimer_CONTROL2_PTR   ( (reg8 *) PosDelayTimer_TimerHW__CFG1)
    #define PosDelayTimer_RT1            (*(reg8 *) PosDelayTimer_TimerHW__RT1)
    #define PosDelayTimer_RT1_PTR        ( (reg8 *) PosDelayTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define PosDelayTimer_CONTROL3       (*(reg8 *) PosDelayTimer_TimerHW__CFG2)
        #define PosDelayTimer_CONTROL3_PTR   ( (reg8 *) PosDelayTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define PosDelayTimer_GLOBAL_ENABLE  (*(reg8 *) PosDelayTimer_TimerHW__PM_ACT_CFG)
    #define PosDelayTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) PosDelayTimer_TimerHW__PM_STBY_CFG)

    #define PosDelayTimer_CAPTURE_LSB         (* (reg16 *) PosDelayTimer_TimerHW__CAP0 )
    #define PosDelayTimer_CAPTURE_LSB_PTR       ((reg16 *) PosDelayTimer_TimerHW__CAP0 )
    #define PosDelayTimer_PERIOD_LSB          (* (reg16 *) PosDelayTimer_TimerHW__PER0 )
    #define PosDelayTimer_PERIOD_LSB_PTR        ((reg16 *) PosDelayTimer_TimerHW__PER0 )
    #define PosDelayTimer_COUNTER_LSB         (* (reg16 *) PosDelayTimer_TimerHW__CNT_CMP0 )
    #define PosDelayTimer_COUNTER_LSB_PTR       ((reg16 *) PosDelayTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define PosDelayTimer_BLOCK_EN_MASK                     PosDelayTimer_TimerHW__PM_ACT_MSK
    #define PosDelayTimer_BLOCK_STBY_EN_MASK                PosDelayTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define PosDelayTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define PosDelayTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define PosDelayTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define PosDelayTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define PosDelayTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define PosDelayTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << PosDelayTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define PosDelayTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define PosDelayTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << PosDelayTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define PosDelayTimer_CTRL_MODE_SHIFT                     0x01u
        #define PosDelayTimer_CTRL_MODE_MASK                     ((uint8)((uint8)0x07u << PosDelayTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define PosDelayTimer_CTRL_RCOD_SHIFT        0x02u
        #define PosDelayTimer_CTRL_ENBL_SHIFT        0x00u
        #define PosDelayTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define PosDelayTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << PosDelayTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define PosDelayTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << PosDelayTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define PosDelayTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << PosDelayTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define PosDelayTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << PosDelayTimer_CTRL_RCOD_SHIFT))
        #define PosDelayTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << PosDelayTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define PosDelayTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define PosDelayTimer_RT1_MASK                        ((uint8)((uint8)0x03u << PosDelayTimer_RT1_SHIFT))
    #define PosDelayTimer_SYNC                            ((uint8)((uint8)0x03u << PosDelayTimer_RT1_SHIFT))
    #define PosDelayTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define PosDelayTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << PosDelayTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define PosDelayTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << PosDelayTimer_SYNCDSI_SHIFT))

    #define PosDelayTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << PosDelayTimer_CTRL_MODE_SHIFT))
    #define PosDelayTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << PosDelayTimer_CTRL_MODE_SHIFT))
    #define PosDelayTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << PosDelayTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define PosDelayTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define PosDelayTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define PosDelayTimer_STATUS_TC_INT_MASK_SHIFT        (PosDelayTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define PosDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (PosDelayTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define PosDelayTimer_STATUS_TC                       ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_TC_SHIFT))
    #define PosDelayTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define PosDelayTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define PosDelayTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define PosDelayTimer_STATUS              (* (reg8 *) PosDelayTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define PosDelayTimer_STATUS_MASK         (* (reg8 *) PosDelayTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define PosDelayTimer_STATUS_AUX_CTRL     (* (reg8 *) PosDelayTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define PosDelayTimer_CONTROL             (* (reg8 *) PosDelayTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(PosDelayTimer_Resolution <= 8u) /* 8-bit Timer */
        #define PosDelayTimer_CAPTURE_LSB         (* (reg8 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define PosDelayTimer_CAPTURE_LSB_PTR       ((reg8 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define PosDelayTimer_PERIOD_LSB          (* (reg8 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define PosDelayTimer_PERIOD_LSB_PTR        ((reg8 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define PosDelayTimer_COUNTER_LSB         (* (reg8 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define PosDelayTimer_COUNTER_LSB_PTR       ((reg8 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #elif(PosDelayTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define PosDelayTimer_CAPTURE_LSB         (* (reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define PosDelayTimer_CAPTURE_LSB_PTR       ((reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define PosDelayTimer_PERIOD_LSB          (* (reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define PosDelayTimer_PERIOD_LSB_PTR        ((reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define PosDelayTimer_COUNTER_LSB         (* (reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define PosDelayTimer_COUNTER_LSB_PTR       ((reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define PosDelayTimer_CAPTURE_LSB         (* (reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define PosDelayTimer_CAPTURE_LSB_PTR       ((reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_F0_REG )
            #define PosDelayTimer_PERIOD_LSB          (* (reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define PosDelayTimer_PERIOD_LSB_PTR        ((reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_D0_REG )
            #define PosDelayTimer_COUNTER_LSB         (* (reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
            #define PosDelayTimer_COUNTER_LSB_PTR       ((reg16 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(PosDelayTimer_Resolution <= 24u)/* 24-bit Timer */
        #define PosDelayTimer_CAPTURE_LSB         (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define PosDelayTimer_CAPTURE_LSB_PTR       ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
        #define PosDelayTimer_PERIOD_LSB          (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define PosDelayTimer_PERIOD_LSB_PTR        ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
        #define PosDelayTimer_COUNTER_LSB         (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #define PosDelayTimer_COUNTER_LSB_PTR       ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define PosDelayTimer_CAPTURE_LSB         (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define PosDelayTimer_CAPTURE_LSB_PTR       ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__F0_REG )
            #define PosDelayTimer_PERIOD_LSB          (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define PosDelayTimer_PERIOD_LSB_PTR        ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__D0_REG )
            #define PosDelayTimer_COUNTER_LSB         (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
            #define PosDelayTimer_COUNTER_LSB_PTR       ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define PosDelayTimer_CAPTURE_LSB         (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define PosDelayTimer_CAPTURE_LSB_PTR       ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_F0_REG )
            #define PosDelayTimer_PERIOD_LSB          (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define PosDelayTimer_PERIOD_LSB_PTR        ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_D0_REG )
            #define PosDelayTimer_COUNTER_LSB         (* (reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
            #define PosDelayTimer_COUNTER_LSB_PTR       ((reg32 *) PosDelayTimer_TimerUDB_sT8_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #if (PosDelayTimer_UsingHWCaptureCounter)
        #define PosDelayTimer_CAP_COUNT              (*(reg8 *) PosDelayTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define PosDelayTimer_CAP_COUNT_PTR          ( (reg8 *) PosDelayTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define PosDelayTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) PosDelayTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define PosDelayTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) PosDelayTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (PosDelayTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define PosDelayTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define PosDelayTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define PosDelayTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define PosDelayTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define PosDelayTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define PosDelayTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << PosDelayTimer_CTRL_INTCNT_SHIFT))
    #define PosDelayTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << PosDelayTimer_CTRL_TRIG_MODE_SHIFT))
    #define PosDelayTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << PosDelayTimer_CTRL_TRIG_EN_SHIFT))
    #define PosDelayTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << PosDelayTimer_CTRL_CAP_MODE_SHIFT))
    #define PosDelayTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << PosDelayTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define PosDelayTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define PosDelayTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define PosDelayTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define PosDelayTimer_STATUS_TC_INT_MASK_SHIFT       PosDelayTimer_STATUS_TC_SHIFT
    #define PosDelayTimer_STATUS_CAPTURE_INT_MASK_SHIFT  PosDelayTimer_STATUS_CAPTURE_SHIFT
    #define PosDelayTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define PosDelayTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define PosDelayTimer_STATUS_FIFOFULL_INT_MASK_SHIFT PosDelayTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define PosDelayTimer_STATUS_TC                      ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define PosDelayTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define PosDelayTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define PosDelayTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define PosDelayTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define PosDelayTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define PosDelayTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << PosDelayTimer_STATUS_FIFOFULL_SHIFT))

    #define PosDelayTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define PosDelayTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define PosDelayTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define PosDelayTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define PosDelayTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define PosDelayTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_PosDelayTimer_H */


/* [] END OF FILE */
