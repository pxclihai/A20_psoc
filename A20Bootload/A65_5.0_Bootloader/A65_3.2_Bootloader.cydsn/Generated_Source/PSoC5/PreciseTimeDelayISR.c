/*******************************************************************************
* File Name: PreciseTimeDelayISR.c  
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
#include <PreciseTimeDelayISR.H>

#if !defined(PreciseTimeDelayISR__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START PreciseTimeDelayISR_intc` */

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
* Function Name: PreciseTimeDelayISR_Start
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
void PreciseTimeDelayISR_Start(void)
{
    /* For all we know the interrupt is active. */
    PreciseTimeDelayISR_Disable();

    /* Set the ISR to point to the PreciseTimeDelayISR Interrupt. */
    PreciseTimeDelayISR_SetVector(&PreciseTimeDelayISR_Interrupt);

    /* Set the priority. */
    PreciseTimeDelayISR_SetPriority((uint8)PreciseTimeDelayISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    PreciseTimeDelayISR_Enable();
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_StartEx
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
void PreciseTimeDelayISR_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    PreciseTimeDelayISR_Disable();

    /* Set the ISR to point to the PreciseTimeDelayISR Interrupt. */
    PreciseTimeDelayISR_SetVector(address);

    /* Set the priority. */
    PreciseTimeDelayISR_SetPriority((uint8)PreciseTimeDelayISR_INTC_PRIOR_NUMBER);

    /* Enable it. */
    PreciseTimeDelayISR_Enable();
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_Stop
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
void PreciseTimeDelayISR_Stop(void)
{
    /* Disable this interrupt. */
    PreciseTimeDelayISR_Disable();

    /* Set the ISR to point to the passive one. */
    PreciseTimeDelayISR_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for PreciseTimeDelayISR.
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
CY_ISR(PreciseTimeDelayISR_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START PreciseTimeDelayISR_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling PreciseTimeDelayISR_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use PreciseTimeDelayISR_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void PreciseTimeDelayISR_SetVector(cyisraddress address)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    ramVectorTable[CYINT_IRQ_BASE + (uint32)PreciseTimeDelayISR__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_GetVector
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
cyisraddress PreciseTimeDelayISR_GetVector(void)
{
    cyisraddress * ramVectorTable;

    ramVectorTable = (cyisraddress *) *CYINT_VECT_TABLE;

    return ramVectorTable[CYINT_IRQ_BASE + (uint32)PreciseTimeDelayISR__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling PreciseTimeDelayISR_Start
*   or PreciseTimeDelayISR_StartEx will override any effect this method 
*   would have had. This method should only be called after 
*   PreciseTimeDelayISR_Start or PreciseTimeDelayISR_StartEx has been called. To set 
*   the initial priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void PreciseTimeDelayISR_SetPriority(uint8 priority)
{
    *PreciseTimeDelayISR_INTC_PRIOR = priority << 5;
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_GetPriority
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
uint8 PreciseTimeDelayISR_GetPriority(void)
{
    uint8 priority;


    priority = *PreciseTimeDelayISR_INTC_PRIOR >> 5;

    return priority;
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_Enable
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
void PreciseTimeDelayISR_Enable(void)
{
    /* Enable the general interrupt. */
    *PreciseTimeDelayISR_INTC_SET_EN = PreciseTimeDelayISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_GetState
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
uint8 PreciseTimeDelayISR_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*PreciseTimeDelayISR_INTC_SET_EN & (uint32)PreciseTimeDelayISR__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_Disable
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
void PreciseTimeDelayISR_Disable(void)
{
    /* Disable the general interrupt. */
    *PreciseTimeDelayISR_INTC_CLR_EN = PreciseTimeDelayISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_SetPending
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
void PreciseTimeDelayISR_SetPending(void)
{
    *PreciseTimeDelayISR_INTC_SET_PD = PreciseTimeDelayISR__INTC_MASK;
}


/*******************************************************************************
* Function Name: PreciseTimeDelayISR_ClearPending
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
void PreciseTimeDelayISR_ClearPending(void)
{
    *PreciseTimeDelayISR_INTC_CLR_PD = PreciseTimeDelayISR__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
