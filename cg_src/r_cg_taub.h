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
* File Name    : r_cg_taub.h
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for TAUB module.
* Creation Date: 07-06-2023
***********************************************************************************************************************/
#ifndef TAUB_H
#define TAUB_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    TAUBm Prescaler Clock Select Register (TAUBmTPS)
*/
/* Operating mode selection (TAUBmPRS3[3-0]) */
#define _TAUB_CK3_PRE_PCLK_0                                (0x0000U) /* CK3_PRE - PCLK/2^0 */
#define _TAUB_CK3_PRE_PCLK_1                                (0x1000U) /* CK3_PRE - PCLK/2^1 */
#define _TAUB_CK3_PRE_PCLK_2                                (0x2000U) /* CK3_PRE - PCLK/2^2 */
#define _TAUB_CK3_PRE_PCLK_3                                (0x3000U) /* CK3_PRE - PCLK/2^3 */
#define _TAUB_CK3_PRE_PCLK_4                                (0x4000U) /* CK3_PRE - PCLK/2^4 */
#define _TAUB_CK3_PRE_PCLK_5                                (0x5000U) /* CK3_PRE - PCLK/2^5 */
#define _TAUB_CK3_PRE_PCLK_6                                (0x6000U) /* CK3_PRE - PCLK/2^6 */
#define _TAUB_CK3_PRE_PCLK_7                                (0x7000U) /* CK3_PRE - PCLK/2^7 */
#define _TAUB_CK3_PRE_PCLK_8                                (0x8000U) /* CK3_PRE - PCLK/2^8 */
#define _TAUB_CK3_PRE_PCLK_9                                (0x9000U) /* CK3_PRE - PCLK/2^9 */
#define _TAUB_CK3_PRE_PCLK_10                               (0xA000U) /* CK3_PRE - PCLK/2^10 */
#define _TAUB_CK3_PRE_PCLK_11                               (0xB000U) /* CK3_PRE - PCLK/2^11 */
#define _TAUB_CK3_PRE_PCLK_12                               (0xC000U) /* CK3_PRE - PCLK/2^12 */
#define _TAUB_CK3_PRE_PCLK_13                               (0xD000U) /* CK3_PRE - PCLK/2^13 */
#define _TAUB_CK3_PRE_PCLK_14                               (0xE000U) /* CK3_PRE - PCLK/2^14 */
#define _TAUB_CK3_PRE_PCLK_15                               (0xF000U) /* CK3_PRE - PCLK/2^15 */
/* Operating mode selection (TAUBmPRS2[3-0]) */
#define _TAUB_CK2_PRE_PCLK_0                                (0x0000U) /* CK2_PRE - PCLK/2^0 */
#define _TAUB_CK2_PRE_PCLK_1                                (0x0100U) /* CK2_PRE - PCLK/2^1 */
#define _TAUB_CK2_PRE_PCLK_2                                (0x0200U) /* CK2_PRE - PCLK/2^2 */
#define _TAUB_CK2_PRE_PCLK_3                                (0x0300U) /* CK2_PRE - PCLK/2^3 */
#define _TAUB_CK2_PRE_PCLK_4                                (0x0400U) /* CK2_PRE - PCLK/2^4 */
#define _TAUB_CK2_PRE_PCLK_5                                (0x0500U) /* CK2_PRE - PCLK/2^5 */
#define _TAUB_CK2_PRE_PCLK_6                                (0x0600U) /* CK2_PRE - PCLK/2^6 */
#define _TAUB_CK2_PRE_PCLK_7                                (0x0700U) /* CK2_PRE - PCLK/2^7 */
#define _TAUB_CK2_PRE_PCLK_8                                (0x0800U) /* CK2_PRE - PCLK/2^8 */
#define _TAUB_CK2_PRE_PCLK_9                                (0x0900U) /* CK2_PRE - PCLK/2^9 */
#define _TAUB_CK2_PRE_PCLK_10                               (0x0A00U) /* CK2_PRE - PCLK/2^10 */
#define _TAUB_CK2_PRE_PCLK_11                               (0x0B00U) /* CK2_PRE - PCLK/2^11 */
#define _TAUB_CK2_PRE_PCLK_12                               (0x0C00U) /* CK2_PRE - PCLK/2^12 */
#define _TAUB_CK2_PRE_PCLK_13                               (0x0D00U) /* CK2_PRE - PCLK/2^13 */
#define _TAUB_CK2_PRE_PCLK_14                               (0x0E00U) /* CK2_PRE - PCLK/2^14 */
#define _TAUB_CK2_PRE_PCLK_15                               (0x0F00U) /* CK2_PRE - PCLK/2^15 */
/* Operating mode selection (TAUBmPRS1[3-0]) */
#define _TAUB_CK1_PRE_PCLK_0                                (0x0000U) /* CK1_PRE - PCLK/2^0 */
#define _TAUB_CK1_PRE_PCLK_1                                (0x0010U) /* CK1_PRE - PCLK/2^1 */
#define _TAUB_CK1_PRE_PCLK_2                                (0x0020U) /* CK1_PRE - PCLK/2^2 */
#define _TAUB_CK1_PRE_PCLK_3                                (0x0030U) /* CK1_PRE - PCLK/2^3 */
#define _TAUB_CK1_PRE_PCLK_4                                (0x0040U) /* CK1_PRE - PCLK/2^4 */
#define _TAUB_CK1_PRE_PCLK_5                                (0x0050U) /* CK1_PRE - PCLK/2^5 */
#define _TAUB_CK1_PRE_PCLK_6                                (0x0060U) /* CK1_PRE - PCLK/2^6 */
#define _TAUB_CK1_PRE_PCLK_7                                (0x0070U) /* CK1_PRE - PCLK/2^7 */
#define _TAUB_CK1_PRE_PCLK_8                                (0x0080U) /* CK1_PRE - PCLK/2^8 */
#define _TAUB_CK1_PRE_PCLK_9                                (0x0090U) /* CK1_PRE - PCLK/2^9 */
#define _TAUB_CK1_PRE_PCLK_10                               (0x00A0U) /* CK1_PRE - PCLK/2^10 */
#define _TAUB_CK1_PRE_PCLK_11                               (0x00B0U) /* CK1_PRE - PCLK/2^11 */
#define _TAUB_CK1_PRE_PCLK_12                               (0x00C0U) /* CK1_PRE - PCLK/2^12 */
#define _TAUB_CK1_PRE_PCLK_13                               (0x00D0U) /* CK1_PRE - PCLK/2^13 */
#define _TAUB_CK1_PRE_PCLK_14                               (0x00E0U) /* CK1_PRE - PCLK/2^14 */
#define _TAUB_CK1_PRE_PCLK_15                               (0x00F0U) /* CK1_PRE - PCLK/2^15 */
/* Operating mode selection (TAUBmPRS0[3-0]) */
#define _TAUB_CK0_PRE_PCLK_0                                (0x0000U) /* CK0_PRE - PCLK/2^0 */
#define _TAUB_CK0_PRE_PCLK_1                                (0x0001U) /* CK0_PRE - PCLK/2^1 */
#define _TAUB_CK0_PRE_PCLK_2                                (0x0002U) /* CK0_PRE - PCLK/2^2 */
#define _TAUB_CK0_PRE_PCLK_3                                (0x0003U) /* CK0_PRE - PCLK/2^3 */
#define _TAUB_CK0_PRE_PCLK_4                                (0x0004U) /* CK0_PRE - PCLK/2^4 */
#define _TAUB_CK0_PRE_PCLK_5                                (0x0005U) /* CK0_PRE - PCLK/2^5 */
#define _TAUB_CK0_PRE_PCLK_6                                (0x0006U) /* CK0_PRE - PCLK/2^6 */
#define _TAUB_CK0_PRE_PCLK_7                                (0x0007U) /* CK0_PRE - PCLK/2^7 */
#define _TAUB_CK0_PRE_PCLK_8                                (0x0008U) /* CK0_PRE - PCLK/2^8 */
#define _TAUB_CK0_PRE_PCLK_9                                (0x0009U) /* CK0_PRE - PCLK/2^9 */
#define _TAUB_CK0_PRE_PCLK_10                               (0x000AU) /* CK0_PRE - PCLK/2^10 */
#define _TAUB_CK0_PRE_PCLK_11                               (0x000BU) /* CK0_PRE - PCLK/2^11 */
#define _TAUB_CK0_PRE_PCLK_12                               (0x000CU) /* CK0_PRE - PCLK/2^12 */
#define _TAUB_CK0_PRE_PCLK_13                               (0x000DU) /* CK0_PRE - PCLK/2^13 */
#define _TAUB_CK0_PRE_PCLK_14                               (0x000EU) /* CK0_PRE - PCLK/2^14 */
#define _TAUB_CK0_PRE_PCLK_15                               (0x000FU) /* CK0_PRE - PCLK/2^15 */

