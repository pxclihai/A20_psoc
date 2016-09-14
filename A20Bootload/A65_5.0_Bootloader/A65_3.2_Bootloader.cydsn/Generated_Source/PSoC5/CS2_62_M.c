/*******************************************************************************
* File Name: CS2_62_M.c  
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
#include "CS2_62_M.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 CS2_62_M__PORT == 15 && ((CS2_62_M__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: CS2_62_M_Write
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
void CS2_62_M_Write(uint8 value) 
{
    uint8 staticBits = (CS2_62_M_DR & (uint8)(~CS2_62_M_MASK));
    CS2_62_M_DR = staticBits | ((uint8)(value << CS2_62_M_SHIFT) & CS2_62_M_MASK);
}


/*******************************************************************************
* Function Name: CS2_62_M_SetDriveMode
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
void CS2_62_M_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(CS2_62_M_0, mode);
}


/*******************************************************************************
* Function Name: CS2_62_M_Read
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
*  Macro CS2_62_M_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CS2_62_M_Read(void) 
{
    return (CS2_62_M_PS & CS2_62_M_MASK) >> CS2_62_M_SHIFT;
}


/*******************************************************************************
* Function Name: CS2_62_M_ReadDataReg
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
uint8 CS2_62_M_ReadDataReg(void) 
{
    return (CS2_62_M_DR & CS2_62_M_MASK) >> CS2_62_M_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CS2_62_M_INTSTAT) 

    /*******************************************************************************
    * Function Name: CS2_62_M_ClearInterrupt
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
    uint8 CS2_62_M_ClearInterrupt(void) 
    {
        return (CS2_62_M_INTSTAT & CS2_62_M_MASK) >> CS2_62_M_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
