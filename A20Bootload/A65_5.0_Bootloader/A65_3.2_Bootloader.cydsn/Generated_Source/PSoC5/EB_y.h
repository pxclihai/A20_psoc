/*******************************************************************************
* File Name: EB_y.h  
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

#if !defined(CY_PINS_EB_y_H) /* Pins EB_y_H */
#define CY_PINS_EB_y_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EB_y_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EB_y__PORT == 15 && ((EB_y__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EB_y_Write(uint8 value) ;
void    EB_y_SetDriveMode(uint8 mode) ;
uint8   EB_y_ReadDataReg(void) ;
uint8   EB_y_Read(void) ;
uint8   EB_y_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EB_y_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EB_y_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EB_y_DM_RES_UP          PIN_DM_RES_UP
#define EB_y_DM_RES_DWN         PIN_DM_RES_DWN
#define EB_y_DM_OD_LO           PIN_DM_OD_LO
#define EB_y_DM_OD_HI           PIN_DM_OD_HI
#define EB_y_DM_STRONG          PIN_DM_STRONG
#define EB_y_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EB_y_MASK               EB_y__MASK
#define EB_y_SHIFT              EB_y__SHIFT
#define EB_y_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EB_y_PS                     (* (reg8 *) EB_y__PS)
/* Data Register */
#define EB_y_DR                     (* (reg8 *) EB_y__DR)
/* Port Number */
#define EB_y_PRT_NUM                (* (reg8 *) EB_y__PRT) 
/* Connect to Analog Globals */                                                  
#define EB_y_AG                     (* (reg8 *) EB_y__AG)                       
/* Analog MUX bux enable */
#define EB_y_AMUX                   (* (reg8 *) EB_y__AMUX) 
/* Bidirectional Enable */                                                        
#define EB_y_BIE                    (* (reg8 *) EB_y__BIE)
/* Bit-mask for Aliased Register Access */
#define EB_y_BIT_MASK               (* (reg8 *) EB_y__BIT_MASK)
/* Bypass Enable */
#define EB_y_BYP                    (* (reg8 *) EB_y__BYP)
/* Port wide control signals */                                                   
#define EB_y_CTL                    (* (reg8 *) EB_y__CTL)
/* Drive Modes */
#define EB_y_DM0                    (* (reg8 *) EB_y__DM0) 
#define EB_y_DM1                    (* (reg8 *) EB_y__DM1)
#define EB_y_DM2                    (* (reg8 *) EB_y__DM2) 
/* Input Buffer Disable Override */
#define EB_y_INP_DIS                (* (reg8 *) EB_y__INP_DIS)
/* LCD Common or Segment Drive */
#define EB_y_LCD_COM_SEG            (* (reg8 *) EB_y__LCD_COM_SEG)
/* Enable Segment LCD */
#define EB_y_LCD_EN                 (* (reg8 *) EB_y__LCD_EN)
/* Slew Rate Control */
#define EB_y_SLW                    (* (reg8 *) EB_y__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EB_y_PRTDSI__CAPS_SEL       (* (reg8 *) EB_y__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EB_y_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EB_y__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EB_y_PRTDSI__OE_SEL0        (* (reg8 *) EB_y__PRTDSI__OE_SEL0) 
#define EB_y_PRTDSI__OE_SEL1        (* (reg8 *) EB_y__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EB_y_PRTDSI__OUT_SEL0       (* (reg8 *) EB_y__PRTDSI__OUT_SEL0) 
#define EB_y_PRTDSI__OUT_SEL1       (* (reg8 *) EB_y__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EB_y_PRTDSI__SYNC_OUT       (* (reg8 *) EB_y__PRTDSI__SYNC_OUT) 


#if defined(EB_y__INTSTAT)  /* Interrupt Registers */

    #define EB_y_INTSTAT                (* (reg8 *) EB_y__INTSTAT)
    #define EB_y_SNAP                   (* (reg8 *) EB_y__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EB_y_H */


/* [] END OF FILE */
