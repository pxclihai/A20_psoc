/*******************************************************************************
* File Name: OUT_12.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_OUT_12_H) /* Pins OUT_12_H */
#define CY_PINS_OUT_12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OUT_12_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OUT_12__PORT == 15 && ((OUT_12__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    OUT_12_Write(uint8 value) ;
void    OUT_12_SetDriveMode(uint8 mode) ;
uint8   OUT_12_ReadDataReg(void) ;
uint8   OUT_12_Read(void) ;
uint8   OUT_12_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OUT_12_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define OUT_12_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define OUT_12_DM_RES_UP          PIN_DM_RES_UP
#define OUT_12_DM_RES_DWN         PIN_DM_RES_DWN
#define OUT_12_DM_OD_LO           PIN_DM_OD_LO
#define OUT_12_DM_OD_HI           PIN_DM_OD_HI
#define OUT_12_DM_STRONG          PIN_DM_STRONG
#define OUT_12_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define OUT_12_MASK               OUT_12__MASK
#define OUT_12_SHIFT              OUT_12__SHIFT
#define OUT_12_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OUT_12_PS                     (* (reg8 *) OUT_12__PS)
/* Data Register */
#define OUT_12_DR                     (* (reg8 *) OUT_12__DR)
/* Port Number */
#define OUT_12_PRT_NUM                (* (reg8 *) OUT_12__PRT) 
/* Connect to Analog Globals */                                                  
#define OUT_12_AG                     (* (reg8 *) OUT_12__AG)                       
/* Analog MUX bux enable */
#define OUT_12_AMUX                   (* (reg8 *) OUT_12__AMUX) 
/* Bidirectional Enable */                                                        
#define OUT_12_BIE                    (* (reg8 *) OUT_12__BIE)
/* Bit-mask for Aliased Register Access */
#define OUT_12_BIT_MASK               (* (reg8 *) OUT_12__BIT_MASK)
/* Bypass Enable */
#define OUT_12_BYP                    (* (reg8 *) OUT_12__BYP)
/* Port wide control signals */                                                   
#define OUT_12_CTL                    (* (reg8 *) OUT_12__CTL)
/* Drive Modes */
#define OUT_12_DM0                    (* (reg8 *) OUT_12__DM0) 
#define OUT_12_DM1                    (* (reg8 *) OUT_12__DM1)
#define OUT_12_DM2                    (* (reg8 *) OUT_12__DM2) 
/* Input Buffer Disable Override */
#define OUT_12_INP_DIS                (* (reg8 *) OUT_12__INP_DIS)
/* LCD Common or Segment Drive */
#define OUT_12_LCD_COM_SEG            (* (reg8 *) OUT_12__LCD_COM_SEG)
/* Enable Segment LCD */
#define OUT_12_LCD_EN                 (* (reg8 *) OUT_12__LCD_EN)
/* Slew Rate Control */
#define OUT_12_SLW                    (* (reg8 *) OUT_12__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OUT_12_PRTDSI__CAPS_SEL       (* (reg8 *) OUT_12__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OUT_12_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OUT_12__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OUT_12_PRTDSI__OE_SEL0        (* (reg8 *) OUT_12__PRTDSI__OE_SEL0) 
#define OUT_12_PRTDSI__OE_SEL1        (* (reg8 *) OUT_12__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OUT_12_PRTDSI__OUT_SEL0       (* (reg8 *) OUT_12__PRTDSI__OUT_SEL0) 
#define OUT_12_PRTDSI__OUT_SEL1       (* (reg8 *) OUT_12__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OUT_12_PRTDSI__SYNC_OUT       (* (reg8 *) OUT_12__PRTDSI__SYNC_OUT) 


#if defined(OUT_12__INTSTAT)  /* Interrupt Registers */

    #define OUT_12_INTSTAT                (* (reg8 *) OUT_12__INTSTAT)
    #define OUT_12_SNAP                   (* (reg8 *) OUT_12__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OUT_12_H */


/* [] END OF FILE */
