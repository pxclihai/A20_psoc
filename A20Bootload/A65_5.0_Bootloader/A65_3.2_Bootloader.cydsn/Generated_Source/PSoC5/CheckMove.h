/*******************************************************************************
* File Name: CheckMove.h
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
#if !defined(CY_ISR_CheckMove_H)
#define CY_ISR_CheckMove_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void CheckMove_Start(void);
void CheckMove_StartEx(cyisraddress address);
void CheckMove_Stop(void);

CY_ISR_PROTO(CheckMove_Interrupt);

void CheckMove_SetVector(cyisraddress address);
cyisraddress CheckMove_GetVector(void);

void CheckMove_SetPriority(uint8 priority);
uint8 CheckMove_GetPriority(void);

void CheckMove_Enable(void);
uint8 CheckMove_GetState(void);
void CheckMove_Disable(void);

void CheckMove_SetPending(void);
void CheckMove_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the CheckMove ISR. */
#define CheckMove_INTC_VECTOR            ((reg32 *) CheckMove__INTC_VECT)

/* Address of the CheckMove ISR priority. */
#define CheckMove_INTC_PRIOR             ((reg8 *) CheckMove__INTC_PRIOR_REG)

/* Priority of the CheckMove interrupt. */
#define CheckMove_INTC_PRIOR_NUMBER      CheckMove__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable CheckMove interrupt. */
#define CheckMove_INTC_SET_EN            ((reg32 *) CheckMove__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the CheckMove interrupt. */
#define CheckMove_INTC_CLR_EN            ((reg32 *) CheckMove__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the CheckMove interrupt state to pending. */
#define CheckMove_INTC_SET_PD            ((reg32 *) CheckMove__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the CheckMove interrupt. */
#define CheckMove_INTC_CLR_PD            ((reg32 *) CheckMove__INTC_CLR_PD_REG)


#endif /* CY_ISR_CheckMove_H */


/* [] END OF FILE */
