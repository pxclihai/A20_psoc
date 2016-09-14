/*******************************************************************************
* File Name: KeyScanTimer_1_PM.c
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

#include "KeyScanTimer_1.h"
static KeyScanTimer_1_backupStruct KeyScanTimer_1_backup;


/*******************************************************************************
* Function Name: KeyScanTimer_1_SaveConfig
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
*  KeyScanTimer_1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void KeyScanTimer_1_SaveConfig(void) 
{
    #if (!KeyScanTimer_1_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            KeyScanTimer_1_backup.TimerUdb = KeyScanTimer_1_ReadCounter();
            KeyScanTimer_1_backup.TimerPeriod = KeyScanTimer_1_ReadPeriod();
            KeyScanTimer_1_backup.InterruptMaskValue = KeyScanTimer_1_STATUS_MASK;
            #if (KeyScanTimer_1_UsingHWCaptureCounter)
                KeyScanTimer_1_backup.TimerCaptureCounter = KeyScanTimer_1_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            KeyScanTimer_1_backup.TimerUdb = KeyScanTimer_1_ReadCounter();
            KeyScanTimer_1_backup.InterruptMaskValue = KeyScanTimer_1_STATUS_MASK;
            #if (KeyScanTimer_1_UsingHWCaptureCounter)
                KeyScanTimer_1_backup.TimerCaptureCounter = KeyScanTimer_1_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!KeyScanTimer_1_ControlRegRemoved)
            KeyScanTimer_1_backup.TimerControlRegister = KeyScanTimer_1_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: KeyScanTimer_1_RestoreConfig
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
*  KeyScanTimer_1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void KeyScanTimer_1_RestoreConfig(void) 
{   
    #if (!KeyScanTimer_1_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 KeyScanTimer_1_interruptState;

            KeyScanTimer_1_WriteCounter(KeyScanTimer_1_backup.TimerUdb);
            KeyScanTimer_1_WritePeriod(KeyScanTimer_1_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            KeyScanTimer_1_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            KeyScanTimer_1_STATUS_AUX_CTRL |= KeyScanTimer_1_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(KeyScanTimer_1_interruptState);
            KeyScanTimer_1_STATUS_MASK =KeyScanTimer_1_backup.InterruptMaskValue;
            #if (KeyScanTimer_1_UsingHWCaptureCounter)
                KeyScanTimer_1_SetCaptureCount(KeyScanTimer_1_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            KeyScanTimer_1_WriteCounter(KeyScanTimer_1_backup.TimerUdb);
            KeyScanTimer_1_STATUS_MASK =KeyScanTimer_1_backup.InterruptMaskValue;
            #if (KeyScanTimer_1_UsingHWCaptureCounter)
                KeyScanTimer_1_SetCaptureCount(KeyScanTimer_1_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!KeyScanTimer_1_ControlRegRemoved)
            KeyScanTimer_1_WriteControlRegister(KeyScanTimer_1_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: KeyScanTimer_1_Sleep
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
*  KeyScanTimer_1_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void KeyScanTimer_1_Sleep(void) 
{
    #if(!KeyScanTimer_1_ControlRegRemoved)
        /* Save Counter's enable state */
        if(KeyScanTimer_1_CTRL_ENABLE == (KeyScanTimer_1_CONTROL & KeyScanTimer_1_CTRL_ENABLE))
        {
            /* Timer is enabled */
            KeyScanTimer_1_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            KeyScanTimer_1_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    KeyScanTimer_1_Stop();
    KeyScanTimer_1_SaveConfig();
}


/*******************************************************************************
* Function Name: KeyScanTimer_1_Wakeup
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
*  KeyScanTimer_1_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void KeyScanTimer_1_Wakeup(void) 
{
    KeyScanTimer_1_RestoreConfig();
    #if(!KeyScanTimer_1_ControlRegRemoved)
        if(KeyScanTimer_1_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                KeyScanTimer_1_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
