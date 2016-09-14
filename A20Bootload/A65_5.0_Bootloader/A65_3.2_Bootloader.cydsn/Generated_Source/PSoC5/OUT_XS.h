/*******************************************************************************
* File Name: OUT_XS.h  
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

#if !defined(CY_PINS_OUT_XS_H) /* Pins OUT_XS_H */
#define CY_PINS_OUT_XS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OUT_XS_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OUT_XS__PORT == 15 && ((OUT_XS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    OUT_XS_Write(uint8 value) ;
void    OUT_XS_SetDriveMode(uint8 mode) ;
uint8   OUT_XS_ReadDataReg(void) ;
uint8   OUT_XS_Read(void) ;
uint8   OUT_XS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OUT_XS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define OUT_XS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define OUT_XS_DM_RES_UP          PIN_DM_RES_UP
#define OUT_XS_DM_RES_DWN         PIN_DM_RES_DWN
#define OUT_XS_DM_OD_LO           PIN_DM_OD_LO
#define OUT_XS_DM_OD_HI           PIN_DM_OD_HI
#define OUT_XS_DM_STRONG          PIN_DM_STRONG
#define OUT_XS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define OUT_XS_MASK               OUT_XS__MASK
#define OUT_XS_SHIFT              OUT_XS__SHIFT
#define OUT_XS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OUT_XS_PS                     (* (reg8 *) OUT_XS__PS)
/* Data Register */
#define OUT_XS_DR                     (* (reg8 *) OUT_XS__DR)
/* Port Number */
#define OUT_XS_PRT_NUM                (* (reg8 *) OUT_XS__PRT) 
/* Connect to Analog Globals */                                                  
#define OUT_XS_AG                     (* (reg8 *) OUT_XS__AG)                       
/* Analog MUX bux enable */
#define OUT_XS_AMUX                   (* (reg8 *) OUT_XS__AMUX) 
/* Bidirectional Enable */                                                        
#define OUT_XS_BIE                    (* (reg8 *) OUT_XS__BIE)
/* Bit-mask for Aliased Register Access */
#define OUT_XS_BIT_MASK               (* (reg8 *) OUT_XS__BIT_MASK)
/* Bypass Enable */
#define OUT_XS_BYP                    (* (reg8 *) OUT_XS__BYP)
/* Port wide control signals */                                                   
#define OUT_XS_CTL                    (* (reg8 *) OUT_XS__CTL)
/* Drive Modes */
#define OUT_XS_DM0                    (* (reg8 *) OUT_XS__DM0) 
#define OUT_XS_DM1                    (* (reg8 *) OUT_XS__DM1)
#define OUT_XS_DM2                    (* (reg8 *) OUT_XS__DM2) 
/* Input Buffer Disable Override */
#define OUT_XS_INP_DIS                (* (reg8 *) OUT_XS__INP_DIS)
/* LCD Common or Segment Drive */
#define OUT_XS_LCD_COM_SEG            (* (reg8 *) OUT_XS__LCD_COM_SEG)
/* Enable Segment LCD */
#define OUT_XS_LCD_EN                 (* (reg8 *) OUT_XS__LCD_EN)
/* Slew Rate Control */
#define OUT_XS_SLW                    (* (reg8 *) OUT_XS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OUT_XS_PRTDSI__CAPS_SEL       (* (reg8 *) OUT_XS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OUT_XS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OUT_XS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OUT_XS_PRTDSI__OE_SEL0        (* (reg8 *) OUT_XS__PRTDSI__OE_SEL0) 
#define OUT_XS_PRTDSI__OE_SEL1        (* (reg8 *) OUT_XS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OUT_XS_PRTDSI__OUT_SEL0       (* (reg8 *) OUT_XS__PRTDSI__OUT_SEL0) 
#define OUT_XS_PRTDSI__OUT_SEL1       (* (reg8 *) OUT_XS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OUT_XS_PRTDSI__SYNC_OUT       (* (reg8 *) OUT_XS__PRTDSI__SYNC_OUT) 


#if defined(OUT_XS__INTSTAT)  /* Interrupt Registers */

    #define OUT_XS_INTSTAT                (* (reg8 *) OUT_XS__INTSTAT)
    #define OUT_XS_SNAP                   (* (reg8 *) OUT_XS__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OUT_XS_H */


/* [] END OF FILE */
