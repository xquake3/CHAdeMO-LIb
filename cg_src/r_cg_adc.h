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
* File Name    : r_cg_adc.h
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for ADCA module.
* Creation Date: 07-06-2023
***********************************************************************************************************************/
#ifndef ADCA_H
#define ADCA_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
#define _ADC0_VCHANNEL_DATA_BASE                  (0xFFF20100UL)
#define _ADC1_VCHANNEL_DATA_BASE                  (0xFFD6D100UL)
/*
    Virtual channel control register (ADCAnVCRm)
*/
/* A/D Conversion End Interrupt Enable. (ADIE) */
#define _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE      (0x00000000UL) /* not generated */
#define _ADC_VIRTUAL_CHANNEL_END_INT_ENABLE       (0x00000100UL) /* generated */
/* Upper limit/lower limit table select (ULS[1-0]) */
#define _ADC_LIMIT_TABLE_SELECT_NONE              (0x00000000UL) /* Upper limit and lower limit are not checked. */
#define _ADC_LIMIT_TABLE_SELECT_0                 (0x00000040UL) /* Upper limit and lower limit are checked for ULLMTBR0. */
#define _ADC_LIMIT_TABLE_SELECT_1                 (0x00000080UL) /* Upper limit and lower limit are checked for ULLMTBR1. */
#define _ADC_LIMIT_TABLE_SELECT_2                 (0x000000C0UL) /* Upper limit and lower limit are checked for ULLMTBR2. */
/* A/D conversion general control (GCTRL[5-0]) */
#define _ADC_PHYSICAL_CHANNEL_AN00                (0x00000000UL) /* AN00 */
#define _ADC_PHYSICAL_CHANNEL_AN01                (0x00000001UL) /* AN01 */
#define _ADC_PHYSICAL_CHANNEL_AN02                (0x00000002UL) /* AN02 */
#define _ADC_PHYSICAL_CHANNEL_AN03                (0x00000003UL) /* AN03 */
#define _ADC_PHYSICAL_CHANNEL_AN04                (0x00000004UL) /* AN04 */
#define _ADC_PHYSICAL_CHANNEL_AN05                (0x00000005UL) /* AN05 */
#define _ADC_PHYSICAL_CHANNEL_AN06                (0x00000006UL) /* AN06 */
#define _ADC_PHYSICAL_CHANNEL_AN07                (0x00000007UL) /* AN07 */
#define _ADC_PHYSICAL_CHANNEL_AN08                (0x00000008UL) /* AN08 */
#define _ADC_PHYSICAL_CHANNEL_AN09                (0x00000009UL) /* AN09 */
#define _ADC_PHYSICAL_CHANNEL_AN10                (0x0000000AUL) /* AN10 */
#define _ADC_PHYSICAL_CHANNEL_AN11                (0x0000000BUL) /* AN11 */
#define _ADC_PHYSICAL_CHANNEL_AN12                (0x0000000CUL) /* AN12 */
#define _ADC_PHYSICAL_CHANNEL_AN13                (0x0000000DUL) /* AN13 */
#define _ADC_PHYSICAL_CHANNEL_AN14                (0x0000000EUL) /* AN14 */
#define _ADC_PHYSICAL_CHANNEL_AN15                (0x0000000FUL) /* AN15 */
#define _ADC_PHYSICAL_CHANNEL_AN16                (0x00000010UL) /* AN16 */
#define _ADC_PHYSICAL_CHANNEL_AN17                (0x00000011UL) /* AN17 */
#define _ADC_PHYSICAL_CHANNEL_AN18                (0x00000012UL) /* AN18 */
#define _ADC_PHYSICAL_CHANNEL_AN19                (0x00000013UL) /* AN19 */
#define _ADC_PHYSICAL_CHANNEL_AN20                (0x00000014UL) /* AN20 */
#define _ADC_PHYSICAL_CHANNEL_AN21                (0x00000015UL) /* AN21 */
#define _ADC_PHYSICAL_CHANNEL_AN22                (0x00000016UL) /* AN22 */
#define _ADC_PHYSICAL_CHANNEL_AN23                (0x00000017UL) /* AN23 */
#define _ADC_PHYSICAL_CHANNEL_AN24                (0x00000018UL) /* AN24 */
#define _ADC_PHYSICAL_CHANNEL_AN25                (0x00000019UL) /* AN25 */
#define _ADC_PHYSICAL_CHANNEL_AN26                (0x0000001AUL) /* AN26 */
#define _ADC_PHYSICAL_CHANNEL_AN27                (0x0000001BUL) /* AN27 */
#define _ADC_PHYSICAL_CHANNEL_AN28                (0x0000001CUL) /* AN28 */
#define _ADC_PHYSICAL_CHANNEL_AN29                (0x0000001DUL) /* AN29 */
#define _ADC_PHYSICAL_CHANNEL_AN30                (0x0000001EUL) /* AN30 */
#define _ADC_PHYSICAL_CHANNEL_AN31                (0x0000001FUL) /* AN31 */
#define _ADC_PHYSICAL_CHANNEL_AN32                (0x00000020UL) /* AN32 */
#define _ADC_PHYSICAL_CHANNEL_AN33                (0x00000021UL) /* AN33 */
#define _ADC_PHYSICAL_CHANNEL_AN34                (0x00000022UL) /* AN34 */
#define _ADC_PHYSICAL_CHANNEL_AN35                (0x00000023UL) /* AN35 */

