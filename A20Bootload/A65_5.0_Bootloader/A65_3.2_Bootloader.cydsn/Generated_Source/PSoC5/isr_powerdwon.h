/*******************************************************************************
* File Name: isr_powerdwon.h
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
#if !defined(CY_ISR_isr_powerdwon_H)
#define CY_ISR_isr_powerdwon_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_powerdwon_Start(void);
void isr_powerdwon_StartEx(cyisraddress address);
void isr_powerdwon_Stop(void);

CY_ISR_PROTO(isr_powerdwon_Interrupt);

void isr_powerdwon_SetVector(cyisraddress address);
cyisraddress isr_powerdwon_GetVector(void);

void isr_powerdwon_SetPriority(uint8 priority);
uint8 isr_powerdwon_GetPriority(void);

void isr_powerdwon_Enable(void);
uint8 isr_powerdwon_GetState(void);
void isr_powerdwon_Disable(void);

void isr_powerdwon_SetPending(void);
void isr_powerdwon_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_powerdwon ISR. */
#define isr_powerdwon_INTC_VECTOR            ((reg32 *) isr_powerdwon__INTC_VECT)

/* Address of the isr_powerdwon ISR priority. */
#define isr_powerdwon_INTC_PRIOR             ((reg8 *) isr_powerdwon__INTC_PRIOR_REG)

/* Priority of the isr_powerdwon interrupt. */
#define isr_powerdwon_INTC_PRIOR_NUMBER      isr_powerdwon__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_powerdwon interrupt. */
#define isr_powerdwon_INTC_SET_EN            ((reg32 *) isr_powerdwon__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_powerdwon interrupt. */
#define isr_powerdwon_INTC_CLR_EN            ((reg32 *) isr_powerdwon__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_powerdwon interrupt state to pending. */
#define isr_powerdwon_INTC_SET_PD            ((reg32 *) isr_powerdwon__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_powerdwon interrupt. */
#define isr_powerdwon_INTC_CLR_PD            ((reg32 *) isr_powerdwon__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_powerdwon_H */


/* [] END OF FILE */
