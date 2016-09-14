/*******************************************************************************
* File Name: EZ.c  
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
#include "EZ.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 EZ__PORT == 15 && ((EZ__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: EZ_Write
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
void EZ_Write(uint8 value) 
{
    uint8 staticBits = (EZ_DR & (uint8)(~EZ_MASK));
    EZ_DR = staticBits | ((uint8)(value << EZ_SHIFT) & EZ_MASK);
}


/*******************************************************************************
* Function Name: EZ_SetDriveMode
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
void EZ_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(EZ_0, mode);
}


/*******************************************************************************
* Function Name: EZ_Read
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
*  Macro EZ_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 EZ_Read(void) 
{
    return (EZ_PS & EZ_MASK) >> EZ_SHIFT;
}


/*******************************************************************************
* Function Name: EZ_ReadDataReg
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
uint8 EZ_ReadDataReg(void) 
{
    return (EZ_DR & EZ_MASK) >> EZ_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(EZ_INTSTAT) 

    /*******************************************************************************
    * Function Name: EZ_ClearInterrupt
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
    uint8 EZ_ClearInterrupt(void) 
    {
        return (EZ_INTSTAT & EZ_MASK) >> EZ_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