/*
    TAUBn Channel Mode OS Register (TAUBnCMORm)
*/
/* Selection of operation clock (TAUBnCKS[1-0]) */
#define _TAUB_SELECTION_CK0                                 (0x0000U) /* CK0 */
#define _TAUB_SELECTION_CK1                                 (0x4000U) /* CK1 */
#define _TAUB_SELECTION_CK2                                 (0x8000U) /* CK2 */
#define _TAUB_SELECTION_CK3                                 (0xC000U) /* CK3 */
/* Selects the count clock for TAUBnCNTm counter (TAUBnCCS[1-0]) */
#define _TAUB_OPERATION_CLOCK                               (0x0000U) /* Operation clock as specified by TAUBnCMORm */
#define _TAUB_CLOCK_VALID_EDGE_SOFTWARE                     (0x1000U) /* Valid edge of TAUBTTINm input signal */
/* A channel during synchronous channel operation (TAUBnMAS) */
#define _TAUB_INDEPENDENT_CHANNEL                           (0x0000U) /* Slave */
#define _TAUB_SLAVE_CHANNEL                                 (0x0000U) /* Slave */
#define _TAUB_MASTER_CHANNEL                                (0x0800U) /* Master */
/* Selects the external start trigger (TAUBnSTS[2-0]) */
#define _TAUB_SOFTWARE_TRIGGER                              (0x0000U) /* Software trigger */
#define _TAUB_VALID_EDGE_SOFTWARE                           (0x0100U) /* Valid edge of the TAUBTTINm input signal. */
#define _TAUB_VALID_REVERSE_EDGE_HARDWARE                   (0x0200U) /* The tart trigger and the reverse edge is the stop trigger */
#define _TAUB_MASTER_START                                  (0x0400U) /* INTTAUBnIm is the start trigger of master channel */
#define _TAUB_MASTER_SETTING                                (0x0500U) /* INTTAUBnIm is the start trigger regardless of master setting */
#define _TAUB_OUTPUT_UPPER                                  (0x0600U) /* Dead time output signal of TAUBTTOUTm generating unit */
#define _TAUB_MASTER_OUTPUT_TRIGGER_SIGNAL                  (0x0700U) /* Up/down output trigger signal of master channel */
/* Specifies the timing for updating capture register (TAUBnCOS[1-0]) */
#define _TAUB_OVERFLOW_AUTO_CLEAR                           (0x0000U) /* TAUBnCDRm update upon detection of edge of TAUBTTINm and TAUBnOVF update */
#define _TAUB_OVERFLOW_MANUAL_CLEAR                         (0x0040U) /* TAUBnCDRm update upon detection of edge of TAUBTTINm and TAUBnOVF is set */
#define _TAUB_OVERFLOW_COUNT_STOP                           (0x0080U) /* TAUBnCDRm update upon detection of edge of TAUBTTINm and at counter overflow, TAUBnOVF is not set */
#define _TAUB_OVERFLOW_COUNT_STOP_MANUAL_CLEAR              (0x00C0U) /* TAUBnCDRm update upon detection of edge of TAUBTTINm and at counter overflow, TAUBnOVF is set */
/* Specifies an operating mode (TAUBnMD[4-0]) */
#define _TAUB_INTERVAL_TIMER_MODE                           (0x0000U) /* Interval timer mode */
#define _TAUB_JUDGE_MODE                                    (0x0002U) /* Judge mode */
#define _TAUB_CAPTURE_MODE                                  (0x0004U) /* Capture mode */
#define _TAUB_EVEVT_COUNT_MODE                              (0x0006U) /* Event count mode */
#define _TAUB_ONE_COUNT_MODE                                (0x0008U) /* One-count mode */
#define _TAUB_CAPTURE_ONE_COUNT_MODE                        (0x000CU) /* Capture and one-count mode */
#define _TAUB_JUDGE_ONE_COUNT_MODE                          (0x000EU) /* Judge and one-count mode */
#define _TAUB_COUNT_UP_DOWN_MODE                            (0x0012U) /* Count-up/-down mode  */
#define _TAUB_PULSE_ONECOUNT_MODE                           (0x0014U) /* Pulse one-count mode */
#define _TAUB_COUNT_CAPTURE_MODE                            (0x0016U) /* Count capture mode  */
#define _TAUB_GATE_COUNT_MODE                               (0x0018U) /* Gate count mode */
#define _TAUB_CAPTURE_AND_GATE_COUNT_MODE                   (0x001AU) /* Capture and gate count mode  */
/* Role of TAUBnMD0 Bit (TAUBnMD0) */
#define _TAUB_START_INT_NOT_GENERATED                       (0x0000U) /* INTTAUBnIm is not generated */
#define _TAUB_START_TRIGGER_DISABLE                         (0x0000U) /* Disables detection. */
#define _TAUB_OUTPUT_IN_SIGNAL_WIDTH                        (0x0000U) /* TAUB output in signal width */
#define _TAUB_START_INT_GENERATED                           (0x0001U) /* INTTAUBnIm is generated */
#define _TAUB_START_TRIGGER_ENABLE                          (0x0001U) /* Enables detection. */
#define _TAUB_OUTPUT_OVER_SIGNAL_WIDTH                      (0x0001U) /* TAUB output over signal width */

