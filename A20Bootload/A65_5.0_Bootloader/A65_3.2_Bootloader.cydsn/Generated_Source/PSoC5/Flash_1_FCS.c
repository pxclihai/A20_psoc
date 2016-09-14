/*******************************************************************************
* File Name: Flash_1_FCS.c  
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
#include "Flash_1_FCS.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Flash_1_FCS__PORT == 15 && ((Flash_1_FCS__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Flash_1_FCS_Write
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
void Flash_1_FCS_Write(uint8 value) 
{
    uint8 staticBits = (Flash_1_FCS_DR & (uint8)(~Flash_1_FCS_MASK));
    Flash_1_FCS_DR = staticBits | ((uint8)(value << Flash_1_FCS_SHIFT) & Flash_1_FCS_MASK);
}


/*******************************************************************************
* Function Name: Flash_1_FCS_SetDriveMode
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
void Flash_1_FCS_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Flash_1_FCS_0, mode);
}


/*******************************************************************************
* Function Name: Flash_1_FCS_Read
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
*  Macro Flash_1_FCS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Flash_1_FCS_Read(void) 
{
    return (Flash_1_FCS_PS & Flash_1_FCS_MASK) >> Flash_1_FCS_SHIFT;
}


/*******************************************************************************
* Function Name: Flash_1_FCS_ReadDataReg
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
uint8 Flash_1_FCS_ReadDataReg(void) 
{
    return (Flash_1_FCS_DR & Flash_1_FCS_MASK) >> Flash_1_FCS_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Flash_1_FCS_INTSTAT) 

    /*******************************************************************************
    * Function Name: Flash_1_FCS_ClearInterrupt
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
    uint8 Flash_1_FCS_ClearInterrupt(void) 
    {
        return (Flash_1_FCS_INTSTAT & Flash_1_FCS_MASK) >> Flash_1_FCS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
