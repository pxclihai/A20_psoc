/*******************************************************************************
* File Name: EBx.h  
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

#if !defined(CY_PINS_EBx_H) /* Pins EBx_H */
#define CY_PINS_EBx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EBx_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EBx__PORT == 15 && ((EBx__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EBx_Write(uint8 value) ;
void    EBx_SetDriveMode(uint8 mode) ;
uint8   EBx_ReadDataReg(void) ;
uint8   EBx_Read(void) ;
uint8   EBx_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EBx_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EBx_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EBx_DM_RES_UP          PIN_DM_RES_UP
#define EBx_DM_RES_DWN         PIN_DM_RES_DWN
#define EBx_DM_OD_LO           PIN_DM_OD_LO
#define EBx_DM_OD_HI           PIN_DM_OD_HI
#define EBx_DM_STRONG          PIN_DM_STRONG
#define EBx_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EBx_MASK               EBx__MASK
#define EBx_SHIFT              EBx__SHIFT
#define EBx_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EBx_PS                     (* (reg8 *) EBx__PS)
/* Data Register */
#define EBx_DR                     (* (reg8 *) EBx__DR)
/* Port Number */
#define EBx_PRT_NUM                (* (reg8 *) EBx__PRT) 
/* Connect to Analog Globals */                                                  
#define EBx_AG                     (* (reg8 *) EBx__AG)                       
/* Analog MUX bux enable */
#define EBx_AMUX                   (* (reg8 *) EBx__AMUX) 
/* Bidirectional Enable */                                                        
#define EBx_BIE                    (* (reg8 *) EBx__BIE)
/* Bit-mask for Aliased Register Access */
#define EBx_BIT_MASK               (* (reg8 *) EBx__BIT_MASK)
/* Bypass Enable */
#define EBx_BYP                    (* (reg8 *) EBx__BYP)
/* Port wide control signals */                                                   
#define EBx_CTL                    (* (reg8 *) EBx__CTL)
/* Drive Modes */
#define EBx_DM0                    (* (reg8 *) EBx__DM0) 
#define EBx_DM1                    (* (reg8 *) EBx__DM1)
#define EBx_DM2                    (* (reg8 *) EBx__DM2) 
/* Input Buffer Disable Override */
#define EBx_INP_DIS                (* (reg8 *) EBx__INP_DIS)
/* LCD Common or Segment Drive */
#define EBx_LCD_COM_SEG            (* (reg8 *) EBx__LCD_COM_SEG)
/* Enable Segment LCD */
#define EBx_LCD_EN                 (* (reg8 *) EBx__LCD_EN)
/* Slew Rate Control */
#define EBx_SLW                    (* (reg8 *) EBx__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EBx_PRTDSI__CAPS_SEL       (* (reg8 *) EBx__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EBx_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EBx__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EBx_PRTDSI__OE_SEL0        (* (reg8 *) EBx__PRTDSI__OE_SEL0) 
#define EBx_PRTDSI__OE_SEL1        (* (reg8 *) EBx__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EBx_PRTDSI__OUT_SEL0       (* (reg8 *) EBx__PRTDSI__OUT_SEL0) 
#define EBx_PRTDSI__OUT_SEL1       (* (reg8 *) EBx__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EBx_PRTDSI__SYNC_OUT       (* (reg8 *) EBx__PRTDSI__SYNC_OUT) 


#if defined(EBx__INTSTAT)  /* Interrupt Registers */

    #define EBx_INTSTAT                (* (reg8 *) EBx__INTSTAT)
    #define EBx_SNAP                   (* (reg8 *) EBx__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EBx_H */


/* [] END OF FILE */
