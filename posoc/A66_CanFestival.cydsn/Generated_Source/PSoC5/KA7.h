/*******************************************************************************
* File Name: KA7.h  
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

#if !defined(CY_PINS_KA7_H) /* Pins KA7_H */
#define CY_PINS_KA7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KA7_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KA7__PORT == 15 && ((KA7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KA7_Write(uint8 value) ;
void    KA7_SetDriveMode(uint8 mode) ;
uint8   KA7_ReadDataReg(void) ;
uint8   KA7_Read(void) ;
uint8   KA7_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KA7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KA7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KA7_DM_RES_UP          PIN_DM_RES_UP
#define KA7_DM_RES_DWN         PIN_DM_RES_DWN
#define KA7_DM_OD_LO           PIN_DM_OD_LO
#define KA7_DM_OD_HI           PIN_DM_OD_HI
#define KA7_DM_STRONG          PIN_DM_STRONG
#define KA7_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KA7_MASK               KA7__MASK
#define KA7_SHIFT              KA7__SHIFT
#define KA7_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KA7_PS                     (* (reg8 *) KA7__PS)
/* Data Register */
#define KA7_DR                     (* (reg8 *) KA7__DR)
/* Port Number */
#define KA7_PRT_NUM                (* (reg8 *) KA7__PRT) 
/* Connect to Analog Globals */                                                  
#define KA7_AG                     (* (reg8 *) KA7__AG)                       
/* Analog MUX bux enable */
#define KA7_AMUX                   (* (reg8 *) KA7__AMUX) 
/* Bidirectional Enable */                                                        
#define KA7_BIE                    (* (reg8 *) KA7__BIE)
/* Bit-mask for Aliased Register Access */
#define KA7_BIT_MASK               (* (reg8 *) KA7__BIT_MASK)
/* Bypass Enable */
#define KA7_BYP                    (* (reg8 *) KA7__BYP)
/* Port wide control signals */                                                   
#define KA7_CTL                    (* (reg8 *) KA7__CTL)
/* Drive Modes */
#define KA7_DM0                    (* (reg8 *) KA7__DM0) 
#define KA7_DM1                    (* (reg8 *) KA7__DM1)
#define KA7_DM2                    (* (reg8 *) KA7__DM2) 
/* Input Buffer Disable Override */
#define KA7_INP_DIS                (* (reg8 *) KA7__INP_DIS)
/* LCD Common or Segment Drive */
#define KA7_LCD_COM_SEG            (* (reg8 *) KA7__LCD_COM_SEG)
/* Enable Segment LCD */
#define KA7_LCD_EN                 (* (reg8 *) KA7__LCD_EN)
/* Slew Rate Control */
#define KA7_SLW                    (* (reg8 *) KA7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KA7_PRTDSI__CAPS_SEL       (* (reg8 *) KA7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KA7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KA7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KA7_PRTDSI__OE_SEL0        (* (reg8 *) KA7__PRTDSI__OE_SEL0) 
#define KA7_PRTDSI__OE_SEL1        (* (reg8 *) KA7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KA7_PRTDSI__OUT_SEL0       (* (reg8 *) KA7__PRTDSI__OUT_SEL0) 
#define KA7_PRTDSI__OUT_SEL1       (* (reg8 *) KA7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KA7_PRTDSI__SYNC_OUT       (* (reg8 *) KA7__PRTDSI__SYNC_OUT) 


#if defined(KA7__INTSTAT)  /* Interrupt Registers */

    #define KA7_INTSTAT                (* (reg8 *) KA7__INTSTAT)
    #define KA7_SNAP                   (* (reg8 *) KA7__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KA7_H */


/* [] END OF FILE */
