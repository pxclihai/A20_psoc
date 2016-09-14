/*******************************************************************************
* File Name: PreciseTimeDelayTimer_PM.c
* Version 2.50
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "PreciseTimeDelayTimer.h"
static PreciseTimeDelayTimer_backupStruct PreciseTimeDelayTimer_backup;


/*******************************************************************************
* Function Name: PreciseTimeDelayTimer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PreciseTimeDelayTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PreciseTimeDelayTimer_SaveConfig(void) 
{
    #if (!PreciseTimeDelayTimer_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            PreciseTimeDelayTimer_backup.TimerUdb = PreciseTimeDelayTimer_ReadCounter();
            PreciseTimeDelayTimer_backup.TimerPeriod = PreciseTimeDelayTimer_ReadPeriod();
            PreciseTimeDelayTimer_backup.InterruptMaskValue = PreciseTimeDelayTimer_STATUS_MASK;
            #if (PreciseTimeDelayTimer_UsingHWCaptureCounter)
                PreciseTimeDelayTimer_backup.TimerCaptureCounter = PreciseTimeDelayTimer_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            PreciseTimeDelayTimer_backup.TimerUdb = PreciseTimeDelayTimer_ReadCounter();
            PreciseTimeDelayTimer_backup.InterruptMaskValue = PreciseTimeDelayTimer_STATUS_MASK;
            #if (PreciseTimeDelayTimer_UsingHWCaptureCounter)
                PreciseTimeDelayTimer_backup.TimerCaptureCounter = PreciseTimeDelayTimer_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!PreciseTimeDelayTimer_ControlRegRemoved)
            PreciseTimeDelayTimer_backup.TimerControlRegister = PreciseTimeDelayTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: PreciseTimeDelayTimer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PreciseTimeDelayTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PreciseTimeDelayTimer_RestoreConfig(void) 
{   
    #if (!PreciseTimeDelayTimer_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 PreciseTimeDelayTimer_interruptState;

            PreciseTimeDelayTimer_WriteCounter(PreciseTimeDelayTimer_backup.TimerUdb);
            PreciseTimeDelayTimer_WritePeriod(PreciseTimeDelayTimer_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            PreciseTimeDelayTimer_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            PreciseTimeDelayTimer_STATUS_AUX_CTRL |= PreciseTimeDelayTimer_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(PreciseTimeDelayTimer_interruptState);
            PreciseTimeDelayTimer_STATUS_MASK =PreciseTimeDelayTimer_backup.InterruptMaskValue;
            #if (PreciseTimeDelayTimer_UsingHWCaptureCounter)
                PreciseTimeDelayTimer_SetCaptureCount(PreciseTimeDelayTimer_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            PreciseTimeDelayTimer_WriteCounter(PreciseTimeDelayTimer_backup.TimerUdb);
            PreciseTimeDelayTimer_STATUS_MASK =PreciseTimeDelayTimer_backup.InterruptMaskValue;
            #if (PreciseTimeDelayTimer_UsingHWCaptureCounter)
                PreciseTimeDelayTimer_SetCaptureCount(PreciseTimeDelayTimer_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!PreciseTimeDelayTimer_ControlRegRemoved)
            PreciseTimeDelayTimer_WriteControlRegister(PreciseTimeDelayTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: PreciseTimeDelayTimer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PreciseTimeDelayTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void PreciseTimeDelayTimer_Sleep(void) 
{
    #if(!PreciseTimeDelayTimer_ControlRegRemoved)
        /* Save Counter's enable state */
        if(PreciseTimeDelayTimer_CTRL_ENABLE == (PreciseTimeDelayTimer_CONTROL & PreciseTimeDelayTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            PreciseTimeDelayTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            PreciseTimeDelayTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    PreciseTimeDelayTimer_Stop();
    PreciseTimeDelayTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: PreciseTimeDelayTimer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  PreciseTimeDelayTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PreciseTimeDelayTimer_Wakeup(void) 
{
    PreciseTimeDelayTimer_RestoreConfig();
    #if(!PreciseTimeDelayTimer_ControlRegRemoved)
        if(PreciseTimeDelayTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                PreciseTimeDelayTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
