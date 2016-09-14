/*******************************************************************************
* File Name: Voltage_IN.c  
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
#include "Voltage_IN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Voltage_IN__PORT == 15 && ((Voltage_IN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Voltage_IN_Write
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
void Voltage_IN_Write(uint8 value) 
{
    uint8 staticBits = (Voltage_IN_DR & (uint8)(~Voltage_IN_MASK));
    Voltage_IN_DR = staticBits | ((uint8)(value << Voltage_IN_SHIFT) & Voltage_IN_MASK);
}


/*******************************************************************************
* Function Name: Voltage_IN_SetDriveMode
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
void Voltage_IN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Voltage_IN_0, mode);
}


/*******************************************************************************
* Function Name: Voltage_IN_Read
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
*  Macro Voltage_IN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Voltage_IN_Read(void) 
{
    return (Voltage_IN_PS & Voltage_IN_MASK) >> Voltage_IN_SHIFT;
}


/*******************************************************************************
* Function Name: Voltage_IN_ReadDataReg
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
uint8 Voltage_IN_ReadDataReg(void) 
{
    return (Voltage_IN_DR & Voltage_IN_MASK) >> Voltage_IN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Voltage_IN_INTSTAT) 

    /*******************************************************************************
    * Function Name: Voltage_IN_ClearInterrupt
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
    uint8 Voltage_IN_ClearInterrupt(void) 
    {
        return (Voltage_IN_INTSTAT & Voltage_IN_MASK) >> Voltage_IN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
