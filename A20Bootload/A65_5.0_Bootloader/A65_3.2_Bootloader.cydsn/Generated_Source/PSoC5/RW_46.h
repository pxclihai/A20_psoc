/*******************************************************************************
* File Name: RW_46.h  
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

#if !defined(CY_PINS_RW_46_H) /* Pins RW_46_H */
#define CY_PINS_RW_46_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RW_46_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_80 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RW_46__PORT == 15 && ((RW_46__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RW_46_Write(uint8 value) ;
void    RW_46_SetDriveMode(uint8 mode) ;
uint8   RW_46_ReadDataReg(void) ;
uint8   RW_46_Read(void) ;
uint8   RW_46_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RW_46_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RW_46_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RW_46_DM_RES_UP          PIN_DM_RES_UP
#define RW_46_DM_RES_DWN         PIN_DM_RES_DWN
#define RW_46_DM_OD_LO           PIN_DM_OD_LO
#define RW_46_DM_OD_HI           PIN_DM_OD_HI
#define RW_46_DM_STRONG          PIN_DM_STRONG
#define RW_46_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RW_46_MASK               RW_46__MASK
#define RW_46_SHIFT              RW_46__SHIFT
#define RW_46_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RW_46_PS                     (* (reg8 *) RW_46__PS)
/* Data Register */
#define RW_46_DR                     (* (reg8 *) RW_46__DR)
/* Port Number */
#define RW_46_PRT_NUM                (* (reg8 *) RW_46__PRT) 
/* Connect to Analog Globals */                                                  
#define RW_46_AG                     (* (reg8 *) RW_46__AG)                       
/* Analog MUX bux enable */
#define RW_46_AMUX                   (* (reg8 *) RW_46__AMUX) 
/* Bidirectional Enable */                                                        
#define RW_46_BIE                    (* (reg8 *) RW_46__BIE)
/* Bit-mask for Aliased Register Access */
#define RW_46_BIT_MASK               (* (reg8 *) RW_46__BIT_MASK)
/* Bypass Enable */
#define RW_46_BYP                    (* (reg8 *) RW_46__BYP)
/* Port wide control signals */                                                   
#define RW_46_CTL                    (* (reg8 *) RW_46__CTL)
/* Drive Modes */
#define RW_46_DM0                    (* (reg8 *) RW_46__DM0) 
#define RW_46_DM1                    (* (reg8 *) RW_46__DM1)
#define RW_46_DM2                    (* (reg8 *) RW_46__DM2) 
/* Input Buffer Disable Override */
#define RW_46_INP_DIS                (* (reg8 *) RW_46__INP_DIS)
/* LCD Common or Segment Drive */
#define RW_46_LCD_COM_SEG            (* (reg8 *) RW_46__LCD_COM_SEG)
/* Enable Segment LCD */
#define RW_46_LCD_EN                 (* (reg8 *) RW_46__LCD_EN)
/* Slew Rate Control */
#define RW_46_SLW                    (* (reg8 *) RW_46__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RW_46_PRTDSI__CAPS_SEL       (* (reg8 *) RW_46__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RW_46_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RW_46__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RW_46_PRTDSI__OE_SEL0        (* (reg8 *) RW_46__PRTDSI__OE_SEL0) 
#define RW_46_PRTDSI__OE_SEL1        (* (reg8 *) RW_46__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RW_46_PRTDSI__OUT_SEL0       (* (reg8 *) RW_46__PRTDSI__OUT_SEL0) 
#define RW_46_PRTDSI__OUT_SEL1       (* (reg8 *) RW_46__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RW_46_PRTDSI__SYNC_OUT       (* (reg8 *) RW_46__PRTDSI__SYNC_OUT) 


#if defined(RW_46__INTSTAT)  /* Interrupt Registers */

    #define RW_46_INTSTAT                (* (reg8 *) RW_46__INTSTAT)
    #define RW_46_SNAP                   (* (reg8 *) RW_46__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RW_46_H */


/* [] END OF FILE */
