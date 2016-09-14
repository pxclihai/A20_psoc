/*******************************************************************************
* File Name: EA.c  
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
#include "EA.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 EA__PORT == 15 && ((EA__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: EA_Write
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
void EA_Write(uint8 value) 
{
    uint8 staticBits = (EA_DR & (uint8)(~EA_MASK));
    EA_DR = staticBits | ((uint8)(value << EA_SHIFT) & EA_MASK);
}


/*******************************************************************************
* Function Name: EA_SetDriveMode
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
void EA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EA_0, mode);
}


/*******************************************************************************
* Function Name: EA_Read
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
*  Macro EA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EA_Read(void) 
{
    return (EA_PS & EA_MASK) >> EA_SHIFT;
}


/*******************************************************************************
* Function Name: EA_ReadDataReg
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
uint8 EA_ReadDataReg(void) 
{
    return (EA_DR & EA_MASK) >> EA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EA_INTSTAT) 

    /*******************************************************************************
    * Function Name: EA_ClearInterrupt
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
    uint8 EA_ClearInterrupt(void) 
    {
        return (EA_INTSTAT & EA_MASK) >> EA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
