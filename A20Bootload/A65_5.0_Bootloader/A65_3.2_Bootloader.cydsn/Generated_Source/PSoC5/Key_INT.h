/*******************************************************************************
* File Name: Key_INT.h  
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

#if !defined(CY_PINS_Key_INT_H) /* Pins Key_INT_H */
#define CY_PINS_Key_INT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Key_INT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Key_INT__PORT == 15 && ((Key_INT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Key_INT_Write(uint8 value) ;
void    Key_INT_SetDriveMode(uint8 mode) ;
uint8   Key_INT_ReadDataReg(void) ;
uint8   Key_INT_Read(void) ;
uint8   Key_INT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Key_INT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Key_INT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Key_INT_DM_RES_UP          PIN_DM_RES_UP
#define Key_INT_DM_RES_DWN         PIN_DM_RES_DWN
#define Key_INT_DM_OD_LO           PIN_DM_OD_LO
#define Key_INT_DM_OD_HI           PIN_DM_OD_HI
#define Key_INT_DM_STRONG          PIN_DM_STRONG
#define Key_INT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Key_INT_MASK               Key_INT__MASK
#define Key_INT_SHIFT              Key_INT__SHIFT
#define Key_INT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Key_INT_PS                     (* (reg8 *) Key_INT__PS)
/* Data Register */
#define Key_INT_DR                     (* (reg8 *) Key_INT__DR)
/* Port Number */
#define Key_INT_PRT_NUM                (* (reg8 *) Key_INT__PRT) 
/* Connect to Analog Globals */                                                  
#define Key_INT_AG                     (* (reg8 *) Key_INT__AG)                       
/* Analog MUX bux enable */
#define Key_INT_AMUX                   (* (reg8 *) Key_INT__AMUX) 
/* Bidirectional Enable */                                                        
#define Key_INT_BIE                    (* (reg8 *) Key_INT__BIE)
/* Bit-mask for Aliased Register Access */
#define Key_INT_BIT_MASK               (* (reg8 *) Key_INT__BIT_MASK)
/* Bypass Enable */
#define Key_INT_BYP                    (* (reg8 *) Key_INT__BYP)
/* Port wide control signals */                                                   
#define Key_INT_CTL                    (* (reg8 *) Key_INT__CTL)
/* Drive Modes */
#define Key_INT_DM0                    (* (reg8 *) Key_INT__DM0) 
#define Key_INT_DM1                    (* (reg8 *) Key_INT__DM1)
#define Key_INT_DM2                    (* (reg8 *) Key_INT__DM2) 
/* Input Buffer Disable Override */
#define Key_INT_INP_DIS                (* (reg8 *) Key_INT__INP_DIS)
/* LCD Common or Segment Drive */
#define Key_INT_LCD_COM_SEG            (* (reg8 *) Key_INT__LCD_COM_SEG)
/* Enable Segment LCD */
#define Key_INT_LCD_EN                 (* (reg8 *) Key_INT__LCD_EN)
/* Slew Rate Control */
#define Key_INT_SLW                    (* (reg8 *) Key_INT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Key_INT_PRTDSI__CAPS_SEL       (* (reg8 *) Key_INT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Key_INT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Key_INT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Key_INT_PRTDSI__OE_SEL0        (* (reg8 *) Key_INT__PRTDSI__OE_SEL0) 
#define Key_INT_PRTDSI__OE_SEL1        (* (reg8 *) Key_INT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Key_INT_PRTDSI__OUT_SEL0       (* (reg8 *) Key_INT__PRTDSI__OUT_SEL0) 
#define Key_INT_PRTDSI__OUT_SEL1       (* (reg8 *) Key_INT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Key_INT_PRTDSI__SYNC_OUT       (* (reg8 *) Key_INT__PRTDSI__SYNC_OUT) 


#if defined(Key_INT__INTSTAT)  /* Interrupt Registers */

    #define Key_INT_INTSTAT                (* (reg8 *) Key_INT__INTSTAT)
    #define Key_INT_SNAP                   (* (reg8 *) Key_INT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Key_INT_H */


/* [] END OF FILE */
