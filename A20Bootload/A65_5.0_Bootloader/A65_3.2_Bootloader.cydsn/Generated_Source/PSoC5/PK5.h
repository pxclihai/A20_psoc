/*******************************************************************************
* File Name: PK5.h  
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

#if !defined(CY_PINS_PK5_H) /* Pins PK5_H */
#define CY_PINS_PK5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PK5_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PK5__PORT == 15 && ((PK5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PK5_Write(uint8 value) ;
void    PK5_SetDriveMode(uint8 mode) ;
uint8   PK5_ReadDataReg(void) ;
uint8   PK5_Read(void) ;
uint8   PK5_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PK5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PK5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PK5_DM_RES_UP          PIN_DM_RES_UP
#define PK5_DM_RES_DWN         PIN_DM_RES_DWN
#define PK5_DM_OD_LO           PIN_DM_OD_LO
#define PK5_DM_OD_HI           PIN_DM_OD_HI
#define PK5_DM_STRONG          PIN_DM_STRONG
#define PK5_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PK5_MASK               PK5__MASK
#define PK5_SHIFT              PK5__SHIFT
#define PK5_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PK5_PS                     (* (reg8 *) PK5__PS)
/* Data Register */
#define PK5_DR                     (* (reg8 *) PK5__DR)
/* Port Number */
#define PK5_PRT_NUM                (* (reg8 *) PK5__PRT) 
/* Connect to Analog Globals */                                                  
#define PK5_AG                     (* (reg8 *) PK5__AG)                       
/* Analog MUX bux enable */
#define PK5_AMUX                   (* (reg8 *) PK5__AMUX) 
/* Bidirectional Enable */                                                        
#define PK5_BIE                    (* (reg8 *) PK5__BIE)
/* Bit-mask for Aliased Register Access */
#define PK5_BIT_MASK               (* (reg8 *) PK5__BIT_MASK)
/* Bypass Enable */
#define PK5_BYP                    (* (reg8 *) PK5__BYP)
/* Port wide control signals */                                                   
#define PK5_CTL                    (* (reg8 *) PK5__CTL)
/* Drive Modes */
#define PK5_DM0                    (* (reg8 *) PK5__DM0) 
#define PK5_DM1                    (* (reg8 *) PK5__DM1)
#define PK5_DM2                    (* (reg8 *) PK5__DM2) 
/* Input Buffer Disable Override */
#define PK5_INP_DIS                (* (reg8 *) PK5__INP_DIS)
/* LCD Common or Segment Drive */
#define PK5_LCD_COM_SEG            (* (reg8 *) PK5__LCD_COM_SEG)
/* Enable Segment LCD */
#define PK5_LCD_EN                 (* (reg8 *) PK5__LCD_EN)
/* Slew Rate Control */
#define PK5_SLW                    (* (reg8 *) PK5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PK5_PRTDSI__CAPS_SEL       (* (reg8 *) PK5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PK5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PK5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PK5_PRTDSI__OE_SEL0        (* (reg8 *) PK5__PRTDSI__OE_SEL0) 
#define PK5_PRTDSI__OE_SEL1        (* (reg8 *) PK5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PK5_PRTDSI__OUT_SEL0       (* (reg8 *) PK5__PRTDSI__OUT_SEL0) 
#define PK5_PRTDSI__OUT_SEL1       (* (reg8 *) PK5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PK5_PRTDSI__SYNC_OUT       (* (reg8 *) PK5__PRTDSI__SYNC_OUT) 


#if defined(PK5__INTSTAT)  /* Interrupt Registers */

    #define PK5_INTSTAT                (* (reg8 *) PK5__INTSTAT)
    #define PK5_SNAP                   (* (reg8 *) PK5__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PK5_H */


/* [] END OF FILE */
