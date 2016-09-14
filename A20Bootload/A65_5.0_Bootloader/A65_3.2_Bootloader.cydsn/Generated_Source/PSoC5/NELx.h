/*******************************************************************************
* File Name: NELx.h  
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

#if !defined(CY_PINS_NELx_H) /* Pins NELx_H */
#define CY_PINS_NELx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "NELx_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 NELx__PORT == 15 && ((NELx__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    NELx_Write(uint8 value) ;
void    NELx_SetDriveMode(uint8 mode) ;
uint8   NELx_ReadDataReg(void) ;
uint8   NELx_Read(void) ;
uint8   NELx_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define NELx_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define NELx_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define NELx_DM_RES_UP          PIN_DM_RES_UP
#define NELx_DM_RES_DWN         PIN_DM_RES_DWN
#define NELx_DM_OD_LO           PIN_DM_OD_LO
#define NELx_DM_OD_HI           PIN_DM_OD_HI
#define NELx_DM_STRONG          PIN_DM_STRONG
#define NELx_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define NELx_MASK               NELx__MASK
#define NELx_SHIFT              NELx__SHIFT
#define NELx_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define NELx_PS                     (* (reg8 *) NELx__PS)
/* Data Register */
#define NELx_DR                     (* (reg8 *) NELx__DR)
/* Port Number */
#define NELx_PRT_NUM                (* (reg8 *) NELx__PRT) 
/* Connect to Analog Globals */                                                  
#define NELx_AG                     (* (reg8 *) NELx__AG)                       
/* Analog MUX bux enable */
#define NELx_AMUX                   (* (reg8 *) NELx__AMUX) 
/* Bidirectional Enable */                                                        
#define NELx_BIE                    (* (reg8 *) NELx__BIE)
/* Bit-mask for Aliased Register Access */
#define NELx_BIT_MASK               (* (reg8 *) NELx__BIT_MASK)
/* Bypass Enable */
#define NELx_BYP                    (* (reg8 *) NELx__BYP)
/* Port wide control signals */                                                   
#define NELx_CTL                    (* (reg8 *) NELx__CTL)
/* Drive Modes */
#define NELx_DM0                    (* (reg8 *) NELx__DM0) 
#define NELx_DM1                    (* (reg8 *) NELx__DM1)
#define NELx_DM2                    (* (reg8 *) NELx__DM2) 
/* Input Buffer Disable Override */
#define NELx_INP_DIS                (* (reg8 *) NELx__INP_DIS)
/* LCD Common or Segment Drive */
#define NELx_LCD_COM_SEG            (* (reg8 *) NELx__LCD_COM_SEG)
/* Enable Segment LCD */
#define NELx_LCD_EN                 (* (reg8 *) NELx__LCD_EN)
/* Slew Rate Control */
#define NELx_SLW                    (* (reg8 *) NELx__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define NELx_PRTDSI__CAPS_SEL       (* (reg8 *) NELx__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define NELx_PRTDSI__DBL_SYNC_IN    (* (reg8 *) NELx__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define NELx_PRTDSI__OE_SEL0        (* (reg8 *) NELx__PRTDSI__OE_SEL0) 
#define NELx_PRTDSI__OE_SEL1        (* (reg8 *) NELx__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define NELx_PRTDSI__OUT_SEL0       (* (reg8 *) NELx__PRTDSI__OUT_SEL0) 
#define NELx_PRTDSI__OUT_SEL1       (* (reg8 *) NELx__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define NELx_PRTDSI__SYNC_OUT       (* (reg8 *) NELx__PRTDSI__SYNC_OUT) 


#if defined(NELx__INTSTAT)  /* Interrupt Registers */

    #define NELx_INTSTAT                (* (reg8 *) NELx__INTSTAT)
    #define NELx_SNAP                   (* (reg8 *) NELx__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_NELx_H */


/* [] END OF FILE */
