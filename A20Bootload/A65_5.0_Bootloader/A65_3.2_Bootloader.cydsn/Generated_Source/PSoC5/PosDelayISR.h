/*******************************************************************************
* File Name: PosDelayISR.h
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
#if !defined(CY_ISR_PosDelayISR_H)
#define CY_ISR_PosDelayISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void PosDelayISR_Start(void);
void PosDelayISR_StartEx(cyisraddress address);
void PosDelayISR_Stop(void);

CY_ISR_PROTO(PosDelayISR_Interrupt);

void PosDelayISR_SetVector(cyisraddress address);
cyisraddress PosDelayISR_GetVector(void);

void PosDelayISR_SetPriority(uint8 priority);
uint8 PosDelayISR_GetPriority(void);

void PosDelayISR_Enable(void);
uint8 PosDelayISR_GetState(void);
void PosDelayISR_Disable(void);

void PosDelayISR_SetPending(void);
void PosDelayISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the PosDelayISR ISR. */
#define PosDelayISR_INTC_VECTOR            ((reg32 *) PosDelayISR__INTC_VECT)

/* Address of the PosDelayISR ISR priority. */
#define PosDelayISR_INTC_PRIOR             ((reg8 *) PosDelayISR__INTC_PRIOR_REG)

/* Priority of the PosDelayISR interrupt. */
#define PosDelayISR_INTC_PRIOR_NUMBER      PosDelayISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable PosDelayISR interrupt. */
#define PosDelayISR_INTC_SET_EN            ((reg32 *) PosDelayISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the PosDelayISR interrupt. */
#define PosDelayISR_INTC_CLR_EN            ((reg32 *) PosDelayISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the PosDelayISR interrupt state to pending. */
#define PosDelayISR_INTC_SET_PD            ((reg32 *) PosDelayISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the PosDelayISR interrupt. */
#define PosDelayISR_INTC_CLR_PD            ((reg32 *) PosDelayISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_PosDelayISR_H */


/* [] END OF FILE */
