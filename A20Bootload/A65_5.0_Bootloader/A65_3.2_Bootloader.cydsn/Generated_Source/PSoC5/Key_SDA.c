/*******************************************************************************
* File Name: Key_SDA.c  
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
#include "Key_SDA.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Key_SDA__PORT == 15 && ((Key_SDA__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Key_SDA_Write
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
void Key_SDA_Write(uint8 value) 
{
    uint8 staticBits = (Key_SDA_DR & (uint8)(~Key_SDA_MASK));
    Key_SDA_DR = staticBits | ((uint8)(value << Key_SDA_SHIFT) & Key_SDA_MASK);
}


/*******************************************************************************
* Function Name: Key_SDA_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Key_SDA_DM_STRONG     Strong Drive 
*  Key_SDA_DM_OD_HI      Open Drain, Drives High 
*  Key_SDA_DM_OD_LO      Open Drain, Drives Low 
*  Key_SDA_DM_RES_UP     Resistive Pull Up 
*  Key_SDA_DM_RES_DWN    Resistive Pull Down 
*  Key_SDA_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Key_SDA_DM_DIG_HIZ    High Impedance Digital 
*  Key_SDA_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Key_SDA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Key_SDA_0, mode);
}


/*******************************************************************************
* Function Name: Key_SDA_Read
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
*  Macro Key_SDA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Key_SDA_Read(void) 
{
    return (Key_SDA_PS & Key_SDA_MASK) >> Key_SDA_SHIFT;
}


/*******************************************************************************
* Function Name: Key_SDA_ReadDataReg
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
uint8 Key_SDA_ReadDataReg(void) 
{
    return (Key_SDA_DR & Key_SDA_MASK) >> Key_SDA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Key_SDA_INTSTAT) 

    /*******************************************************************************
    * Function Name: Key_SDA_ClearInterrupt
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
    uint8 Key_SDA_ClearInterrupt(void) 
    {
        return (Key_SDA_INTSTAT & Key_SDA_MASK) >> Key_SDA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
