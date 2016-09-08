/*******************************************************************************
* File Name: TLC5616_CLK.h  
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

#if !defined(CY_PINS_TLC5616_CLK_H) /* Pins TLC5616_CLK_H */
#define CY_PINS_TLC5616_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "TLC5616_CLK_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 TLC5616_CLK__PORT == 15 && ((TLC5616_CLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    TLC5616_CLK_Write(uint8 value) ;
void    TLC5616_CLK_SetDriveMode(uint8 mode) ;
uint8   TLC5616_CLK_ReadDataReg(void) ;
uint8   TLC5616_CLK_Read(void) ;
uint8   TLC5616_CLK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TLC5616_CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define TLC5616_CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define TLC5616_CLK_DM_RES_UP          PIN_DM_RES_UP
#define TLC5616_CLK_DM_RES_DWN         PIN_DM_RES_DWN
#define TLC5616_CLK_DM_OD_LO           PIN_DM_OD_LO
#define TLC5616_CLK_DM_OD_HI           PIN_DM_OD_HI
#define TLC5616_CLK_DM_STRONG          PIN_DM_STRONG
#define TLC5616_CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define TLC5616_CLK_MASK               TLC5616_CLK__MASK
#define TLC5616_CLK_SHIFT              TLC5616_CLK__SHIFT
#define TLC5616_CLK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TLC5616_CLK_PS                     (* (reg8 *) TLC5616_CLK__PS)
/* Data Register */
#define TLC5616_CLK_DR                     (* (reg8 *) TLC5616_CLK__DR)
/* Port Number */
#define TLC5616_CLK_PRT_NUM                (* (reg8 *) TLC5616_CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define TLC5616_CLK_AG                     (* (reg8 *) TLC5616_CLK__AG)                       
/* Analog MUX bux enable */
#define TLC5616_CLK_AMUX                   (* (reg8 *) TLC5616_CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define TLC5616_CLK_BIE                    (* (reg8 *) TLC5616_CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define TLC5616_CLK_BIT_MASK               (* (reg8 *) TLC5616_CLK__BIT_MASK)
/* Bypass Enable */
#define TLC5616_CLK_BYP                    (* (reg8 *) TLC5616_CLK__BYP)
/* Port wide control signals */                                                   
#define TLC5616_CLK_CTL                    (* (reg8 *) TLC5616_CLK__CTL)
/* Drive Modes */
#define TLC5616_CLK_DM0                    (* (reg8 *) TLC5616_CLK__DM0) 
#define TLC5616_CLK_DM1                    (* (reg8 *) TLC5616_CLK__DM1)
#define TLC5616_CLK_DM2                    (* (reg8 *) TLC5616_CLK__DM2) 
/* Input Buffer Disable Override */
#define TLC5616_CLK_INP_DIS                (* (reg8 *) TLC5616_CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define TLC5616_CLK_LCD_COM_SEG            (* (reg8 *) TLC5616_CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define TLC5616_CLK_LCD_EN                 (* (reg8 *) TLC5616_CLK__LCD_EN)
/* Slew Rate Control */
#define TLC5616_CLK_SLW                    (* (reg8 *) TLC5616_CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define TLC5616_CLK_PRTDSI__CAPS_SEL       (* (reg8 *) TLC5616_CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define TLC5616_CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) TLC5616_CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define TLC5616_CLK_PRTDSI__OE_SEL0        (* (reg8 *) TLC5616_CLK__PRTDSI__OE_SEL0) 
#define TLC5616_CLK_PRTDSI__OE_SEL1        (* (reg8 *) TLC5616_CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define TLC5616_CLK_PRTDSI__OUT_SEL0       (* (reg8 *) TLC5616_CLK__PRTDSI__OUT_SEL0) 
#define TLC5616_CLK_PRTDSI__OUT_SEL1       (* (reg8 *) TLC5616_CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define TLC5616_CLK_PRTDSI__SYNC_OUT       (* (reg8 *) TLC5616_CLK__PRTDSI__SYNC_OUT) 


#if defined(TLC5616_CLK__INTSTAT)  /* Interrupt Registers */

    #define TLC5616_CLK_INTSTAT                (* (reg8 *) TLC5616_CLK__INTSTAT)
    #define TLC5616_CLK_SNAP                   (* (reg8 *) TLC5616_CLK__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_TLC5616_CLK_H */


/* [] END OF FILE */
