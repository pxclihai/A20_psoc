/*******************************************************************************
* File Name: Y_REV.h  
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

#if !defined(CY_PINS_Y_REV_H) /* Pins Y_REV_H */
#define CY_PINS_Y_REV_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Y_REV_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Y_REV__PORT == 15 && ((Y_REV__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Y_REV_Write(uint8 value) ;
void    Y_REV_SetDriveMode(uint8 mode) ;
uint8   Y_REV_ReadDataReg(void) ;
uint8   Y_REV_Read(void) ;
uint8   Y_REV_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Y_REV_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Y_REV_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Y_REV_DM_RES_UP          PIN_DM_RES_UP
#define Y_REV_DM_RES_DWN         PIN_DM_RES_DWN
#define Y_REV_DM_OD_LO           PIN_DM_OD_LO
#define Y_REV_DM_OD_HI           PIN_DM_OD_HI
#define Y_REV_DM_STRONG          PIN_DM_STRONG
#define Y_REV_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Y_REV_MASK               Y_REV__MASK
#define Y_REV_SHIFT              Y_REV__SHIFT
#define Y_REV_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Y_REV_PS                     (* (reg8 *) Y_REV__PS)
/* Data Register */
#define Y_REV_DR                     (* (reg8 *) Y_REV__DR)
/* Port Number */
#define Y_REV_PRT_NUM                (* (reg8 *) Y_REV__PRT) 
/* Connect to Analog Globals */                                                  
#define Y_REV_AG                     (* (reg8 *) Y_REV__AG)                       
/* Analog MUX bux enable */
#define Y_REV_AMUX                   (* (reg8 *) Y_REV__AMUX) 
/* Bidirectional Enable */                                                        
#define Y_REV_BIE                    (* (reg8 *) Y_REV__BIE)
/* Bit-mask for Aliased Register Access */
#define Y_REV_BIT_MASK               (* (reg8 *) Y_REV__BIT_MASK)
/* Bypass Enable */
#define Y_REV_BYP                    (* (reg8 *) Y_REV__BYP)
/* Port wide control signals */                                                   
#define Y_REV_CTL                    (* (reg8 *) Y_REV__CTL)
/* Drive Modes */
#define Y_REV_DM0                    (* (reg8 *) Y_REV__DM0) 
#define Y_REV_DM1                    (* (reg8 *) Y_REV__DM1)
#define Y_REV_DM2                    (* (reg8 *) Y_REV__DM2) 
/* Input Buffer Disable Override */
#define Y_REV_INP_DIS                (* (reg8 *) Y_REV__INP_DIS)
/* LCD Common or Segment Drive */
#define Y_REV_LCD_COM_SEG            (* (reg8 *) Y_REV__LCD_COM_SEG)
/* Enable Segment LCD */
#define Y_REV_LCD_EN                 (* (reg8 *) Y_REV__LCD_EN)
/* Slew Rate Control */
#define Y_REV_SLW                    (* (reg8 *) Y_REV__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Y_REV_PRTDSI__CAPS_SEL       (* (reg8 *) Y_REV__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Y_REV_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Y_REV__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Y_REV_PRTDSI__OE_SEL0        (* (reg8 *) Y_REV__PRTDSI__OE_SEL0) 
#define Y_REV_PRTDSI__OE_SEL1        (* (reg8 *) Y_REV__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Y_REV_PRTDSI__OUT_SEL0       (* (reg8 *) Y_REV__PRTDSI__OUT_SEL0) 
#define Y_REV_PRTDSI__OUT_SEL1       (* (reg8 *) Y_REV__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Y_REV_PRTDSI__SYNC_OUT       (* (reg8 *) Y_REV__PRTDSI__SYNC_OUT) 


#if defined(Y_REV__INTSTAT)  /* Interrupt Registers */

    #define Y_REV_INTSTAT                (* (reg8 *) Y_REV__INTSTAT)
    #define Y_REV_SNAP                   (* (reg8 *) Y_REV__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Y_REV_H */


/* [] END OF FILE */
