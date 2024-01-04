/*********************************************************************************************************************
 * File Name     : $Source: target.h $
 * Mod. Revision : $Revision: 1.4 $
 * Mod. Date     : $Date: 2019/04/26 11:37:35JST $
 * Device(s)     : RV40 Flash based RH850 microcontroller
 * Description   : Target specific defines
 *********************************************************************************************************************/

/*********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only  intended for use with Renesas products.
 * No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
 * TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS
 * AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
 * REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * www.renesas.com/disclaimer
 *
 * Copyright (C) 2015-2019 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/

#ifndef TARGET_H
#define TARGET_H

/*********************************************************************************************************************
 * Include list
 *********************************************************************************************************************/
#include "app.h"

#if (!defined APP_COMPILER)
    #error "APP_COMPILER is not defined"
#elif APP_COMPILER == APP_COMP_GHS
    #include "dr7f701587.dvf.h"
#elif APP_COMPILER == APP_COMP_IAR
    #include "ior7f701587.h"
#elif APP_COMPILER == APP_COMP_REC
    #include "iodefine.h"
#else
    #error "APP_COMPILER is unknown"
#endif

/*********************************************************************************************************************
 * Global macros
 *********************************************************************************************************************/

/******* Initialize CPU clock and peripheral clock ***************************/
#define protected_write(preg,pstatus,reg,value)             \
do                                                          \
{                                                           \
    (preg) = 0xa5u;                                         \
    (reg) = (value);                                        \
    (reg) = ~(value);                                       \
    (reg) = (value);                                        \
} while ((pstatus) == 1u)

#define INIT_CPU_AND_FPERIPHERAL_CLK                                                                \
    CLKCTL.MOSCC = 0x06;                    /* Set MainOSC gain for 16MHz */                        \
    CLKCTL.MOSCST = 0x0000FFFF;             /* Set MainOSC stabilization time to 4 ms */            \
    protected_write(WPROTR.PROTCMD0,WPROTR.PROTS0,CLKCTL.MOSCE,0x01);   /* Trigger MainOsc start */ \
    while ((CLKCTL.MOSCS & 0x04) != 0x4);   /* Wait for active MainOSC */                           \
                                                                                                    \
    /* Prepare PLL */                                                                               \
    CLKCTL.PLLC = 0x00010B3B;               /* 16 MHz MainOSC setting (VCOOUT=480MHz) */            \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.PLLE,0x01);   /* enable PLL */             \
    while ((CLKCTL.PLLS & 0x04) != 0x04);   /* Wait for active PLL */                               \
                                                                                                    \
    /* CPLLOUT = VCOOUT * 1/4 = 120 MHz (for Premium Device) */                                     \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKD_CTL,0x11);                    \
    while (CLKCTL.CKSC_CPUCLKD_ACT != 0x11);                                                        \
                                                                                                    \
    /* PLL -> CPU Clock */                                                                          \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_CPUCLKS_CTL,0x03);                    \
    while (CLKCTL.CKSC_CPUCLKS_ACT != 0x03);                                                        \
                                                                                                    \
    /* PPLLOUT -> PPLLCLK (Set Peripheral Clock to PLL) */                                          \
    protected_write(WPROTR.PROTCMD1,WPROTR.PROTS1,CLKCTL.CKSC_PPLLCLKS_CTL,0x03);                   \
    while (CLKCTL.CKSC_PPLLCLKS_ACT != 0x03);


/******* Initialize the Data Flash access ************************************/
#define INIT_FLASHACCESS

#define DISABLE_FLASHACCESS

/************************************************************************************************************
Typedef definitions
************************************************************************************************************/


/************************************************************************************************************
Exported global variables
************************************************************************************************************/


/************************************************************************************************************
Exported global functions (to be accessed by other files)
************************************************************************************************************/

#endif /* endif TARGET_H */

