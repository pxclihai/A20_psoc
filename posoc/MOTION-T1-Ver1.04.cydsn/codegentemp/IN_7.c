/*******************************************************************************
* File Name: IN_7.c  
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
#include "IN_7.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 IN_7__PORT == 15 && ((IN_7__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: IN_7_Write
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
void IN_7_Write(uint8 value) 
{
    uint8 staticBits = (IN_7_DR & (uint8)(~IN_7_MASK));
    IN_7_DR = staticBits | ((uint8)(value << IN_7_SHIFT) & IN_7_MASK);
}


/*******************************************************************************
* Function Name: IN_7_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  IN_7_DM_STRONG     Strong Drive 
*  IN_7_DM_OD_HI      Open Drain, Drives High 
*  IN_7_DM_OD_LO      Open Drain, Drives Low 
*  IN_7_DM_RES_UP     Resistive Pull Up 
*  IN_7_DM_RES_DWN    Resistive Pull Down 
*  IN_7_DM_RES_UPDWN  Resistive Pull Up/Down 
*  IN_7_DM_DIG_HIZ    High Impedance Digital 
*  IN_7_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void IN_7_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(IN_7_0, mode);
}


/*******************************************************************************
* Function Name: IN_7_Read
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
*  Macro IN_7_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 IN_7_Read(void) 
{
    return (IN_7_PS & IN_7_MASK) >> IN_7_SHIFT;
}


/*******************************************************************************
* Function Name: IN_7_ReadDataReg
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
uint8 IN_7_ReadDataReg(void) 
{
    return (IN_7_DR & IN_7_MASK) >> IN_7_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(IN_7_INTSTAT) 

    /*******************************************************************************
    * Function Name: IN_7_ClearInterrupt
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
    uint8 IN_7_ClearInterrupt(void) 
    {
        return (IN_7_INTSTAT & IN_7_MASK) >> IN_7_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
