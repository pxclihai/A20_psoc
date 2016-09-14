/*******************************************************************************
* File Name: Y_FWD.h  
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

#if !defined(CY_PINS_Y_FWD_H) /* Pins Y_FWD_H */
#define CY_PINS_Y_FWD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Y_FWD_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Y_FWD__PORT == 15 && ((Y_FWD__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Y_FWD_Write(uint8 value) ;
void    Y_FWD_SetDriveMode(uint8 mode) ;
uint8   Y_FWD_ReadDataReg(void) ;
uint8   Y_FWD_Read(void) ;
uint8   Y_FWD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Y_FWD_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Y_FWD_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Y_FWD_DM_RES_UP          PIN_DM_RES_UP
#define Y_FWD_DM_RES_DWN         PIN_DM_RES_DWN
#define Y_FWD_DM_OD_LO           PIN_DM_OD_LO
#define Y_FWD_DM_OD_HI           PIN_DM_OD_HI
#define Y_FWD_DM_STRONG          PIN_DM_STRONG
#define Y_FWD_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Y_FWD_MASK               Y_FWD__MASK
#define Y_FWD_SHIFT              Y_FWD__SHIFT
#define Y_FWD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Y_FWD_PS                     (* (reg8 *) Y_FWD__PS)
/* Data Register */
#define Y_FWD_DR                     (* (reg8 *) Y_FWD__DR)
/* Port Number */
#define Y_FWD_PRT_NUM                (* (reg8 *) Y_FWD__PRT) 
/* Connect to Analog Globals */                                                  
#define Y_FWD_AG                     (* (reg8 *) Y_FWD__AG)                       
/* Analog MUX bux enable */
#define Y_FWD_AMUX                   (* (reg8 *) Y_FWD__AMUX) 
/* Bidirectional Enable */                                                        
#define Y_FWD_BIE                    (* (reg8 *) Y_FWD__BIE)
/* Bit-mask for Aliased Register Access */
#define Y_FWD_BIT_MASK               (* (reg8 *) Y_FWD__BIT_MASK)
/* Bypass Enable */
#define Y_FWD_BYP                    (* (reg8 *) Y_FWD__BYP)
/* Port wide control signals */                                                   
#define Y_FWD_CTL                    (* (reg8 *) Y_FWD__CTL)
/* Drive Modes */
#define Y_FWD_DM0                    (* (reg8 *) Y_FWD__DM0) 
#define Y_FWD_DM1                    (* (reg8 *) Y_FWD__DM1)
#define Y_FWD_DM2                    (* (reg8 *) Y_FWD__DM2) 
/* Input Buffer Disable Override */
#define Y_FWD_INP_DIS                (* (reg8 *) Y_FWD__INP_DIS)
/* LCD Common or Segment Drive */
#define Y_FWD_LCD_COM_SEG            (* (reg8 *) Y_FWD__LCD_COM_SEG)
/* Enable Segment LCD */
#define Y_FWD_LCD_EN                 (* (reg8 *) Y_FWD__LCD_EN)
/* Slew Rate Control */
#define Y_FWD_SLW                    (* (reg8 *) Y_FWD__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Y_FWD_PRTDSI__CAPS_SEL       (* (reg8 *) Y_FWD__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Y_FWD_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Y_FWD__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Y_FWD_PRTDSI__OE_SEL0        (* (reg8 *) Y_FWD__PRTDSI__OE_SEL0) 
#define Y_FWD_PRTDSI__OE_SEL1        (* (reg8 *) Y_FWD__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Y_FWD_PRTDSI__OUT_SEL0       (* (reg8 *) Y_FWD__PRTDSI__OUT_SEL0) 
#define Y_FWD_PRTDSI__OUT_SEL1       (* (reg8 *) Y_FWD__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Y_FWD_PRTDSI__SYNC_OUT       (* (reg8 *) Y_FWD__PRTDSI__SYNC_OUT) 


#if defined(Y_FWD__INTSTAT)  /* Interrupt Registers */

    #define Y_FWD_INTSTAT                (* (reg8 *) Y_FWD__INTSTAT)
    #define Y_FWD_SNAP                   (* (reg8 *) Y_FWD__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Y_FWD_H */


/* [] END OF FILE */
