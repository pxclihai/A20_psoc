/*******************************************************************************
* File Name: WR.h  
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

#if !defined(CY_PINS_WR_H) /* Pins WR_H */
#define CY_PINS_WR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "WR_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 WR__PORT == 15 && ((WR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    WR_Write(uint8 value) ;
void    WR_SetDriveMode(uint8 mode) ;
uint8   WR_ReadDataReg(void) ;
uint8   WR_Read(void) ;
uint8   WR_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define WR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define WR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define WR_DM_RES_UP          PIN_DM_RES_UP
#define WR_DM_RES_DWN         PIN_DM_RES_DWN
#define WR_DM_OD_LO           PIN_DM_OD_LO
#define WR_DM_OD_HI           PIN_DM_OD_HI
#define WR_DM_STRONG          PIN_DM_STRONG
#define WR_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define WR_MASK               WR__MASK
#define WR_SHIFT              WR__SHIFT
#define WR_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WR_PS                     (* (reg8 *) WR__PS)
/* Data Register */
#define WR_DR                     (* (reg8 *) WR__DR)
/* Port Number */
#define WR_PRT_NUM                (* (reg8 *) WR__PRT) 
/* Connect to Analog Globals */                                                  
#define WR_AG                     (* (reg8 *) WR__AG)                       
/* Analog MUX bux enable */
#define WR_AMUX                   (* (reg8 *) WR__AMUX) 
/* Bidirectional Enable */                                                        
#define WR_BIE                    (* (reg8 *) WR__BIE)
/* Bit-mask for Aliased Register Access */
#define WR_BIT_MASK               (* (reg8 *) WR__BIT_MASK)
/* Bypass Enable */
#define WR_BYP                    (* (reg8 *) WR__BYP)
/* Port wide control signals */                                                   
#define WR_CTL                    (* (reg8 *) WR__CTL)
/* Drive Modes */
#define WR_DM0                    (* (reg8 *) WR__DM0) 
#define WR_DM1                    (* (reg8 *) WR__DM1)
#define WR_DM2                    (* (reg8 *) WR__DM2) 
/* Input Buffer Disable Override */
#define WR_INP_DIS                (* (reg8 *) WR__INP_DIS)
/* LCD Common or Segment Drive */
#define WR_LCD_COM_SEG            (* (reg8 *) WR__LCD_COM_SEG)
/* Enable Segment LCD */
#define WR_LCD_EN                 (* (reg8 *) WR__LCD_EN)
/* Slew Rate Control */
#define WR_SLW                    (* (reg8 *) WR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define WR_PRTDSI__CAPS_SEL       (* (reg8 *) WR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define WR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) WR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define WR_PRTDSI__OE_SEL0        (* (reg8 *) WR__PRTDSI__OE_SEL0) 
#define WR_PRTDSI__OE_SEL1        (* (reg8 *) WR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define WR_PRTDSI__OUT_SEL0       (* (reg8 *) WR__PRTDSI__OUT_SEL0) 
#define WR_PRTDSI__OUT_SEL1       (* (reg8 *) WR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define WR_PRTDSI__SYNC_OUT       (* (reg8 *) WR__PRTDSI__SYNC_OUT) 


#if defined(WR__INTSTAT)  /* Interrupt Registers */

    #define WR_INTSTAT                (* (reg8 *) WR__INTSTAT)
    #define WR_SNAP                   (* (reg8 *) WR__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_WR_H */


/* [] END OF FILE */
