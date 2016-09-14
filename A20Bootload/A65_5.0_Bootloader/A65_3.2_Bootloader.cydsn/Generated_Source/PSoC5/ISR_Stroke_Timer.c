/*******************************************************************************
* File Name: ISR_Stroke_Timer.c  
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
#include <ISR_Stroke_Timer.H>

#if !defined(ISR_Stroke_Timer__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START ISR_Stroke_Timer_intc` */

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
* Function Name: ISR_Stroke_Timer_Start
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
void ISR_Stroke_Timer_Start(void)
{
    /* For all we know the interrupt is active. */
    ISR_Stroke_Timer_Disable();

    /* Set the ISR to point to the ISR_Stroke_Timer Interrupt. */
    ISR_Stroke_Timer_SetVector(&ISR_Stroke_Timer_Interrupt);

    /* Set the priority. */
    ISR_Stroke_Timer_SetPriority((uint8)ISR_Stroke_Timer_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Stroke_Timer_Enable();
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_StartEx
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
void ISR_Stroke_Timer_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    ISR_Stroke_Timer_Disable();

    /* Set the ISR to point to the ISR_Stroke_Timer Interrupt. */
    ISR_Stroke_Timer_SetVector(address);

    /* Set the priority. */
    ISR_Stroke_Timer_SetPriority((uint8)ISR_Stroke_Timer_INTC_PRIOR_NUMBER);

    /* Enable it. */
    ISR_Stroke_Timer_Enable();
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_Stop
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
void ISR_Stroke_Timer_Stop(void)
{
    /* Disable this interrupt. */
    ISR_Stroke_Timer_Disable();

    /* Set the ISR to point to the passive one. */
    ISR_Stroke_Timer_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for ISR_Stroke_Timer.
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
CY_ISR(ISR_Stroke_Timer_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START ISR_Stroke_Timer_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling ISR_Stroke_Timer_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use ISR_Stroke_Timer_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Stroke_Timer_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)ISR_Stroke_Timer__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_GetVector
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
cyisraddress ISR_Stroke_Timer_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)ISR_Stroke_Timer__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling ISR_Stroke_Timer_Start
*   or ISR_Stroke_Timer_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   ISR_Stroke_Timer_Start or ISR_Stroke_Timer_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void ISR_Stroke_Timer_SetPriority(uint8 priority)
{
    *ISR_Stroke_Timer_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_GetPriority
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
uint8 ISR_Stroke_Timer_GetPriority(void)
{
    uint8 priority;


    priority = *ISR_Stroke_Timer_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_Enable
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
void ISR_Stroke_Timer_Enable(void)
{
    /* Enable the general interrupt. */
    *ISR_Stroke_Timer_INTC_SET_EN = ISR_Stroke_Timer__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_GetState
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
uint8 ISR_Stroke_Timer_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*ISR_Stroke_Timer_INTC_SET_EN & (uint32)ISR_Stroke_Timer__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_Disable
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
void ISR_Stroke_Timer_Disable(void)
{
    /* Disable the general interrupt. */
    *ISR_Stroke_Timer_INTC_CLR_EN = ISR_Stroke_Timer__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_SetPending
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
void ISR_Stroke_Timer_SetPending(void)
{
    *ISR_Stroke_Timer_INTC_SET_PD = ISR_Stroke_Timer__INTC_MASK;
}


/*******************************************************************************
* Function Name: ISR_Stroke_Timer_ClearPending
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
void ISR_Stroke_Timer_ClearPending(void)
{
    *ISR_Stroke_Timer_INTC_CLR_PD = ISR_Stroke_Timer__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
