/*******************************************************************************
* File Name: EA.h  
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

#if !defined(CY_PINS_EA_H) /* Pins EA_H */
#define CY_PINS_EA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EA__PORT == 15 && ((EA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EA_Write(uint8 value) ;
void    EA_SetDriveMode(uint8 mode) ;
uint8   EA_ReadDataReg(void) ;
uint8   EA_Read(void) ;
uint8   EA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EA_DM_RES_UP          PIN_DM_RES_UP
#define EA_DM_RES_DWN         PIN_DM_RES_DWN
#define EA_DM_OD_LO           PIN_DM_OD_LO
#define EA_DM_OD_HI           PIN_DM_OD_HI
#define EA_DM_STRONG          PIN_DM_STRONG
#define EA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EA_MASK               EA__MASK
#define EA_SHIFT              EA__SHIFT
#define EA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EA_PS                     (* (reg8 *) EA__PS)
/* Data Register */
#define EA_DR                     (* (reg8 *) EA__DR)
/* Port Number */
#define EA_PRT_NUM                (* (reg8 *) EA__PRT) 
/* Connect to Analog Globals */                                                  
#define EA_AG                     (* (reg8 *) EA__AG)                       
/* Analog MUX bux enable */
#define EA_AMUX                   (* (reg8 *) EA__AMUX) 
/* Bidirectional Enable */                                                        
#define EA_BIE                    (* (reg8 *) EA__BIE)
/* Bit-mask for Aliased Register Access */
#define EA_BIT_MASK               (* (reg8 *) EA__BIT_MASK)
/* Bypass Enable */
#define EA_BYP                    (* (reg8 *) EA__BYP)
/* Port wide control signals */                                                   
#define EA_CTL                    (* (reg8 *) EA__CTL)
/* Drive Modes */
#define EA_DM0                    (* (reg8 *) EA__DM0) 
#define EA_DM1                    (* (reg8 *) EA__DM1)
#define EA_DM2                    (* (reg8 *) EA__DM2) 
/* Input Buffer Disable Override */
#define EA_INP_DIS                (* (reg8 *) EA__INP_DIS)
/* LCD Common or Segment Drive */
#define EA_LCD_COM_SEG            (* (reg8 *) EA__LCD_COM_SEG)
/* Enable Segment LCD */
#define EA_LCD_EN                 (* (reg8 *) EA__LCD_EN)
/* Slew Rate Control */
#define EA_SLW                    (* (reg8 *) EA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EA_PRTDSI__CAPS_SEL       (* (reg8 *) EA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EA_PRTDSI__OE_SEL0        (* (reg8 *) EA__PRTDSI__OE_SEL0) 
#define EA_PRTDSI__OE_SEL1        (* (reg8 *) EA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EA_PRTDSI__OUT_SEL0       (* (reg8 *) EA__PRTDSI__OUT_SEL0) 
#define EA_PRTDSI__OUT_SEL1       (* (reg8 *) EA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EA_PRTDSI__SYNC_OUT       (* (reg8 *) EA__PRTDSI__SYNC_OUT) 


#if defined(EA__INTSTAT)  /* Interrupt Registers */

    #define EA_INTSTAT                (* (reg8 *) EA__INTSTAT)
    #define EA_SNAP                   (* (reg8 *) EA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EA_H */


/* [] END OF FILE */
