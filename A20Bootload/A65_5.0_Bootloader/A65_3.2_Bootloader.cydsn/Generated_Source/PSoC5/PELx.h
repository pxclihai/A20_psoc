/*******************************************************************************
* File Name: PELx.h  
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

#if !defined(CY_PINS_PELx_H) /* Pins PELx_H */
#define CY_PINS_PELx_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PELx_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PELx__PORT == 15 && ((PELx__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PELx_Write(uint8 value) ;
void    PELx_SetDriveMode(uint8 mode) ;
uint8   PELx_ReadDataReg(void) ;
uint8   PELx_Read(void) ;
uint8   PELx_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PELx_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PELx_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PELx_DM_RES_UP          PIN_DM_RES_UP
#define PELx_DM_RES_DWN         PIN_DM_RES_DWN
#define PELx_DM_OD_LO           PIN_DM_OD_LO
#define PELx_DM_OD_HI           PIN_DM_OD_HI
#define PELx_DM_STRONG          PIN_DM_STRONG
#define PELx_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PELx_MASK               PELx__MASK
#define PELx_SHIFT              PELx__SHIFT
#define PELx_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PELx_PS                     (* (reg8 *) PELx__PS)
/* Data Register */
#define PELx_DR                     (* (reg8 *) PELx__DR)
/* Port Number */
#define PELx_PRT_NUM                (* (reg8 *) PELx__PRT) 
/* Connect to Analog Globals */                                                  
#define PELx_AG                     (* (reg8 *) PELx__AG)                       
/* Analog MUX bux enable */
#define PELx_AMUX                   (* (reg8 *) PELx__AMUX) 
/* Bidirectional Enable */                                                        
#define PELx_BIE                    (* (reg8 *) PELx__BIE)
/* Bit-mask for Aliased Register Access */
#define PELx_BIT_MASK               (* (reg8 *) PELx__BIT_MASK)
/* Bypass Enable */
#define PELx_BYP                    (* (reg8 *) PELx__BYP)
/* Port wide control signals */                                                   
#define PELx_CTL                    (* (reg8 *) PELx__CTL)
/* Drive Modes */
#define PELx_DM0                    (* (reg8 *) PELx__DM0) 
#define PELx_DM1                    (* (reg8 *) PELx__DM1)
#define PELx_DM2                    (* (reg8 *) PELx__DM2) 
/* Input Buffer Disable Override */
#define PELx_INP_DIS                (* (reg8 *) PELx__INP_DIS)
/* LCD Common or Segment Drive */
#define PELx_LCD_COM_SEG            (* (reg8 *) PELx__LCD_COM_SEG)
/* Enable Segment LCD */
#define PELx_LCD_EN                 (* (reg8 *) PELx__LCD_EN)
/* Slew Rate Control */
#define PELx_SLW                    (* (reg8 *) PELx__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PELx_PRTDSI__CAPS_SEL       (* (reg8 *) PELx__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PELx_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PELx__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PELx_PRTDSI__OE_SEL0        (* (reg8 *) PELx__PRTDSI__OE_SEL0) 
#define PELx_PRTDSI__OE_SEL1        (* (reg8 *) PELx__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PELx_PRTDSI__OUT_SEL0       (* (reg8 *) PELx__PRTDSI__OUT_SEL0) 
#define PELx_PRTDSI__OUT_SEL1       (* (reg8 *) PELx__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PELx_PRTDSI__SYNC_OUT       (* (reg8 *) PELx__PRTDSI__SYNC_OUT) 


#if defined(PELx__INTSTAT)  /* Interrupt Registers */

    #define PELx_INTSTAT                (* (reg8 *) PELx__INTSTAT)
    #define PELx_SNAP                   (* (reg8 *) PELx__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PELx_H */


/* [] END OF FILE */
