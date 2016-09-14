/*******************************************************************************
* File Name: FRAM_IO_1_SCL.h  
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

#if !defined(CY_PINS_FRAM_IO_1_SCL_H) /* Pins FRAM_IO_1_SCL_H */
#define CY_PINS_FRAM_IO_1_SCL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FRAM_IO_1_SCL_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FRAM_IO_1_SCL__PORT == 15 && ((FRAM_IO_1_SCL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    FRAM_IO_1_SCL_Write(uint8 value) ;
void    FRAM_IO_1_SCL_SetDriveMode(uint8 mode) ;
uint8   FRAM_IO_1_SCL_ReadDataReg(void) ;
uint8   FRAM_IO_1_SCL_Read(void) ;
uint8   FRAM_IO_1_SCL_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define FRAM_IO_1_SCL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define FRAM_IO_1_SCL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define FRAM_IO_1_SCL_DM_RES_UP          PIN_DM_RES_UP
#define FRAM_IO_1_SCL_DM_RES_DWN         PIN_DM_RES_DWN
#define FRAM_IO_1_SCL_DM_OD_LO           PIN_DM_OD_LO
#define FRAM_IO_1_SCL_DM_OD_HI           PIN_DM_OD_HI
#define FRAM_IO_1_SCL_DM_STRONG          PIN_DM_STRONG
#define FRAM_IO_1_SCL_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define FRAM_IO_1_SCL_MASK               FRAM_IO_1_SCL__MASK
#define FRAM_IO_1_SCL_SHIFT              FRAM_IO_1_SCL__SHIFT
#define FRAM_IO_1_SCL_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FRAM_IO_1_SCL_PS                     (* (reg8 *) FRAM_IO_1_SCL__PS)
/* Data Register */
#define FRAM_IO_1_SCL_DR                     (* (reg8 *) FRAM_IO_1_SCL__DR)
/* Port Number */
#define FRAM_IO_1_SCL_PRT_NUM                (* (reg8 *) FRAM_IO_1_SCL__PRT) 
/* Connect to Analog Globals */                                                  
#define FRAM_IO_1_SCL_AG                     (* (reg8 *) FRAM_IO_1_SCL__AG)                       
/* Analog MUX bux enable */
#define FRAM_IO_1_SCL_AMUX                   (* (reg8 *) FRAM_IO_1_SCL__AMUX) 
/* Bidirectional Enable */                                                        
#define FRAM_IO_1_SCL_BIE                    (* (reg8 *) FRAM_IO_1_SCL__BIE)
/* Bit-mask for Aliased Register Access */
#define FRAM_IO_1_SCL_BIT_MASK               (* (reg8 *) FRAM_IO_1_SCL__BIT_MASK)
/* Bypass Enable */
#define FRAM_IO_1_SCL_BYP                    (* (reg8 *) FRAM_IO_1_SCL__BYP)
/* Port wide control signals */                                                   
#define FRAM_IO_1_SCL_CTL                    (* (reg8 *) FRAM_IO_1_SCL__CTL)
/* Drive Modes */
#define FRAM_IO_1_SCL_DM0                    (* (reg8 *) FRAM_IO_1_SCL__DM0) 
#define FRAM_IO_1_SCL_DM1                    (* (reg8 *) FRAM_IO_1_SCL__DM1)
#define FRAM_IO_1_SCL_DM2                    (* (reg8 *) FRAM_IO_1_SCL__DM2) 
/* Input Buffer Disable Override */
#define FRAM_IO_1_SCL_INP_DIS                (* (reg8 *) FRAM_IO_1_SCL__INP_DIS)
/* LCD Common or Segment Drive */
#define FRAM_IO_1_SCL_LCD_COM_SEG            (* (reg8 *) FRAM_IO_1_SCL__LCD_COM_SEG)
/* Enable Segment LCD */
#define FRAM_IO_1_SCL_LCD_EN                 (* (reg8 *) FRAM_IO_1_SCL__LCD_EN)
/* Slew Rate Control */
#define FRAM_IO_1_SCL_SLW                    (* (reg8 *) FRAM_IO_1_SCL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FRAM_IO_1_SCL_PRTDSI__CAPS_SEL       (* (reg8 *) FRAM_IO_1_SCL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FRAM_IO_1_SCL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FRAM_IO_1_SCL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FRAM_IO_1_SCL_PRTDSI__OE_SEL0        (* (reg8 *) FRAM_IO_1_SCL__PRTDSI__OE_SEL0) 
#define FRAM_IO_1_SCL_PRTDSI__OE_SEL1        (* (reg8 *) FRAM_IO_1_SCL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FRAM_IO_1_SCL_PRTDSI__OUT_SEL0       (* (reg8 *) FRAM_IO_1_SCL__PRTDSI__OUT_SEL0) 
#define FRAM_IO_1_SCL_PRTDSI__OUT_SEL1       (* (reg8 *) FRAM_IO_1_SCL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FRAM_IO_1_SCL_PRTDSI__SYNC_OUT       (* (reg8 *) FRAM_IO_1_SCL__PRTDSI__SYNC_OUT) 


#if defined(FRAM_IO_1_SCL__INTSTAT)  /* Interrupt Registers */

    #define FRAM_IO_1_SCL_INTSTAT                (* (reg8 *) FRAM_IO_1_SCL__INTSTAT)
    #define FRAM_IO_1_SCL_SNAP                   (* (reg8 *) FRAM_IO_1_SCL__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FRAM_IO_1_SCL_H */


/* [] END OF FILE */
