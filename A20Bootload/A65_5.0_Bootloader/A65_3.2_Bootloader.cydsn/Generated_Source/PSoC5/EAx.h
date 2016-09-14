/*******************************************************************************
* File Name: EAx.h  
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

#if !defined(CY_PINS_EAx_H) /* Pins EAx_H */
#define CY_PINS_EAx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EAx_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EAx__PORT == 15 && ((EAx__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EAx_Write(uint8 value) ;
void    EAx_SetDriveMode(uint8 mode) ;
uint8   EAx_ReadDataReg(void) ;
uint8   EAx_Read(void) ;
uint8   EAx_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EAx_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EAx_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EAx_DM_RES_UP          PIN_DM_RES_UP
#define EAx_DM_RES_DWN         PIN_DM_RES_DWN
#define EAx_DM_OD_LO           PIN_DM_OD_LO
#define EAx_DM_OD_HI           PIN_DM_OD_HI
#define EAx_DM_STRONG          PIN_DM_STRONG
#define EAx_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EAx_MASK               EAx__MASK
#define EAx_SHIFT              EAx__SHIFT
#define EAx_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EAx_PS                     (* (reg8 *) EAx__PS)
/* Data Register */
#define EAx_DR                     (* (reg8 *) EAx__DR)
/* Port Number */
#define EAx_PRT_NUM                (* (reg8 *) EAx__PRT) 
/* Connect to Analog Globals */                                                  
#define EAx_AG                     (* (reg8 *) EAx__AG)                       
/* Analog MUX bux enable */
#define EAx_AMUX                   (* (reg8 *) EAx__AMUX) 
/* Bidirectional Enable */                                                        
#define EAx_BIE                    (* (reg8 *) EAx__BIE)
/* Bit-mask for Aliased Register Access */
#define EAx_BIT_MASK               (* (reg8 *) EAx__BIT_MASK)
/* Bypass Enable */
#define EAx_BYP                    (* (reg8 *) EAx__BYP)
/* Port wide control signals */                                                   
#define EAx_CTL                    (* (reg8 *) EAx__CTL)
/* Drive Modes */
#define EAx_DM0                    (* (reg8 *) EAx__DM0) 
#define EAx_DM1                    (* (reg8 *) EAx__DM1)
#define EAx_DM2                    (* (reg8 *) EAx__DM2) 
/* Input Buffer Disable Override */
#define EAx_INP_DIS                (* (reg8 *) EAx__INP_DIS)
/* LCD Common or Segment Drive */
#define EAx_LCD_COM_SEG            (* (reg8 *) EAx__LCD_COM_SEG)
/* Enable Segment LCD */
#define EAx_LCD_EN                 (* (reg8 *) EAx__LCD_EN)
/* Slew Rate Control */
#define EAx_SLW                    (* (reg8 *) EAx__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EAx_PRTDSI__CAPS_SEL       (* (reg8 *) EAx__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EAx_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EAx__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EAx_PRTDSI__OE_SEL0        (* (reg8 *) EAx__PRTDSI__OE_SEL0) 
#define EAx_PRTDSI__OE_SEL1        (* (reg8 *) EAx__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EAx_PRTDSI__OUT_SEL0       (* (reg8 *) EAx__PRTDSI__OUT_SEL0) 
#define EAx_PRTDSI__OUT_SEL1       (* (reg8 *) EAx__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EAx_PRTDSI__SYNC_OUT       (* (reg8 *) EAx__PRTDSI__SYNC_OUT) 


#if defined(EAx__INTSTAT)  /* Interrupt Registers */

    #define EAx_INTSTAT                (* (reg8 *) EAx__INTSTAT)
    #define EAx_SNAP                   (* (reg8 *) EAx__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EAx_H */


/* [] END OF FILE */
