/*******************************************************************************
* File Name: Timer1.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Timer1_H)
#define CY_ISR_Timer1_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Timer1_Start(void);
void Timer1_StartEx(cyisraddress address);
void Timer1_Stop(void);

CY_ISR_PROTO(Timer1_Interrupt);

void Timer1_SetVector(cyisraddress address);
cyisraddress Timer1_GetVector(void);

void Timer1_SetPriority(uint8 priority);
uint8 Timer1_GetPriority(void);

void Timer1_Enable(void);
uint8 Timer1_GetState(void);
void Timer1_Disable(void);

void Timer1_SetPending(void);
void Timer1_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Timer1 ISR. */
#define Timer1_INTC_VECTOR            ((reg32 *) Timer1__INTC_VECT)

/* Address of the Timer1 ISR priority. */
#define Timer1_INTC_PRIOR             ((reg8 *) Timer1__INTC_PRIOR_REG)

/* Priority of the Timer1 interrupt. */
#define Timer1_INTC_PRIOR_NUMBER      Timer1__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Timer1 interrupt. */
#define Timer1_INTC_SET_EN            ((reg32 *) Timer1__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Timer1 interrupt. */
#define Timer1_INTC_CLR_EN            ((reg32 *) Timer1__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Timer1 interrupt state to pending. */
#define Timer1_INTC_SET_PD            ((reg32 *) Timer1__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Timer1 interrupt. */
#define Timer1_INTC_CLR_PD            ((reg32 *) Timer1__INTC_CLR_PD_REG)


#endif /* CY_ISR_Timer1_H */


/* [] END OF FILE */
