/*******************************************************************************
* File Name: KeyScanTimer_PM.c
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

#include "KeyScanTimer.h"
static KeyScanTimer_backupStruct KeyScanTimer_backup;


/*******************************************************************************
* Function Name: KeyScanTimer_SaveConfig
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
*  KeyScanTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void KeyScanTimer_SaveConfig(void) 
{
    #if (!KeyScanTimer_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            KeyScanTimer_backup.TimerUdb = KeyScanTimer_ReadCounter();
            KeyScanTimer_backup.TimerPeriod = KeyScanTimer_ReadPeriod();
            KeyScanTimer_backup.InterruptMaskValue = KeyScanTimer_STATUS_MASK;
            #if (KeyScanTimer_UsingHWCaptureCounter)
                KeyScanTimer_backup.TimerCaptureCounter = KeyScanTimer_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            KeyScanTimer_backup.TimerUdb = KeyScanTimer_ReadCounter();
            KeyScanTimer_backup.InterruptMaskValue = KeyScanTimer_STATUS_MASK;
            #if (KeyScanTimer_UsingHWCaptureCounter)
                KeyScanTimer_backup.TimerCaptureCounter = KeyScanTimer_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!KeyScanTimer_ControlRegRemoved)
            KeyScanTimer_backup.TimerControlRegister = KeyScanTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: KeyScanTimer_RestoreConfig
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
*  KeyScanTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void KeyScanTimer_RestoreConfig(void) 
{   
    #if (!KeyScanTimer_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 KeyScanTimer_interruptState;

            KeyScanTimer_WriteCounter(KeyScanTimer_backup.TimerUdb);
            KeyScanTimer_WritePeriod(KeyScanTimer_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            KeyScanTimer_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            KeyScanTimer_STATUS_AUX_CTRL |= KeyScanTimer_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(KeyScanTimer_interruptState);
            KeyScanTimer_STATUS_MASK =KeyScanTimer_backup.InterruptMaskValue;
            #if (KeyScanTimer_UsingHWCaptureCounter)
                KeyScanTimer_SetCaptureCount(KeyScanTimer_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            KeyScanTimer_WriteCounter(KeyScanTimer_backup.TimerUdb);
            KeyScanTimer_STATUS_MASK =KeyScanTimer_backup.InterruptMaskValue;
            #if (KeyScanTimer_UsingHWCaptureCounter)
                KeyScanTimer_SetCaptureCount(KeyScanTimer_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!KeyScanTimer_ControlRegRemoved)
            KeyScanTimer_WriteControlRegister(KeyScanTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: KeyScanTimer_Sleep
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
*  KeyScanTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void KeyScanTimer_Sleep(void) 
{
    #if(!KeyScanTimer_ControlRegRemoved)
        /* Save Counter's enable state */
        if(KeyScanTimer_CTRL_ENABLE == (KeyScanTimer_CONTROL & KeyScanTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            KeyScanTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            KeyScanTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    KeyScanTimer_Stop();
    KeyScanTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: KeyScanTimer_Wakeup
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
*  KeyScanTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void KeyScanTimer_Wakeup(void) 
{
    KeyScanTimer_RestoreConfig();
    #if(!KeyScanTimer_ControlRegRemoved)
        if(KeyScanTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                KeyScanTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