/*
    A/D force halt register (ADCAnADHALTR)
*/
/* A/D force halt register (HALT) */
#define _ADC_HALT                                 (0x00000001UL) /* Scan groups are halted */

/*
    A/D control register (ADCAnADCR)
*/
/* 12/10 Bit Select Mode (CTYP) */
#define _ADC_12_BIT_MODE                          (0x00000000UL) /* 12-bit mode */
#define _ADC_10_BIT_MODE                          (0x00000010UL) /* 10-bit mode */

/*
    TH sampling start control register (ADCAnTHSMPSTCR)
*/
/* TH sampling start control trigger (SMPST) */
#define _ADC_TH_SAMPLING_ALL_START                (0x00000001UL) /* Sampling for all TH is started */

/*
    TH control register (ADCAnTHCR)
*/
/* Automatic sampling mask control (ASMPMSK) */
#define _ADC_TH_SAMPLING_MANUAL                   (0x00000000UL) /* Automatic sampling is not performed */
#define _ADC_TH_SAMPLING_AUTOMATIC                (0x00000001UL) /* Automatic sampling is performed */

/*
    TH group A/B control register (ADCAnTHABCR)
*/
/* TH group A/B hold trigger enable (HLDTE) */
#define _ADC_TH_SG_START_TRIGGER_USED             (0x00000000UL) /* trigger is selected for the hold start trigger of TH group A/B */
#define _ADC_TH_SG_START_TRIGGER_UNUSED           (0x00000010UL) /* trigger is not selected for the hold start trigger of TH group A/B */
/* TH group A/B scan group select (SGS[1-0]) */
#define _ADC_TH_SELECT_NONE                       (0x00000000UL) /* No scan group is selected for TH group A/B */
#define _ADC_TH_SELECT_SG1                        (0x00000001UL) /* SG1 is selected for TH group A/B */
#define _ADC_TH_SELECT_SG2                        (0x00000002UL) /* SG2 is selected for TH group A/B */
#define _ADC_TH_SELECT_SG3                        (0x00000003UL) /* SG3 is selected for TH group A/B */

/*
    TH enable register (ADCAnTHER)
*/
/* TH5 Enable (TH5E) */
#define _ADC_TH5_DISABLED                         (0x00000000UL) /* TH5 is disabled */
#define _ADCn_TH5_ENABLED                         (0x00000020UL) /* TH5 is enabled */
/* TH4 Enable (TH4E) */
#define _ADC_TH4_DISABLED                         (0x00000000UL) /* TH4 is disabled */
#define _ADC_TH4_ENABLED                          (0x00000010UL) /* TH4 is enabled */
/* TH3 Enable (TH3E) */
#define _ADC_TH3_DISABLED                         (0x00000000UL) /* TH3 is disabled */
#define _ADC_TH3_ENABLED                          (0x00000008UL) /* TH3 is enabled */
/* TH2 Enable (TH2E) */
#define _ADC_TH2_DISABLED                         (0x00000000UL) /* TH2 is disabled */
#define _ADC_TH2_ENABLED                          (0x00000004UL) /* TH2 is enabled */
/* TH1 Enable (TH1E) */
#define _ADC_TH1_DISABLED                         (0x00000000UL) /* TH1 is disabled */
#define _ADC_TH1_ENABLED                          (0x00000002UL) /* TH1 is enabled */
/* TH0 Enable (TH0E) */
#define _ADC_TH0_DISABLED                         (0x00000000UL) /* TH0 is disabled */
#define _ADC_TH0_ENABLED                          (0x00000001UL) /* TH0 is enabled */

