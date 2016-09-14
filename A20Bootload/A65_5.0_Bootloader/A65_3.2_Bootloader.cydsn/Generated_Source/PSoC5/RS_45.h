/*******************************************************************************
* File Name: RS_45.h  
* Version 1.80
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

#if !defined(CY_PINS_RS_45_H) /* Pins RS_45_H */
#define CY_PINS_RS_45_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RS_45_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RS_45__PORT == 15 && ((RS_45__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RS_45_Write(uint8 value) ;
void    RS_45_SetDriveMode(uint8 mode) ;
uint8   RS_45_ReadDataReg(void) ;
uint8   RS_45_Read(void) ;
uint8   RS_45_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RS_45_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RS_45_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RS_45_DM_RES_UP          PIN_DM_RES_UP
#define RS_45_DM_RES_DWN         PIN_DM_RES_DWN
#define RS_45_DM_OD_LO           PIN_DM_OD_LO
#define RS_45_DM_OD_HI           PIN_DM_OD_HI
#define RS_45_DM_STRONG          PIN_DM_STRONG
#define RS_45_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RS_45_MASK               RS_45__MASK
#define RS_45_SHIFT              RS_45__SHIFT
#define RS_45_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RS_45_PS                     (* (reg8 *) RS_45__PS)
/* Data Register */
#define RS_45_DR                     (* (reg8 *) RS_45__DR)
/* Port Number */
#define RS_45_PRT_NUM                (* (reg8 *) RS_45__PRT) 
/* Connect to Analog Globals */                                                  
#define RS_45_AG                     (* (reg8 *) RS_45__AG)                       
/* Analog MUX bux enable */
#define RS_45_AMUX                   (* (reg8 *) RS_45__AMUX) 
/* Bidirectional Enable */                                                        
#define RS_45_BIE                    (* (reg8 *) RS_45__BIE)
/* Bit-mask for Aliased Register Access */
#define RS_45_BIT_MASK               (* (reg8 *) RS_45__BIT_MASK)
/* Bypass Enable */
#define RS_45_BYP                    (* (reg8 *) RS_45__BYP)
/* Port wide control signals */                                                   
#define RS_45_CTL                    (* (reg8 *) RS_45__CTL)
/* Drive Modes */
#define RS_45_DM0                    (* (reg8 *) RS_45__DM0) 
#define RS_45_DM1                    (* (reg8 *) RS_45__DM1)
#define RS_45_DM2                    (* (reg8 *) RS_45__DM2) 
/* Input Buffer Disable Override */
#define RS_45_INP_DIS                (* (reg8 *) RS_45__INP_DIS)
/* LCD Common or Segment Drive */
#define RS_45_LCD_COM_SEG            (* (reg8 *) RS_45__LCD_COM_SEG)
/* Enable Segment LCD */
#define RS_45_LCD_EN                 (* (reg8 *) RS_45__LCD_EN)
/* Slew Rate Control */
#define RS_45_SLW                    (* (reg8 *) RS_45__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RS_45_PRTDSI__CAPS_SEL       (* (reg8 *) RS_45__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RS_45_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RS_45__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RS_45_PRTDSI__OE_SEL0        (* (reg8 *) RS_45__PRTDSI__OE_SEL0) 
#define RS_45_PRTDSI__OE_SEL1        (* (reg8 *) RS_45__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RS_45_PRTDSI__OUT_SEL0       (* (reg8 *) RS_45__PRTDSI__OUT_SEL0) 
#define RS_45_PRTDSI__OUT_SEL1       (* (reg8 *) RS_45__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RS_45_PRTDSI__SYNC_OUT       (* (reg8 *) RS_45__PRTDSI__SYNC_OUT) 


#if defined(RS_45__INTSTAT)  /* Interrupt Registers */

    #define RS_45_INTSTAT                (* (reg8 *) RS_45__INTSTAT)
    #define RS_45_SNAP                   (* (reg8 *) RS_45__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RS_45_H */


/* [] END OF FILE */
