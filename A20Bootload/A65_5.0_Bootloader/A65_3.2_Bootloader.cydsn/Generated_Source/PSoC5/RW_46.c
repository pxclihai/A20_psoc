/*******************************************************************************
* File Name: RW_46.c  
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
#include "RW_46.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 RW_46__PORT == 15 && ((RW_46__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: RW_46_Write
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
void RW_46_Write(uint8 value) 
{
    uint8 staticBits = (RW_46_DR & (uint8)(~RW_46_MASK));
    RW_46_DR = staticBits | ((uint8)(value << RW_46_SHIFT) & RW_46_MASK);
}


/*******************************************************************************
* Function Name: RW_46_SetDriveMode
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
void RW_46_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(RW_46_0, mode);
}


/*******************************************************************************
* Function Name: RW_46_Read
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
*  Macro RW_46_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RW_46_Read(void) 
{
    return (RW_46_PS & RW_46_MASK) >> RW_46_SHIFT;
}


/*******************************************************************************
* Function Name: RW_46_ReadDataReg
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
uint8 RW_46_ReadDataReg(void) 
{
    return (RW_46_DR & RW_46_MASK) >> RW_46_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RW_46_INTSTAT) 

    /*******************************************************************************
    * Function Name: RW_46_ClearInterrupt
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
    uint8 RW_46_ClearInterrupt(void) 
    {
        return (RW_46_INTSTAT & RW_46_MASK) >> RW_46_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
