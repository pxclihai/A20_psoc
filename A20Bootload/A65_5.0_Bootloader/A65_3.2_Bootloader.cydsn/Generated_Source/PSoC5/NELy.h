/*******************************************************************************
* File Name: NELy.h  
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

#if !defined(CY_PINS_NELy_H) /* Pins NELy_H */
#define CY_PINS_NELy_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "NELy_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 NELy__PORT == 15 && ((NELy__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    NELy_Write(uint8 value) ;
void    NELy_SetDriveMode(uint8 mode) ;
uint8   NELy_ReadDataReg(void) ;
uint8   NELy_Read(void) ;
uint8   NELy_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NELy_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define NELy_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define NELy_DM_RES_UP          PIN_DM_RES_UP
#define NELy_DM_RES_DWN         PIN_DM_RES_DWN
#define NELy_DM_OD_LO           PIN_DM_OD_LO
#define NELy_DM_OD_HI           PIN_DM_OD_HI
#define NELy_DM_STRONG          PIN_DM_STRONG
#define NELy_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define NELy_MASK               NELy__MASK
#define NELy_SHIFT              NELy__SHIFT
#define NELy_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NELy_PS                     (* (reg8 *) NELy__PS)
/* Data Register */
#define NELy_DR                     (* (reg8 *) NELy__DR)
/* Port Number */
#define NELy_PRT_NUM                (* (reg8 *) NELy__PRT) 
/* Connect to Analog Globals */                                                  
#define NELy_AG                     (* (reg8 *) NELy__AG)                       
/* Analog MUX bux enable */
#define NELy_AMUX                   (* (reg8 *) NELy__AMUX) 
/* Bidirectional Enable */                                                        
#define NELy_BIE                    (* (reg8 *) NELy__BIE)
/* Bit-mask for Aliased Register Access */
#define NELy_BIT_MASK               (* (reg8 *) NELy__BIT_MASK)
/* Bypass Enable */
#define NELy_BYP                    (* (reg8 *) NELy__BYP)
/* Port wide control signals */                                                   
#define NELy_CTL                    (* (reg8 *) NELy__CTL)
/* Drive Modes */
#define NELy_DM0                    (* (reg8 *) NELy__DM0) 
#define NELy_DM1                    (* (reg8 *) NELy__DM1)
#define NELy_DM2                    (* (reg8 *) NELy__DM2) 
/* Input Buffer Disable Override */
#define NELy_INP_DIS                (* (reg8 *) NELy__INP_DIS)
/* LCD Common or Segment Drive */
#define NELy_LCD_COM_SEG            (* (reg8 *) NELy__LCD_COM_SEG)
/* Enable Segment LCD */
#define NELy_LCD_EN                 (* (reg8 *) NELy__LCD_EN)
/* Slew Rate Control */
#define NELy_SLW                    (* (reg8 *) NELy__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define NELy_PRTDSI__CAPS_SEL       (* (reg8 *) NELy__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define NELy_PRTDSI__DBL_SYNC_IN    (* (reg8 *) NELy__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define NELy_PRTDSI__OE_SEL0        (* (reg8 *) NELy__PRTDSI__OE_SEL0) 
#define NELy_PRTDSI__OE_SEL1        (* (reg8 *) NELy__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define NELy_PRTDSI__OUT_SEL0       (* (reg8 *) NELy__PRTDSI__OUT_SEL0) 
#define NELy_PRTDSI__OUT_SEL1       (* (reg8 *) NELy__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define NELy_PRTDSI__SYNC_OUT       (* (reg8 *) NELy__PRTDSI__SYNC_OUT) 


#if defined(NELy__INTSTAT)  /* Interrupt Registers */

    #define NELy_INTSTAT                (* (reg8 *) NELy__INTSTAT)
    #define NELy_SNAP                   (* (reg8 *) NELy__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_NELy_H */


/* [] END OF FILE */
