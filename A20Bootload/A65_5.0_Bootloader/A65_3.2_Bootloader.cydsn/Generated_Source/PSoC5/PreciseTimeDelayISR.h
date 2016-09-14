/*******************************************************************************
* File Name: PreciseTimeDelayISR.h
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
#if !defined(CY_ISR_PreciseTimeDelayISR_H)
#define CY_ISR_PreciseTimeDelayISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void PreciseTimeDelayISR_Start(void);
void PreciseTimeDelayISR_StartEx(cyisraddress address);
void PreciseTimeDelayISR_Stop(void);

CY_ISR_PROTO(PreciseTimeDelayISR_Interrupt);

void PreciseTimeDelayISR_SetVector(cyisraddress address);
cyisraddress PreciseTimeDelayISR_GetVector(void);

void PreciseTimeDelayISR_SetPriority(uint8 priority);
uint8 PreciseTimeDelayISR_GetPriority(void);

void PreciseTimeDelayISR_Enable(void);
uint8 PreciseTimeDelayISR_GetState(void);
void PreciseTimeDelayISR_Disable(void);

void PreciseTimeDelayISR_SetPending(void);
void PreciseTimeDelayISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the PreciseTimeDelayISR ISR. */
#define PreciseTimeDelayISR_INTC_VECTOR            ((reg32 *) PreciseTimeDelayISR__INTC_VECT)

/* Address of the PreciseTimeDelayISR ISR priority. */
#define PreciseTimeDelayISR_INTC_PRIOR             ((reg8 *) PreciseTimeDelayISR__INTC_PRIOR_REG)

/* Priority of the PreciseTimeDelayISR interrupt. */
#define PreciseTimeDelayISR_INTC_PRIOR_NUMBER      PreciseTimeDelayISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable PreciseTimeDelayISR interrupt. */
#define PreciseTimeDelayISR_INTC_SET_EN            ((reg32 *) PreciseTimeDelayISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the PreciseTimeDelayISR interrupt. */
#define PreciseTimeDelayISR_INTC_CLR_EN            ((reg32 *) PreciseTimeDelayISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the PreciseTimeDelayISR interrupt state to pending. */
#define PreciseTimeDelayISR_INTC_SET_PD            ((reg32 *) PreciseTimeDelayISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the PreciseTimeDelayISR interrupt. */
#define PreciseTimeDelayISR_INTC_CLR_PD            ((reg32 *) PreciseTimeDelayISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_PreciseTimeDelayISR_H */


/* [] END OF FILE */
