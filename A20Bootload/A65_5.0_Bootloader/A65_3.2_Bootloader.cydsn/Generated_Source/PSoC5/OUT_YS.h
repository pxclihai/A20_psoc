/*******************************************************************************
* File Name: OUT_YS.h  
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

#if !defined(CY_PINS_OUT_YS_H) /* Pins OUT_YS_H */
#define CY_PINS_OUT_YS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OUT_YS_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OUT_YS__PORT == 15 && ((OUT_YS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    OUT_YS_Write(uint8 value) ;
void    OUT_YS_SetDriveMode(uint8 mode) ;
uint8   OUT_YS_ReadDataReg(void) ;
uint8   OUT_YS_Read(void) ;
uint8   OUT_YS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OUT_YS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define OUT_YS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define OUT_YS_DM_RES_UP          PIN_DM_RES_UP
#define OUT_YS_DM_RES_DWN         PIN_DM_RES_DWN
#define OUT_YS_DM_OD_LO           PIN_DM_OD_LO
#define OUT_YS_DM_OD_HI           PIN_DM_OD_HI
#define OUT_YS_DM_STRONG          PIN_DM_STRONG
#define OUT_YS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define OUT_YS_MASK               OUT_YS__MASK
#define OUT_YS_SHIFT              OUT_YS__SHIFT
#define OUT_YS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OUT_YS_PS                     (* (reg8 *) OUT_YS__PS)
/* Data Register */
#define OUT_YS_DR                     (* (reg8 *) OUT_YS__DR)
/* Port Number */
#define OUT_YS_PRT_NUM                (* (reg8 *) OUT_YS__PRT) 
/* Connect to Analog Globals */                                                  
#define OUT_YS_AG                     (* (reg8 *) OUT_YS__AG)                       
/* Analog MUX bux enable */
#define OUT_YS_AMUX                   (* (reg8 *) OUT_YS__AMUX) 
/* Bidirectional Enable */                                                        
#define OUT_YS_BIE                    (* (reg8 *) OUT_YS__BIE)
/* Bit-mask for Aliased Register Access */
#define OUT_YS_BIT_MASK               (* (reg8 *) OUT_YS__BIT_MASK)
/* Bypass Enable */
#define OUT_YS_BYP                    (* (reg8 *) OUT_YS__BYP)
/* Port wide control signals */                                                   
#define OUT_YS_CTL                    (* (reg8 *) OUT_YS__CTL)
/* Drive Modes */
#define OUT_YS_DM0                    (* (reg8 *) OUT_YS__DM0) 
#define OUT_YS_DM1                    (* (reg8 *) OUT_YS__DM1)
#define OUT_YS_DM2                    (* (reg8 *) OUT_YS__DM2) 
/* Input Buffer Disable Override */
#define OUT_YS_INP_DIS                (* (reg8 *) OUT_YS__INP_DIS)
/* LCD Common or Segment Drive */
#define OUT_YS_LCD_COM_SEG            (* (reg8 *) OUT_YS__LCD_COM_SEG)
/* Enable Segment LCD */
#define OUT_YS_LCD_EN                 (* (reg8 *) OUT_YS__LCD_EN)
/* Slew Rate Control */
#define OUT_YS_SLW                    (* (reg8 *) OUT_YS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OUT_YS_PRTDSI__CAPS_SEL       (* (reg8 *) OUT_YS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OUT_YS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OUT_YS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OUT_YS_PRTDSI__OE_SEL0        (* (reg8 *) OUT_YS__PRTDSI__OE_SEL0) 
#define OUT_YS_PRTDSI__OE_SEL1        (* (reg8 *) OUT_YS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OUT_YS_PRTDSI__OUT_SEL0       (* (reg8 *) OUT_YS__PRTDSI__OUT_SEL0) 
#define OUT_YS_PRTDSI__OUT_SEL1       (* (reg8 *) OUT_YS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OUT_YS_PRTDSI__SYNC_OUT       (* (reg8 *) OUT_YS__PRTDSI__SYNC_OUT) 


#if defined(OUT_YS__INTSTAT)  /* Interrupt Registers */

    #define OUT_YS_INTSTAT                (* (reg8 *) OUT_YS__INTSTAT)
    #define OUT_YS_SNAP                   (* (reg8 *) OUT_YS__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OUT_YS_H */


/* [] END OF FILE */
