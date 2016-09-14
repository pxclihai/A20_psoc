/*******************************************************************************
* File Name: E_47.c  
* Version 1.80
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
#include "E_47.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 E_47__PORT == 15 && ((E_47__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: E_47_Write
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
void E_47_Write(uint8 value) 
{
    uint8 staticBits = (E_47_DR & (uint8)(~E_47_MASK));
    E_47_DR = staticBits | ((uint8)(value << E_47_SHIFT) & E_47_MASK);
}


/*******************************************************************************
* Function Name: E_47_SetDriveMode
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
void E_47_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(E_47_0, mode);
}


/*******************************************************************************
* Function Name: E_47_Read
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
*  Macro E_47_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 E_47_Read(void) 
{
    return (E_47_PS & E_47_MASK) >> E_47_SHIFT;
}


/*******************************************************************************
* Function Name: E_47_ReadDataReg
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
uint8 E_47_ReadDataReg(void) 
{
    return (E_47_DR & E_47_MASK) >> E_47_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(E_47_INTSTAT) 

    /*******************************************************************************
    * Function Name: E_47_ClearInterrupt
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
    uint8 E_47_ClearInterrupt(void) 
    {
        return (E_47_INTSTAT & E_47_MASK) >> E_47_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
