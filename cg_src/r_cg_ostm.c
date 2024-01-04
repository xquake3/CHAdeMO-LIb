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
* File Name    : r_cg_ostm.c
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for OSTM module.
* Creation Date: 07-06-2023
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
#include "r_cg_ostm.h"
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
* Function Name: R_OSTM0_Create
* Description  : This function initializes OS timer.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_OSTM0_Create(void)
{
    /* Disable OSTM0 operation */
    OSTM0.TT = _OSTM_COUNTER_STOP;
    /* Disable OSTM0 interrupt operation and clear request */
    INTC2.ICOSTM0.BIT.MKOSTM0 = _INT_PROCESSING_DISABLED;
    INTC2.ICOSTM0.BIT.RFOSTM0 = _INT_REQUEST_NOT_OCCUR;
    /* Set OSTM0 interrupt setting */
    INTC2.ICOSTM0.BIT.TBOSTM0 = _INT_TABLE_VECTOR;
    INTC2.ICOSTM0.UINT16 &= _INT_PRIORITY_HIGHEST;
    /* Set OSTM0 control setting */
    OSTM0.CTL = _OSTM_MODE_INTERVAL_TIMER | _OSTM_START_INTERRUPT_ENABLE;
    OSTM0.CMP = _OSTM_COMPARING_COUNTER;
    /* Synchronization processing */
    g_cg_sync_read = OSTM0.CTL;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_OSTM0_Start
* Description  : This function starts OS timer.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_OSTM0_Start(void)
{
    /* Clear OSTM0 interrupt request and enable operation */
    INTC2.ICOSTM0.BIT.RFOSTM0 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICOSTM0.BIT.MKOSTM0 = _INT_PROCESSING_ENABLED;    
    /* Enable OSTM0 operation */
    OSTM0.TS = _OSTM_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_OSTM0_Stop
* Description  : This function stops OS timer.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_OSTM0_Stop(void)
{
    /* Disable OSTM0 operation */
    OSTM0.TT = _OSTM_COUNTER_STOP;
    /* Disable OSTM0 interrupt operation and clear request */
    INTC2.ICOSTM0.BIT.MKOSTM0 = _INT_PROCESSING_DISABLED;
    INTC2.ICOSTM0.BIT.RFOSTM0 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = OSTM0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_OSTM0_Set_CompareValue
* Description  : This function sets counter value of OS timer.
* Arguments    : value -
*                    counter value
* Return Value : None
***********************************************************************************************************************/
void R_OSTM0_Set_CompareValue(uint32_t value)
{
    OSTM0.CMP = value;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