/*
    TAUBn Channel Mode User Register (TAUBnCMURm)
*/
/* Specifies a valid edge of TAUBTTINm input signal (TAUBnTIS[1-0]) */
#define _TAUB_INPUT_EDGE_UNUSED                             (0x00U) /* Unused Falling edge */
#define _TAUB_INPUT_EDGE_FALLING                            (0x00U) /* Falling edge */
#define _TAUB_INPUT_EDGE_RISING                             (0x01U) /* Rising edge */
#define _TAUB_INPUT_EDGE_BOTH_MEASURE_LOW                   (0x02U) /* Detection of rising and falling edges (selects low width measurement) */
#define _TAUB_INPUT_EDGE_BOTH_MEASURE_HIGH                  (0x03U) /* Detection of rising and falling edges (selects high width measurement) */

/*
    TAUBn Channel Start Trigger Register (TAUBnTS)
*/
/* Enables the counter operation of channel 15 (TAUBnTS15) */
#define _TAUB_CHANNEL15_COUNTER_START                       (0x8000U) /* Enables the counter operation */
/* Enables the counter operation of channel 14 (TAUBnTS14) */
#define _TAUB_CHANNEL14_COUNTER_START                       (0x4000U) /* Enables the counter operation */
/* Enables the counter operation of channel 13 (TAUBnTS13) */
#define _TAUB_CHANNEL13_COUNTER_START                       (0x2000U) /* Enables the counter operation */
/* Enables the counter operation of channel 12 (TAUBnTS12) */
#define _TAUB_CHANNEL12_COUNTER_START                       (0x1000U) /* Enables the counter operation */
/* Enables the counter operation of channel 11 (TAUBnTS11) */
#define _TAUB_CHANNEL11_COUNTER_START                       (0x0800U) /* Enables the counter operation */
/* Enables the counter operation of channel 10 (TAUBnTS10) */
#define _TAUB_CHANNEL10_COUNTER_START                       (0x0400U) /* Enables the counter operation */
/* Enables the counter operation of channel 9 (TAUBnTS09) */
#define _TAUB_CHANNEL9_COUNTER_START                        (0x0200U) /* Enables the counter operation */
/* Enables the counter operation of channel 8 (TAUBnTS08) */
#define _TAUB_CHANNEL8_COUNTER_START                        (0x0100U) /* Enables the counter operation */
/* Enables the counter operation of channel 7 (TAUBnTS07) */
#define _TAUB_CHANNEL7_COUNTER_START                        (0x0080U) /* Enables the counter operation */
/* Enables the counter operation of channel 6 (TAUBnTS06) */
#define _TAUB_CHANNEL6_COUNTER_START                        (0x0040U) /* Enables the counter operation */
/* Enables the counter operation of channel 5 (TAUBnTS05) */
#define _TAUB_CHANNEL5_COUNTER_START                        (0x0020U) /* Enables the counter operation */
/* Enables the counter operation of channel 4 (TAUBnTS04) */
#define _TAUB_CHANNEL4_COUNTER_START                        (0x0010U) /* Enables the counter operation */
/* Enables the counter operation of channel 3 (TAUBnTS03) */
#define _TAUB_CHANNEL3_COUNTER_START                        (0x0008U) /* Enables the counter operation */
/* Enables the counter operation of channel 2 (TAUBnTS02) */
#define _TAUB_CHANNEL2_COUNTER_START                        (0x0004U) /* Enables the counter operation */
/* Enables the counter operation of channel 1 (TAUBnTS01) */
#define _TAUB_CHANNEL1_COUNTER_START                        (0x0002U) /* Enables the counter operation */
/* Enables the counter operation of channel 0 (TAUBnTS00) */
#define _TAUB_CHANNEL0_COUNTER_START                        (0x0001U) /* Enables the counter operation */

