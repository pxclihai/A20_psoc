/*******************************************************************************
* File Name: Beep.h  
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

#if !defined(CY_PINS_Beep_H) /* Pins Beep_H */
#define CY_PINS_Beep_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Beep_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Beep__PORT == 15 && ((Beep__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Beep_Write(uint8 value) ;
void    Beep_SetDriveMode(uint8 mode) ;
uint8   Beep_ReadDataReg(void) ;
uint8   Beep_Read(void) ;
uint8   Beep_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Beep_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Beep_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Beep_DM_RES_UP          PIN_DM_RES_UP
#define Beep_DM_RES_DWN         PIN_DM_RES_DWN
#define Beep_DM_OD_LO           PIN_DM_OD_LO
#define Beep_DM_OD_HI           PIN_DM_OD_HI
#define Beep_DM_STRONG          PIN_DM_STRONG
#define Beep_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Beep_MASK               Beep__MASK
#define Beep_SHIFT              Beep__SHIFT
#define Beep_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Beep_PS                     (* (reg8 *) Beep__PS)
/* Data Register */
#define Beep_DR                     (* (reg8 *) Beep__DR)
/* Port Number */
#define Beep_PRT_NUM                (* (reg8 *) Beep__PRT) 
/* Connect to Analog Globals */                                                  
#define Beep_AG                     (* (reg8 *) Beep__AG)                       
/* Analog MUX bux enable */
#define Beep_AMUX                   (* (reg8 *) Beep__AMUX) 
/* Bidirectional Enable */                                                        
#define Beep_BIE                    (* (reg8 *) Beep__BIE)
/* Bit-mask for Aliased Register Access */
#define Beep_BIT_MASK               (* (reg8 *) Beep__BIT_MASK)
/* Bypass Enable */
#define Beep_BYP                    (* (reg8 *) Beep__BYP)
/* Port wide control signals */                                                   
#define Beep_CTL                    (* (reg8 *) Beep__CTL)
/* Drive Modes */
#define Beep_DM0                    (* (reg8 *) Beep__DM0) 
#define Beep_DM1                    (* (reg8 *) Beep__DM1)
#define Beep_DM2                    (* (reg8 *) Beep__DM2) 
/* Input Buffer Disable Override */
#define Beep_INP_DIS                (* (reg8 *) Beep__INP_DIS)
/* LCD Common or Segment Drive */
#define Beep_LCD_COM_SEG            (* (reg8 *) Beep__LCD_COM_SEG)
/* Enable Segment LCD */
#define Beep_LCD_EN                 (* (reg8 *) Beep__LCD_EN)
/* Slew Rate Control */
#define Beep_SLW                    (* (reg8 *) Beep__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Beep_PRTDSI__CAPS_SEL       (* (reg8 *) Beep__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Beep_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Beep__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Beep_PRTDSI__OE_SEL0        (* (reg8 *) Beep__PRTDSI__OE_SEL0) 
#define Beep_PRTDSI__OE_SEL1        (* (reg8 *) Beep__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Beep_PRTDSI__OUT_SEL0       (* (reg8 *) Beep__PRTDSI__OUT_SEL0) 
#define Beep_PRTDSI__OUT_SEL1       (* (reg8 *) Beep__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Beep_PRTDSI__SYNC_OUT       (* (reg8 *) Beep__PRTDSI__SYNC_OUT) 


#if defined(Beep__INTSTAT)  /* Interrupt Registers */

    #define Beep_INTSTAT                (* (reg8 *) Beep__INTSTAT)
    #define Beep_SNAP                   (* (reg8 *) Beep__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Beep_H */


/* [] END OF FILE */
