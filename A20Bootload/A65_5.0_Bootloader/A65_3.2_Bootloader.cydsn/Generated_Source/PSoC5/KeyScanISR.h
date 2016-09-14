/*******************************************************************************
* File Name: KeyScanISR.h
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
#if !defined(CY_ISR_KeyScanISR_H)
#define CY_ISR_KeyScanISR_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void KeyScanISR_Start(void);
void KeyScanISR_StartEx(cyisraddress address);
void KeyScanISR_Stop(void);

CY_ISR_PROTO(KeyScanISR_Interrupt);

void KeyScanISR_SetVector(cyisraddress address);
cyisraddress KeyScanISR_GetVector(void);

void KeyScanISR_SetPriority(uint8 priority);
uint8 KeyScanISR_GetPriority(void);

void KeyScanISR_Enable(void);
uint8 KeyScanISR_GetState(void);
void KeyScanISR_Disable(void);

void KeyScanISR_SetPending(void);
void KeyScanISR_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the KeyScanISR ISR. */
#define KeyScanISR_INTC_VECTOR            ((reg32 *) KeyScanISR__INTC_VECT)

/* Address of the KeyScanISR ISR priority. */
#define KeyScanISR_INTC_PRIOR             ((reg8 *) KeyScanISR__INTC_PRIOR_REG)

/* Priority of the KeyScanISR interrupt. */
#define KeyScanISR_INTC_PRIOR_NUMBER      KeyScanISR__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable KeyScanISR interrupt. */
#define KeyScanISR_INTC_SET_EN            ((reg32 *) KeyScanISR__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the KeyScanISR interrupt. */
#define KeyScanISR_INTC_CLR_EN            ((reg32 *) KeyScanISR__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the KeyScanISR interrupt state to pending. */
#define KeyScanISR_INTC_SET_PD            ((reg32 *) KeyScanISR__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the KeyScanISR interrupt. */
#define KeyScanISR_INTC_CLR_PD            ((reg32 *) KeyScanISR__INTC_CLR_PD_REG)


#endif /* CY_ISR_KeyScanISR_H */


/* [] END OF FILE */
