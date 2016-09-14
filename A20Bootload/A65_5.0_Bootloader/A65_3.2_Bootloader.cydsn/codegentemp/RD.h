/*******************************************************************************
* File Name: RD.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RD_H) /* Pins RD_H */
#define CY_PINS_RD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RD_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RD__PORT == 15 && ((RD__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RD_Write(uint8 value) ;
void    RD_SetDriveMode(uint8 mode) ;
uint8   RD_ReadDataReg(void) ;
uint8   RD_Read(void) ;
uint8   RD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RD_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RD_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RD_DM_RES_UP          PIN_DM_RES_UP
#define RD_DM_RES_DWN         PIN_DM_RES_DWN
#define RD_DM_OD_LO           PIN_DM_OD_LO
#define RD_DM_OD_HI           PIN_DM_OD_HI
#define RD_DM_STRONG          PIN_DM_STRONG
#define RD_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RD_MASK               RD__MASK
#define RD_SHIFT              RD__SHIFT
#define RD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RD_PS                     (* (reg8 *) RD__PS)
/* Data Register */
#define RD_DR                     (* (reg8 *) RD__DR)
/* Port Number */
#define RD_PRT_NUM                (* (reg8 *) RD__PRT) 
/* Connect to Analog Globals */                                                  
#define RD_AG                     (* (reg8 *) RD__AG)                       
/* Analog MUX bux enable */
#define RD_AMUX                   (* (reg8 *) RD__AMUX) 
/* Bidirectional Enable */                                                        
#define RD_BIE                    (* (reg8 *) RD__BIE)
/* Bit-mask for Aliased Register Access */
#define RD_BIT_MASK               (* (reg8 *) RD__BIT_MASK)
/* Bypass Enable */
#define RD_BYP                    (* (reg8 *) RD__BYP)
/* Port wide control signals */                                                   
#define RD_CTL                    (* (reg8 *) RD__CTL)
/* Drive Modes */
#define RD_DM0                    (* (reg8 *) RD__DM0) 
#define RD_DM1                    (* (reg8 *) RD__DM1)
#define RD_DM2                    (* (reg8 *) RD__DM2) 
/* Input Buffer Disable Override */
#define RD_INP_DIS                (* (reg8 *) RD__INP_DIS)
/* LCD Common or Segment Drive */
#define RD_LCD_COM_SEG            (* (reg8 *) RD__LCD_COM_SEG)
/* Enable Segment LCD */
#define RD_LCD_EN                 (* (reg8 *) RD__LCD_EN)
/* Slew Rate Control */
#define RD_SLW                    (* (reg8 *) RD__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RD_PRTDSI__CAPS_SEL       (* (reg8 *) RD__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RD_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RD__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RD_PRTDSI__OE_SEL0        (* (reg8 *) RD__PRTDSI__OE_SEL0) 
#define RD_PRTDSI__OE_SEL1        (* (reg8 *) RD__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RD_PRTDSI__OUT_SEL0       (* (reg8 *) RD__PRTDSI__OUT_SEL0) 
#define RD_PRTDSI__OUT_SEL1       (* (reg8 *) RD__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RD_PRTDSI__SYNC_OUT       (* (reg8 *) RD__PRTDSI__SYNC_OUT) 


#if defined(RD__INTSTAT)  /* Interrupt Registers */

    #define RD_INTSTAT                (* (reg8 *) RD__INTSTAT)
    #define RD_SNAP                   (* (reg8 *) RD__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RD_H */


/* [] END OF FILE */
