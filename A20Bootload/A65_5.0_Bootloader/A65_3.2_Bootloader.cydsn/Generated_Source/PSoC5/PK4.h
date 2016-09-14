/*******************************************************************************
* File Name: PK4.h  
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

#if !defined(CY_PINS_PK4_H) /* Pins PK4_H */
#define CY_PINS_PK4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PK4_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PK4__PORT == 15 && ((PK4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PK4_Write(uint8 value) ;
void    PK4_SetDriveMode(uint8 mode) ;
uint8   PK4_ReadDataReg(void) ;
uint8   PK4_Read(void) ;
uint8   PK4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PK4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PK4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PK4_DM_RES_UP          PIN_DM_RES_UP
#define PK4_DM_RES_DWN         PIN_DM_RES_DWN
#define PK4_DM_OD_LO           PIN_DM_OD_LO
#define PK4_DM_OD_HI           PIN_DM_OD_HI
#define PK4_DM_STRONG          PIN_DM_STRONG
#define PK4_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PK4_MASK               PK4__MASK
#define PK4_SHIFT              PK4__SHIFT
#define PK4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PK4_PS                     (* (reg8 *) PK4__PS)
/* Data Register */
#define PK4_DR                     (* (reg8 *) PK4__DR)
/* Port Number */
#define PK4_PRT_NUM                (* (reg8 *) PK4__PRT) 
/* Connect to Analog Globals */                                                  
#define PK4_AG                     (* (reg8 *) PK4__AG)                       
/* Analog MUX bux enable */
#define PK4_AMUX                   (* (reg8 *) PK4__AMUX) 
/* Bidirectional Enable */                                                        
#define PK4_BIE                    (* (reg8 *) PK4__BIE)
/* Bit-mask for Aliased Register Access */
#define PK4_BIT_MASK               (* (reg8 *) PK4__BIT_MASK)
/* Bypass Enable */
#define PK4_BYP                    (* (reg8 *) PK4__BYP)
/* Port wide control signals */                                                   
#define PK4_CTL                    (* (reg8 *) PK4__CTL)
/* Drive Modes */
#define PK4_DM0                    (* (reg8 *) PK4__DM0) 
#define PK4_DM1                    (* (reg8 *) PK4__DM1)
#define PK4_DM2                    (* (reg8 *) PK4__DM2) 
/* Input Buffer Disable Override */
#define PK4_INP_DIS                (* (reg8 *) PK4__INP_DIS)
/* LCD Common or Segment Drive */
#define PK4_LCD_COM_SEG            (* (reg8 *) PK4__LCD_COM_SEG)
/* Enable Segment LCD */
#define PK4_LCD_EN                 (* (reg8 *) PK4__LCD_EN)
/* Slew Rate Control */
#define PK4_SLW                    (* (reg8 *) PK4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PK4_PRTDSI__CAPS_SEL       (* (reg8 *) PK4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PK4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PK4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PK4_PRTDSI__OE_SEL0        (* (reg8 *) PK4__PRTDSI__OE_SEL0) 
#define PK4_PRTDSI__OE_SEL1        (* (reg8 *) PK4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PK4_PRTDSI__OUT_SEL0       (* (reg8 *) PK4__PRTDSI__OUT_SEL0) 
#define PK4_PRTDSI__OUT_SEL1       (* (reg8 *) PK4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PK4_PRTDSI__SYNC_OUT       (* (reg8 *) PK4__PRTDSI__SYNC_OUT) 


#if defined(PK4__INTSTAT)  /* Interrupt Registers */

    #define PK4_INTSTAT                (* (reg8 *) PK4__INTSTAT)
    #define PK4_SNAP                   (* (reg8 *) PK4__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PK4_H */


/* [] END OF FILE */
