/*******************************************************************************
* File Name: EAy.c  
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
#include "EAy.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 EAy__PORT == 15 && ((EAy__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: EAy_Write
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
void EAy_Write(uint8 value) 
{
    uint8 staticBits = (EAy_DR & (uint8)(~EAy_MASK));
    EAy_DR = staticBits | ((uint8)(value << EAy_SHIFT) & EAy_MASK);
}


/*******************************************************************************
* Function Name: EAy_SetDriveMode
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
void EAy_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EAy_0, mode);
}


/*******************************************************************************
* Function Name: EAy_Read
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
*  Macro EAy_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EAy_Read(void) 
{
    return (EAy_PS & EAy_MASK) >> EAy_SHIFT;
}


/*******************************************************************************
* Function Name: EAy_ReadDataReg
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
uint8 EAy_ReadDataReg(void) 
{
    return (EAy_DR & EAy_MASK) >> EAy_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EAy_INTSTAT) 

    /*******************************************************************************
    * Function Name: EAy_ClearInterrupt
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
    uint8 EAy_ClearInterrupt(void) 
    {
        return (EAy_INTSTAT & EAy_MASK) >> EAy_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
