/*******************************************************************************
* File Name: UEN.c  
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
#include "UEN.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 UEN__PORT == 15 && ((UEN__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: UEN_Write
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
void UEN_Write(uint8 value) 
{
    uint8 staticBits = (UEN_DR & (uint8)(~UEN_MASK));
    UEN_DR = staticBits | ((uint8)(value << UEN_SHIFT) & UEN_MASK);
}


/*******************************************************************************
* Function Name: UEN_SetDriveMode
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
void UEN_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(UEN_0, mode);
}


/*******************************************************************************
* Function Name: UEN_Read
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
*  Macro UEN_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 UEN_Read(void) 
{
    return (UEN_PS & UEN_MASK) >> UEN_SHIFT;
}


/*******************************************************************************
* Function Name: UEN_ReadDataReg
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
uint8 UEN_ReadDataReg(void) 
{
    return (UEN_DR & UEN_MASK) >> UEN_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(UEN_INTSTAT) 

    /*******************************************************************************
    * Function Name: UEN_ClearInterrupt
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
    uint8 UEN_ClearInterrupt(void) 
    {
        return (UEN_INTSTAT & UEN_MASK) >> UEN_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
