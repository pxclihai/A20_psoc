/*******************************************************************************
* File Name: isr_decoder.h
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
#if !defined(CY_ISR_isr_decoder_H)
#define CY_ISR_isr_decoder_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isr_decoder_Start(void);
void isr_decoder_StartEx(cyisraddress address);
void isr_decoder_Stop(void);

CY_ISR_PROTO(isr_decoder_Interrupt);

void isr_decoder_SetVector(cyisraddress address);
cyisraddress isr_decoder_GetVector(void);

void isr_decoder_SetPriority(uint8 priority);
uint8 isr_decoder_GetPriority(void);

void isr_decoder_Enable(void);
uint8 isr_decoder_GetState(void);
void isr_decoder_Disable(void);

void isr_decoder_SetPending(void);
void isr_decoder_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isr_decoder ISR. */
#define isr_decoder_INTC_VECTOR            ((reg32 *) isr_decoder__INTC_VECT)

/* Address of the isr_decoder ISR priority. */
#define isr_decoder_INTC_PRIOR             ((reg8 *) isr_decoder__INTC_PRIOR_REG)

/* Priority of the isr_decoder interrupt. */
#define isr_decoder_INTC_PRIOR_NUMBER      isr_decoder__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isr_decoder interrupt. */
#define isr_decoder_INTC_SET_EN            ((reg32 *) isr_decoder__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isr_decoder interrupt. */
#define isr_decoder_INTC_CLR_EN            ((reg32 *) isr_decoder__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isr_decoder interrupt state to pending. */
#define isr_decoder_INTC_SET_PD            ((reg32 *) isr_decoder__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isr_decoder interrupt. */
#define isr_decoder_INTC_CLR_PD            ((reg32 *) isr_decoder__INTC_CLR_PD_REG)


#endif /* CY_ISR_isr_decoder_H */


/* [] END OF FILE */
