/*******************************************************************************
* File Name: Flash_1_FSO.h  
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

#if !defined(CY_PINS_Flash_1_FSO_H) /* Pins Flash_1_FSO_H */
#define CY_PINS_Flash_1_FSO_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Flash_1_FSO_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Flash_1_FSO__PORT == 15 && ((Flash_1_FSO__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Flash_1_FSO_Write(uint8 value) ;
void    Flash_1_FSO_SetDriveMode(uint8 mode) ;
uint8   Flash_1_FSO_ReadDataReg(void) ;
uint8   Flash_1_FSO_Read(void) ;
uint8   Flash_1_FSO_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Flash_1_FSO_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Flash_1_FSO_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Flash_1_FSO_DM_RES_UP          PIN_DM_RES_UP
#define Flash_1_FSO_DM_RES_DWN         PIN_DM_RES_DWN
#define Flash_1_FSO_DM_OD_LO           PIN_DM_OD_LO
#define Flash_1_FSO_DM_OD_HI           PIN_DM_OD_HI
#define Flash_1_FSO_DM_STRONG          PIN_DM_STRONG
#define Flash_1_FSO_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Flash_1_FSO_MASK               Flash_1_FSO__MASK
#define Flash_1_FSO_SHIFT              Flash_1_FSO__SHIFT
#define Flash_1_FSO_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Flash_1_FSO_PS                     (* (reg8 *) Flash_1_FSO__PS)
/* Data Register */
#define Flash_1_FSO_DR                     (* (reg8 *) Flash_1_FSO__DR)
/* Port Number */
#define Flash_1_FSO_PRT_NUM                (* (reg8 *) Flash_1_FSO__PRT) 
/* Connect to Analog Globals */                                                  
#define Flash_1_FSO_AG                     (* (reg8 *) Flash_1_FSO__AG)                       
/* Analog MUX bux enable */
#define Flash_1_FSO_AMUX                   (* (reg8 *) Flash_1_FSO__AMUX) 
/* Bidirectional Enable */                                                        
#define Flash_1_FSO_BIE                    (* (reg8 *) Flash_1_FSO__BIE)
/* Bit-mask for Aliased Register Access */
#define Flash_1_FSO_BIT_MASK               (* (reg8 *) Flash_1_FSO__BIT_MASK)
/* Bypass Enable */
#define Flash_1_FSO_BYP                    (* (reg8 *) Flash_1_FSO__BYP)
/* Port wide control signals */                                                   
#define Flash_1_FSO_CTL                    (* (reg8 *) Flash_1_FSO__CTL)
/* Drive Modes */
#define Flash_1_FSO_DM0                    (* (reg8 *) Flash_1_FSO__DM0) 
#define Flash_1_FSO_DM1                    (* (reg8 *) Flash_1_FSO__DM1)
#define Flash_1_FSO_DM2                    (* (reg8 *) Flash_1_FSO__DM2) 
/* Input Buffer Disable Override */
#define Flash_1_FSO_INP_DIS                (* (reg8 *) Flash_1_FSO__INP_DIS)
/* LCD Common or Segment Drive */
#define Flash_1_FSO_LCD_COM_SEG            (* (reg8 *) Flash_1_FSO__LCD_COM_SEG)
/* Enable Segment LCD */
#define Flash_1_FSO_LCD_EN                 (* (reg8 *) Flash_1_FSO__LCD_EN)
/* Slew Rate Control */
#define Flash_1_FSO_SLW                    (* (reg8 *) Flash_1_FSO__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Flash_1_FSO_PRTDSI__CAPS_SEL       (* (reg8 *) Flash_1_FSO__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Flash_1_FSO_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Flash_1_FSO__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Flash_1_FSO_PRTDSI__OE_SEL0        (* (reg8 *) Flash_1_FSO__PRTDSI__OE_SEL0) 
#define Flash_1_FSO_PRTDSI__OE_SEL1        (* (reg8 *) Flash_1_FSO__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Flash_1_FSO_PRTDSI__OUT_SEL0       (* (reg8 *) Flash_1_FSO__PRTDSI__OUT_SEL0) 
#define Flash_1_FSO_PRTDSI__OUT_SEL1       (* (reg8 *) Flash_1_FSO__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Flash_1_FSO_PRTDSI__SYNC_OUT       (* (reg8 *) Flash_1_FSO__PRTDSI__SYNC_OUT) 


#if defined(Flash_1_FSO__INTSTAT)  /* Interrupt Registers */

    #define Flash_1_FSO_INTSTAT                (* (reg8 *) Flash_1_FSO__INTSTAT)
    #define Flash_1_FSO_SNAP                   (* (reg8 *) Flash_1_FSO__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Flash_1_FSO_H */


/* [] END OF FILE */
