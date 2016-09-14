/*******************************************************************************
* File Name: KeyStatusReg.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "KeyStatusReg.h"

#if !defined(KeyStatusReg_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: KeyStatusReg_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 KeyStatusReg_Read(void) 
{ 
    return KeyStatusReg_Status;
}


/*******************************************************************************
* Function Name: KeyStatusReg_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void KeyStatusReg_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    KeyStatusReg_Status_Aux_Ctrl |= KeyStatusReg_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: KeyStatusReg_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void KeyStatusReg_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    KeyStatusReg_Status_Aux_Ctrl &= (uint8)(~KeyStatusReg_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: KeyStatusReg_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void KeyStatusReg_WriteMask(uint8 mask) 
{
    #if(KeyStatusReg_INPUTS < 8u)
    	mask &= (uint8)((((uint8)1u) << KeyStatusReg_INPUTS) - 1u);
	#endif /* End KeyStatusReg_INPUTS < 8u */
    KeyStatusReg_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: KeyStatusReg_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 KeyStatusReg_ReadMask(void) 
{
    return KeyStatusReg_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
