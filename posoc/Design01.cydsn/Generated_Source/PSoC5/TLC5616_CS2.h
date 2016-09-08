/*******************************************************************************
* File Name: TLC5616_CS2.h  
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

#if !defined(CY_PINS_TLC5616_CS2_H) /* Pins TLC5616_CS2_H */
#define CY_PINS_TLC5616_CS2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TLC5616_CS2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TLC5616_CS2__PORT == 15 && ((TLC5616_CS2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    TLC5616_CS2_Write(uint8 value) ;
void    TLC5616_CS2_SetDriveMode(uint8 mode) ;
uint8   TLC5616_CS2_ReadDataReg(void) ;
uint8   TLC5616_CS2_Read(void) ;
uint8   TLC5616_CS2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TLC5616_CS2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TLC5616_CS2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TLC5616_CS2_DM_RES_UP          PIN_DM_RES_UP
#define TLC5616_CS2_DM_RES_DWN         PIN_DM_RES_DWN
#define TLC5616_CS2_DM_OD_LO           PIN_DM_OD_LO
#define TLC5616_CS2_DM_OD_HI           PIN_DM_OD_HI
#define TLC5616_CS2_DM_STRONG          PIN_DM_STRONG
#define TLC5616_CS2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TLC5616_CS2_MASK               TLC5616_CS2__MASK
#define TLC5616_CS2_SHIFT              TLC5616_CS2__SHIFT
#define TLC5616_CS2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TLC5616_CS2_PS                     (* (reg8 *) TLC5616_CS2__PS)
/* Data Register */
#define TLC5616_CS2_DR                     (* (reg8 *) TLC5616_CS2__DR)
/* Port Number */
#define TLC5616_CS2_PRT_NUM                (* (reg8 *) TLC5616_CS2__PRT) 
/* Connect to Analog Globals */                                                  
#define TLC5616_CS2_AG                     (* (reg8 *) TLC5616_CS2__AG)                       
/* Analog MUX bux enable */
#define TLC5616_CS2_AMUX                   (* (reg8 *) TLC5616_CS2__AMUX) 
/* Bidirectional Enable */                                                        
#define TLC5616_CS2_BIE                    (* (reg8 *) TLC5616_CS2__BIE)
/* Bit-mask for Aliased Register Access */
#define TLC5616_CS2_BIT_MASK               (* (reg8 *) TLC5616_CS2__BIT_MASK)
/* Bypass Enable */
#define TLC5616_CS2_BYP                    (* (reg8 *) TLC5616_CS2__BYP)
/* Port wide control signals */                                                   
#define TLC5616_CS2_CTL                    (* (reg8 *) TLC5616_CS2__CTL)
/* Drive Modes */
#define TLC5616_CS2_DM0                    (* (reg8 *) TLC5616_CS2__DM0) 
#define TLC5616_CS2_DM1                    (* (reg8 *) TLC5616_CS2__DM1)
#define TLC5616_CS2_DM2                    (* (reg8 *) TLC5616_CS2__DM2) 
/* Input Buffer Disable Override */
#define TLC5616_CS2_INP_DIS                (* (reg8 *) TLC5616_CS2__INP_DIS)
/* LCD Common or Segment Drive */
#define TLC5616_CS2_LCD_COM_SEG            (* (reg8 *) TLC5616_CS2__LCD_COM_SEG)
/* Enable Segment LCD */
#define TLC5616_CS2_LCD_EN                 (* (reg8 *) TLC5616_CS2__LCD_EN)
/* Slew Rate Control */
#define TLC5616_CS2_SLW                    (* (reg8 *) TLC5616_CS2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TLC5616_CS2_PRTDSI__CAPS_SEL       (* (reg8 *) TLC5616_CS2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TLC5616_CS2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TLC5616_CS2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TLC5616_CS2_PRTDSI__OE_SEL0        (* (reg8 *) TLC5616_CS2__PRTDSI__OE_SEL0) 
#define TLC5616_CS2_PRTDSI__OE_SEL1        (* (reg8 *) TLC5616_CS2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TLC5616_CS2_PRTDSI__OUT_SEL0       (* (reg8 *) TLC5616_CS2__PRTDSI__OUT_SEL0) 
#define TLC5616_CS2_PRTDSI__OUT_SEL1       (* (reg8 *) TLC5616_CS2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TLC5616_CS2_PRTDSI__SYNC_OUT       (* (reg8 *) TLC5616_CS2__PRTDSI__SYNC_OUT) 


#if defined(TLC5616_CS2__INTSTAT)  /* Interrupt Registers */

    #define TLC5616_CS2_INTSTAT                (* (reg8 *) TLC5616_CS2__INTSTAT)
    #define TLC5616_CS2_SNAP                   (* (reg8 *) TLC5616_CS2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TLC5616_CS2_H */


/* [] END OF FILE */
