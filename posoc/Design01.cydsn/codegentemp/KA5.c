/*******************************************************************************
* File Name: KA5.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "KA5.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 KA5__PORT == 15 && ((KA5__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: KA5_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void KA5_Write(uint8 value) 
{
    uint8 staticBits = (KA5_DR & (uint8)(~KA5_MASK));
    KA5_DR = staticBits | ((uint8)(value << KA5_SHIFT) & KA5_MASK);
}


/*******************************************************************************
* Function Name: KA5_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  KA5_DM_STRONG     Strong Drive 
*  KA5_DM_OD_HI      Open Drain, Drives High 
*  KA5_DM_OD_LO      Open Drain, Drives Low 
*  KA5_DM_RES_UP     Resistive Pull Up 
*  KA5_DM_RES_DWN    Resistive Pull Down 
*  KA5_DM_RES_UPDWN  Resistive Pull Up/Down 
*  KA5_DM_DIG_HIZ    High Impedance Digital 
*  KA5_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void KA5_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(KA5_0, mode);
}


/*******************************************************************************
* Function Name: KA5_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro KA5_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 KA5_Read(void) 
{
    return (KA5_PS & KA5_MASK) >> KA5_SHIFT;
}


/*******************************************************************************
* Function Name: KA5_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 KA5_ReadDataReg(void) 
{
    return (KA5_DR & KA5_MASK) >> KA5_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(KA5_INTSTAT) 

    /*******************************************************************************
    * Function Name: KA5_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 KA5_ClearInterrupt(void) 
    {
        return (KA5_INTSTAT & KA5_MASK) >> KA5_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