/*
    TAUBn Channel Stop Trigger Register (TAUBnTT)
*/
/* Stops the counter operation of channel 15 (TAUBnTT15) */
#define _TAUB_CHANNEL15_COUNTER_STOP                        (0x8000U) /* Stops the counter operation */
/* Stops the counter operation of channel 14 (TAUBnTT14) */
#define _TAUB_CHANNEL14_COUNTER_STOP                        (0x4000U) /* Stops the counter operation */
/* Stops the counter operation of channel 13 (TAUBnTT13) */
#define _TAUB_CHANNEL13_COUNTER_STOP                        (0x2000U) /* Stops the counter operation */
/* Stops the counter operation of channel 12 (TAUBnTT12) */
#define _TAUB_CHANNEL12_COUNTER_STOP                        (0x1000U) /* Stops the counter operation */
/* Stops the counter operation of channel 11 (TAUBnTT11) */
#define _TAUB_CHANNEL11_COUNTER_STOP                        (0x0800U) /* Stops the counter operation */
/* Stops the counter operation of channel 10 (TAUBnTT10) */
#define _TAUB_CHANNEL10_COUNTER_STOP                        (0x0400U) /* Stops the counter operation  */
/* Stops the counter operation of channel 9 (TAUBnTT9) */
#define _TAUB_CHANNEL9_COUNTER_STOP                         (0x0200U) /* Stops the counter operation */
/* Stops the counter operation of channel 8 (TAUBnTT8) */
#define _TAUB_CHANNEL8_COUNTER_STOP                         (0x0100U) /* Stops the counter operation */
/* Stops the counter operation of channel 7 (TAUBnTT7) */
#define _TAUB_CHANNEL7_COUNTER_STOP                         (0x0080U) /* Stops the counter operation */
/* Stops the counter operation of channel 6 (TAUBnTT6) */
#define _TAUB_CHANNEL6_COUNTER_STOP                         (0x0040U) /* Stops the counter operation */
/* Stops the counter operation of channel 5 (TAUBnTT5) */
#define _TAUB_CHANNEL5_COUNTER_STOP                         (0x0020U) /* Stops the counter operation */
/* Stops the counter operation of channel 4 (TAUBnTT4) */
#define _TAUB_CHANNEL4_COUNTER_STOP                         (0x0010U) /* Stops the counter operation */
/* Stops the counter operation of channel 3 (TAUBnTT3) */
#define _TAUB_CHANNEL3_COUNTER_STOP                         (0x0008U) /* Stops the counter operation */
/* Stops the counter operation of channel 2 (TAUBnTT2) */
#define _TAUB_CHANNEL2_COUNTER_STOP                         (0x0004U) /* Stops the counter operation */
/* Stops the counter operation of channel 1 (TAUBnTT1) */
#define _TAUB_CHANNEL1_COUNTER_STOP                         (0x0002U) /* Stops the counter operation */
/* Stops the counter operation of channel 0 (TAUBnTT0) */
#define _TAUB_CHANNEL0_COUNTER_STOP                         (0x0001U) /* Stops the counter operation */

