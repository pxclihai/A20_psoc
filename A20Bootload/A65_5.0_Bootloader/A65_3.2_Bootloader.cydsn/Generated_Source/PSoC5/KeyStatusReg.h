/*******************************************************************************
* File Name: KeyStatusReg.h  
* Version 1.80
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_KeyStatusReg_H) /* CY_STATUS_REG_KeyStatusReg_H */
#define CY_STATUS_REG_KeyStatusReg_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*        Function Prototypes
***************************************/

uint8 KeyStatusReg_Read(void) ;
void KeyStatusReg_InterruptEnable(void) ;
void KeyStatusReg_InterruptDisable(void) ;
void KeyStatusReg_WriteMask(uint8 mask) ;
uint8 KeyStatusReg_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define KeyStatusReg_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define KeyStatusReg_INPUTS              5


/***************************************
*             Registers
***************************************/

/* Status Register */
#define KeyStatusReg_Status             (* (reg8 *) KeyStatusReg_sts_sts_reg__STATUS_REG )
#define KeyStatusReg_Status_PTR         (  (reg8 *) KeyStatusReg_sts_sts_reg__STATUS_REG )
#define KeyStatusReg_Status_Mask        (* (reg8 *) KeyStatusReg_sts_sts_reg__MASK_REG )
#define KeyStatusReg_Status_Aux_Ctrl    (* (reg8 *) KeyStatusReg_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_KeyStatusReg_H */


/* [] END OF FILE */
