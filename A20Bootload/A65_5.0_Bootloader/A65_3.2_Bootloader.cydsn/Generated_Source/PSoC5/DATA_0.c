/*******************************************************************************
* File Name: DATA_0.c  
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
#include "DATA_0.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 DATA_0__PORT == 15 && ((DATA_0__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: DATA_0_Write
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
void DATA_0_Write(uint8 value) 
{
    uint8 staticBits = (DATA_0_DR & (uint8)(~DATA_0_MASK));
    DATA_0_DR = staticBits | ((uint8)(value << DATA_0_SHIFT) & DATA_0_MASK);
}


/*******************************************************************************
* Function Name: DATA_0_SetDriveMode
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
void DATA_0_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DATA_0_0, mode);
	CyPins_SetPinDriveMode(DATA_0_1, mode);
	CyPins_SetPinDriveMode(DATA_0_2, mode);
	CyPins_SetPinDriveMode(DATA_0_3, mode);
	CyPins_SetPinDriveMode(DATA_0_4, mode);
	CyPins_SetPinDriveMode(DATA_0_5, mode);
	CyPins_SetPinDriveMode(DATA_0_6, mode);
	CyPins_SetPinDriveMode(DATA_0_7, mode);
}


/*******************************************************************************
* Function Name: DATA_0_Read
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
*  Macro DATA_0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DATA_0_Read(void) 
{
    return (DATA_0_PS & DATA_0_MASK) >> DATA_0_SHIFT;
}


/*******************************************************************************
* Function Name: DATA_0_ReadDataReg
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
uint8 DATA_0_ReadDataReg(void) 
{
    return (DATA_0_DR & DATA_0_MASK) >> DATA_0_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DATA_0_INTSTAT) 

    /*******************************************************************************
    * Function Name: DATA_0_ClearInterrupt
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
    uint8 DATA_0_ClearInterrupt(void) 
    {
        return (DATA_0_INTSTAT & DATA_0_MASK) >> DATA_0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
