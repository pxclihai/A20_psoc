/*******************************************************************************
* File Name: FRAM_IO_1_SDA.h  
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

#if !defined(CY_PINS_FRAM_IO_1_SDA_H) /* Pins FRAM_IO_1_SDA_H */
#define CY_PINS_FRAM_IO_1_SDA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FRAM_IO_1_SDA_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FRAM_IO_1_SDA__PORT == 15 && ((FRAM_IO_1_SDA__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    FRAM_IO_1_SDA_Write(uint8 value) ;
void    FRAM_IO_1_SDA_SetDriveMode(uint8 mode) ;
uint8   FRAM_IO_1_SDA_ReadDataReg(void) ;
uint8   FRAM_IO_1_SDA_Read(void) ;
uint8   FRAM_IO_1_SDA_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define FRAM_IO_1_SDA_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define FRAM_IO_1_SDA_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define FRAM_IO_1_SDA_DM_RES_UP          PIN_DM_RES_UP
#define FRAM_IO_1_SDA_DM_RES_DWN         PIN_DM_RES_DWN
#define FRAM_IO_1_SDA_DM_OD_LO           PIN_DM_OD_LO
#define FRAM_IO_1_SDA_DM_OD_HI           PIN_DM_OD_HI
#define FRAM_IO_1_SDA_DM_STRONG          PIN_DM_STRONG
#define FRAM_IO_1_SDA_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define FRAM_IO_1_SDA_MASK               FRAM_IO_1_SDA__MASK
#define FRAM_IO_1_SDA_SHIFT              FRAM_IO_1_SDA__SHIFT
#define FRAM_IO_1_SDA_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FRAM_IO_1_SDA_PS                     (* (reg8 *) FRAM_IO_1_SDA__PS)
/* Data Register */
#define FRAM_IO_1_SDA_DR                     (* (reg8 *) FRAM_IO_1_SDA__DR)
/* Port Number */
#define FRAM_IO_1_SDA_PRT_NUM                (* (reg8 *) FRAM_IO_1_SDA__PRT) 
/* Connect to Analog Globals */                                                  
#define FRAM_IO_1_SDA_AG                     (* (reg8 *) FRAM_IO_1_SDA__AG)                       
/* Analog MUX bux enable */
#define FRAM_IO_1_SDA_AMUX                   (* (reg8 *) FRAM_IO_1_SDA__AMUX) 
/* Bidirectional Enable */                                                        
#define FRAM_IO_1_SDA_BIE                    (* (reg8 *) FRAM_IO_1_SDA__BIE)
/* Bit-mask for Aliased Register Access */
#define FRAM_IO_1_SDA_BIT_MASK               (* (reg8 *) FRAM_IO_1_SDA__BIT_MASK)
/* Bypass Enable */
#define FRAM_IO_1_SDA_BYP                    (* (reg8 *) FRAM_IO_1_SDA__BYP)
/* Port wide control signals */                                                   
#define FRAM_IO_1_SDA_CTL                    (* (reg8 *) FRAM_IO_1_SDA__CTL)
/* Drive Modes */
#define FRAM_IO_1_SDA_DM0                    (* (reg8 *) FRAM_IO_1_SDA__DM0) 
#define FRAM_IO_1_SDA_DM1                    (* (reg8 *) FRAM_IO_1_SDA__DM1)
#define FRAM_IO_1_SDA_DM2                    (* (reg8 *) FRAM_IO_1_SDA__DM2) 
/* Input Buffer Disable Override */
#define FRAM_IO_1_SDA_INP_DIS                (* (reg8 *) FRAM_IO_1_SDA__INP_DIS)
/* LCD Common or Segment Drive */
#define FRAM_IO_1_SDA_LCD_COM_SEG            (* (reg8 *) FRAM_IO_1_SDA__LCD_COM_SEG)
/* Enable Segment LCD */
#define FRAM_IO_1_SDA_LCD_EN                 (* (reg8 *) FRAM_IO_1_SDA__LCD_EN)
/* Slew Rate Control */
#define FRAM_IO_1_SDA_SLW                    (* (reg8 *) FRAM_IO_1_SDA__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FRAM_IO_1_SDA_PRTDSI__CAPS_SEL       (* (reg8 *) FRAM_IO_1_SDA__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FRAM_IO_1_SDA_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FRAM_IO_1_SDA__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FRAM_IO_1_SDA_PRTDSI__OE_SEL0        (* (reg8 *) FRAM_IO_1_SDA__PRTDSI__OE_SEL0) 
#define FRAM_IO_1_SDA_PRTDSI__OE_SEL1        (* (reg8 *) FRAM_IO_1_SDA__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FRAM_IO_1_SDA_PRTDSI__OUT_SEL0       (* (reg8 *) FRAM_IO_1_SDA__PRTDSI__OUT_SEL0) 
#define FRAM_IO_1_SDA_PRTDSI__OUT_SEL1       (* (reg8 *) FRAM_IO_1_SDA__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FRAM_IO_1_SDA_PRTDSI__SYNC_OUT       (* (reg8 *) FRAM_IO_1_SDA__PRTDSI__SYNC_OUT) 


#if defined(FRAM_IO_1_SDA__INTSTAT)  /* Interrupt Registers */

    #define FRAM_IO_1_SDA_INTSTAT                (* (reg8 *) FRAM_IO_1_SDA__INTSTAT)
    #define FRAM_IO_1_SDA_SNAP                   (* (reg8 *) FRAM_IO_1_SDA__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FRAM_IO_1_SDA_H */


/* [] END OF FILE */