/*
    TH group select register (ADCAnTHGSR)
*/
/* TH5 group select (TH5GS) */
#define _ADC_TH5_GROUP_A                          (0x00000000UL) /* TH5 is selected to group A */
#define _ADC_TH5_GROUP_B                          (0x00000020UL) /* TH5 is selected to group B */
/* TH4 group select (TH4GS) */
#define _ADC_TH4_GROUP_A                          (0x00000000UL) /* TH4 is selected to group A */
#define _ADC_TH4_GROUP_B                          (0x00000010UL) /* TH4 is selected to group B */
/* TH3 group select (TH3GS) */
#define _ADC_TH3_GROUP_A                          (0x00000000UL) /* TH3 is selected to group A */
#define _ADC_TH3_GROUP_B                          (0x00000008UL) /* TH3 is selected to group B */
/* TH2 group select (TH2GS) */
#define _ADC_TH2_GROUP_A                          (0x00000000UL) /* TH2 is selected to group A */
#define _ADC_TH2_GROUP_B                          (0x00000004UL) /* TH2 is selected to group B */
/* TH1 group select (TH1GS) */
#define _ADC_TH1_GROUP_A                          (0x00000000UL) /* TH1 is selected to group A */
#define _ADC_TH1_GROUP_B                          (0x00000002UL) /* TH1 is selected to group B */
/* TH0 group select (TH0GS) */
#define _ADC_TH0_GROUP_A                          (0x00000000UL) /* TH0 is selected to group A */
#define _ADC_TH0_GROUP_B                          (0x00000001UL) /* TH0 is selected to group B */

/*
    Sampling control register (ADCAnSMPCR)
*/
/* These bits are used to set the sampling time (the number of cycles) (SMPT[7-0]) */
#define _ADC_18_CYCLES                            (0x00000012UL) /* 18 cycles (PCLK = 8 MHz to 32 MHz) */
#define _ADC_24_CYCLES                            (0x00000018UL) /* 24 cycles (PCLK = 8 MHz to 40 MHz) */

/*
    Safety control register (ADCAnSFTCR)
*/
/* Read and clear enable (RDCLRE) */
#define _ADC_READ_CLEAR_DISABLED                  (0x00000000UL) /* The A/D conversion result is not cleared by hardware */
#define _ADC_READ_CLEAR_ENABLED                   (0x00000010UL) /* The A/D conversion result is cleared by hardware */
/* A/D Error Interrupt (INT_ADE) Enable on Upper/Lower Limit Error Detection (ULEIE) */
#define _ADC_LIMIT_ERROR_INT_DISABLE              (0x00000000UL) /* Disabled */
#define _ADC_LIMIT_ERROR_INT_ENABLE               (0x00000008UL) /* Enabled */
/* A/D Error Interrupt (INT_ADE) Enable on Overwrite Error Detection (OWEIE) */
#define _ADC_OVERWRITE_ERROR_INT_DISABLE          (0x00000000UL) /* Disabled */
#define _ADC_OVERWRITE_ERROR_INT_ENABLE           (0x00000004UL) /* Enabled */

/*
    Scan group 1 start control register (ADCAnSGSTCRm)
*/
/* Scan group start trigger (SGST) */
#define _ADC_START                                (0x00000001UL) /* Starts the target SG */

/*
    Scan group 1 control register (ADCAnSGCRm)
*/
/* Scan mode (SCANMD) */
#define _ADC_SG_SCAN_MODE_MULTICYCLE              (0x00000000UL) /* Multicycle scan mode */
#define _ADC_SG_SCAN_MODE_CONTINUOUS              (0x00000020UL) /* Continuous scan mode */
/* Scan end interrupt enable (ADIE) */
#define _ADC_SG_SCAN_END_INT_DISABLE              (0x00000000UL) /* INT_SG1 is not output */
#define _ADC_SG_SCAN_END_INT_ENABLE               (0x00000010UL) /* INT_SG1 is output */
/* Trigger mode (TRGMD) */
#define _ADC_SG_HW_TRIGGER_DISABLE                (0x00000000UL) /* Trigger input is disabled */
#define _ADC_SG_HW_TRIGGER_ENABLE                 (0x00000001UL) /* Start trigger or hold complete trigger selected for the trigger input */

/*
    Scan Group 1 Multicycle Register (ADCAnSGMCYCRm)
*/
/* Multicycle number specification (MCYC[1-0]) */
#define _ADC_SG_MULTICYCLE_NUMBER_1               (0x00000000UL) /* Number of scans = 1 */
#define _ADC_SG_MULTICYCLE_NUMBER_2               (0x00000001UL) /* Number of scans = 2 */
#define _ADC_SG_MULTICYCLE_NUMBER_4               (0x00000003UL) /* Number of scans = 4 */

