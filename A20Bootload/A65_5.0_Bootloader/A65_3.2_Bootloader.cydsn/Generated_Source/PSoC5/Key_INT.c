/*******************************************************************************
* File Name: Key_INT.c  
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
#include "Key_INT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Key_INT__PORT == 15 && ((Key_INT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Key_INT_Write
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
void Key_INT_Write(uint8 value) 
{
    uint8 staticBits = (Key_INT_DR & (uint8)(~Key_INT_MASK));
    Key_INT_DR = staticBits | ((uint8)(value << Key_INT_SHIFT) & Key_INT_MASK);
}


/*******************************************************************************
* Function Name: Key_INT_SetDriveMode
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
void Key_INT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Key_INT_0, mode);
}


/*******************************************************************************
* Function Name: Key_INT_Read
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
*  Macro Key_INT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Key_INT_Read(void) 
{
    return (Key_INT_PS & Key_INT_MASK) >> Key_INT_SHIFT;
}


/*******************************************************************************
* Function Name: Key_INT_ReadDataReg
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
uint8 Key_INT_ReadDataReg(void) 
{
    return (Key_INT_DR & Key_INT_MASK) >> Key_INT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Key_INT_INTSTAT) 

    /*******************************************************************************
    * Function Name: Key_INT_ClearInterrupt
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
    uint8 Key_INT_ClearInterrupt(void) 
    {
        return (Key_INT_INTSTAT & Key_INT_MASK) >> Key_INT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
