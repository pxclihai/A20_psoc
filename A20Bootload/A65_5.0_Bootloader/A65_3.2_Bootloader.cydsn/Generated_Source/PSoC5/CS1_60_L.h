/*******************************************************************************
* File Name: CS1_60_L.h  
* Version 1.80
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

#if !defined(CY_PINS_CS1_60_L_H) /* Pins CS1_60_L_H */
#define CY_PINS_CS1_60_L_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CS1_60_L_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CS1_60_L__PORT == 15 && ((CS1_60_L__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CS1_60_L_Write(uint8 value) ;
void    CS1_60_L_SetDriveMode(uint8 mode) ;
uint8   CS1_60_L_ReadDataReg(void) ;
uint8   CS1_60_L_Read(void) ;
uint8   CS1_60_L_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CS1_60_L_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CS1_60_L_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CS1_60_L_DM_RES_UP          PIN_DM_RES_UP
#define CS1_60_L_DM_RES_DWN         PIN_DM_RES_DWN
#define CS1_60_L_DM_OD_LO           PIN_DM_OD_LO
#define CS1_60_L_DM_OD_HI           PIN_DM_OD_HI
#define CS1_60_L_DM_STRONG          PIN_DM_STRONG
#define CS1_60_L_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CS1_60_L_MASK               CS1_60_L__MASK
#define CS1_60_L_SHIFT              CS1_60_L__SHIFT
#define CS1_60_L_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CS1_60_L_PS                     (* (reg8 *) CS1_60_L__PS)
/* Data Register */
#define CS1_60_L_DR                     (* (reg8 *) CS1_60_L__DR)
/* Port Number */
#define CS1_60_L_PRT_NUM                (* (reg8 *) CS1_60_L__PRT) 
/* Connect to Analog Globals */                                                  
#define CS1_60_L_AG                     (* (reg8 *) CS1_60_L__AG)                       
/* Analog MUX bux enable */
#define CS1_60_L_AMUX                   (* (reg8 *) CS1_60_L__AMUX) 
/* Bidirectional Enable */                                                        
#define CS1_60_L_BIE                    (* (reg8 *) CS1_60_L__BIE)
/* Bit-mask for Aliased Register Access */
#define CS1_60_L_BIT_MASK               (* (reg8 *) CS1_60_L__BIT_MASK)
/* Bypass Enable */
#define CS1_60_L_BYP                    (* (reg8 *) CS1_60_L__BYP)
/* Port wide control signals */                                                   
#define CS1_60_L_CTL                    (* (reg8 *) CS1_60_L__CTL)
/* Drive Modes */
#define CS1_60_L_DM0                    (* (reg8 *) CS1_60_L__DM0) 
#define CS1_60_L_DM1                    (* (reg8 *) CS1_60_L__DM1)
#define CS1_60_L_DM2                    (* (reg8 *) CS1_60_L__DM2) 
/* Input Buffer Disable Override */
#define CS1_60_L_INP_DIS                (* (reg8 *) CS1_60_L__INP_DIS)
/* LCD Common or Segment Drive */
#define CS1_60_L_LCD_COM_SEG            (* (reg8 *) CS1_60_L__LCD_COM_SEG)
/* Enable Segment LCD */
#define CS1_60_L_LCD_EN                 (* (reg8 *) CS1_60_L__LCD_EN)
/* Slew Rate Control */
#define CS1_60_L_SLW                    (* (reg8 *) CS1_60_L__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CS1_60_L_PRTDSI__CAPS_SEL       (* (reg8 *) CS1_60_L__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CS1_60_L_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CS1_60_L__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CS1_60_L_PRTDSI__OE_SEL0        (* (reg8 *) CS1_60_L__PRTDSI__OE_SEL0) 
#define CS1_60_L_PRTDSI__OE_SEL1        (* (reg8 *) CS1_60_L__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CS1_60_L_PRTDSI__OUT_SEL0       (* (reg8 *) CS1_60_L__PRTDSI__OUT_SEL0) 
#define CS1_60_L_PRTDSI__OUT_SEL1       (* (reg8 *) CS1_60_L__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CS1_60_L_PRTDSI__SYNC_OUT       (* (reg8 *) CS1_60_L__PRTDSI__SYNC_OUT) 


#if defined(CS1_60_L__INTSTAT)  /* Interrupt Registers */

    #define CS1_60_L_INTSTAT                (* (reg8 *) CS1_60_L__INTSTAT)
    #define CS1_60_L_SNAP                   (* (reg8 *) CS1_60_L__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CS1_60_L_H */


/* [] END OF FILE */
