/*******************************************************************************
* File Name: IN_10.c  
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
#include "IN_10.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 IN_10__PORT == 15 && ((IN_10__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: IN_10_Write
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
void IN_10_Write(uint8 value) 
{
    uint8 staticBits = (IN_10_DR & (uint8)(~IN_10_MASK));
    IN_10_DR = staticBits | ((uint8)(value << IN_10_SHIFT) & IN_10_MASK);
}


/*******************************************************************************
* Function Name: IN_10_SetDriveMode
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
void IN_10_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(IN_10_0, mode);
}


/*******************************************************************************
* Function Name: IN_10_Read
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
*  Macro IN_10_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 IN_10_Read(void) 
{
    return (IN_10_PS & IN_10_MASK) >> IN_10_SHIFT;
}


/*******************************************************************************
* Function Name: IN_10_ReadDataReg
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
uint8 IN_10_ReadDataReg(void) 
{
    return (IN_10_DR & IN_10_MASK) >> IN_10_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(IN_10_INTSTAT) 

    /*******************************************************************************
    * Function Name: IN_10_ClearInterrupt
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
    uint8 IN_10_ClearInterrupt(void) 
    {
        return (IN_10_INTSTAT & IN_10_MASK) >> IN_10_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