/*
    TAUBn Channel Output Enable Register (TAUBnTOE)
*/
/* Enables/disables the independent channel output mode (TAUBnTOE15) */
#define _TAUB_CHANNEL15_DISABLES_OUTPUT_MODE                (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL15_ENABLES_OUTPUT_MODE                 (0x8000U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE14) */
#define _TAUB_CHANNEL14_DISABLES_OUTPUT_MODE                (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL14_ENABLES_OUTPUT_MODE                 (0x4000U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE13) */
#define _TAUB_CHANNEL13_DISABLES_OUTPUT_MODE                (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL13_ENABLES_OUTPUT_MODE                 (0x2000U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE12) */
#define _TAUB_CHANNEL12_DISABLES_OUTPUT_MODE                (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL12_ENABLES_OUTPUT_MODE                 (0x1000U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE11) */
#define _TAUB_CHANNEL11_DISABLES_OUTPUT_MODE                (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL11_ENABLES_OUTPUT_MODE                 (0x0800U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE10) */
#define _TAUB_CHANNEL10_DISABLES_OUTPUT_MODE                (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL10_ENABLES_OUTPUT_MODE                 (0x0400U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE9) */
#define _TAUB_CHANNEL9_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL9_ENABLES_OUTPUT_MODE                  (0x0200U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE8) */
#define _TAUB_CHANNEL8_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL8_ENABLES_OUTPUT_MODE                  (0x0100U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE7) */
#define _TAUB_CHANNEL7_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL7_ENABLES_OUTPUT_MODE                  (0x0080U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE6) */
#define _TAUB_CHANNEL6_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL6_ENABLES_OUTPUT_MODE                  (0x0040U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE5) */
#define _TAUB_CHANNEL5_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL5_ENABLES_OUTPUT_MODE                  (0x0020U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE4) */
#define _TAUB_CHANNEL4_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL4_ENABLES_OUTPUT_MODE                  (0x0010U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE3) */
#define _TAUB_CHANNEL3_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL3_ENABLES_OUTPUT_MODE                  (0x0008U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE2) */
#define _TAUB_CHANNEL2_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL2_ENABLES_OUTPUT_MODE                  (0x0004U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE1) */
#define _TAUB_CHANNEL1_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL1_ENABLES_OUTPUT_MODE                  (0x0002U) /* Enables independent channel output mode */
/* Enables/disables the independent channel output function (TAUBnTOE0) */
#define _TAUB_CHANNEL0_DISABLES_OUTPUT_MODE                 (0x0000U) /* Disables independent channel output mode */
#define _TAUB_CHANNEL0_ENABLES_OUTPUT_MODE                  (0x0001U) /* Enables independent channel output mode */

