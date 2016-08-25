/*******************************************************************************
* File Name: KA2.h  
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

#if !defined(CY_PINS_KA2_H) /* Pins KA2_H */
#define CY_PINS_KA2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KA2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KA2__PORT == 15 && ((KA2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KA2_Write(uint8 value) ;
void    KA2_SetDriveMode(uint8 mode) ;
uint8   KA2_ReadDataReg(void) ;
uint8   KA2_Read(void) ;
uint8   KA2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KA2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KA2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KA2_DM_RES_UP          PIN_DM_RES_UP
#define KA2_DM_RES_DWN         PIN_DM_RES_DWN
#define KA2_DM_OD_LO           PIN_DM_OD_LO
#define KA2_DM_OD_HI           PIN_DM_OD_HI
#define KA2_DM_STRONG          PIN_DM_STRONG
#define KA2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KA2_MASK               KA2__MASK
#define KA2_SHIFT              KA2__SHIFT
#define KA2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KA2_PS                     (* (reg8 *) KA2__PS)
/* Data Register */
#define KA2_DR                     (* (reg8 *) KA2__DR)
/* Port Number */
#define KA2_PRT_NUM                (* (reg8 *) KA2__PRT) 
/* Connect to Analog Globals */                                                  
#define KA2_AG                     (* (reg8 *) KA2__AG)                       
/* Analog MUX bux enable */
#define KA2_AMUX                   (* (reg8 *) KA2__AMUX) 
/* Bidirectional Enable */                                                        
#define KA2_BIE                    (* (reg8 *) KA2__BIE)
/* Bit-mask for Aliased Register Access */
#define KA2_BIT_MASK               (* (reg8 *) KA2__BIT_MASK)
/* Bypass Enable */
#define KA2_BYP                    (* (reg8 *) KA2__BYP)
/* Port wide control signals */                                                   
#define KA2_CTL                    (* (reg8 *) KA2__CTL)
/* Drive Modes */
#define KA2_DM0                    (* (reg8 *) KA2__DM0) 
#define KA2_DM1                    (* (reg8 *) KA2__DM1)
#define KA2_DM2                    (* (reg8 *) KA2__DM2) 
/* Input Buffer Disable Override */
#define KA2_INP_DIS                (* (reg8 *) KA2__INP_DIS)
/* LCD Common or Segment Drive */
#define KA2_LCD_COM_SEG            (* (reg8 *) KA2__LCD_COM_SEG)
/* Enable Segment LCD */
#define KA2_LCD_EN                 (* (reg8 *) KA2__LCD_EN)
/* Slew Rate Control */
#define KA2_SLW                    (* (reg8 *) KA2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KA2_PRTDSI__CAPS_SEL       (* (reg8 *) KA2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KA2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KA2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KA2_PRTDSI__OE_SEL0        (* (reg8 *) KA2__PRTDSI__OE_SEL0) 
#define KA2_PRTDSI__OE_SEL1        (* (reg8 *) KA2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KA2_PRTDSI__OUT_SEL0       (* (reg8 *) KA2__PRTDSI__OUT_SEL0) 
#define KA2_PRTDSI__OUT_SEL1       (* (reg8 *) KA2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KA2_PRTDSI__SYNC_OUT       (* (reg8 *) KA2__PRTDSI__SYNC_OUT) 


#if defined(KA2__INTSTAT)  /* Interrupt Registers */

    #define KA2_INTSTAT                (* (reg8 *) KA2__INTSTAT)
    #define KA2_SNAP                   (* (reg8 *) KA2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KA2_H */


/* [] END OF FILE */
