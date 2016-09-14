/*******************************************************************************
* File Name: OUT_11.c  
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
#include "OUT_11.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 OUT_11__PORT == 15 && ((OUT_11__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: OUT_11_Write
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
void OUT_11_Write(uint8 value) 
{
    uint8 staticBits = (OUT_11_DR & (uint8)(~OUT_11_MASK));
    OUT_11_DR = staticBits | ((uint8)(value << OUT_11_SHIFT) & OUT_11_MASK);
}


/*******************************************************************************
* Function Name: OUT_11_SetDriveMode
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
void OUT_11_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(OUT_11_0, mode);
}


/*******************************************************************************
* Function Name: OUT_11_Read
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
*  Macro OUT_11_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OUT_11_Read(void) 
{
    return (OUT_11_PS & OUT_11_MASK) >> OUT_11_SHIFT;
}


/*******************************************************************************
* Function Name: OUT_11_ReadDataReg
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
uint8 OUT_11_ReadDataReg(void) 
{
    return (OUT_11_DR & OUT_11_MASK) >> OUT_11_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OUT_11_INTSTAT) 

    /*******************************************************************************
    * Function Name: OUT_11_ClearInterrupt
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
    uint8 OUT_11_ClearInterrupt(void) 
    {
        return (OUT_11_INTSTAT & OUT_11_MASK) >> OUT_11_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
