/*******************************************************************************
* File Name: X_REV.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "X_REV.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 X_REV__PORT == 15 && ((X_REV__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: X_REV_Write
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
void X_REV_Write(uint8 value) 
{
    uint8 staticBits = (X_REV_DR & (uint8)(~X_REV_MASK));
    X_REV_DR = staticBits | ((uint8)(value << X_REV_SHIFT) & X_REV_MASK);
}


/*******************************************************************************
* Function Name: X_REV_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void X_REV_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(X_REV_0, mode);
}


/*******************************************************************************
* Function Name: X_REV_Read
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
*  Macro X_REV_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 X_REV_Read(void) 
{
    return (X_REV_PS & X_REV_MASK) >> X_REV_SHIFT;
}


/*******************************************************************************
* Function Name: X_REV_ReadDataReg
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
uint8 X_REV_ReadDataReg(void) 
{
    return (X_REV_DR & X_REV_MASK) >> X_REV_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(X_REV_INTSTAT) 

    /*******************************************************************************
    * Function Name: X_REV_ClearInterrupt
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
    uint8 X_REV_ClearInterrupt(void) 
    {
        return (X_REV_INTSTAT & X_REV_MASK) >> X_REV_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
