/*******************************************************************************
* File Name: KA6.h  
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

#if !defined(CY_PINS_KA6_H) /* Pins KA6_H */
#define CY_PINS_KA6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KA6_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KA6__PORT == 15 && ((KA6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    KA6_Write(uint8 value) ;
void    KA6_SetDriveMode(uint8 mode) ;
uint8   KA6_ReadDataReg(void) ;
uint8   KA6_Read(void) ;
uint8   KA6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define KA6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define KA6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define KA6_DM_RES_UP          PIN_DM_RES_UP
#define KA6_DM_RES_DWN         PIN_DM_RES_DWN
#define KA6_DM_OD_LO           PIN_DM_OD_LO
#define KA6_DM_OD_HI           PIN_DM_OD_HI
#define KA6_DM_STRONG          PIN_DM_STRONG
#define KA6_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define KA6_MASK               KA6__MASK
#define KA6_SHIFT              KA6__SHIFT
#define KA6_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KA6_PS                     (* (reg8 *) KA6__PS)
/* Data Register */
#define KA6_DR                     (* (reg8 *) KA6__DR)
/* Port Number */
#define KA6_PRT_NUM                (* (reg8 *) KA6__PRT) 
/* Connect to Analog Globals */                                                  
#define KA6_AG                     (* (reg8 *) KA6__AG)                       
/* Analog MUX bux enable */
#define KA6_AMUX                   (* (reg8 *) KA6__AMUX) 
/* Bidirectional Enable */                                                        
#define KA6_BIE                    (* (reg8 *) KA6__BIE)
/* Bit-mask for Aliased Register Access */
#define KA6_BIT_MASK               (* (reg8 *) KA6__BIT_MASK)
/* Bypass Enable */
#define KA6_BYP                    (* (reg8 *) KA6__BYP)
/* Port wide control signals */                                                   
#define KA6_CTL                    (* (reg8 *) KA6__CTL)
/* Drive Modes */
#define KA6_DM0                    (* (reg8 *) KA6__DM0) 
#define KA6_DM1                    (* (reg8 *) KA6__DM1)
#define KA6_DM2                    (* (reg8 *) KA6__DM2) 
/* Input Buffer Disable Override */
#define KA6_INP_DIS                (* (reg8 *) KA6__INP_DIS)
/* LCD Common or Segment Drive */
#define KA6_LCD_COM_SEG            (* (reg8 *) KA6__LCD_COM_SEG)
/* Enable Segment LCD */
#define KA6_LCD_EN                 (* (reg8 *) KA6__LCD_EN)
/* Slew Rate Control */
#define KA6_SLW                    (* (reg8 *) KA6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KA6_PRTDSI__CAPS_SEL       (* (reg8 *) KA6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KA6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KA6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KA6_PRTDSI__OE_SEL0        (* (reg8 *) KA6__PRTDSI__OE_SEL0) 
#define KA6_PRTDSI__OE_SEL1        (* (reg8 *) KA6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KA6_PRTDSI__OUT_SEL0       (* (reg8 *) KA6__PRTDSI__OUT_SEL0) 
#define KA6_PRTDSI__OUT_SEL1       (* (reg8 *) KA6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KA6_PRTDSI__SYNC_OUT       (* (reg8 *) KA6__PRTDSI__SYNC_OUT) 


#if defined(KA6__INTSTAT)  /* Interrupt Registers */

    #define KA6_INTSTAT                (* (reg8 *) KA6__INTSTAT)
    #define KA6_SNAP                   (* (reg8 *) KA6__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KA6_H */


/* [] END OF FILE */
