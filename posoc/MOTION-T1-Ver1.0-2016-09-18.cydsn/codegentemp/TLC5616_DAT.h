/*******************************************************************************
* File Name: TLC5616_DAT.h  
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

#if !defined(CY_PINS_TLC5616_DAT_H) /* Pins TLC5616_DAT_H */
#define CY_PINS_TLC5616_DAT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TLC5616_DAT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TLC5616_DAT__PORT == 15 && ((TLC5616_DAT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    TLC5616_DAT_Write(uint8 value) ;
void    TLC5616_DAT_SetDriveMode(uint8 mode) ;
uint8   TLC5616_DAT_ReadDataReg(void) ;
uint8   TLC5616_DAT_Read(void) ;
uint8   TLC5616_DAT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TLC5616_DAT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TLC5616_DAT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TLC5616_DAT_DM_RES_UP          PIN_DM_RES_UP
#define TLC5616_DAT_DM_RES_DWN         PIN_DM_RES_DWN
#define TLC5616_DAT_DM_OD_LO           PIN_DM_OD_LO
#define TLC5616_DAT_DM_OD_HI           PIN_DM_OD_HI
#define TLC5616_DAT_DM_STRONG          PIN_DM_STRONG
#define TLC5616_DAT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TLC5616_DAT_MASK               TLC5616_DAT__MASK
#define TLC5616_DAT_SHIFT              TLC5616_DAT__SHIFT
#define TLC5616_DAT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TLC5616_DAT_PS                     (* (reg8 *) TLC5616_DAT__PS)
/* Data Register */
#define TLC5616_DAT_DR                     (* (reg8 *) TLC5616_DAT__DR)
/* Port Number */
#define TLC5616_DAT_PRT_NUM                (* (reg8 *) TLC5616_DAT__PRT) 
/* Connect to Analog Globals */                                                  
#define TLC5616_DAT_AG                     (* (reg8 *) TLC5616_DAT__AG)                       
/* Analog MUX bux enable */
#define TLC5616_DAT_AMUX                   (* (reg8 *) TLC5616_DAT__AMUX) 
/* Bidirectional Enable */                                                        
#define TLC5616_DAT_BIE                    (* (reg8 *) TLC5616_DAT__BIE)
/* Bit-mask for Aliased Register Access */
#define TLC5616_DAT_BIT_MASK               (* (reg8 *) TLC5616_DAT__BIT_MASK)
/* Bypass Enable */
#define TLC5616_DAT_BYP                    (* (reg8 *) TLC5616_DAT__BYP)
/* Port wide control signals */                                                   
#define TLC5616_DAT_CTL                    (* (reg8 *) TLC5616_DAT__CTL)
/* Drive Modes */
#define TLC5616_DAT_DM0                    (* (reg8 *) TLC5616_DAT__DM0) 
#define TLC5616_DAT_DM1                    (* (reg8 *) TLC5616_DAT__DM1)
#define TLC5616_DAT_DM2                    (* (reg8 *) TLC5616_DAT__DM2) 
/* Input Buffer Disable Override */
#define TLC5616_DAT_INP_DIS                (* (reg8 *) TLC5616_DAT__INP_DIS)
/* LCD Common or Segment Drive */
#define TLC5616_DAT_LCD_COM_SEG            (* (reg8 *) TLC5616_DAT__LCD_COM_SEG)
/* Enable Segment LCD */
#define TLC5616_DAT_LCD_EN                 (* (reg8 *) TLC5616_DAT__LCD_EN)
/* Slew Rate Control */
#define TLC5616_DAT_SLW                    (* (reg8 *) TLC5616_DAT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TLC5616_DAT_PRTDSI__CAPS_SEL       (* (reg8 *) TLC5616_DAT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TLC5616_DAT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TLC5616_DAT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TLC5616_DAT_PRTDSI__OE_SEL0        (* (reg8 *) TLC5616_DAT__PRTDSI__OE_SEL0) 
#define TLC5616_DAT_PRTDSI__OE_SEL1        (* (reg8 *) TLC5616_DAT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TLC5616_DAT_PRTDSI__OUT_SEL0       (* (reg8 *) TLC5616_DAT__PRTDSI__OUT_SEL0) 
#define TLC5616_DAT_PRTDSI__OUT_SEL1       (* (reg8 *) TLC5616_DAT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TLC5616_DAT_PRTDSI__SYNC_OUT       (* (reg8 *) TLC5616_DAT__PRTDSI__SYNC_OUT) 


#if defined(TLC5616_DAT__INTSTAT)  /* Interrupt Registers */

    #define TLC5616_DAT_INTSTAT                (* (reg8 *) TLC5616_DAT__INTSTAT)
    #define TLC5616_DAT_SNAP                   (* (reg8 *) TLC5616_DAT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TLC5616_DAT_H */


/* [] END OF FILE */
