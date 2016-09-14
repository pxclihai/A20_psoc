/*******************************************************************************
* File Name: CS1_60_L.c  
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
#include "CS1_60_L.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 CS1_60_L__PORT == 15 && ((CS1_60_L__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: CS1_60_L_Write
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
void CS1_60_L_Write(uint8 value) 
{
    uint8 staticBits = (CS1_60_L_DR & (uint8)(~CS1_60_L_MASK));
    CS1_60_L_DR = staticBits | ((uint8)(value << CS1_60_L_SHIFT) & CS1_60_L_MASK);
}


/*******************************************************************************
* Function Name: CS1_60_L_SetDriveMode
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
void CS1_60_L_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(CS1_60_L_0, mode);
}


/*******************************************************************************
* Function Name: CS1_60_L_Read
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
*  Macro CS1_60_L_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CS1_60_L_Read(void) 
{
    return (CS1_60_L_PS & CS1_60_L_MASK) >> CS1_60_L_SHIFT;
}


/*******************************************************************************
* Function Name: CS1_60_L_ReadDataReg
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
uint8 CS1_60_L_ReadDataReg(void) 
{
    return (CS1_60_L_DR & CS1_60_L_MASK) >> CS1_60_L_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CS1_60_L_INTSTAT) 

    /*******************************************************************************
    * Function Name: CS1_60_L_ClearInterrupt
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
    uint8 CS1_60_L_ClearInterrupt(void) 
    {
        return (CS1_60_L_INTSTAT & CS1_60_L_MASK) >> CS1_60_L_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
