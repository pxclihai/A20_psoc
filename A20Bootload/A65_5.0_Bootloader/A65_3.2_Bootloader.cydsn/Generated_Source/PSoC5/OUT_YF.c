/*******************************************************************************
* File Name: OUT_YF.c  
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
#include "OUT_YF.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 OUT_YF__PORT == 15 && ((OUT_YF__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: OUT_YF_Write
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
void OUT_YF_Write(uint8 value) 
{
    uint8 staticBits = (OUT_YF_DR & (uint8)(~OUT_YF_MASK));
    OUT_YF_DR = staticBits | ((uint8)(value << OUT_YF_SHIFT) & OUT_YF_MASK);
}


/*******************************************************************************
* Function Name: OUT_YF_SetDriveMode
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
void OUT_YF_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(OUT_YF_0, mode);
}


/*******************************************************************************
* Function Name: OUT_YF_Read
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
*  Macro OUT_YF_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OUT_YF_Read(void) 
{
    return (OUT_YF_PS & OUT_YF_MASK) >> OUT_YF_SHIFT;
}


/*******************************************************************************
* Function Name: OUT_YF_ReadDataReg
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
uint8 OUT_YF_ReadDataReg(void) 
{
    return (OUT_YF_DR & OUT_YF_MASK) >> OUT_YF_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OUT_YF_INTSTAT) 

    /*******************************************************************************
    * Function Name: OUT_YF_ClearInterrupt
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
    uint8 OUT_YF_ClearInterrupt(void) 
    {
        return (OUT_YF_INTSTAT & OUT_YF_MASK) >> OUT_YF_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
