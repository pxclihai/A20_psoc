/*******************************************************************************
* File Name: CS3_63_R.h  
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

#if !defined(CY_PINS_CS3_63_R_H) /* Pins CS3_63_R_H */
#define CY_PINS_CS3_63_R_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CS3_63_R_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CS3_63_R__PORT == 15 && ((CS3_63_R__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CS3_63_R_Write(uint8 value) ;
void    CS3_63_R_SetDriveMode(uint8 mode) ;
uint8   CS3_63_R_ReadDataReg(void) ;
uint8   CS3_63_R_Read(void) ;
uint8   CS3_63_R_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CS3_63_R_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CS3_63_R_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CS3_63_R_DM_RES_UP          PIN_DM_RES_UP
#define CS3_63_R_DM_RES_DWN         PIN_DM_RES_DWN
#define CS3_63_R_DM_OD_LO           PIN_DM_OD_LO
#define CS3_63_R_DM_OD_HI           PIN_DM_OD_HI
#define CS3_63_R_DM_STRONG          PIN_DM_STRONG
#define CS3_63_R_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CS3_63_R_MASK               CS3_63_R__MASK
#define CS3_63_R_SHIFT              CS3_63_R__SHIFT
#define CS3_63_R_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CS3_63_R_PS                     (* (reg8 *) CS3_63_R__PS)
/* Data Register */
#define CS3_63_R_DR                     (* (reg8 *) CS3_63_R__DR)
/* Port Number */
#define CS3_63_R_PRT_NUM                (* (reg8 *) CS3_63_R__PRT) 
/* Connect to Analog Globals */                                                  
#define CS3_63_R_AG                     (* (reg8 *) CS3_63_R__AG)                       
/* Analog MUX bux enable */
#define CS3_63_R_AMUX                   (* (reg8 *) CS3_63_R__AMUX) 
/* Bidirectional Enable */                                                        
#define CS3_63_R_BIE                    (* (reg8 *) CS3_63_R__BIE)
/* Bit-mask for Aliased Register Access */
#define CS3_63_R_BIT_MASK               (* (reg8 *) CS3_63_R__BIT_MASK)
/* Bypass Enable */
#define CS3_63_R_BYP                    (* (reg8 *) CS3_63_R__BYP)
/* Port wide control signals */                                                   
#define CS3_63_R_CTL                    (* (reg8 *) CS3_63_R__CTL)
/* Drive Modes */
#define CS3_63_R_DM0                    (* (reg8 *) CS3_63_R__DM0) 
#define CS3_63_R_DM1                    (* (reg8 *) CS3_63_R__DM1)
#define CS3_63_R_DM2                    (* (reg8 *) CS3_63_R__DM2) 
/* Input Buffer Disable Override */
#define CS3_63_R_INP_DIS                (* (reg8 *) CS3_63_R__INP_DIS)
/* LCD Common or Segment Drive */
#define CS3_63_R_LCD_COM_SEG            (* (reg8 *) CS3_63_R__LCD_COM_SEG)
/* Enable Segment LCD */
#define CS3_63_R_LCD_EN                 (* (reg8 *) CS3_63_R__LCD_EN)
/* Slew Rate Control */
#define CS3_63_R_SLW                    (* (reg8 *) CS3_63_R__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CS3_63_R_PRTDSI__CAPS_SEL       (* (reg8 *) CS3_63_R__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CS3_63_R_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CS3_63_R__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CS3_63_R_PRTDSI__OE_SEL0        (* (reg8 *) CS3_63_R__PRTDSI__OE_SEL0) 
#define CS3_63_R_PRTDSI__OE_SEL1        (* (reg8 *) CS3_63_R__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CS3_63_R_PRTDSI__OUT_SEL0       (* (reg8 *) CS3_63_R__PRTDSI__OUT_SEL0) 
#define CS3_63_R_PRTDSI__OUT_SEL1       (* (reg8 *) CS3_63_R__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CS3_63_R_PRTDSI__SYNC_OUT       (* (reg8 *) CS3_63_R__PRTDSI__SYNC_OUT) 


#if defined(CS3_63_R__INTSTAT)  /* Interrupt Registers */

    #define CS3_63_R_INTSTAT                (* (reg8 *) CS3_63_R__INTSTAT)
    #define CS3_63_R_SNAP                   (* (reg8 *) CS3_63_R__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CS3_63_R_H */


/* [] END OF FILE */
