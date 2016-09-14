/*******************************************************************************
* File Name: Flash_1_FCS.h  
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

#if !defined(CY_PINS_Flash_1_FCS_H) /* Pins Flash_1_FCS_H */
#define CY_PINS_Flash_1_FCS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Flash_1_FCS_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Flash_1_FCS__PORT == 15 && ((Flash_1_FCS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Flash_1_FCS_Write(uint8 value) ;
void    Flash_1_FCS_SetDriveMode(uint8 mode) ;
uint8   Flash_1_FCS_ReadDataReg(void) ;
uint8   Flash_1_FCS_Read(void) ;
uint8   Flash_1_FCS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Flash_1_FCS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Flash_1_FCS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Flash_1_FCS_DM_RES_UP          PIN_DM_RES_UP
#define Flash_1_FCS_DM_RES_DWN         PIN_DM_RES_DWN
#define Flash_1_FCS_DM_OD_LO           PIN_DM_OD_LO
#define Flash_1_FCS_DM_OD_HI           PIN_DM_OD_HI
#define Flash_1_FCS_DM_STRONG          PIN_DM_STRONG
#define Flash_1_FCS_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Flash_1_FCS_MASK               Flash_1_FCS__MASK
#define Flash_1_FCS_SHIFT              Flash_1_FCS__SHIFT
#define Flash_1_FCS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Flash_1_FCS_PS                     (* (reg8 *) Flash_1_FCS__PS)
/* Data Register */
#define Flash_1_FCS_DR                     (* (reg8 *) Flash_1_FCS__DR)
/* Port Number */
#define Flash_1_FCS_PRT_NUM                (* (reg8 *) Flash_1_FCS__PRT) 
/* Connect to Analog Globals */                                                  
#define Flash_1_FCS_AG                     (* (reg8 *) Flash_1_FCS__AG)                       
/* Analog MUX bux enable */
#define Flash_1_FCS_AMUX                   (* (reg8 *) Flash_1_FCS__AMUX) 
/* Bidirectional Enable */                                                        
#define Flash_1_FCS_BIE                    (* (reg8 *) Flash_1_FCS__BIE)
/* Bit-mask for Aliased Register Access */
#define Flash_1_FCS_BIT_MASK               (* (reg8 *) Flash_1_FCS__BIT_MASK)
/* Bypass Enable */
#define Flash_1_FCS_BYP                    (* (reg8 *) Flash_1_FCS__BYP)
/* Port wide control signals */                                                   
#define Flash_1_FCS_CTL                    (* (reg8 *) Flash_1_FCS__CTL)
/* Drive Modes */
#define Flash_1_FCS_DM0                    (* (reg8 *) Flash_1_FCS__DM0) 
#define Flash_1_FCS_DM1                    (* (reg8 *) Flash_1_FCS__DM1)
#define Flash_1_FCS_DM2                    (* (reg8 *) Flash_1_FCS__DM2) 
/* Input Buffer Disable Override */
#define Flash_1_FCS_INP_DIS                (* (reg8 *) Flash_1_FCS__INP_DIS)
/* LCD Common or Segment Drive */
#define Flash_1_FCS_LCD_COM_SEG            (* (reg8 *) Flash_1_FCS__LCD_COM_SEG)
/* Enable Segment LCD */
#define Flash_1_FCS_LCD_EN                 (* (reg8 *) Flash_1_FCS__LCD_EN)
/* Slew Rate Control */
#define Flash_1_FCS_SLW                    (* (reg8 *) Flash_1_FCS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Flash_1_FCS_PRTDSI__CAPS_SEL       (* (reg8 *) Flash_1_FCS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Flash_1_FCS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Flash_1_FCS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Flash_1_FCS_PRTDSI__OE_SEL0        (* (reg8 *) Flash_1_FCS__PRTDSI__OE_SEL0) 
#define Flash_1_FCS_PRTDSI__OE_SEL1        (* (reg8 *) Flash_1_FCS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Flash_1_FCS_PRTDSI__OUT_SEL0       (* (reg8 *) Flash_1_FCS__PRTDSI__OUT_SEL0) 
#define Flash_1_FCS_PRTDSI__OUT_SEL1       (* (reg8 *) Flash_1_FCS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Flash_1_FCS_PRTDSI__SYNC_OUT       (* (reg8 *) Flash_1_FCS__PRTDSI__SYNC_OUT) 


#if defined(Flash_1_FCS__INTSTAT)  /* Interrupt Registers */

    #define Flash_1_FCS_INTSTAT                (* (reg8 *) Flash_1_FCS__INTSTAT)
    #define Flash_1_FCS_SNAP                   (* (reg8 *) Flash_1_FCS__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Flash_1_FCS_H */


/* [] END OF FILE */
