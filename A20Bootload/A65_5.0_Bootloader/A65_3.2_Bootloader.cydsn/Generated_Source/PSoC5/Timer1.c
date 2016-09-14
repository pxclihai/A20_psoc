/*******************************************************************************
* File Name: Timer1.c  
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
#include <Timer1.H>

#if !defined(Timer1__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START Timer1_intc` */

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
* Function Name: Timer1_Start
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
void Timer1_Start(void)
{
    /* For all we know the interrupt is active. */
    Timer1_Disable();

    /* Set the ISR to point to the Timer1 Interrupt. */
    Timer1_SetVector(&Timer1_Interrupt);

    /* Set the priority. */
    Timer1_SetPriority((uint8)Timer1_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Timer1_Enable();
}


/*******************************************************************************
* Function Name: Timer1_StartEx
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
void Timer1_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    Timer1_Disable();

    /* Set the ISR to point to the Timer1 Interrupt. */
    Timer1_SetVector(address);

    /* Set the priority. */
    Timer1_SetPriority((uint8)Timer1_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Timer1_Enable();
}


/*******************************************************************************
* Function Name: Timer1_Stop
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
void Timer1_Stop(void)
{
    /* Disable this interrupt. */
    Timer1_Disable();

    /* Set the ISR to point to the passive one. */
    Timer1_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: Timer1_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for Timer1.
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
CY_ISR(Timer1_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START Timer1_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: Timer1_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling Timer1_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use Timer1_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void Timer1_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)Timer1__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: Timer1_GetVector
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
cyisraddress Timer1_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)Timer1__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: Timer1_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling Timer1_Start
*   or Timer1_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   Timer1_Start or Timer1_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void Timer1_SetPriority(uint8 priority)
{
    *Timer1_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: Timer1_GetPriority
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
uint8 Timer1_GetPriority(void)
{
    uint8 priority;


    priority = *Timer1_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: Timer1_Enable
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
void Timer1_Enable(void)
{
    /* Enable the general interrupt. */
    *Timer1_INTC_SET_EN = Timer1__INTC_MASK;
}


/*******************************************************************************
* Function Name: Timer1_GetState
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
uint8 Timer1_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*Timer1_INTC_SET_EN & (uint32)Timer1__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: Timer1_Disable
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
void Timer1_Disable(void)
{
    /* Disable the general interrupt. */
    *Timer1_INTC_CLR_EN = Timer1__INTC_MASK;
}


/*******************************************************************************
* Function Name: Timer1_SetPending
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
void Timer1_SetPending(void)
{
    *Timer1_INTC_SET_PD = Timer1__INTC_MASK;
}


/*******************************************************************************
* Function Name: Timer1_ClearPending
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
void Timer1_ClearPending(void)
{
    *Timer1_INTC_CLR_PD = Timer1__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
