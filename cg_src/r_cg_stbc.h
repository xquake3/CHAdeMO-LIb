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
* File Name    : r_cg_stbc.h
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for STBC module.
* Creation Date: 07-06-2023
***********************************************************************************************************************/
#ifndef STBC_H
#define STBC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Wake up factor register (WUF0)
*/
/* Indicates the generation of a wake-up event */
#define _STBC_WUF0_CLEAR_100PIN                                 (0x72FFFFE7UL) /* Wake-up event is not generated */
#define _STBC_WUF0_CLEAR_144PIN                                 (0xFFFFFFE7UL) /* Wake-up event is not generated */
#define _STBC_WUF0_CLEAR_176PIN                                 (0xFFFFFFE7UL) /* Wake-up event is not generated */
/*
    Wake up factor register (WUF_ISO0)
*/
/* Indicates the generation of a wake-up event */
#define _STBC_WUF_ISO0_CLEAR_100PIN                             (0x000001FEUL) /* Wake-up event is not generated */
#define _STBC_WUF_ISO0_CLEAR_144PIN                             (0x000001FEUL) /* Wake-up event is not generated */
#define _STBC_WUF_ISO0_CLEAR_176PIN                             (0x000007FEUL) /* Wake-up event is not generated */
/*
    Wake up factor register (WUF20)
*/
/* Indicates the generation of a wake-up event */
#define _STBC_WUF20_CLEAR_100PIN                                (0x000023FFUL) /* Wake-up event is not generated */
#define _STBC_WUF20_CLEAR_144PIN                                (0x0000FFFFUL) /* Wake-up event is not generated */
#define _STBC_WUF20_CLEAR_176PIN                                (0x0000FFFFUL) /* Wake-up event is not generated */
/*
    Wake up factor register (WUF0)
*/
/* Indicates the generation of a wake-up event (WUF00) */
#define _STBC_WUF0_FACTOR_TNMI                                  (0xFFFFFFFEUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF01) */
#define _STBC_WUF0_FACTOR_WDTA0NMI                              (0xFFFFFFFDUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF02) */
#define _STBC_WUF0_FACTOR_INTLVIL                               (0xFFFFFFFBUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF05) */
#define _STBC_WUF0_FACTOR_INTP0                                 (0xFFFFFFDFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF06) */
#define _STBC_WUF0_FACTOR_INTP1                                 (0xFFFFFFBFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF07) */
#define _STBC_WUF0_FACTOR_INTP2                                 (0xFFFFFF7FUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF08) */
#define _STBC_WUF0_FACTOR_INTWDTA0                              (0xFFFFFEFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF09) */
#define _STBC_WUF0_FACTOR_INTP3                                 (0xFFFFFDFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF10) */
#define _STBC_WUF0_FACTOR_INTP4                                 (0xFFFFFBFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF11) */
#define _STBC_WUF0_FACTOR_INTP5                                 (0xFFFFF7FFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF12) */
#define _STBC_WUF0_FACTOR_INTP10                                (0xFFFFEFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF13) */
#define _STBC_WUF0_FACTOR_INTP11                                (0xFFFFDFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF14) */
#define _STBC_WUF0_FACTOR_WUTRG1                                (0xFFFFBFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF15) */
#define _STBC_WUF0_FACTOR_INTTAUJ0I0                            (0xFFFF7FFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF16) */
#define _STBC_WUF0_FACTOR_INTTAUJ0I1                            (0xFFFEFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF17) */
#define _STBC_WUF0_FACTOR_INTTAUJ0I2                            (0xFFFDFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF18) */
#define _STBC_WUF0_FACTOR_INTTAUJ0I3                            (0xFFFBFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF19) */
#define _STBC_WUF0_FACTOR_WUTRG0                                (0xFFF7FFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF20) */
#define _STBC_WUF0_FACTOR_INTP6                                 (0xFFEFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF21) */
#define _STBC_WUF0_FACTOR_INTP7                                 (0xFFDFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF22) */
#define _STBC_WUF0_FACTOR_INTP8                                 (0xFFBFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF23) */
#define _STBC_WUF0_FACTOR_INTP12                                (0xFF7FFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF24) */
#define _STBC_WUF0_FACTOR_INTP9                                 (0xFEFFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF25) */
#define _STBC_WUF0_FACTOR_INTP13                                (0xFDFFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF26) */
#define _STBC_WUF0_FACTOR_INTP14                                (0xFBFFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF27) */
#define _STBC_WUF0_FACTOR_INTP15                                (0xF7FFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF28) */
#define _STBC_WUF0_FACTOR_INTRTCA01S                            (0xEFFFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF29) */
#define _STBC_WUF0_FACTOR_INTRTCA0AL                            (0xDFFFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF30) */
#define _STBC_WUF0_FACTOR_INTRTCA0R                             (0xBFFFFFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF31) */
#define _STBC_WUF0_FACTOR_INTDCUTDI                             (0x7FFFFFFFUL) /* Wake-up event is generated */
/*
    Wake up factor register (WUF_ISO0)
*/
/* Indicates the generation of a wake-up event (WUF01) */
#define _STBC_WUF_ISO0_FACTOR_INTKR0                            (0xFFFFFFFDUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF02) */
#define _STBC_WUF_ISO0_FACTOR_INTRCANGRECC0                     (0xFFFFFFFBUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF03) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN0REC                       (0xFFFFFFF7UL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF04) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN1REC                       (0xFFFFFFEFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF05) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN2REC                       (0xFFFFFFDFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF06) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN3REC                       (0xFFFFFFBFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF07) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN4REC                       (0xFFFFFF7FUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF08) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN5REC                       (0xFFFFFEFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF09) */
#define _STBC_WUF_ISO0_FACTOR_INTRCANGRECC1                     (0xFFFFFDFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF10) */
#define _STBC_WUF_ISO0_FACTOR_INTRCAN6REC                       (0xFFFFFBFFUL) /* Wake-up event is generated */
/*
    Wake up factor register (WUF20)
*/
/* Indicates the generation of a wake-up event (WUF00) */
#define _STBC_WUF20_FACTOR_INTADCA0I0                           (0xFFFFFFFEUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF01) */
#define _STBC_WUF20_FACTOR_INTADCA0I1                           (0xFFFFFFFDUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF02) */
#define _STBC_WUF20_FACTOR_INTADCA0I2                           (0xFFFFFFFBUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF03) */
#define _STBC_WUF20_FACTOR_INTRLIN30                            (0xFFFFFFF7UL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF04) */
#define _STBC_WUF20_FACTOR_INTTAUJ0I0                           (0xFFFFFFEFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF05) */
#define _STBC_WUF20_FACTOR_INTTAUJ0I1                           (0xFFFFFFDFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF06) */
#define _STBC_WUF20_FACTOR_INTTAUJ0I2                           (0xFFFFFFBFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF07) */
#define _STBC_WUF20_FACTOR_INTTAUJ0I3                           (0xFFFFFF7FUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF08) */
#define _STBC_WUF20_FACTOR_INTRLIN31                            (0xFFFFFEFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF09) */
#define _STBC_WUF20_FACTOR_INTRLIN32                            (0xFFFFFDFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF10) */
#define _STBC_WUF20_FACTOR_INTRTCA01S                           (0xFFFFFBFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF11) */
#define _STBC_WUF20_FACTOR_INTRTCA0AL                           (0xFFFFF7FFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF12) */
#define _STBC_WUF20_FACTOR_INTRTCA0R                            (0xFFFFEFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF13) */
#define _STBC_WUF20_FACTOR_INTRLIN33                            (0xFFFFDFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF14) */
#define _STBC_WUF20_FACTOR_INTRLIN34                            (0xFFFFBFFFUL) /* Wake-up event is generated */
/* Indicates the generation of a wake-up event (WUF15) */
#define _STBC_WUF20_FACTOR_INTRLIN35                            (0xFFFF7FFFUL) /* Wake-up event is generated */