/*
    TAUBn Channel Output Mode Register (TAUBnTOM)
*/
/* Specifies the channel output mode (TAUBnTOM15) */
#define _TAUB_CHANNEL15_INDEPENDENT_OUTPUT_MODE             (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL15_SYNCHRONOUS_OUTPUT_MODE             (0x8000U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM14) */
#define _TAUB_CHANNEL14_INDEPENDENT_OUTPUT_MODE             (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL14_SYNCHRONOUS_OUTPUT_MODE             (0x4000U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM13) */
#define _TAUB_CHANNEL13_INDEPENDENT_OUTPUT_MODE             (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL13_SYNCHRONOUS_OUTPUT_MODE             (0x2000U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM12) */
#define _TAUB_CHANNEL12_INDEPENDENT_OUTPUT_MODE             (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL12_SYNCHRONOUS_OUTPUT_MODE             (0x1000U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM11) */
#define _TAUB_CHANNEL11_INDEPENDENT_OUTPUT_MODE             (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL11_SYNCHRONOUS_OUTPUT_MODE             (0x0800U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM10) */
#define _TAUB_CHANNEL10_INDEPENDENT_OUTPUT_MODE             (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL10_SYNCHRONOUS_OUTPUT_MODE             (0x0400U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM9) */
#define _TAUB_CHANNEL9_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL9_SYNCHRONOUS_OUTPUT_MODE              (0x0200U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM8) */
#define _TAUB_CHANNEL8_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL8_SYNCHRONOUS_OUTPUT_MODE              (0x0100U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM7) */
#define _TAUB_CHANNEL7_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL7_SYNCHRONOUS_OUTPUT_MODE              (0x0080U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM6) */
#define _TAUB_CHANNEL6_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL6_SYNCHRONOUS_OUTPUT_MODE              (0x0040U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM5) */
#define _TAUB_CHANNEL5_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL5_SYNCHRONOUS_OUTPUT_MODE              (0x0020U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM4) */
#define _TAUB_CHANNEL4_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL4_SYNCHRONOUS_OUTPUT_MODE              (0x0010U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM3) */
#define _TAUB_CHANNEL3_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL3_SYNCHRONOUS_OUTPUT_MODE              (0x0008U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM2) */
#define _TAUB_CHANNEL2_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL2_SYNCHRONOUS_OUTPUT_MODE              (0x0004U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM1) */
#define _TAUB_CHANNEL1_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL1_SYNCHRONOUS_OUTPUT_MODE              (0x0002U) /* Synchronous channel output mode */
/* Specifies the channel output mode (TAUBnTOM0) */
#define _TAUB_CHANNEL0_INDEPENDENT_OUTPUT_MODE              (0x0000U) /* Independent channel output mode */
#define _TAUB_CHANNEL0_SYNCHRONOUS_OUTPUT_MODE              (0x0001U) /* Synchronous channel output mode */

/*
    TAUBn Channel Output Configuration Register (TAUBnTOC)
*/
/* Specifies the output mode (TAUBnTOC15) */
#define _TAUB_CHANNEL15_OPERATION_MODE1                     (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL15_OPERATION_MODE2                     (0x8000U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC14) */
#define _TAUB_CHANNEL14_OPERATION_MODE1                     (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL14_OPERATION_MODE2                     (0x4000U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC13) */
#define _TAUB_CHANNEL13_OPERATION_MODE1                     (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL13_OPERATION_MODE2                     (0x2000U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC12) */
#define _TAUB_CHANNEL12_OPERATION_MODE1                     (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL12_OPERATION_MODE2                     (0x1000U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC11) */
#define _TAUB_CHANNEL11_OPERATION_MODE1                     (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL11_OPERATION_MODE2                     (0x0800U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC10) */
#define _TAUB_CHANNEL10_OPERATION_MODE1                     (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL10_OPERATION_MODE2                     (0x0400U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC9) */
#define _TAUB_CHANNEL9_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL9_OPERATION_MODE2                      (0x0200U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC8) */
#define _TAUB_CHANNEL8_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL8_OPERATION_MODE2                      (0x0100U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC7) */
#define _TAUB_CHANNEL7_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL7_OPERATION_MODE2                      (0x0080U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC6) */
#define _TAUB_CHANNEL6_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL6_OPERATION_MODE2                      (0x0040U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC5) */
#define _TAUB_CHANNEL5_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL5_OPERATION_MODE2                      (0x0020U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC4) */
#define _TAUB_CHANNEL4_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL4_OPERATION_MODE2                      (0x0010U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC3) */
#define _TAUB_CHANNEL3_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL3_OPERATION_MODE2                      (0x0008U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC2) */
#define _TAUB_CHANNEL2_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL2_OPERATION_MODE2                      (0x0004U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC1) */
#define _TAUB_CHANNEL1_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL1_OPERATION_MODE2                      (0x0002U) /* Operation mode 2 */
/* Specifies the output mode (TAUBnTOC0) */
#define _TAUB_CHANNEL0_OPERATION_MODE1                      (0x0000U) /* Operation mode 1 */
#define _TAUB_CHANNEL0_OPERATION_MODE2                      (0x0001U) /* Operation mode 2 */

