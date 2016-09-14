/*******************************************************************************
* File Name: KeyScanClk.h
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

#if !defined(CY_CLOCK_KeyScanClk_H)
#define CY_CLOCK_KeyScanClk_H

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

void KeyScanClk_Start(void) ;
void KeyScanClk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void KeyScanClk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void KeyScanClk_StandbyPower(uint8 state) ;
void KeyScanClk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 KeyScanClk_GetDividerRegister(void) ;
void KeyScanClk_SetModeRegister(uint8 modeBitMask) ;
void KeyScanClk_ClearModeRegister(uint8 modeBitMask) ;
uint8 KeyScanClk_GetModeRegister(void) ;
void KeyScanClk_SetSourceRegister(uint8 clkSource) ;
uint8 KeyScanClk_GetSourceRegister(void) ;
#if defined(KeyScanClk__CFG3)
void KeyScanClk_SetPhaseRegister(uint8 clkPhase) ;
uint8 KeyScanClk_GetPhaseRegister(void) ;
#endif /* defined(KeyScanClk__CFG3) */

#define KeyScanClk_Enable()                       KeyScanClk_Start()
#define KeyScanClk_Disable()                      KeyScanClk_Stop()
#define KeyScanClk_SetDivider(clkDivider)         KeyScanClk_SetDividerRegister(clkDivider, 1)
#define KeyScanClk_SetDividerValue(clkDivider)    KeyScanClk_SetDividerRegister((clkDivider) - 1, 1)
#define KeyScanClk_SetMode(clkMode)               KeyScanClk_SetModeRegister(clkMode)
#define KeyScanClk_SetSource(clkSource)           KeyScanClk_SetSourceRegister(clkSource)
#if defined(KeyScanClk__CFG3)
#define KeyScanClk_SetPhase(clkPhase)             KeyScanClk_SetPhaseRegister(clkPhase)
#define KeyScanClk_SetPhaseValue(clkPhase)        KeyScanClk_SetPhaseRegister((clkPhase) + 1)
#endif /* defined(KeyScanClk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define KeyScanClk_CLKEN              (* (reg8 *) KeyScanClk__PM_ACT_CFG)
#define KeyScanClk_CLKEN_PTR          ((reg8 *) KeyScanClk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define KeyScanClk_CLKSTBY            (* (reg8 *) KeyScanClk__PM_STBY_CFG)
#define KeyScanClk_CLKSTBY_PTR        ((reg8 *) KeyScanClk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define KeyScanClk_DIV_LSB            (* (reg8 *) KeyScanClk__CFG0)
#define KeyScanClk_DIV_LSB_PTR        ((reg8 *) KeyScanClk__CFG0)
#define KeyScanClk_DIV_PTR            ((reg16 *) KeyScanClk__CFG0)

/* Clock MSB divider configuration register. */
#define KeyScanClk_DIV_MSB            (* (reg8 *) KeyScanClk__CFG1)
#define KeyScanClk_DIV_MSB_PTR        ((reg8 *) KeyScanClk__CFG1)

/* Mode and source configuration register */
#define KeyScanClk_MOD_SRC            (* (reg8 *) KeyScanClk__CFG2)
#define KeyScanClk_MOD_SRC_PTR        ((reg8 *) KeyScanClk__CFG2)

#if defined(KeyScanClk__CFG3)
/* Analog clock phase configuration register */
#define KeyScanClk_PHASE              (* (reg8 *) KeyScanClk__CFG3)
#define KeyScanClk_PHASE_PTR          ((reg8 *) KeyScanClk__CFG3)
#endif /* defined(KeyScanClk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define KeyScanClk_CLKEN_MASK         KeyScanClk__PM_ACT_MSK
#define KeyScanClk_CLKSTBY_MASK       KeyScanClk__PM_STBY_MSK

/* CFG2 field masks */
#define KeyScanClk_SRC_SEL_MSK        KeyScanClk__CFG2_SRC_SEL_MASK
#define KeyScanClk_MODE_MASK          (~(KeyScanClk_SRC_SEL_MSK))

#if defined(KeyScanClk__CFG3)
/* CFG3 phase mask */
#define KeyScanClk_PHASE_MASK         KeyScanClk__CFG3_PHASE_DLY_MASK
#endif /* defined(KeyScanClk__CFG3) */

#endif /* CY_CLOCK_KeyScanClk_H */


/* [] END OF FILE */
