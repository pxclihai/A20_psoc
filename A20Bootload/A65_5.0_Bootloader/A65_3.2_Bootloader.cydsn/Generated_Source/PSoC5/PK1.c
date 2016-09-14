/*******************************************************************************
* File Name: PK1.c  
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
#include "PK1.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PK1__PORT == 15 && ((PK1__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PK1_Write
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
void PK1_Write(uint8 value) 
{
    uint8 staticBits = (PK1_DR & (uint8)(~PK1_MASK));
    PK1_DR = staticBits | ((uint8)(value << PK1_SHIFT) & PK1_MASK);
}


/*******************************************************************************
* Function Name: PK1_SetDriveMode
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
void PK1_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PK1_0, mode);
}


/*******************************************************************************
* Function Name: PK1_Read
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
*  Macro PK1_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PK1_Read(void) 
{
    return (PK1_PS & PK1_MASK) >> PK1_SHIFT;
}


/*******************************************************************************
* Function Name: PK1_ReadDataReg
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
uint8 PK1_ReadDataReg(void) 
{
    return (PK1_DR & PK1_MASK) >> PK1_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PK1_INTSTAT) 

    /*******************************************************************************
    * Function Name: PK1_ClearInterrupt
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
    uint8 PK1_ClearInterrupt(void) 
    {
        return (PK1_INTSTAT & PK1_MASK) >> PK1_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
