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
* File Name    : r_cg_stbc.c
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for STBC module.
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
#include "r_cg_stbc.h"
/* Start user code for include. Do not edit comment generated here */
#include "state.h"
#include "r_cg_port.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_STBC_Prepare_Stop_Mode
* Description  : This function Prepare Stop Mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_STBC_Prepare_Stop_Mode(void)
{
    /* Change the waiting time according to the system */
    R_STBC_Prepare_Stop_Mode_Set_Peripheral();
    /* Disable interrupts */
    DI();
    /* Change the waiting time according to the system */
    R_STBC_Prepare_Stop_Mode_Set_Interrupt();
    /* Clear wake-up factor */
    STBC_WUF0.WUFC0 = _STBC_WUF0_CLEAR_144PIN;
    STBC_WUFISO.WUFC_ISO0 = _STBC_WUF_ISO0_CLEAR_144PIN;
    /* Enable wake-up factor */
    STBC_WUF0.WUFMSK0 = _STBC_FACTOR_DEFAULT_VALUE & _STBC_WUF0_FACTOR_INTP2 & 
                        _STBC_WUF0_FACTOR_INTP6 & _STBC_WUF0_FACTOR_INTP7 & 
                        _STBC_WUF0_FACTOR_INTP8 & _STBC_WUF0_FACTOR_INTP9 & 
                        _STBC_WUF0_FACTOR_INTP13;
    STBC_WUFISO.WUFMSK_ISO0 = _STBC_FACTOR_DEFAULT_VALUE & _STBC_WUF_ISO0_FACTOR_INTRCAN0REC & 
                              _STBC_WUF_ISO0_FACTOR_INTRCANGRECC0;
    /* Change the waiting time according to the system */
    R_STBC_Prepare_Stop_Mode_Set_Clock_Mask();
    /* Change the waiting time according to the system */
    R_STBC_Prepare_Stop_Mode_Set_Clock_Source();
}
/***********************************************************************************************************************
* Function Name: R_STBC_Start_Stop_Mode
* Description  : This function Start Stop Mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_STBC_Start_Stop_Mode(void)
{
    WPROTR.PROTCMD0 = _WRITE_PROTECT_COMMAND;
    STBC0.STPT = _STBC_STOP_MODE_ENTERED;
    STBC0.STPT = (uint32_t) ~_STBC_STOP_MODE_ENTERED;
    STBC0.STPT = _STBC_STOP_MODE_ENTERED;
    while (STBC0.STPT == _STBC_STOP_MODE_ENTERED)
    {
        NOP();
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
