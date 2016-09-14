/*******************************************************************************
* File Name: CS2_62_M.h  
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

#if !defined(CY_PINS_CS2_62_M_H) /* Pins CS2_62_M_H */
#define CY_PINS_CS2_62_M_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CS2_62_M_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CS2_62_M__PORT == 15 && ((CS2_62_M__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CS2_62_M_Write(uint8 value) ;
void    CS2_62_M_SetDriveMode(uint8 mode) ;
uint8   CS2_62_M_ReadDataReg(void) ;
uint8   CS2_62_M_Read(void) ;
uint8   CS2_62_M_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CS2_62_M_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CS2_62_M_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CS2_62_M_DM_RES_UP          PIN_DM_RES_UP
#define CS2_62_M_DM_RES_DWN         PIN_DM_RES_DWN
#define CS2_62_M_DM_OD_LO           PIN_DM_OD_LO
#define CS2_62_M_DM_OD_HI           PIN_DM_OD_HI
#define CS2_62_M_DM_STRONG          PIN_DM_STRONG
#define CS2_62_M_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CS2_62_M_MASK               CS2_62_M__MASK
#define CS2_62_M_SHIFT              CS2_62_M__SHIFT
#define CS2_62_M_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CS2_62_M_PS                     (* (reg8 *) CS2_62_M__PS)
/* Data Register */
#define CS2_62_M_DR                     (* (reg8 *) CS2_62_M__DR)
/* Port Number */
#define CS2_62_M_PRT_NUM                (* (reg8 *) CS2_62_M__PRT) 
/* Connect to Analog Globals */                                                  
#define CS2_62_M_AG                     (* (reg8 *) CS2_62_M__AG)                       
/* Analog MUX bux enable */
#define CS2_62_M_AMUX                   (* (reg8 *) CS2_62_M__AMUX) 
/* Bidirectional Enable */                                                        
#define CS2_62_M_BIE                    (* (reg8 *) CS2_62_M__BIE)
/* Bit-mask for Aliased Register Access */
#define CS2_62_M_BIT_MASK               (* (reg8 *) CS2_62_M__BIT_MASK)
/* Bypass Enable */
#define CS2_62_M_BYP                    (* (reg8 *) CS2_62_M__BYP)
/* Port wide control signals */                                                   
#define CS2_62_M_CTL                    (* (reg8 *) CS2_62_M__CTL)
/* Drive Modes */
#define CS2_62_M_DM0                    (* (reg8 *) CS2_62_M__DM0) 
#define CS2_62_M_DM1                    (* (reg8 *) CS2_62_M__DM1)
#define CS2_62_M_DM2                    (* (reg8 *) CS2_62_M__DM2) 
/* Input Buffer Disable Override */
#define CS2_62_M_INP_DIS                (* (reg8 *) CS2_62_M__INP_DIS)
/* LCD Common or Segment Drive */
#define CS2_62_M_LCD_COM_SEG            (* (reg8 *) CS2_62_M__LCD_COM_SEG)
/* Enable Segment LCD */
#define CS2_62_M_LCD_EN                 (* (reg8 *) CS2_62_M__LCD_EN)
/* Slew Rate Control */
#define CS2_62_M_SLW                    (* (reg8 *) CS2_62_M__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CS2_62_M_PRTDSI__CAPS_SEL       (* (reg8 *) CS2_62_M__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CS2_62_M_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CS2_62_M__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CS2_62_M_PRTDSI__OE_SEL0        (* (reg8 *) CS2_62_M__PRTDSI__OE_SEL0) 
#define CS2_62_M_PRTDSI__OE_SEL1        (* (reg8 *) CS2_62_M__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CS2_62_M_PRTDSI__OUT_SEL0       (* (reg8 *) CS2_62_M__PRTDSI__OUT_SEL0) 
#define CS2_62_M_PRTDSI__OUT_SEL1       (* (reg8 *) CS2_62_M__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CS2_62_M_PRTDSI__SYNC_OUT       (* (reg8 *) CS2_62_M__PRTDSI__SYNC_OUT) 


#if defined(CS2_62_M__INTSTAT)  /* Interrupt Registers */

    #define CS2_62_M_INTSTAT                (* (reg8 *) CS2_62_M__INTSTAT)
    #define CS2_62_M_SNAP                   (* (reg8 *) CS2_62_M__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CS2_62_M_H */


/* [] END OF FILE */
