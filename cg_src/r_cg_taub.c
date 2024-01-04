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
* File Name    : r_cg_taub.c
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for TAUB module.
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
#include "r_cg_taub.h"
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
* Function Name: R_TAUB0_Create
* Description  : This function initializes the TAUB0 Bus Interface.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Create(void)
{
    /* Disable channel0 counter operation */
    TAUB0.TT = _TAUB_CHANNEL15_COUNTER_STOP | _TAUB_CHANNEL14_COUNTER_STOP | _TAUB_CHANNEL13_COUNTER_STOP | 
               _TAUB_CHANNEL12_COUNTER_STOP | _TAUB_CHANNEL11_COUNTER_STOP | _TAUB_CHANNEL10_COUNTER_STOP | 
               _TAUB_CHANNEL9_COUNTER_STOP | _TAUB_CHANNEL8_COUNTER_STOP | _TAUB_CHANNEL7_COUNTER_STOP | 
               _TAUB_CHANNEL6_COUNTER_STOP | _TAUB_CHANNEL5_COUNTER_STOP | _TAUB_CHANNEL4_COUNTER_STOP | 
               _TAUB_CHANNEL3_COUNTER_STOP | _TAUB_CHANNEL2_COUNTER_STOP | _TAUB_CHANNEL1_COUNTER_STOP | 
               _TAUB_CHANNEL0_COUNTER_STOP;
    /* Disable INTTAUB0I0 operation and clear request */
    INTC2.ICTAUB0I0.BIT.MKTAUB0I0 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I0.BIT.RFTAUB0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I1 operation and clear request */
    INTC2.ICTAUB0I1.BIT.MKTAUB0I1 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I1.BIT.RFTAUB0I1 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I13 operation and clear request */
    INTC2.ICTAUB0I13.BIT.MKTAUB0I13 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I13.BIT.RFTAUB0I13 = _INT_REQUEST_NOT_OCCUR;
    /* Set INTTAUB0I0 setting */
    INTC2.ICTAUB0I0.BIT.TBTAUB0I0 = _INT_TABLE_VECTOR;
    INTC2.ICTAUB0I0.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set INTTAUB0I1 setting */
    INTC2.ICTAUB0I1.BIT.TBTAUB0I1 = _INT_TABLE_VECTOR;
    INTC2.ICTAUB0I1.UINT16 &= _INT_PRIORITY_LOWEST;
    /* Set INTTAUB0I13 setting */
    INTC2.ICTAUB0I13.BIT.TBTAUB0I13 = _INT_TABLE_VECTOR;
    INTC2.ICTAUB0I13.UINT16 &= _INT_PRIORITY_LOWEST;
    TAUB0.TPS = _TAUB_CK3_PRE_PCLK_15 | _TAUB_CK2_PRE_PCLK_15 | _TAUB_CK1_PRE_PCLK_15 | _TAUB_CK0_PRE_PCLK_10;
    /* Set channel 0 setting */
    TAUB0.CMOR0 = _TAUB_SELECTION_CK0 | _TAUB_OPERATION_CLOCK | _TAUB_MASTER_CHANNEL | _TAUB_SOFTWARE_TRIGGER | 
                  _TAUB_OVERFLOW_AUTO_CLEAR | _TAUB_INTERVAL_TIMER_MODE | _TAUB_START_INT_GENERATED;
    TAUB0.CMUR0 = _TAUB_INPUT_EDGE_UNUSED;
    TAUB0.CDR0 = _TAUB0_CHANNEL0_COMPARE_VALUE;
    /* Set channel 1 setting */
    TAUB0.CMOR1 = _TAUB_SELECTION_CK0 | _TAUB_OPERATION_CLOCK | _TAUB_INDEPENDENT_CHANNEL | _TAUB_SOFTWARE_TRIGGER | 
                  _TAUB_OVERFLOW_AUTO_CLEAR | _TAUB_INTERVAL_TIMER_MODE | _TAUB_START_INT_NOT_GENERATED;
    TAUB0.CMUR1 = _TAUB_INPUT_EDGE_UNUSED;
    TAUB0.CDR1 = _TAUB0_CHANNEL1_COMPARE_VALUE;
    /* Set channel 13 setting */
    TAUB0.CMOR13 = _TAUB_SELECTION_CK0 | _TAUB_OPERATION_CLOCK | _TAUB_SLAVE_CHANNEL | _TAUB_MASTER_START | 
                   _TAUB_OVERFLOW_AUTO_CLEAR | _TAUB_ONE_COUNT_MODE | _TAUB_START_TRIGGER_ENABLE;
    TAUB0.CMUR13 = _TAUB_INPUT_EDGE_UNUSED;
    TAUB0.CDR13 = _TAUB0_CHANNEL13_COMPARE_VALUE;
    /* Set output mode setting */
    TAUB0.TOE = _TAUB_CHANNEL13_ENABLES_OUTPUT_MODE | _TAUB_CHANNEL1_ENABLES_OUTPUT_MODE | 
                _TAUB_CHANNEL0_DISABLES_OUTPUT_MODE;
    TAUB0.TOM = _TAUB_CHANNEL13_SYNCHRONOUS_OUTPUT_MODE | _TAUB_CHANNEL1_INDEPENDENT_OUTPUT_MODE;
    TAUB0.TOC = _TAUB_CHANNEL13_OPERATION_MODE1 | _TAUB_CHANNEL1_OPERATION_MODE1;
    TAUB0.TOL = _TAUB_CHANNEL13_POSITIVE_LOGIC | _TAUB_CHANNEL1_POSITIVE_LOGIC;
    TAUB0.TDE = _TAUB_CHANNEL13_DISABLE_DEAD_TIME_OPERATE | _TAUB_CHANNEL1_DISABLE_DEAD_TIME_OPERATE;
    TAUB0.TDL = _TAUB_CHANNEL13_POSITIVE_PHASE_PERIOD | _TAUB_CHANNEL1_POSITIVE_PHASE_PERIOD;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TPS;
    __syncp();

    /* Set TAUB0O1 pin */
    PORT.PIBC10 &= _PORT_CLEAR_BIT11;
    PORT.PBDC10 &= _PORT_CLEAR_BIT11;
    PORT.PM10 |= _PORT_SET_BIT11;  
    PORT.PMC10 &= _PORT_CLEAR_BIT11;
    PORT.PFC10 |= _PORT_SET_BIT11;  
    PORT.PFCE10 |= _PORT_SET_BIT11;  
    PORT.PMC10 |= _PORT_SET_BIT11;  
    PORT.PM10 &= _PORT_CLEAR_BIT11;
    /* Set TAUB0O13 pin */
    PORT.PIBC11 &= _PORT_CLEAR_BIT1;
    PORT.PBDC11 &= _PORT_CLEAR_BIT1;
    PORT.PM11 |= _PORT_SET_BIT1;  
    PORT.PMC11 &= _PORT_CLEAR_BIT1;
    PORT.PFC11 |= _PORT_SET_BIT1;  
    PORT.PFCE11 |= _PORT_SET_BIT1;  
    PORT.PMC11 |= _PORT_SET_BIT1;  
    PORT.PM11 &= _PORT_CLEAR_BIT1;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel0_Start
* Description  : This function clears TAUB00 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel0_Start(void)
{
    /* Clear INTTAUB0I0 request and enable operation */
    INTC2.ICTAUB0I0.BIT.RFTAUB0I0 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUB0I0.BIT.MKTAUB0I0 = _INT_PROCESSING_ENABLED;    
    /* Clear INTTAUB0I13 request and enable operation */
    INTC2.ICTAUB0I13.BIT.RFTAUB0I13 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUB0I13.BIT.MKTAUB0I13 = _INT_PROCESSING_ENABLED; 
    /* Enable channel0 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL0_COUNTER_START | _TAUB_CHANNEL13_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel0_Stop
* Description  : This function disables TAUB00 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel0_Stop(void)
{
    /* Disable channel0 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL0_COUNTER_STOP | _TAUB_CHANNEL13_COUNTER_STOP;
    /* Disable INTTAUB0I0 operation and clear request */
    INTC2.ICTAUB0I0.BIT.MKTAUB0I0 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I0.BIT.RFTAUB0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTTAUB0I13 operation and clear request */
    INTC2.ICTAUB0I13.BIT.MKTAUB0I13 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I13.BIT.RFTAUB0I13 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel1_Start
* Description  : This function clears TAUB01 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel1_Start(void)
{
    /* Clear INTTAUB0I1 request and enable operation */
    INTC2.ICTAUB0I1.BIT.RFTAUB0I1 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICTAUB0I1.BIT.MKTAUB0I1 = _INT_PROCESSING_ENABLED;    
    /* Enable channel1 counter operation */
    TAUB0.TS |= _TAUB_CHANNEL1_COUNTER_START;
}
/***********************************************************************************************************************
* Function Name: R_TAUB0_Channel1_Stop
* Description  : This function disables TAUB01 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TAUB0_Channel1_Stop(void)
{
    /* Disable channel1 counter operation */
    TAUB0.TT |= _TAUB_CHANNEL1_COUNTER_STOP;
    /* Disable INTTAUB0I0 operation and clear request */
    INTC2.ICTAUB0I1.BIT.MKTAUB0I1 = _INT_PROCESSING_DISABLED;
    INTC2.ICTAUB0I1.BIT.RFTAUB0I1 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = TAUB0.TT;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
