/*******************************************************************************
* File Name: CheckMoveClk.h
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

#if !defined(CY_CLOCK_CheckMoveClk_H)
#define CY_CLOCK_CheckMoveClk_H

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

void CheckMoveClk_Start(void) ;
void CheckMoveClk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void CheckMoveClk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void CheckMoveClk_StandbyPower(uint8 state) ;
void CheckMoveClk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 CheckMoveClk_GetDividerRegister(void) ;
void CheckMoveClk_SetModeRegister(uint8 modeBitMask) ;
void CheckMoveClk_ClearModeRegister(uint8 modeBitMask) ;
uint8 CheckMoveClk_GetModeRegister(void) ;
void CheckMoveClk_SetSourceRegister(uint8 clkSource) ;
uint8 CheckMoveClk_GetSourceRegister(void) ;
#if defined(CheckMoveClk__CFG3)
void CheckMoveClk_SetPhaseRegister(uint8 clkPhase) ;
uint8 CheckMoveClk_GetPhaseRegister(void) ;
#endif /* defined(CheckMoveClk__CFG3) */

#define CheckMoveClk_Enable()                       CheckMoveClk_Start()
#define CheckMoveClk_Disable()                      CheckMoveClk_Stop()
#define CheckMoveClk_SetDivider(clkDivider)         CheckMoveClk_SetDividerRegister(clkDivider, 1)
#define CheckMoveClk_SetDividerValue(clkDivider)    CheckMoveClk_SetDividerRegister((clkDivider) - 1, 1)
#define CheckMoveClk_SetMode(clkMode)               CheckMoveClk_SetModeRegister(clkMode)
#define CheckMoveClk_SetSource(clkSource)           CheckMoveClk_SetSourceRegister(clkSource)
#if defined(CheckMoveClk__CFG3)
#define CheckMoveClk_SetPhase(clkPhase)             CheckMoveClk_SetPhaseRegister(clkPhase)
#define CheckMoveClk_SetPhaseValue(clkPhase)        CheckMoveClk_SetPhaseRegister((clkPhase) + 1)
#endif /* defined(CheckMoveClk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define CheckMoveClk_CLKEN              (* (reg8 *) CheckMoveClk__PM_ACT_CFG)
#define CheckMoveClk_CLKEN_PTR          ((reg8 *) CheckMoveClk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define CheckMoveClk_CLKSTBY            (* (reg8 *) CheckMoveClk__PM_STBY_CFG)
#define CheckMoveClk_CLKSTBY_PTR        ((reg8 *) CheckMoveClk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define CheckMoveClk_DIV_LSB            (* (reg8 *) CheckMoveClk__CFG0)
#define CheckMoveClk_DIV_LSB_PTR        ((reg8 *) CheckMoveClk__CFG0)
#define CheckMoveClk_DIV_PTR            ((reg16 *) CheckMoveClk__CFG0)

/* Clock MSB divider configuration register. */
#define CheckMoveClk_DIV_MSB            (* (reg8 *) CheckMoveClk__CFG1)
#define CheckMoveClk_DIV_MSB_PTR        ((reg8 *) CheckMoveClk__CFG1)

/* Mode and source configuration register */
#define CheckMoveClk_MOD_SRC            (* (reg8 *) CheckMoveClk__CFG2)
#define CheckMoveClk_MOD_SRC_PTR        ((reg8 *) CheckMoveClk__CFG2)

#if defined(CheckMoveClk__CFG3)
/* Analog clock phase configuration register */
#define CheckMoveClk_PHASE              (* (reg8 *) CheckMoveClk__CFG3)
#define CheckMoveClk_PHASE_PTR          ((reg8 *) CheckMoveClk__CFG3)
#endif /* defined(CheckMoveClk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define CheckMoveClk_CLKEN_MASK         CheckMoveClk__PM_ACT_MSK
#define CheckMoveClk_CLKSTBY_MASK       CheckMoveClk__PM_STBY_MSK

/* CFG2 field masks */
#define CheckMoveClk_SRC_SEL_MSK        CheckMoveClk__CFG2_SRC_SEL_MASK
#define CheckMoveClk_MODE_MASK          (~(CheckMoveClk_SRC_SEL_MSK))

#if defined(CheckMoveClk__CFG3)
/* CFG3 phase mask */
#define CheckMoveClk_PHASE_MASK         CheckMoveClk__CFG3_PHASE_DLY_MASK
#endif /* defined(CheckMoveClk__CFG3) */

#endif /* CY_CLOCK_CheckMoveClk_H */


/* [] END OF FILE */
