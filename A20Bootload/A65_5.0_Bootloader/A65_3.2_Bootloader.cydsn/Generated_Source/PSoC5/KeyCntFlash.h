/*******************************************************************************
* File Name: KeyCntFlash.h
* Version 2.0
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_KeyCntFlash_H)
#define CY_CLOCK_KeyCntFlash_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void KeyCntFlash_Start(void) ;
void KeyCntFlash_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void KeyCntFlash_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void KeyCntFlash_StandbyPower(uint8 state) ;
void KeyCntFlash_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 KeyCntFlash_GetDividerRegister(void) ;
void KeyCntFlash_SetModeRegister(uint8 modeBitMask) ;
void KeyCntFlash_ClearModeRegister(uint8 modeBitMask) ;
uint8 KeyCntFlash_GetModeRegister(void) ;
void KeyCntFlash_SetSourceRegister(uint8 clkSource) ;
uint8 KeyCntFlash_GetSourceRegister(void) ;
#if defined(KeyCntFlash__CFG3)
void KeyCntFlash_SetPhaseRegister(uint8 clkPhase) ;
uint8 KeyCntFlash_GetPhaseRegister(void) ;
#endif /* defined(KeyCntFlash__CFG3) */

#define KeyCntFlash_Enable()                       KeyCntFlash_Start()
#define KeyCntFlash_Disable()                      KeyCntFlash_Stop()
#define KeyCntFlash_SetDivider(clkDivider)         KeyCntFlash_SetDividerRegister(clkDivider, 1)
#define KeyCntFlash_SetDividerValue(clkDivider)    KeyCntFlash_SetDividerRegister((clkDivider) - 1, 1)
#define KeyCntFlash_SetMode(clkMode)               KeyCntFlash_SetModeRegister(clkMode)
#define KeyCntFlash_SetSource(clkSource)           KeyCntFlash_SetSourceRegister(clkSource)
#if defined(KeyCntFlash__CFG3)
#define KeyCntFlash_SetPhase(clkPhase)             KeyCntFlash_SetPhaseRegister(clkPhase)
#define KeyCntFlash_SetPhaseValue(clkPhase)        KeyCntFlash_SetPhaseRegister((clkPhase) + 1)
#endif /* defined(KeyCntFlash__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define KeyCntFlash_CLKEN              (* (reg8 *) KeyCntFlash__PM_ACT_CFG)
#define KeyCntFlash_CLKEN_PTR          ((reg8 *) KeyCntFlash__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define KeyCntFlash_CLKSTBY            (* (reg8 *) KeyCntFlash__PM_STBY_CFG)
#define KeyCntFlash_CLKSTBY_PTR        ((reg8 *) KeyCntFlash__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define KeyCntFlash_DIV_LSB            (* (reg8 *) KeyCntFlash__CFG0)
#define KeyCntFlash_DIV_LSB_PTR        ((reg8 *) KeyCntFlash__CFG0)
#define KeyCntFlash_DIV_PTR            ((reg16 *) KeyCntFlash__CFG0)

/* Clock MSB divider configuration register. */
#define KeyCntFlash_DIV_MSB            (* (reg8 *) KeyCntFlash__CFG1)
#define KeyCntFlash_DIV_MSB_PTR        ((reg8 *) KeyCntFlash__CFG1)

/* Mode and source configuration register */
#define KeyCntFlash_MOD_SRC            (* (reg8 *) KeyCntFlash__CFG2)
#define KeyCntFlash_MOD_SRC_PTR        ((reg8 *) KeyCntFlash__CFG2)

#if defined(KeyCntFlash__CFG3)
/* Analog clock phase configuration register */
#define KeyCntFlash_PHASE              (* (reg8 *) KeyCntFlash__CFG3)
#define KeyCntFlash_PHASE_PTR          ((reg8 *) KeyCntFlash__CFG3)
#endif /* defined(KeyCntFlash__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define KeyCntFlash_CLKEN_MASK         KeyCntFlash__PM_ACT_MSK
#define KeyCntFlash_CLKSTBY_MASK       KeyCntFlash__PM_STBY_MSK

/* CFG2 field masks */
#define KeyCntFlash_SRC_SEL_MSK        KeyCntFlash__CFG2_SRC_SEL_MASK
#define KeyCntFlash_MODE_MASK          (~(KeyCntFlash_SRC_SEL_MSK))

#if defined(KeyCntFlash__CFG3)
/* CFG3 phase mask */
#define KeyCntFlash_PHASE_MASK         KeyCntFlash__CFG3_PHASE_DLY_MASK
#endif /* defined(KeyCntFlash__CFG3) */

#endif /* CY_CLOCK_KeyCntFlash_H */


/* [] END OF FILE */
