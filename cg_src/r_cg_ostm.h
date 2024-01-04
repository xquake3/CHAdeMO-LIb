/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2015, 2018 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_ostm.h
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for OSTM module.
* Creation Date: 07-06-2023
***********************************************************************************************************************/
#ifndef OSTM_H
#define OSTM_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/*
    OSTM Count Start Trigger Register (OSTMnTS)
*/
/* Starts the counter (OSTMnTS) */
#define _OSTM_COUNTER_START                       (0x01U) /* Starts the counter */

/*
    OSTM Count Stop Trigger Register (OSTMnTT)
*/
/* Stops the counter (OSTMnTT) */
#define _OSTM_COUNTER_STOP                        (0x01U) /* Stops the counter */

/*
    OSTM Control Register (OSTMnCTL)
*/
/* Specifies the operating mode for the counter (OSTMnMD1) */
#define _OSTM_MODE_INTERVAL_TIMER                 (0x00U) /* Interval timer mode */
#define _OSTM_MODE_FREE_RUNNING                   (0x02U) /* Free-running comparison mode */
/* Specifies the operating mode for the counter (OSTMnMD0) */
#define _OSTM_START_INTERRUPT_DISABLE             (0x00U) /* Disables the interrupts when counting starts */
#define _OSTM_START_INTERRUPT_ENABLE              (0x01U) /* Enables the interrupts when counting starts */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _OSTM_COMPARING_COUNTER                   (0x005B8D7FUL)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_OSTM0_Create(void);
void R_OSTM0_Start(void);
void R_OSTM0_Stop(void);
void R_OSTM0_Set_CompareValue(uint32_t value);

/* Start user code for function. Do not edit comment generated here */
extern uint32_t AUXchargeTimeStamper;
extern uint32_t ChargerSOCTimeStamper;
extern uint32_t SleepTimer;
extern uint32_t GuideMeHomeCounter;
extern uint32_t JuiceCounter ;
extern uint32_t JuinceInASecond ;
extern uint32_t DiagnosticBlinkCounter;
extern uint32_t wdtCounter;
extern uint16_t ChadSubTimeOut ;
extern volatile uint16_t ch0_max_value;
/* End user code. Do not edit comment generated here */
#endif