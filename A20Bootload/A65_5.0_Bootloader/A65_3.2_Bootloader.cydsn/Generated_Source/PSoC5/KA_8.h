/*******************************************************************************
* File Name: KA_8.h  
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

#if !defined(CY_PINS_KA_8_H) /* Pins KA_8_H */
#define CY_PINS_KA_8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KA_8_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KA_8__PORT == 15 && ((KA_8__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KA_8_Write(uint8 value) ;
void    KA_8_SetDriveMode(uint8 mode) ;
uint8   KA_8_ReadDataReg(void) ;
uint8   KA_8_Read(void) ;
uint8   KA_8_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KA_8_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KA_8_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KA_8_DM_RES_UP          PIN_DM_RES_UP
#define KA_8_DM_RES_DWN         PIN_DM_RES_DWN
#define KA_8_DM_OD_LO           PIN_DM_OD_LO
#define KA_8_DM_OD_HI           PIN_DM_OD_HI
#define KA_8_DM_STRONG          PIN_DM_STRONG
#define KA_8_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KA_8_MASK               KA_8__MASK
#define KA_8_SHIFT              KA_8__SHIFT
#define KA_8_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KA_8_PS                     (* (reg8 *) KA_8__PS)
/* Data Register */
#define KA_8_DR                     (* (reg8 *) KA_8__DR)
/* Port Number */
#define KA_8_PRT_NUM                (* (reg8 *) KA_8__PRT) 
/* Connect to Analog Globals */                                                  
#define KA_8_AG                     (* (reg8 *) KA_8__AG)                       
/* Analog MUX bux enable */
#define KA_8_AMUX                   (* (reg8 *) KA_8__AMUX) 
/* Bidirectional Enable */                                                        
#define KA_8_BIE                    (* (reg8 *) KA_8__BIE)
/* Bit-mask for Aliased Register Access */
#define KA_8_BIT_MASK               (* (reg8 *) KA_8__BIT_MASK)
/* Bypass Enable */
#define KA_8_BYP                    (* (reg8 *) KA_8__BYP)
/* Port wide control signals */                                                   
#define KA_8_CTL                    (* (reg8 *) KA_8__CTL)
/* Drive Modes */
#define KA_8_DM0                    (* (reg8 *) KA_8__DM0) 
#define KA_8_DM1                    (* (reg8 *) KA_8__DM1)
#define KA_8_DM2                    (* (reg8 *) KA_8__DM2) 
/* Input Buffer Disable Override */
#define KA_8_INP_DIS                (* (reg8 *) KA_8__INP_DIS)
/* LCD Common or Segment Drive */
#define KA_8_LCD_COM_SEG            (* (reg8 *) KA_8__LCD_COM_SEG)
/* Enable Segment LCD */
#define KA_8_LCD_EN                 (* (reg8 *) KA_8__LCD_EN)
/* Slew Rate Control */
#define KA_8_SLW                    (* (reg8 *) KA_8__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KA_8_PRTDSI__CAPS_SEL       (* (reg8 *) KA_8__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KA_8_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KA_8__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KA_8_PRTDSI__OE_SEL0        (* (reg8 *) KA_8__PRTDSI__OE_SEL0) 
#define KA_8_PRTDSI__OE_SEL1        (* (reg8 *) KA_8__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KA_8_PRTDSI__OUT_SEL0       (* (reg8 *) KA_8__PRTDSI__OUT_SEL0) 
#define KA_8_PRTDSI__OUT_SEL1       (* (reg8 *) KA_8__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KA_8_PRTDSI__SYNC_OUT       (* (reg8 *) KA_8__PRTDSI__SYNC_OUT) 


#if defined(KA_8__INTSTAT)  /* Interrupt Registers */

    #define KA_8_INTSTAT                (* (reg8 *) KA_8__INTSTAT)
    #define KA_8_SNAP                   (* (reg8 *) KA_8__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KA_8_H */


/* [] END OF FILE */
