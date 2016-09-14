/*******************************************************************************
* File Name: KA_3.h  
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

#if !defined(CY_PINS_KA_3_H) /* Pins KA_3_H */
#define CY_PINS_KA_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KA_3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KA_3__PORT == 15 && ((KA_3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KA_3_Write(uint8 value) ;
void    KA_3_SetDriveMode(uint8 mode) ;
uint8   KA_3_ReadDataReg(void) ;
uint8   KA_3_Read(void) ;
uint8   KA_3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KA_3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KA_3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KA_3_DM_RES_UP          PIN_DM_RES_UP
#define KA_3_DM_RES_DWN         PIN_DM_RES_DWN
#define KA_3_DM_OD_LO           PIN_DM_OD_LO
#define KA_3_DM_OD_HI           PIN_DM_OD_HI
#define KA_3_DM_STRONG          PIN_DM_STRONG
#define KA_3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KA_3_MASK               KA_3__MASK
#define KA_3_SHIFT              KA_3__SHIFT
#define KA_3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KA_3_PS                     (* (reg8 *) KA_3__PS)
/* Data Register */
#define KA_3_DR                     (* (reg8 *) KA_3__DR)
/* Port Number */
#define KA_3_PRT_NUM                (* (reg8 *) KA_3__PRT) 
/* Connect to Analog Globals */                                                  
#define KA_3_AG                     (* (reg8 *) KA_3__AG)                       
/* Analog MUX bux enable */
#define KA_3_AMUX                   (* (reg8 *) KA_3__AMUX) 
/* Bidirectional Enable */                                                        
#define KA_3_BIE                    (* (reg8 *) KA_3__BIE)
/* Bit-mask for Aliased Register Access */
#define KA_3_BIT_MASK               (* (reg8 *) KA_3__BIT_MASK)
/* Bypass Enable */
#define KA_3_BYP                    (* (reg8 *) KA_3__BYP)
/* Port wide control signals */                                                   
#define KA_3_CTL                    (* (reg8 *) KA_3__CTL)
/* Drive Modes */
#define KA_3_DM0                    (* (reg8 *) KA_3__DM0) 
#define KA_3_DM1                    (* (reg8 *) KA_3__DM1)
#define KA_3_DM2                    (* (reg8 *) KA_3__DM2) 
/* Input Buffer Disable Override */
#define KA_3_INP_DIS                (* (reg8 *) KA_3__INP_DIS)
/* LCD Common or Segment Drive */
#define KA_3_LCD_COM_SEG            (* (reg8 *) KA_3__LCD_COM_SEG)
/* Enable Segment LCD */
#define KA_3_LCD_EN                 (* (reg8 *) KA_3__LCD_EN)
/* Slew Rate Control */
#define KA_3_SLW                    (* (reg8 *) KA_3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KA_3_PRTDSI__CAPS_SEL       (* (reg8 *) KA_3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KA_3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KA_3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KA_3_PRTDSI__OE_SEL0        (* (reg8 *) KA_3__PRTDSI__OE_SEL0) 
#define KA_3_PRTDSI__OE_SEL1        (* (reg8 *) KA_3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KA_3_PRTDSI__OUT_SEL0       (* (reg8 *) KA_3__PRTDSI__OUT_SEL0) 
#define KA_3_PRTDSI__OUT_SEL1       (* (reg8 *) KA_3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KA_3_PRTDSI__SYNC_OUT       (* (reg8 *) KA_3__PRTDSI__SYNC_OUT) 


#if defined(KA_3__INTSTAT)  /* Interrupt Registers */

    #define KA_3_INTSTAT                (* (reg8 *) KA_3__INTSTAT)
    #define KA_3_SNAP                   (* (reg8 *) KA_3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KA_3_H */


/* [] END OF FILE */
