/*******************************************************************************
* File Name: CheckMove.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <CYDEVICE_TRM.H>
#include <CYLIB.H>
#include <CheckMove.H>

#if !defined(CheckMove__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START CheckMove_intc` */

/* `#END` */

#ifndef CYINT_IRQ_BASE
#define CYINT_IRQ_BASE      16
#endif /* CYINT_IRQ_BASE */
#ifndef CYINT_VECT_TABLE
#define CYINT_VECT_TABLE    ((cyisraddress **) CYREG_NVIC_VECT_OFFSET)
#endif /* CYINT_VECT_TABLE */

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: CheckMove_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_Start(void)
{
    /* For all we know the interrupt is active. */
    CheckMove_Disable();

    /* Set the ISR to point to the CheckMove Interrupt. */
    CheckMove_SetVector(&CheckMove_Interrupt);

    /* Set the priority. */
    CheckMove_SetPriority((uint8)CheckMove_INTC_PRIOR_NUMBER);

    /* Enable it. */
    CheckMove_Enable();
}


/*******************************************************************************
* Function Name: CheckMove_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    CheckMove_Disable();

    /* Set the ISR to point to the CheckMove Interrupt. */
    CheckMove_SetVector(address);

    /* Set the priority. */
    CheckMove_SetPriority((uint8)CheckMove_INTC_PRIOR_NUMBER);

    /* Enable it. */
    CheckMove_Enable();
}


/*******************************************************************************
* Function Name: CheckMove_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_Stop(void)
{
    /* Disable this interrupt. */
    CheckMove_Disable();

    /* Set the ISR to point to the passive one. */
    CheckMove_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: CheckMove_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for CheckMove.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(CheckMove_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START CheckMove_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: CheckMove_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling CheckMove_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use CheckMove_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)CheckMove__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: CheckMove_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress CheckMove_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)CheckMove__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: CheckMove_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling CheckMove_Start
*   or CheckMove_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   CheckMove_Start or CheckMove_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_SetPriority(uint8 priority)
{
    *CheckMove_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: CheckMove_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*******************************************************************************/
uint8 CheckMove_GetPriority(void)
{
    uint8 priority;


    priority = *CheckMove_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: CheckMove_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_Enable(void)
{
    /* Enable the general interrupt. */
    *CheckMove_INTC_SET_EN = CheckMove__INTC_MASK;
}


/*******************************************************************************
* Function Name: CheckMove_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 CheckMove_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*CheckMove_INTC_SET_EN & (uint32)CheckMove__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: CheckMove_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_Disable(void)
{
    /* Disable the general interrupt. */
    *CheckMove_INTC_CLR_EN = CheckMove__INTC_MASK;
}


/*******************************************************************************
* Function Name: CheckMove_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_SetPending(void)
{
    *CheckMove_INTC_SET_PD = CheckMove__INTC_MASK;
}


/*******************************************************************************
* Function Name: CheckMove_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void CheckMove_ClearPending(void)
{
    *CheckMove_INTC_CLR_PD = CheckMove__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