/*
    Power save control register (STBC0PSC)
*/
/* Power save control (STBC0DISTRG) */
#define _STBC_DEEP_STOP_MODE_DISABLE                            (0x00000000UL) /* Writing 0 has no effect */
#define _STBC_DEEP_STOP_MODE_ENTERED                            (0x00000002UL) /* DeepSTOP mode is entered */

/*
    Power stop trigger register (STBC0STPT)
*/
/* Power stop trigger (STBC0STPTRG) */
#define _STBC_STOP_MODE_DISABLE                                 (0x00000000UL) /* Writing 0 has no effect */
#define _STBC_STOP_MODE_ENTERED                                 (0x00000001UL) /* Stop mode is entered */

/*
    reset factor clear register (RESFC)
*/
/* Reset flag clear by DeepSTOP mode (RESFC10) */
#define _RESFC_RESET_FLAG_CLEAR                                 (0x00000400UL) /* Clear reset flag */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Cycle time */
#define _STBC_WAITTIME                                          (0x5U)
#define _STBC_FACTOR_DEFAULT_VALUE                              (0xFFFFFFFFUL)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_STBC_Prepare_Stop_Mode(void);
void R_STBC_Start_Stop_Mode(void);
void R_STBC_Prepare_Stop_Mode_Set_Peripheral(void);
void R_STBC_Prepare_Stop_Mode_Set_Interrupt(void);
void R_STBC_Prepare_Stop_Mode_Set_Clock_Mask(void);
void R_STBC_Prepare_Stop_Mode_Set_Clock_Source(void);

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif