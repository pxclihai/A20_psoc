/*******************************************************************************
* File Name: PELy.h  
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

#if !defined(CY_PINS_PELy_H) /* Pins PELy_H */
#define CY_PINS_PELy_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PELy_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PELy__PORT == 15 && ((PELy__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PELy_Write(uint8 value) ;
void    PELy_SetDriveMode(uint8 mode) ;
uint8   PELy_ReadDataReg(void) ;
uint8   PELy_Read(void) ;
uint8   PELy_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PELy_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PELy_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PELy_DM_RES_UP          PIN_DM_RES_UP
#define PELy_DM_RES_DWN         PIN_DM_RES_DWN
#define PELy_DM_OD_LO           PIN_DM_OD_LO
#define PELy_DM_OD_HI           PIN_DM_OD_HI
#define PELy_DM_STRONG          PIN_DM_STRONG
#define PELy_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PELy_MASK               PELy__MASK
#define PELy_SHIFT              PELy__SHIFT
#define PELy_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PELy_PS                     (* (reg8 *) PELy__PS)
/* Data Register */
#define PELy_DR                     (* (reg8 *) PELy__DR)
/* Port Number */
#define PELy_PRT_NUM                (* (reg8 *) PELy__PRT) 
/* Connect to Analog Globals */                                                  
#define PELy_AG                     (* (reg8 *) PELy__AG)                       
/* Analog MUX bux enable */
#define PELy_AMUX                   (* (reg8 *) PELy__AMUX) 
/* Bidirectional Enable */                                                        
#define PELy_BIE                    (* (reg8 *) PELy__BIE)
/* Bit-mask for Aliased Register Access */
#define PELy_BIT_MASK               (* (reg8 *) PELy__BIT_MASK)
/* Bypass Enable */
#define PELy_BYP                    (* (reg8 *) PELy__BYP)
/* Port wide control signals */                                                   
#define PELy_CTL                    (* (reg8 *) PELy__CTL)
/* Drive Modes */
#define PELy_DM0                    (* (reg8 *) PELy__DM0) 
#define PELy_DM1                    (* (reg8 *) PELy__DM1)
#define PELy_DM2                    (* (reg8 *) PELy__DM2) 
/* Input Buffer Disable Override */
#define PELy_INP_DIS                (* (reg8 *) PELy__INP_DIS)
/* LCD Common or Segment Drive */
#define PELy_LCD_COM_SEG            (* (reg8 *) PELy__LCD_COM_SEG)
/* Enable Segment LCD */
#define PELy_LCD_EN                 (* (reg8 *) PELy__LCD_EN)
/* Slew Rate Control */
#define PELy_SLW                    (* (reg8 *) PELy__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PELy_PRTDSI__CAPS_SEL       (* (reg8 *) PELy__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PELy_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PELy__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PELy_PRTDSI__OE_SEL0        (* (reg8 *) PELy__PRTDSI__OE_SEL0) 
#define PELy_PRTDSI__OE_SEL1        (* (reg8 *) PELy__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PELy_PRTDSI__OUT_SEL0       (* (reg8 *) PELy__PRTDSI__OUT_SEL0) 
#define PELy_PRTDSI__OUT_SEL1       (* (reg8 *) PELy__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PELy_PRTDSI__SYNC_OUT       (* (reg8 *) PELy__PRTDSI__SYNC_OUT) 


#if defined(PELy__INTSTAT)  /* Interrupt Registers */

    #define PELy_INTSTAT                (* (reg8 *) PELy__INTSTAT)
    #define PELy_SNAP                   (* (reg8 *) PELy__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PELy_H */


/* [] END OF FILE */
