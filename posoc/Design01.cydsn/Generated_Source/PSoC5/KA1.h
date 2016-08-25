/*******************************************************************************
* File Name: KA1.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_KA1_H) /* Pins KA1_H */
#define CY_PINS_KA1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KA1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KA1__PORT == 15 && ((KA1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KA1_Write(uint8 value) ;
void    KA1_SetDriveMode(uint8 mode) ;
uint8   KA1_ReadDataReg(void) ;
uint8   KA1_Read(void) ;
uint8   KA1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KA1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KA1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KA1_DM_RES_UP          PIN_DM_RES_UP
#define KA1_DM_RES_DWN         PIN_DM_RES_DWN
#define KA1_DM_OD_LO           PIN_DM_OD_LO
#define KA1_DM_OD_HI           PIN_DM_OD_HI
#define KA1_DM_STRONG          PIN_DM_STRONG
#define KA1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KA1_MASK               KA1__MASK
#define KA1_SHIFT              KA1__SHIFT
#define KA1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KA1_PS                     (* (reg8 *) KA1__PS)
/* Data Register */
#define KA1_DR                     (* (reg8 *) KA1__DR)
/* Port Number */
#define KA1_PRT_NUM                (* (reg8 *) KA1__PRT) 
/* Connect to Analog Globals */                                                  
#define KA1_AG                     (* (reg8 *) KA1__AG)                       
/* Analog MUX bux enable */
#define KA1_AMUX                   (* (reg8 *) KA1__AMUX) 
/* Bidirectional Enable */                                                        
#define KA1_BIE                    (* (reg8 *) KA1__BIE)
/* Bit-mask for Aliased Register Access */
#define KA1_BIT_MASK               (* (reg8 *) KA1__BIT_MASK)
/* Bypass Enable */
#define KA1_BYP                    (* (reg8 *) KA1__BYP)
/* Port wide control signals */                                                   
#define KA1_CTL                    (* (reg8 *) KA1__CTL)
/* Drive Modes */
#define KA1_DM0                    (* (reg8 *) KA1__DM0) 
#define KA1_DM1                    (* (reg8 *) KA1__DM1)
#define KA1_DM2                    (* (reg8 *) KA1__DM2) 
/* Input Buffer Disable Override */
#define KA1_INP_DIS                (* (reg8 *) KA1__INP_DIS)
/* LCD Common or Segment Drive */
#define KA1_LCD_COM_SEG            (* (reg8 *) KA1__LCD_COM_SEG)
/* Enable Segment LCD */
#define KA1_LCD_EN                 (* (reg8 *) KA1__LCD_EN)
/* Slew Rate Control */
#define KA1_SLW                    (* (reg8 *) KA1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KA1_PRTDSI__CAPS_SEL       (* (reg8 *) KA1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KA1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KA1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KA1_PRTDSI__OE_SEL0        (* (reg8 *) KA1__PRTDSI__OE_SEL0) 
#define KA1_PRTDSI__OE_SEL1        (* (reg8 *) KA1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KA1_PRTDSI__OUT_SEL0       (* (reg8 *) KA1__PRTDSI__OUT_SEL0) 
#define KA1_PRTDSI__OUT_SEL1       (* (reg8 *) KA1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KA1_PRTDSI__SYNC_OUT       (* (reg8 *) KA1__PRTDSI__SYNC_OUT) 


#if defined(KA1__INTSTAT)  /* Interrupt Registers */

    #define KA1_INTSTAT                (* (reg8 *) KA1__INTSTAT)
    #define KA1_SNAP                   (* (reg8 *) KA1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KA1_H */


/* [] END OF FILE */
