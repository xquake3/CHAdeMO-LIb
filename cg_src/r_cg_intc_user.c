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
* File Name    : r_cg_intc_user.c
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for INTC module.
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
#include "r_cg_intc.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_port.h"
#include "state.h"
#include "r_cg_ostm.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint8_t wakeupBy_Tcon = 0;
uint8_t wakeupBy_CAN0 = 0;
uint8_t wakeupBy_CAN1 = 0;
uint8_t wakeupBy_Igni = 0;
uint8_t wakeupBy_Chrg = 0;
uint8_t wakeupBy_Aux = 0;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_intp2_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_intp2_interrupt(enable=false, channel=39, fpu=true, callt=false)
void r_intp2_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    //CAN0_INT
    //enableCANTranscivers();
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_intp5_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_intp5_interrupt(enable=false, channel=45, fpu=true, callt=false)
void r_intp5_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    //CHRG_INT_2
    //enableCANTranscivers();
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_intp6_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_intp6_interrupt(enable=false, channel=128, fpu=true, callt=false)
void r_intp6_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    wakeupBy_Tcon = 1;
    //T_CNTR_INTP
    //enableCANTranscivers();
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_intp7_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_intp7_interrupt(enable=false, channel=129, fpu=true, callt=false)
void r_intp7_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_intp8_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_intp8_interrupt(enable=false, channel=130, fpu=true, callt=false)
void r_intp8_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_intp9_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_intp9_interrupt(enable=false, channel=205, fpu=true, callt=false)
void r_intp9_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_intp13_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_intp13_interrupt(enable=false, channel=206, fpu=true, callt=false)
void r_intp13_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
