/*******************************************************************************
* File Name: PreciseTimeDelayClk.h
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

#if !defined(CY_CLOCK_PreciseTimeDelayClk_H)
#define CY_CLOCK_PreciseTimeDelayClk_H

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

void PreciseTimeDelayClk_Start(void) ;
void PreciseTimeDelayClk_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void PreciseTimeDelayClk_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void PreciseTimeDelayClk_StandbyPower(uint8 state) ;
void PreciseTimeDelayClk_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 PreciseTimeDelayClk_GetDividerRegister(void) ;
void PreciseTimeDelayClk_SetModeRegister(uint8 modeBitMask) ;
void PreciseTimeDelayClk_ClearModeRegister(uint8 modeBitMask) ;
uint8 PreciseTimeDelayClk_GetModeRegister(void) ;
void PreciseTimeDelayClk_SetSourceRegister(uint8 clkSource) ;
uint8 PreciseTimeDelayClk_GetSourceRegister(void) ;
#if defined(PreciseTimeDelayClk__CFG3)
void PreciseTimeDelayClk_SetPhaseRegister(uint8 clkPhase) ;
uint8 PreciseTimeDelayClk_GetPhaseRegister(void) ;
#endif /* defined(PreciseTimeDelayClk__CFG3) */

#define PreciseTimeDelayClk_Enable()                       PreciseTimeDelayClk_Start()
#define PreciseTimeDelayClk_Disable()                      PreciseTimeDelayClk_Stop()
#define PreciseTimeDelayClk_SetDivider(clkDivider)         PreciseTimeDelayClk_SetDividerRegister(clkDivider, 1)
#define PreciseTimeDelayClk_SetDividerValue(clkDivider)    PreciseTimeDelayClk_SetDividerRegister((clkDivider) - 1, 1)
#define PreciseTimeDelayClk_SetMode(clkMode)               PreciseTimeDelayClk_SetModeRegister(clkMode)
#define PreciseTimeDelayClk_SetSource(clkSource)           PreciseTimeDelayClk_SetSourceRegister(clkSource)
#if defined(PreciseTimeDelayClk__CFG3)
#define PreciseTimeDelayClk_SetPhase(clkPhase)             PreciseTimeDelayClk_SetPhaseRegister(clkPhase)
#define PreciseTimeDelayClk_SetPhaseValue(clkPhase)        PreciseTimeDelayClk_SetPhaseRegister((clkPhase) + 1)
#endif /* defined(PreciseTimeDelayClk__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define PreciseTimeDelayClk_CLKEN              (* (reg8 *) PreciseTimeDelayClk__PM_ACT_CFG)
#define PreciseTimeDelayClk_CLKEN_PTR          ((reg8 *) PreciseTimeDelayClk__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define PreciseTimeDelayClk_CLKSTBY            (* (reg8 *) PreciseTimeDelayClk__PM_STBY_CFG)
#define PreciseTimeDelayClk_CLKSTBY_PTR        ((reg8 *) PreciseTimeDelayClk__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define PreciseTimeDelayClk_DIV_LSB            (* (reg8 *) PreciseTimeDelayClk__CFG0)
#define PreciseTimeDelayClk_DIV_LSB_PTR        ((reg8 *) PreciseTimeDelayClk__CFG0)
#define PreciseTimeDelayClk_DIV_PTR            ((reg16 *) PreciseTimeDelayClk__CFG0)

/* Clock MSB divider configuration register. */
#define PreciseTimeDelayClk_DIV_MSB            (* (reg8 *) PreciseTimeDelayClk__CFG1)
#define PreciseTimeDelayClk_DIV_MSB_PTR        ((reg8 *) PreciseTimeDelayClk__CFG1)

/* Mode and source configuration register */
#define PreciseTimeDelayClk_MOD_SRC            (* (reg8 *) PreciseTimeDelayClk__CFG2)
#define PreciseTimeDelayClk_MOD_SRC_PTR        ((reg8 *) PreciseTimeDelayClk__CFG2)

#if defined(PreciseTimeDelayClk__CFG3)
/* Analog clock phase configuration register */
#define PreciseTimeDelayClk_PHASE              (* (reg8 *) PreciseTimeDelayClk__CFG3)
#define PreciseTimeDelayClk_PHASE_PTR          ((reg8 *) PreciseTimeDelayClk__CFG3)
#endif /* defined(PreciseTimeDelayClk__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define PreciseTimeDelayClk_CLKEN_MASK         PreciseTimeDelayClk__PM_ACT_MSK
#define PreciseTimeDelayClk_CLKSTBY_MASK       PreciseTimeDelayClk__PM_STBY_MSK

/* CFG2 field masks */
#define PreciseTimeDelayClk_SRC_SEL_MSK        PreciseTimeDelayClk__CFG2_SRC_SEL_MASK
#define PreciseTimeDelayClk_MODE_MASK          (~(PreciseTimeDelayClk_SRC_SEL_MSK))

#if defined(PreciseTimeDelayClk__CFG3)
/* CFG3 phase mask */
#define PreciseTimeDelayClk_PHASE_MASK         PreciseTimeDelayClk__CFG3_PHASE_DLY_MASK
#endif /* defined(PreciseTimeDelayClk__CFG3) */

#endif /* CY_CLOCK_PreciseTimeDelayClk_H */


/* [] END OF FILE */
