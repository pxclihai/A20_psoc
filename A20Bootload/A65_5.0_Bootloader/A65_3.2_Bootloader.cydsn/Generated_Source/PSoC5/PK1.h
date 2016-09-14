/*******************************************************************************
* File Name: PK1.h  
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

#if !defined(CY_PINS_PK1_H) /* Pins PK1_H */
#define CY_PINS_PK1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PK1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PK1__PORT == 15 && ((PK1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PK1_Write(uint8 value) ;
void    PK1_SetDriveMode(uint8 mode) ;
uint8   PK1_ReadDataReg(void) ;
uint8   PK1_Read(void) ;
uint8   PK1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PK1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PK1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PK1_DM_RES_UP          PIN_DM_RES_UP
#define PK1_DM_RES_DWN         PIN_DM_RES_DWN
#define PK1_DM_OD_LO           PIN_DM_OD_LO
#define PK1_DM_OD_HI           PIN_DM_OD_HI
#define PK1_DM_STRONG          PIN_DM_STRONG
#define PK1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PK1_MASK               PK1__MASK
#define PK1_SHIFT              PK1__SHIFT
#define PK1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PK1_PS                     (* (reg8 *) PK1__PS)
/* Data Register */
#define PK1_DR                     (* (reg8 *) PK1__DR)
/* Port Number */
#define PK1_PRT_NUM                (* (reg8 *) PK1__PRT) 
/* Connect to Analog Globals */                                                  
#define PK1_AG                     (* (reg8 *) PK1__AG)                       
/* Analog MUX bux enable */
#define PK1_AMUX                   (* (reg8 *) PK1__AMUX) 
/* Bidirectional Enable */                                                        
#define PK1_BIE                    (* (reg8 *) PK1__BIE)
/* Bit-mask for Aliased Register Access */
#define PK1_BIT_MASK               (* (reg8 *) PK1__BIT_MASK)
/* Bypass Enable */
#define PK1_BYP                    (* (reg8 *) PK1__BYP)
/* Port wide control signals */                                                   
#define PK1_CTL                    (* (reg8 *) PK1__CTL)
/* Drive Modes */
#define PK1_DM0                    (* (reg8 *) PK1__DM0) 
#define PK1_DM1                    (* (reg8 *) PK1__DM1)
#define PK1_DM2                    (* (reg8 *) PK1__DM2) 
/* Input Buffer Disable Override */
#define PK1_INP_DIS                (* (reg8 *) PK1__INP_DIS)
/* LCD Common or Segment Drive */
#define PK1_LCD_COM_SEG            (* (reg8 *) PK1__LCD_COM_SEG)
/* Enable Segment LCD */
#define PK1_LCD_EN                 (* (reg8 *) PK1__LCD_EN)
/* Slew Rate Control */
#define PK1_SLW                    (* (reg8 *) PK1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PK1_PRTDSI__CAPS_SEL       (* (reg8 *) PK1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PK1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PK1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PK1_PRTDSI__OE_SEL0        (* (reg8 *) PK1__PRTDSI__OE_SEL0) 
#define PK1_PRTDSI__OE_SEL1        (* (reg8 *) PK1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PK1_PRTDSI__OUT_SEL0       (* (reg8 *) PK1__PRTDSI__OUT_SEL0) 
#define PK1_PRTDSI__OUT_SEL1       (* (reg8 *) PK1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PK1_PRTDSI__SYNC_OUT       (* (reg8 *) PK1__PRTDSI__SYNC_OUT) 


#if defined(PK1__INTSTAT)  /* Interrupt Registers */

    #define PK1_INTSTAT                (* (reg8 *) PK1__INTSTAT)
    #define PK1_SNAP                   (* (reg8 *) PK1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PK1_H */


/* [] END OF FILE */