/*
    TAUBn Channel Output Level Register (TAUBnTOL)
*/
/* Specifies the output logic of channel 15 output bit (TAUBnTOL15) */
#define _TAUB_CHANNEL15_POSITIVE_LOGIC                      (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL15_NEGATIVE_LOGIC                      (0x8000U) /* Negative logic */
/* Specifies the output logic of channel 14 output bit (TAUBnTOL14) */
#define _TAUB_CHANNEL14_POSITIVE_LOGIC                      (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL14_NEGATIVE_LOGIC                      (0x4000U) /* Negative logic */
/* Specifies the output logic of channel 13 output bit (TAUBnTOL13) */
#define _TAUB_CHANNEL13_POSITIVE_LOGIC                      (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL13_NEGATIVE_LOGIC                      (0x2000U) /* Negative logic */
/* Specifies the output logic of channel 12 output bit (TAUBnTOL12) */
#define _TAUB_CHANNEL12_POSITIVE_LOGIC                      (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL12_NEGATIVE_LOGIC                      (0x1000U) /* Negative logic */
/* Specifies the output logic of channel 11 output bit (TAUBnTOL11) */
#define _TAUB_CHANNEL11_POSITIVE_LOGIC                      (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL11_NEGATIVE_LOGIC                      (0x0800U) /* Negative logic */
/* Specifies the output logic of channel 10 output bit (TAUBnTOL10) */
#define _TAUB_CHANNEL10_POSITIVE_LOGIC                      (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL10_NEGATIVE_LOGIC                      (0x0400U) /* Negative logic */
/* Specifies the output logic of channel 9 output bit (TAUBnTOL9) */
#define _TAUB_CHANNEL9_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL9_NEGATIVE_LOGIC                       (0x0200U) /* Negative logic */
/* Specifies the output logic of channel 8 output bit (TAUBnTOL8) */
#define _TAUB_CHANNEL8_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL8_NEGATIVE_LOGIC                       (0x0100U) /* Negative logic */
/* Specifies the output logic of channel 7 output bit (TAUBnTOL7) */
#define _TAUB_CHANNEL7_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL7_NEGATIVE_LOGIC                       (0x0080U) /* Negative logic */
/* Specifies the output logic of channel 6 output bit (TAUBnTOL6) */
#define _TAUB_CHANNEL6_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL6_NEGATIVE_LOGIC                       (0x0040U) /* Negative logic */
/* Specifies the output logic of channel 5 output bit (TAUBnTOL5) */
#define _TAUB_CHANNEL5_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL5_NEGATIVE_LOGIC                       (0x0020U) /* Negative logic */
/* Specifies the output logic of channel 4 output bit (TAUBnTOL4) */
#define _TAUB_CHANNEL4_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL4_NEGATIVE_LOGIC                       (0x0010U) /* Negative logic */
/* Specifies the output logic of channel 3 output bit (TAUBnTOL3) */
#define _TAUB_CHANNEL3_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL3_NEGATIVE_LOGIC                       (0x0008U) /* Negative logic */
/* Specifies the output logic of channel 2 output bit (TAUBnTOL2) */
#define _TAUB_CHANNEL2_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL2_NEGATIVE_LOGIC                       (0x0004U) /* Negative logic */
/* Specifies the output logic of channel 1 output bit (TAUBnTOL1) */
#define _TAUB_CHANNEL1_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL1_NEGATIVE_LOGIC                       (0x0002U) /* Negative logic */
/* Specifies the output logic of channel 0 output bit (TAUBnTOL0) */
#define _TAUB_CHANNEL0_POSITIVE_LOGIC                       (0x0000U) /* Positive logic */
#define _TAUB_CHANNEL0_NEGATIVE_LOGIC                       (0x0001U) /* Negative logic */

/*
    TAUBn Channel Dead Time Output Enable Register (TAUBnTDE)
*/
/* Enables/disables the dead time control operation of channel 15 (TAUBnTDE15) */
#define _TAUB_CHANNEL15_DISABLE_DEAD_TIME_OPERATE           (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL15_ENABLE_DEAD_TIME_OPERATE            (0x8000U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 14 (TAUBnTDE14) */
#define _TAUB_CHANNEL14_DISABLE_DEAD_TIME_OPERATE           (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL14_ENABLE_DEAD_TIME_OPERATE            (0x4000U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 13 (TAUBnTDE13) */
#define _TAUB_CHANNEL13_DISABLE_DEAD_TIME_OPERATE           (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL13_ENABLE_DEAD_TIME_OPERATE            (0x2000U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 12 (TAUBnTDE12) */
#define _TAUB_CHANNEL12_DISABLE_DEAD_TIME_OPERATE           (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL12_ENABLE_DEAD_TIME_OPERATE            (0x1000U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 11 (TAUBnTDE11) */
#define _TAUB_CHANNEL11_DISABLE_DEAD_TIME_OPERATE           (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL11_ENABLE_DEAD_TIME_OPERATE            (0x0800U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 10 (TAUBnTDE10) */
#define _TAUB_CHANNEL10_DISABLE_DEAD_TIME_OPERATE           (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL10_ENABLE_DEAD_TIME_OPERATE            (0x0400U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 9 (TAUBnTDE9) */
#define _TAUB_CHANNEL9_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL9_ENABLE_DEAD_TIME_OPERATE             (0x0200U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 8 (TAUBnTDE8) */
#define _TAUB_CHANNEL8_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL8_ENABLE_DEAD_TIME_OPERATE             (0x0100U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 7 (TAUBnTDE7) */
#define _TAUB_CHANNEL7_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL7_ENABLE_DEAD_TIME_OPERATE             (0x0080U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 6 (TAUBnTDE6) */
#define _TAUB_CHANNEL6_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL6_ENABLE_DEAD_TIME_OPERATE             (0x0040U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 5 (TAUBnTDE5) */
#define _TAUB_CHANNEL5_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL5_ENABLE_DEAD_TIME_OPERATE             (0x0020U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 4 (TAUBnTDE4) */
#define _TAUB_CHANNEL4_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL4_ENABLE_DEAD_TIME_OPERATE             (0x0010U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 3 (TAUBnTDE3) */
#define _TAUB_CHANNEL3_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL3_ENABLE_DEAD_TIME_OPERATE             (0x0008U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 2 (TAUBnTDE2) */
#define _TAUB_CHANNEL2_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL2_ENABLE_DEAD_TIME_OPERATE             (0x0004U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 1 (TAUBnTDE1) */
#define _TAUB_CHANNEL1_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL1_ENABLE_DEAD_TIME_OPERATE             (0x0002U) /* Enables dead time operation */
/* Enables/disables the dead time control operation of channel 0 (TAUBnTDE0) */
#define _TAUB_CHANNEL0_DISABLE_DEAD_TIME_OPERATE            (0x0000U) /* Disables dead time operation */
#define _TAUB_CHANNEL0_ENABLE_DEAD_TIME_OPERATE             (0x0001U) /* Enables dead time operation */

