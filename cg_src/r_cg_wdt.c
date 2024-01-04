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
* File Name    : r_cg_wdt.c
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for WDTA module.
* Creation Date: 04-09-2021
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_wdt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_WDT0_Create
* Description  : This function initializes WDTA module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_WDT0_Create(void)
{
    /* Disable WDT0 interrupt operation and clear request */
    INTC2.ICWDTA0.BIT.MKWDTA0 = _INT_PROCESSING_DISABLED;
    INTC2.ICWDTA0.BIT.RFWDTA0 = _INT_REQUEST_NOT_OCCUR;
    /* Set WDT0 interrupt setting */
    INTC2.ICWDTA0.BIT.TBWDTA0 = _INT_TABLE_VECTOR;
    INTC2.ICWDTA0.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set WDT0 control setting */
    WDTA0.MD = _WDT_OVERFLOW_WDTACKI_2_16 | _WDT_INTERRUPT_ENABLED | _WDT_RESET_MODE | _WDT_PERIOD_100;
    /* Synchronization processing */
    g_cg_sync_read = WDTA0.MD;
    __syncp();
    /* Clear WDT0 interrupt request and enable operation */
    INTC2.ICWDTA0.BIT.RFWDTA0 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICWDTA0.BIT.MKWDTA0 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_WDT0_Restart
* Description  : This function restarts WDTA module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_WDT0_Restart(void)
{
    WDTA0.WDTE = _WDT_START_CODE;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
