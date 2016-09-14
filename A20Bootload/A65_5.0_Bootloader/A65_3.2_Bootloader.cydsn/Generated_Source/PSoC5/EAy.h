/*******************************************************************************
* File Name: EAy.h  
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

#if !defined(CY_PINS_EAy_H) /* Pins EAy_H */
#define CY_PINS_EAy_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EAy_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EAy__PORT == 15 && ((EAy__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EAy_Write(uint8 value) ;
void    EAy_SetDriveMode(uint8 mode) ;
uint8   EAy_ReadDataReg(void) ;
uint8   EAy_Read(void) ;
uint8   EAy_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EAy_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EAy_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EAy_DM_RES_UP          PIN_DM_RES_UP
#define EAy_DM_RES_DWN         PIN_DM_RES_DWN
#define EAy_DM_OD_LO           PIN_DM_OD_LO
#define EAy_DM_OD_HI           PIN_DM_OD_HI
#define EAy_DM_STRONG          PIN_DM_STRONG
#define EAy_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EAy_MASK               EAy__MASK
#define EAy_SHIFT              EAy__SHIFT
#define EAy_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EAy_PS                     (* (reg8 *) EAy__PS)
/* Data Register */
#define EAy_DR                     (* (reg8 *) EAy__DR)
/* Port Number */
#define EAy_PRT_NUM                (* (reg8 *) EAy__PRT) 
/* Connect to Analog Globals */                                                  
#define EAy_AG                     (* (reg8 *) EAy__AG)                       
/* Analog MUX bux enable */
#define EAy_AMUX                   (* (reg8 *) EAy__AMUX) 
/* Bidirectional Enable */                                                        
#define EAy_BIE                    (* (reg8 *) EAy__BIE)
/* Bit-mask for Aliased Register Access */
#define EAy_BIT_MASK               (* (reg8 *) EAy__BIT_MASK)
/* Bypass Enable */
#define EAy_BYP                    (* (reg8 *) EAy__BYP)
/* Port wide control signals */                                                   
#define EAy_CTL                    (* (reg8 *) EAy__CTL)
/* Drive Modes */
#define EAy_DM0                    (* (reg8 *) EAy__DM0) 
#define EAy_DM1                    (* (reg8 *) EAy__DM1)
#define EAy_DM2                    (* (reg8 *) EAy__DM2) 
/* Input Buffer Disable Override */
#define EAy_INP_DIS                (* (reg8 *) EAy__INP_DIS)
/* LCD Common or Segment Drive */
#define EAy_LCD_COM_SEG            (* (reg8 *) EAy__LCD_COM_SEG)
/* Enable Segment LCD */
#define EAy_LCD_EN                 (* (reg8 *) EAy__LCD_EN)
/* Slew Rate Control */
#define EAy_SLW                    (* (reg8 *) EAy__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EAy_PRTDSI__CAPS_SEL       (* (reg8 *) EAy__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EAy_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EAy__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EAy_PRTDSI__OE_SEL0        (* (reg8 *) EAy__PRTDSI__OE_SEL0) 
#define EAy_PRTDSI__OE_SEL1        (* (reg8 *) EAy__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EAy_PRTDSI__OUT_SEL0       (* (reg8 *) EAy__PRTDSI__OUT_SEL0) 
#define EAy_PRTDSI__OUT_SEL1       (* (reg8 *) EAy__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EAy_PRTDSI__SYNC_OUT       (* (reg8 *) EAy__PRTDSI__SYNC_OUT) 


#if defined(EAy__INTSTAT)  /* Interrupt Registers */

    #define EAy_INTSTAT                (* (reg8 *) EAy__INTSTAT)
    #define EAy_SNAP                   (* (reg8 *) EAy__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EAy_H */


/* [] END OF FILE */
