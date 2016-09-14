/*******************************************************************************
* File Name: RD.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "RD.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 RD__PORT == 15 && ((RD__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: RD_Write
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
void RD_Write(uint8 value) 
{
    uint8 staticBits = (RD_DR & (uint8)(~RD_MASK));
    RD_DR = staticBits | ((uint8)(value << RD_SHIFT) & RD_MASK);
}


/*******************************************************************************
* Function Name: RD_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  RD_DM_STRONG     Strong Drive 
*  RD_DM_OD_HI      Open Drain, Drives High 
*  RD_DM_OD_LO      Open Drain, Drives Low 
*  RD_DM_RES_UP     Resistive Pull Up 
*  RD_DM_RES_DWN    Resistive Pull Down 
*  RD_DM_RES_UPDWN  Resistive Pull Up/Down 
*  RD_DM_DIG_HIZ    High Impedance Digital 
*  RD_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void RD_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(RD_0, mode);
}


/*******************************************************************************
* Function Name: RD_Read
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
*  Macro RD_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 RD_Read(void) 
{
    return (RD_PS & RD_MASK) >> RD_SHIFT;
}


/*******************************************************************************
* Function Name: RD_ReadDataReg
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
uint8 RD_ReadDataReg(void) 
{
    return (RD_DR & RD_MASK) >> RD_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(RD_INTSTAT) 

    /*******************************************************************************
    * Function Name: RD_ClearInterrupt
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
    uint8 RD_ClearInterrupt(void) 
    {
        return (RD_INTSTAT & RD_MASK) >> RD_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
