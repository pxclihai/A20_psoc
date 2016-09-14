/*******************************************************************************
* File Name: PosDelayTimer_PM.c
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

#include "PosDelayTimer.h"
static PosDelayTimer_backupStruct PosDelayTimer_backup;


/*******************************************************************************
* Function Name: PosDelayTimer_SaveConfig
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
*  PosDelayTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PosDelayTimer_SaveConfig(void) 
{
    #if (!PosDelayTimer_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            PosDelayTimer_backup.TimerUdb = PosDelayTimer_ReadCounter();
            PosDelayTimer_backup.TimerPeriod = PosDelayTimer_ReadPeriod();
            PosDelayTimer_backup.InterruptMaskValue = PosDelayTimer_STATUS_MASK;
            #if (PosDelayTimer_UsingHWCaptureCounter)
                PosDelayTimer_backup.TimerCaptureCounter = PosDelayTimer_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            PosDelayTimer_backup.TimerUdb = PosDelayTimer_ReadCounter();
            PosDelayTimer_backup.InterruptMaskValue = PosDelayTimer_STATUS_MASK;
            #if (PosDelayTimer_UsingHWCaptureCounter)
                PosDelayTimer_backup.TimerCaptureCounter = PosDelayTimer_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!PosDelayTimer_ControlRegRemoved)
            PosDelayTimer_backup.TimerControlRegister = PosDelayTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: PosDelayTimer_RestoreConfig
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
*  PosDelayTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PosDelayTimer_RestoreConfig(void) 
{   
    #if (!PosDelayTimer_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 PosDelayTimer_interruptState;

            PosDelayTimer_WriteCounter(PosDelayTimer_backup.TimerUdb);
            PosDelayTimer_WritePeriod(PosDelayTimer_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            PosDelayTimer_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            PosDelayTimer_STATUS_AUX_CTRL |= PosDelayTimer_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(PosDelayTimer_interruptState);
            PosDelayTimer_STATUS_MASK =PosDelayTimer_backup.InterruptMaskValue;
            #if (PosDelayTimer_UsingHWCaptureCounter)
                PosDelayTimer_SetCaptureCount(PosDelayTimer_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            PosDelayTimer_WriteCounter(PosDelayTimer_backup.TimerUdb);
            PosDelayTimer_STATUS_MASK =PosDelayTimer_backup.InterruptMaskValue;
            #if (PosDelayTimer_UsingHWCaptureCounter)
                PosDelayTimer_SetCaptureCount(PosDelayTimer_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!PosDelayTimer_ControlRegRemoved)
            PosDelayTimer_WriteControlRegister(PosDelayTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: PosDelayTimer_Sleep
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
*  PosDelayTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void PosDelayTimer_Sleep(void) 
{
    #if(!PosDelayTimer_ControlRegRemoved)
        /* Save Counter's enable state */
        if(PosDelayTimer_CTRL_ENABLE == (PosDelayTimer_CONTROL & PosDelayTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            PosDelayTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            PosDelayTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    PosDelayTimer_Stop();
    PosDelayTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: PosDelayTimer_Wakeup
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
*  PosDelayTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PosDelayTimer_Wakeup(void) 
{
    PosDelayTimer_RestoreConfig();
    #if(!PosDelayTimer_ControlRegRemoved)
        if(PosDelayTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                PosDelayTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
