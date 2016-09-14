/*******************************************************************************
* File Name: OUT_YS.c  
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
#include "OUT_YS.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 OUT_YS__PORT == 15 && ((OUT_YS__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: OUT_YS_Write
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
void OUT_YS_Write(uint8 value) 
{
    uint8 staticBits = (OUT_YS_DR & (uint8)(~OUT_YS_MASK));
    OUT_YS_DR = staticBits | ((uint8)(value << OUT_YS_SHIFT) & OUT_YS_MASK);
}


/*******************************************************************************
* Function Name: OUT_YS_SetDriveMode
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
void OUT_YS_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(OUT_YS_0, mode);
}


/*******************************************************************************
* Function Name: OUT_YS_Read
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
*  Macro OUT_YS_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OUT_YS_Read(void) 
{
    return (OUT_YS_PS & OUT_YS_MASK) >> OUT_YS_SHIFT;
}


/*******************************************************************************
* Function Name: OUT_YS_ReadDataReg
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
uint8 OUT_YS_ReadDataReg(void) 
{
    return (OUT_YS_DR & OUT_YS_MASK) >> OUT_YS_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OUT_YS_INTSTAT) 

    /*******************************************************************************
    * Function Name: OUT_YS_ClearInterrupt
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
    uint8 OUT_YS_ClearInterrupt(void) 
    {
        return (OUT_YS_INTSTAT & OUT_YS_MASK) >> OUT_YS_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
