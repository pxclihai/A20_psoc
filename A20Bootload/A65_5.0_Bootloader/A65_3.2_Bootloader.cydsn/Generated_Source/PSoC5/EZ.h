/*******************************************************************************
* File Name: EZ.h  
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

#if !defined(CY_PINS_EZ_H) /* Pins EZ_H */
#define CY_PINS_EZ_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EZ_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EZ__PORT == 15 && ((EZ__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EZ_Write(uint8 value) ;
void    EZ_SetDriveMode(uint8 mode) ;
uint8   EZ_ReadDataReg(void) ;
uint8   EZ_Read(void) ;
uint8   EZ_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EZ_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EZ_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EZ_DM_RES_UP          PIN_DM_RES_UP
#define EZ_DM_RES_DWN         PIN_DM_RES_DWN
#define EZ_DM_OD_LO           PIN_DM_OD_LO
#define EZ_DM_OD_HI           PIN_DM_OD_HI
#define EZ_DM_STRONG          PIN_DM_STRONG
#define EZ_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EZ_MASK               EZ__MASK
#define EZ_SHIFT              EZ__SHIFT
#define EZ_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EZ_PS                     (* (reg8 *) EZ__PS)
/* Data Register */
#define EZ_DR                     (* (reg8 *) EZ__DR)
/* Port Number */
#define EZ_PRT_NUM                (* (reg8 *) EZ__PRT) 
/* Connect to Analog Globals */                                                  
#define EZ_AG                     (* (reg8 *) EZ__AG)                       
/* Analog MUX bux enable */
#define EZ_AMUX                   (* (reg8 *) EZ__AMUX) 
/* Bidirectional Enable */                                                        
#define EZ_BIE                    (* (reg8 *) EZ__BIE)
/* Bit-mask for Aliased Register Access */
#define EZ_BIT_MASK               (* (reg8 *) EZ__BIT_MASK)
/* Bypass Enable */
#define EZ_BYP                    (* (reg8 *) EZ__BYP)
/* Port wide control signals */                                                   
#define EZ_CTL                    (* (reg8 *) EZ__CTL)
/* Drive Modes */
#define EZ_DM0                    (* (reg8 *) EZ__DM0) 
#define EZ_DM1                    (* (reg8 *) EZ__DM1)
#define EZ_DM2                    (* (reg8 *) EZ__DM2) 
/* Input Buffer Disable Override */
#define EZ_INP_DIS                (* (reg8 *) EZ__INP_DIS)
/* LCD Common or Segment Drive */
#define EZ_LCD_COM_SEG            (* (reg8 *) EZ__LCD_COM_SEG)
/* Enable Segment LCD */
#define EZ_LCD_EN                 (* (reg8 *) EZ__LCD_EN)
/* Slew Rate Control */
#define EZ_SLW                    (* (reg8 *) EZ__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EZ_PRTDSI__CAPS_SEL       (* (reg8 *) EZ__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EZ_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EZ__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EZ_PRTDSI__OE_SEL0        (* (reg8 *) EZ__PRTDSI__OE_SEL0) 
#define EZ_PRTDSI__OE_SEL1        (* (reg8 *) EZ__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EZ_PRTDSI__OUT_SEL0       (* (reg8 *) EZ__PRTDSI__OUT_SEL0) 
#define EZ_PRTDSI__OUT_SEL1       (* (reg8 *) EZ__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EZ_PRTDSI__SYNC_OUT       (* (reg8 *) EZ__PRTDSI__SYNC_OUT) 


#if defined(EZ__INTSTAT)  /* Interrupt Registers */

    #define EZ_INTSTAT                (* (reg8 *) EZ__INTSTAT)
    #define EZ_SNAP                   (* (reg8 *) EZ__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EZ_H */


/* [] END OF FILE */
