/*******************************************************************************
* File Name: X_FWD.c  
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
#include "X_FWD.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 X_FWD__PORT == 15 && ((X_FWD__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: X_FWD_Write
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
void X_FWD_Write(uint8 value) 
{
    uint8 staticBits = (X_FWD_DR & (uint8)(~X_FWD_MASK));
    X_FWD_DR = staticBits | ((uint8)(value << X_FWD_SHIFT) & X_FWD_MASK);
}


/*******************************************************************************
* Function Name: X_FWD_SetDriveMode
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
void X_FWD_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(X_FWD_0, mode);
}


/*******************************************************************************
* Function Name: X_FWD_Read
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
*  Macro X_FWD_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 X_FWD_Read(void) 
{
    return (X_FWD_PS & X_FWD_MASK) >> X_FWD_SHIFT;
}


/*******************************************************************************
* Function Name: X_FWD_ReadDataReg
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
uint8 X_FWD_ReadDataReg(void) 
{
    return (X_FWD_DR & X_FWD_MASK) >> X_FWD_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(X_FWD_INTSTAT) 

    /*******************************************************************************
    * Function Name: X_FWD_ClearInterrupt
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
    uint8 X_FWD_ClearInterrupt(void) 
    {
        return (X_FWD_INTSTAT & X_FWD_MASK) >> X_FWD_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
