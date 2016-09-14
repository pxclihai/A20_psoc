/*******************************************************************************
* File Name: OUT_YF.h  
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

#if !defined(CY_PINS_OUT_YF_H) /* Pins OUT_YF_H */
#define CY_PINS_OUT_YF_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OUT_YF_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OUT_YF__PORT == 15 && ((OUT_YF__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    OUT_YF_Write(uint8 value) ;
void    OUT_YF_SetDriveMode(uint8 mode) ;
uint8   OUT_YF_ReadDataReg(void) ;
uint8   OUT_YF_Read(void) ;
uint8   OUT_YF_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OUT_YF_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define OUT_YF_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define OUT_YF_DM_RES_UP          PIN_DM_RES_UP
#define OUT_YF_DM_RES_DWN         PIN_DM_RES_DWN
#define OUT_YF_DM_OD_LO           PIN_DM_OD_LO
#define OUT_YF_DM_OD_HI           PIN_DM_OD_HI
#define OUT_YF_DM_STRONG          PIN_DM_STRONG
#define OUT_YF_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define OUT_YF_MASK               OUT_YF__MASK
#define OUT_YF_SHIFT              OUT_YF__SHIFT
#define OUT_YF_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OUT_YF_PS                     (* (reg8 *) OUT_YF__PS)
/* Data Register */
#define OUT_YF_DR                     (* (reg8 *) OUT_YF__DR)
/* Port Number */
#define OUT_YF_PRT_NUM                (* (reg8 *) OUT_YF__PRT) 
/* Connect to Analog Globals */                                                  
#define OUT_YF_AG                     (* (reg8 *) OUT_YF__AG)                       
/* Analog MUX bux enable */
#define OUT_YF_AMUX                   (* (reg8 *) OUT_YF__AMUX) 
/* Bidirectional Enable */                                                        
#define OUT_YF_BIE                    (* (reg8 *) OUT_YF__BIE)
/* Bit-mask for Aliased Register Access */
#define OUT_YF_BIT_MASK               (* (reg8 *) OUT_YF__BIT_MASK)
/* Bypass Enable */
#define OUT_YF_BYP                    (* (reg8 *) OUT_YF__BYP)
/* Port wide control signals */                                                   
#define OUT_YF_CTL                    (* (reg8 *) OUT_YF__CTL)
/* Drive Modes */
#define OUT_YF_DM0                    (* (reg8 *) OUT_YF__DM0) 
#define OUT_YF_DM1                    (* (reg8 *) OUT_YF__DM1)
#define OUT_YF_DM2                    (* (reg8 *) OUT_YF__DM2) 
/* Input Buffer Disable Override */
#define OUT_YF_INP_DIS                (* (reg8 *) OUT_YF__INP_DIS)
/* LCD Common or Segment Drive */
#define OUT_YF_LCD_COM_SEG            (* (reg8 *) OUT_YF__LCD_COM_SEG)
/* Enable Segment LCD */
#define OUT_YF_LCD_EN                 (* (reg8 *) OUT_YF__LCD_EN)
/* Slew Rate Control */
#define OUT_YF_SLW                    (* (reg8 *) OUT_YF__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OUT_YF_PRTDSI__CAPS_SEL       (* (reg8 *) OUT_YF__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OUT_YF_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OUT_YF__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OUT_YF_PRTDSI__OE_SEL0        (* (reg8 *) OUT_YF__PRTDSI__OE_SEL0) 
#define OUT_YF_PRTDSI__OE_SEL1        (* (reg8 *) OUT_YF__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OUT_YF_PRTDSI__OUT_SEL0       (* (reg8 *) OUT_YF__PRTDSI__OUT_SEL0) 
#define OUT_YF_PRTDSI__OUT_SEL1       (* (reg8 *) OUT_YF__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OUT_YF_PRTDSI__SYNC_OUT       (* (reg8 *) OUT_YF__PRTDSI__SYNC_OUT) 


#if defined(OUT_YF__INTSTAT)  /* Interrupt Registers */

    #define OUT_YF_INTSTAT                (* (reg8 *) OUT_YF__INTSTAT)
    #define OUT_YF_SNAP                   (* (reg8 *) OUT_YF__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OUT_YF_H */


/* [] END OF FILE */