/*
    A/D force halt register (ADCAnSGTSELm)
*/
/* A/D conversion hardware trigger select (T1SEL8) */
#define _ADC_SG_HW_TRIGGER_FACTOR_8               (0x00000100UL) /* Connection Motor control (PIC0) trigger enabled */
/* A/D conversion hardware trigger select (T1SEL7) */
#define _ADC_SG_HW_TRIGGER_FACTOR_7               (0x00000080UL) /* Connection Motor control (TAPA0) trigger enabled */
/* A/D conversion hardware trigger select (T1SEL6) */
#define _ADC_SG_HW_TRIGGER_FACTOR_6               (0x00000040UL) /* Connection Motor control (TAPA0) trigger enabled */
/* A/D conversion hardware trigger select (T1SEL5) */
#define _ADC_SG_HW_TRIGGER_FACTOR_5               (0x00000020UL) /* Connection ENCA0 trigger enabled */
/* A/D conversion hardware trigger select (T1SEL4) */
#define _ADC_SG_HW_TRIGGER_FACTOR_4               (0x00000010UL) /* Connection LPS trigger enabled */
/* A/D conversion hardware trigger select (T1SEL3) */
#define _ADC_SG_HW_TRIGGER_FACTOR_3               (0x00000008UL) /* Connection TAUD0 trigger enabled */
/* A/D conversion hardware trigger select (T1SEL2) */
#define _ADC_SG_HW_TRIGGER_FACTOR_2               (0x00000004UL) /* Connection TAUD0 trigger enabled */
/* A/D conversion hardware trigger select (T1SEL1) */
#define _ADC_SG_HW_TRIGGER_FACTOR_1               (0x00000002UL) /* Connection TAUJ0 trigger enabled */
/* A/D conversion hardware trigger select (T1SEL0) */
#define _ADC_SG_HW_TRIGGER_EXTERNAL_PIN           (0x00000001UL) /* Connection External trigger pin trigger enabled */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _ADC0_UPPER_LIMIT_TABLE0                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE0                  (0x00000000UL)
#define _ADC1_UPPER_LIMIT_TABLE0                  (0xFFF00000UL)
#define _ADC1_LOWER_LIMIT_TABLE0                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE1                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE1                  (0x00000000UL)
#define _ADC1_UPPER_LIMIT_TABLE1                  (0xFFF00000UL)
#define _ADC1_LOWER_LIMIT_TABLE1                  (0x00000000UL)
#define _ADC0_UPPER_LIMIT_TABLE2                  (0xFFF00000UL)
#define _ADC0_LOWER_LIMIT_TABLE2                  (0x00000000UL)
#define _ADC1_UPPER_LIMIT_TABLE2                  (0xFFF00000UL)
#define _ADC1_LOWER_LIMIT_TABLE2                  (0x00000000UL)
#define _ADC0_SG1_START_POINTER                   (0x00000000UL)
#define _ADC1_SG1_START_POINTER                   (0x00000000UL)
#define _ADC0_SG1_END_POINTER                     (0x00000015UL)
#define _ADC1_SG1_END_POINTER                     (0x00000007UL)
#define _ADC_TH_SAMPLING_START                    (0x1U)
#define _ADC_FILTER_ENABLED                       (0x1U) 
#define _ADC_FILTER_EDGE_RISING                   (0x01U) 
#define _ADC_FILTER_EDGE_FALLING                  (0x02U)
#define _ADC_FILTER_EDGE_BOTH                     (0x03U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_ADC0_Create(void);
void R_ADC0_Halt(void);
void R_ADC0_ScanGroup1_Start(void);
void R_ADC0_ScanGroup1_OperationOn(void);
void R_ADC0_ScanGroup1_GetResult(uint16_t * const buffer);
void R_ADC0_TH_Sampling_Start(void);
void R_ADC1_Create(void);
void R_ADC1_Halt(void);
void R_ADC1_ScanGroup1_Start(void);
void R_ADC1_ScanGroup1_OperationOn(void);
void R_ADC1_ScanGroup1_GetResult(uint16_t * const buffer);

/* Start user code for function. Do not edit comment generated here */
#define ADC0_SG1_nVCH   _ADC0_SG1_END_POINTER+1
#define ADC1_SG1_nVCH   _ADC1_SG1_END_POINTER+1

extern uint16_t adc_buffer_raw[ADC0_SG1_nVCH + ADC1_SG1_nVCH];
extern uint32_t adc_buffer_sum[ADC0_SG1_nVCH + ADC1_SG1_nVCH];
extern uint16_t adc_buffer_avg[ADC0_SG1_nVCH + ADC1_SG1_nVCH];
extern uint8_t short_ckt_flag[ADC0_SG1_nVCH + ADC1_SG1_nVCH];

void getADC0n1_result();

#define BRAKE_L_FB_VCH		0
#define POSITION_FB_VCH		2
#define PWM_OUT_FB_VCH		10
#define SPARE3_FB_VCH		12
#define SPARE_FB_VCH		20
#define HEADLAMP_HB_FB_VCH	23
#define HEADLAMP_LB_FB_VCH	24
#define CLUSTER_FB_VCH		25
#define IR_FB_VCH			26
#define HORN_FB_VCH			27
#define TSL_L_FB_VCH		28
#define TSL_R_FB_VCH		29

#define SHORT_CKT_THRESHOLD			400
#define SHORT_CKT_THRESHOLD_HORN	700

/* End user code. Do not edit comment generated here */
#endif