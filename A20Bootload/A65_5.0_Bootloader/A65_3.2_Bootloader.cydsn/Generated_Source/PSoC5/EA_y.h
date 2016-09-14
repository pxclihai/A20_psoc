/*******************************************************************************
* File Name: EA_y.h  
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

#if !defined(CY_PINS_EA_y_H) /* Pins EA_y_H */
#define CY_PINS_EA_y_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EA_y_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EA_y__PORT == 15 && ((EA_y__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    EA_y_Write(uint8 value) ;
void    EA_y_SetDriveMode(uint8 mode) ;
uint8   EA_y_ReadDataReg(void) ;
uint8   EA_y_Read(void) ;
uint8   EA_y_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EA_y_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EA_y_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EA_y_DM_RES_UP          PIN_DM_RES_UP
#define EA_y_DM_RES_DWN         PIN_DM_RES_DWN
#define EA_y_DM_OD_LO           PIN_DM_OD_LO
#define EA_y_DM_OD_HI           PIN_DM_OD_HI
#define EA_y_DM_STRONG          PIN_DM_STRONG
#define EA_y_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EA_y_MASK               EA_y__MASK
#define EA_y_SHIFT              EA_y__SHIFT
#define EA_y_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EA_y_PS                     (* (reg8 *) EA_y__PS)
/* Data Register */
#define EA_y_DR                     (* (reg8 *) EA_y__DR)
/* Port Number */
#define EA_y_PRT_NUM                (* (reg8 *) EA_y__PRT) 
/* Connect to Analog Globals */                                                  
#define EA_y_AG                     (* (reg8 *) EA_y__AG)                       
/* Analog MUX bux enable */
#define EA_y_AMUX                   (* (reg8 *) EA_y__AMUX) 
/* Bidirectional Enable */                                                        
#define EA_y_BIE                    (* (reg8 *) EA_y__BIE)
/* Bit-mask for Aliased Register Access */
#define EA_y_BIT_MASK               (* (reg8 *) EA_y__BIT_MASK)
/* Bypass Enable */
#define EA_y_BYP                    (* (reg8 *) EA_y__BYP)
/* Port wide control signals */                                                   
#define EA_y_CTL                    (* (reg8 *) EA_y__CTL)
/* Drive Modes */
#define EA_y_DM0                    (* (reg8 *) EA_y__DM0) 
#define EA_y_DM1                    (* (reg8 *) EA_y__DM1)
#define EA_y_DM2                    (* (reg8 *) EA_y__DM2) 
/* Input Buffer Disable Override */
#define EA_y_INP_DIS                (* (reg8 *) EA_y__INP_DIS)
/* LCD Common or Segment Drive */
#define EA_y_LCD_COM_SEG            (* (reg8 *) EA_y__LCD_COM_SEG)
/* Enable Segment LCD */
#define EA_y_LCD_EN                 (* (reg8 *) EA_y__LCD_EN)
/* Slew Rate Control */
#define EA_y_SLW                    (* (reg8 *) EA_y__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EA_y_PRTDSI__CAPS_SEL       (* (reg8 *) EA_y__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EA_y_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EA_y__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EA_y_PRTDSI__OE_SEL0        (* (reg8 *) EA_y__PRTDSI__OE_SEL0) 
#define EA_y_PRTDSI__OE_SEL1        (* (reg8 *) EA_y__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EA_y_PRTDSI__OUT_SEL0       (* (reg8 *) EA_y__PRTDSI__OUT_SEL0) 
#define EA_y_PRTDSI__OUT_SEL1       (* (reg8 *) EA_y__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EA_y_PRTDSI__SYNC_OUT       (* (reg8 *) EA_y__PRTDSI__SYNC_OUT) 


#if defined(EA_y__INTSTAT)  /* Interrupt Registers */

    #define EA_y_INTSTAT                (* (reg8 *) EA_y__INTSTAT)
    #define EA_y_SNAP                   (* (reg8 *) EA_y__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EA_y_H */


/* [] END OF FILE */
