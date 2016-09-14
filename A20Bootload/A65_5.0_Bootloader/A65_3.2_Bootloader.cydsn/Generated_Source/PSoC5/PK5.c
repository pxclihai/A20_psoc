/*******************************************************************************
* File Name: PK5.c  
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
#include "PK5.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PK5__PORT == 15 && ((PK5__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PK5_Write
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
void PK5_Write(uint8 value) 
{
    uint8 staticBits = (PK5_DR & (uint8)(~PK5_MASK));
    PK5_DR = staticBits | ((uint8)(value << PK5_SHIFT) & PK5_MASK);
}


/*******************************************************************************
* Function Name: PK5_SetDriveMode
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
void PK5_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PK5_0, mode);
}


/*******************************************************************************
* Function Name: PK5_Read
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
*  Macro PK5_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PK5_Read(void) 
{
    return (PK5_PS & PK5_MASK) >> PK5_SHIFT;
}


/*******************************************************************************
* Function Name: PK5_ReadDataReg
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
uint8 PK5_ReadDataReg(void) 
{
    return (PK5_DR & PK5_MASK) >> PK5_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PK5_INTSTAT) 

    /*******************************************************************************
    * Function Name: PK5_ClearInterrupt
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
    uint8 PK5_ClearInterrupt(void) 
    {
        return (PK5_INTSTAT & PK5_MASK) >> PK5_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