/*
    TAUBn Channel Dead Time Output Level Register (TAUBnTDL)
*/
/* Selects a phase in which dead time is added (TAUBnTDL15) */
#define _TAUB_CHANNEL15_POSITIVE_PHASE_PERIOD               (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL15_NEGATIVE_PHASE_PERIOD               (0x8000U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL14) */
#define _TAUB_CHANNEL14_POSITIVE_PHASE_PERIOD               (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL14_NEGATIVE_PHASE_PERIOD               (0x4000U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL13) */
#define _TAUB_CHANNEL13_POSITIVE_PHASE_PERIOD               (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL13_NEGATIVE_PHASE_PERIOD               (0x2000U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL12) */
#define _TAUB_CHANNEL12_POSITIVE_PHASE_PERIOD               (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL12_NEGATIVE_PHASE_PERIOD               (0x1000U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL11) */
#define _TAUB_CHANNEL11_POSITIVE_PHASE_PERIOD               (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL11_NEGATIVE_PHASE_PERIOD               (0x0800U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL10) */
#define _TAUB_CHANNEL10_POSITIVE_PHASE_PERIOD               (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL10_NEGATIVE_PHASE_PERIOD               (0x0400U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL9) */
#define _TAUB_CHANNEL9_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL9_NEGATIVE_PHASE_PERIOD                (0x0200U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL8) */
#define _TAUB_CHANNEL8_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL8_NEGATIVE_PHASE_PERIOD                (0x0100U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL7) */
#define _TAUB_CHANNEL7_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL7_NEGATIVE_PHASE_PERIOD                (0x0080U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL6) */
#define _TAUB_CHANNEL6_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL6_NEGATIVE_PHASE_PERIOD                (0x0040U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL5) */
#define _TAUB_CHANNEL5_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL5_NEGATIVE_PHASE_PERIOD                (0x0020U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL4) */
#define _TAUB_CHANNEL4_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL4_NEGATIVE_PHASE_PERIOD                (0x0010U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL3) */
#define _TAUB_CHANNEL3_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL3_NEGATIVE_PHASE_PERIOD                (0x0008U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL2) */
#define _TAUB_CHANNEL2_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL2_REVERSE_PHASE                        (0x0004U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL1) */
#define _TAUB_CHANNEL1_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL1_NEGATIVE_PHASE_PERIOD                (0x0002U) /* Negative phase period */
/* Selects a phase in which dead time is added (TAUBnTDL0) */
#define _TAUB_CHANNEL0_POSITIVE_PHASE_PERIOD                (0x0000U) /* Positive phase period */
#define _TAUB_CHANNEL0_NEGATIVE_PHASE_PERIOD                (0x0001U) /* Negative phase period */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _TAUB0_CHANNEL0_COMPARE_VALUE                       (0x0050U) /* Data register for compare values */
#define _TAUB0_CHANNEL1_COMPARE_VALUE                       (0x008CU) /* Data register for compare values */
#define _TAUB0_CHANNEL13_COMPARE_VALUE                      (0x0028U) /* Data register for compare values */
/* Overflow macro */
#define _TAUB_OVERFLOW_OCCURS                               (0x01U)    /* Overflow occurs */
#define _TAUB_OVERFLOW_VALUE                                (0x10000UL) /* Overflow value */
#define _TAUB_FILTER_ENABLED                                (0x01U)    /* Digital Noise Elimination Enable Control */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_TAUB0_Create(void);
void R_TAUB0_Channel0_Start(void);
void R_TAUB0_Channel0_Stop(void);
void R_TAUB0_Channel1_Start(void);
void R_TAUB0_Channel1_Stop(void);

/* Start user code for function. Do not edit comment generated here */
extern uint8_t enableOutFrameMaker;
extern uint16_t tsl_L_Amps;
extern uint16_t tsl_R_Amps;
extern uint32_t LastOdoCount;
extern uint32_t LastSOCwatHr;
extern uint8_t Stamping_50x;
extern uint32_t ChargerADC;
extern uint32_t ChargerADCSampler;
extern uint8_t can_group_180ms;
/* End user code. Do not edit comment generated here */
#endif