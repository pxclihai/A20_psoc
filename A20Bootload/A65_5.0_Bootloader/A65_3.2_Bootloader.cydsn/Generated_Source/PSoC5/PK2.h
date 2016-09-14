/*******************************************************************************
* File Name: PK2.h  
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

#if !defined(CY_PINS_PK2_H) /* Pins PK2_H */
#define CY_PINS_PK2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PK2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PK2__PORT == 15 && ((PK2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PK2_Write(uint8 value) ;
void    PK2_SetDriveMode(uint8 mode) ;
uint8   PK2_ReadDataReg(void) ;
uint8   PK2_Read(void) ;
uint8   PK2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PK2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PK2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PK2_DM_RES_UP          PIN_DM_RES_UP
#define PK2_DM_RES_DWN         PIN_DM_RES_DWN
#define PK2_DM_OD_LO           PIN_DM_OD_LO
#define PK2_DM_OD_HI           PIN_DM_OD_HI
#define PK2_DM_STRONG          PIN_DM_STRONG
#define PK2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PK2_MASK               PK2__MASK
#define PK2_SHIFT              PK2__SHIFT
#define PK2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PK2_PS                     (* (reg8 *) PK2__PS)
/* Data Register */
#define PK2_DR                     (* (reg8 *) PK2__DR)
/* Port Number */
#define PK2_PRT_NUM                (* (reg8 *) PK2__PRT) 
/* Connect to Analog Globals */                                                  
#define PK2_AG                     (* (reg8 *) PK2__AG)                       
/* Analog MUX bux enable */
#define PK2_AMUX                   (* (reg8 *) PK2__AMUX) 
/* Bidirectional Enable */                                                        
#define PK2_BIE                    (* (reg8 *) PK2__BIE)
/* Bit-mask for Aliased Register Access */
#define PK2_BIT_MASK               (* (reg8 *) PK2__BIT_MASK)
/* Bypass Enable */
#define PK2_BYP                    (* (reg8 *) PK2__BYP)
/* Port wide control signals */                                                   
#define PK2_CTL                    (* (reg8 *) PK2__CTL)
/* Drive Modes */
#define PK2_DM0                    (* (reg8 *) PK2__DM0) 
#define PK2_DM1                    (* (reg8 *) PK2__DM1)
#define PK2_DM2                    (* (reg8 *) PK2__DM2) 
/* Input Buffer Disable Override */
#define PK2_INP_DIS                (* (reg8 *) PK2__INP_DIS)
/* LCD Common or Segment Drive */
#define PK2_LCD_COM_SEG            (* (reg8 *) PK2__LCD_COM_SEG)
/* Enable Segment LCD */
#define PK2_LCD_EN                 (* (reg8 *) PK2__LCD_EN)
/* Slew Rate Control */
#define PK2_SLW                    (* (reg8 *) PK2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PK2_PRTDSI__CAPS_SEL       (* (reg8 *) PK2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PK2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PK2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PK2_PRTDSI__OE_SEL0        (* (reg8 *) PK2__PRTDSI__OE_SEL0) 
#define PK2_PRTDSI__OE_SEL1        (* (reg8 *) PK2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PK2_PRTDSI__OUT_SEL0       (* (reg8 *) PK2__PRTDSI__OUT_SEL0) 
#define PK2_PRTDSI__OUT_SEL1       (* (reg8 *) PK2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PK2_PRTDSI__SYNC_OUT       (* (reg8 *) PK2__PRTDSI__SYNC_OUT) 


#if defined(PK2__INTSTAT)  /* Interrupt Registers */

    #define PK2_INTSTAT                (* (reg8 *) PK2__INTSTAT)
    #define PK2_SNAP                   (* (reg8 *) PK2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PK2_H */


/* [] END OF FILE */
