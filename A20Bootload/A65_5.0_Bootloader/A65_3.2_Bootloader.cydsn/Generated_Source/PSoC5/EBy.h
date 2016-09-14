/*******************************************************************************
* File Name: EBy.h  
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

#if !defined(CY_PINS_EBy_H) /* Pins EBy_H */
#define CY_PINS_EBy_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EBy_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EBy__PORT == 15 && ((EBy__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EBy_Write(uint8 value) ;
void    EBy_SetDriveMode(uint8 mode) ;
uint8   EBy_ReadDataReg(void) ;
uint8   EBy_Read(void) ;
uint8   EBy_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EBy_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EBy_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EBy_DM_RES_UP          PIN_DM_RES_UP
#define EBy_DM_RES_DWN         PIN_DM_RES_DWN
#define EBy_DM_OD_LO           PIN_DM_OD_LO
#define EBy_DM_OD_HI           PIN_DM_OD_HI
#define EBy_DM_STRONG          PIN_DM_STRONG
#define EBy_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EBy_MASK               EBy__MASK
#define EBy_SHIFT              EBy__SHIFT
#define EBy_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EBy_PS                     (* (reg8 *) EBy__PS)
/* Data Register */
#define EBy_DR                     (* (reg8 *) EBy__DR)
/* Port Number */
#define EBy_PRT_NUM                (* (reg8 *) EBy__PRT) 
/* Connect to Analog Globals */                                                  
#define EBy_AG                     (* (reg8 *) EBy__AG)                       
/* Analog MUX bux enable */
#define EBy_AMUX                   (* (reg8 *) EBy__AMUX) 
/* Bidirectional Enable */                                                        
#define EBy_BIE                    (* (reg8 *) EBy__BIE)
/* Bit-mask for Aliased Register Access */
#define EBy_BIT_MASK               (* (reg8 *) EBy__BIT_MASK)
/* Bypass Enable */
#define EBy_BYP                    (* (reg8 *) EBy__BYP)
/* Port wide control signals */                                                   
#define EBy_CTL                    (* (reg8 *) EBy__CTL)
/* Drive Modes */
#define EBy_DM0                    (* (reg8 *) EBy__DM0) 
#define EBy_DM1                    (* (reg8 *) EBy__DM1)
#define EBy_DM2                    (* (reg8 *) EBy__DM2) 
/* Input Buffer Disable Override */
#define EBy_INP_DIS                (* (reg8 *) EBy__INP_DIS)
/* LCD Common or Segment Drive */
#define EBy_LCD_COM_SEG            (* (reg8 *) EBy__LCD_COM_SEG)
/* Enable Segment LCD */
#define EBy_LCD_EN                 (* (reg8 *) EBy__LCD_EN)
/* Slew Rate Control */
#define EBy_SLW                    (* (reg8 *) EBy__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EBy_PRTDSI__CAPS_SEL       (* (reg8 *) EBy__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EBy_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EBy__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EBy_PRTDSI__OE_SEL0        (* (reg8 *) EBy__PRTDSI__OE_SEL0) 
#define EBy_PRTDSI__OE_SEL1        (* (reg8 *) EBy__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EBy_PRTDSI__OUT_SEL0       (* (reg8 *) EBy__PRTDSI__OUT_SEL0) 
#define EBy_PRTDSI__OUT_SEL1       (* (reg8 *) EBy__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EBy_PRTDSI__SYNC_OUT       (* (reg8 *) EBy__PRTDSI__SYNC_OUT) 


#if defined(EBy__INTSTAT)  /* Interrupt Registers */

    #define EBy_INTSTAT                (* (reg8 *) EBy__INTSTAT)
    #define EBy_SNAP                   (* (reg8 *) EBy__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EBy_H */


/* [] END OF FILE */
