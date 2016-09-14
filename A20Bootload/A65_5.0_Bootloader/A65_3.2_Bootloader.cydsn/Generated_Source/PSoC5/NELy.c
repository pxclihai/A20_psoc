/*******************************************************************************
* File Name: NELy.c  
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
#include "NELy.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 NELy__PORT == 15 && ((NELy__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: NELy_Write
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
void NELy_Write(uint8 value) 
{
    uint8 staticBits = (NELy_DR & (uint8)(~NELy_MASK));
    NELy_DR = staticBits | ((uint8)(value << NELy_SHIFT) & NELy_MASK);
}


/*******************************************************************************
* Function Name: NELy_SetDriveMode
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
void NELy_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(NELy_0, mode);
}


/*******************************************************************************
* Function Name: NELy_Read
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
*  Macro NELy_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 NELy_Read(void) 
{
    return (NELy_PS & NELy_MASK) >> NELy_SHIFT;
}


/*******************************************************************************
* Function Name: NELy_ReadDataReg
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
uint8 NELy_ReadDataReg(void) 
{
    return (NELy_DR & NELy_MASK) >> NELy_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(NELy_INTSTAT) 

    /*******************************************************************************
    * Function Name: NELy_ClearInterrupt
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
    uint8 NELy_ClearInterrupt(void) 
    {
        return (NELy_INTSTAT & NELy_MASK) >> NELy_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
