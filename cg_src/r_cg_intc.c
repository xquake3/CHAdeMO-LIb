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
* File Name    : r_cg_intc.c
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
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_INTC_Create
* Description  : This function initializes INTP module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTC_Create(void)
{		
    /* Disable INTP2 operation and clear request */
    INTC2.ICP2.BIT.MKP2 = _INT_PROCESSING_DISABLED;
    INTC2.ICP2.BIT.RFP2 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTP5 operation and clear request */
    INTC2.ICP5.BIT.MKP5 = _INT_PROCESSING_DISABLED;
    INTC2.ICP5.BIT.RFP5 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTP6 operation and clear request */
    INTC2.ICP6.BIT.MKP6 = _INT_PROCESSING_DISABLED;
    INTC2.ICP6.BIT.RFP6 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTP7 operation and clear request */
    INTC2.ICP7.BIT.MKP7 = _INT_PROCESSING_DISABLED;
    INTC2.ICP7.BIT.RFP7 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTP8 operation and clear request */
    INTC2.ICP8.BIT.MKP8 = _INT_PROCESSING_DISABLED;
    INTC2.ICP8.BIT.RFP8 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTP9 operation and clear request */
    INTC2.ICP9.BIT.MKP9 = _INT_PROCESSING_DISABLED;
    INTC2.ICP9.BIT.RFP9 = _INT_REQUEST_NOT_OCCUR;
    /* Disable INTP13 operation and clear request */
    INTC2.ICP13.BIT.MKP13 = _INT_PROCESSING_DISABLED;
    INTC2.ICP13.BIT.RFP13 = _INT_REQUEST_NOT_OCCUR;
    /* Set INTP2 setting */
    INTC2.ICP2.BIT.TBP2 = _INT_TABLE_VECTOR;
    INTC2.ICP2.UINT16 &= _INT_PRIORITY_LOWEST;
    FCLA0.CTL2_INTPL = _INTC_EDGE_FALLING;
    /* Set INTP5 setting */
    INTC2.ICP5.BIT.TBP5 = _INT_TABLE_VECTOR;
    INTC2.ICP5.UINT16 &= _INT_PRIORITY_LOWEST;
    FCLA0.CTL5_INTPL = _INTC_EDGE_FALLING;
    /* Set INTP6 setting */
    INTC2.ICP6.BIT.TBP6 = _INT_TABLE_VECTOR;
    INTC2.ICP6.UINT16 &= _INT_PRIORITY_LEVEL3;
    FCLA0.CTL6_INTPL = _INTC_EDGE_FALLING;
    /* Set INTP7 setting */
    INTC2.ICP7.BIT.TBP7 = _INT_TABLE_VECTOR;
    INTC2.ICP7.UINT16 &= _INT_PRIORITY_LEVEL1;
    FCLA0.CTL7_INTPL = _INTC_EDGE_FALLING;
    /* Set INTP8 setting */
    INTC2.ICP8.BIT.TBP8 = _INT_TABLE_VECTOR;
    INTC2.ICP8.UINT16 &= _INT_PRIORITY_LEVEL5;
    FCLA0.CTL0_INTPH = _INTC_EDGE_RISING;
    /* Set INTP9 setting */
    INTC2.ICP9.BIT.TBP9 = _INT_TABLE_VECTOR;
    INTC2.ICP9.UINT16 &= _INT_PRIORITY_LEVEL2;
    FCLA0.CTL1_INTPH = _INTC_EDGE_FALLING;
    /* Set INTP13 setting */
    INTC2.ICP13.BIT.TBP13 = _INT_TABLE_VECTOR;
    INTC2.ICP13.UINT16 &= _INT_PRIORITY_LOWEST;
    FCLA0.CTL5_INTPH = _INTC_EDGE_FALLING;
    /* Synchronization processing */
    g_cg_sync_read = FCLA0.CTL2_INTPL;
    __syncp();
    /* Set INTP2 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT5;
    PORT.PBDC0 &= _PORT_CLEAR_BIT5;
    PORT.PM0 |= _PORT_SET_BIT5;  
    PORT.PMC0 &= _PORT_CLEAR_BIT5;
    PORT.PIPC0 &= _PORT_CLEAR_BIT5;
    PORT.PFC0 &= _PORT_CLEAR_BIT5;
    PORT.PFCE0 &= _PORT_CLEAR_BIT5;
    PORT.PFCAE0 &= _PORT_CLEAR_BIT5;
    PORT.PMC0 |= _PORT_SET_BIT5;  
    /* Set INTP5 pin */
    PORT.PIBC0 &= _PORT_CLEAR_BIT13;
    PORT.PBDC0 &= _PORT_CLEAR_BIT13;
    PORT.PM0 |= _PORT_SET_BIT13;  
    PORT.PMC0 &= _PORT_CLEAR_BIT13;
    PORT.PIPC0 &= _PORT_CLEAR_BIT13;
    PORT.PFC0 &= _PORT_CLEAR_BIT13;
    PORT.PFCE0 &= _PORT_CLEAR_BIT13;
    PORT.PFCAE0 |= _PORT_SET_BIT13;  
    PORT.PMC0 |= _PORT_SET_BIT13;  
    /* Set INTP6 pin */
    PORT.PIBC8 &= _PORT_CLEAR_BIT2;
    PORT.PBDC8 &= _PORT_CLEAR_BIT2;
    PORT.PM8 |= _PORT_SET_BIT2;  
    PORT.PMC8 &= _PORT_CLEAR_BIT2;
    PORT.PFC8 &= _PORT_CLEAR_BIT2;
    PORT.PFCE8 |= _PORT_SET_BIT2;  
    PORT.PMC8 |= _PORT_SET_BIT2;  
    /* Set INTP7 pin */
    PORT.PIBC8 &= _PORT_CLEAR_BIT3;
    PORT.PBDC8 &= _PORT_CLEAR_BIT3;
    PORT.PM8 |= _PORT_SET_BIT3;  
    PORT.PMC8 &= _PORT_CLEAR_BIT3;
    PORT.PFC8 &= _PORT_CLEAR_BIT3;
    PORT.PFCE8 |= _PORT_SET_BIT3;  
    PORT.PMC8 |= _PORT_SET_BIT3;  
    /* Set INTP8 pin */
    PORT.PIBC8 &= _PORT_CLEAR_BIT4;
    PORT.PBDC8 &= _PORT_CLEAR_BIT4;
    PORT.PM8 |= _PORT_SET_BIT4;  
    PORT.PMC8 &= _PORT_CLEAR_BIT4;
    PORT.PFC8 &= _PORT_CLEAR_BIT4;
    PORT.PFCE8 |= _PORT_SET_BIT4;  
    PORT.PMC8 |= _PORT_SET_BIT4;  
    /* Set INTP9 pin */
    PORT.PIBC8 &= _PORT_CLEAR_BIT5;
    PORT.PBDC8 &= _PORT_CLEAR_BIT5;
    PORT.PM8 |= _PORT_SET_BIT5;  
    PORT.PMC8 &= _PORT_CLEAR_BIT5;
    PORT.PFC8 &= _PORT_CLEAR_BIT5;
    PORT.PFCE8 |= _PORT_SET_BIT5;  
    PORT.PMC8 |= _PORT_SET_BIT5;  
    /* Set INTP13 pin */
    PORT.PIBC1 &= _PORT_CLEAR_BIT0;
    PORT.PBDC1 &= _PORT_CLEAR_BIT0;
    PORT.PM1 |= _PORT_SET_BIT0;  
    PORT.PMC1 &= _PORT_CLEAR_BIT0;
    PORT.PFC1 |= _PORT_SET_BIT0;  
    PORT.PFCE1 &= _PORT_CLEAR_BIT0;
    PORT.PFCAE1 &= _PORT_CLEAR_BIT0;
    PORT.PMC1 |= _PORT_SET_BIT0;  
}
/***********************************************************************************************************************
* Function Name: R_INTP2_Start
* Description  : This function clears INTP2 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP2_Start(void)
{
    /* Clear INTP2 request and enable operation */
    INTC2.ICP2.BIT.RFP2 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP2.BIT.MKP2 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_INTP2_Stop
* Description  : This function disables INTP2 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP2_Stop(void)
{
    /* Disable INTP2 operation and clear request */
    INTC2.ICP2.BIT.MKP2 = _INT_PROCESSING_DISABLED;
    INTC2.ICP2.BIT.RFP2 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP2.UINT16;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_INTP5_Start
* Description  : This function clears INTP5 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP5_Start(void)
{
    /* Clear INTP5 request and enable operation */
    INTC2.ICP5.BIT.RFP5 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP5.BIT.MKP5 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_INTP5_Stop
* Description  : This function disables INTP5 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP5_Stop(void)
{
    /* Disable INTP5 operation and clear request */
    INTC2.ICP5.BIT.MKP5 = _INT_PROCESSING_DISABLED;
    INTC2.ICP5.BIT.RFP5 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP5.UINT16;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_INTP6_Start
* Description  : This function clears INTP6 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP6_Start(void)
{
    /* Clear INTP6 request and enable operation */
    INTC2.ICP6.BIT.RFP6 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP6.BIT.MKP6 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_INTP6_Stop
* Description  : This function disables INTP6 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP6_Stop(void)
{
    /* Disable INTP6 operation and clear request */
    INTC2.ICP6.BIT.MKP6 = _INT_PROCESSING_DISABLED;
    INTC2.ICP6.BIT.RFP6 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP6.UINT16;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_INTP7_Start
* Description  : This function clears INTP7 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP7_Start(void)
{
    /* Clear INTP7 request and enable operation */
    INTC2.ICP7.BIT.RFP7 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP7.BIT.MKP7 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_INTP7_Stop
* Description  : This function disables INTP7 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP7_Stop(void)
{
    /* Disable INTP7 operation and clear request */
    INTC2.ICP7.BIT.MKP7 = _INT_PROCESSING_DISABLED;
    INTC2.ICP7.BIT.RFP7 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP7.UINT16;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_INTP8_Start
* Description  : This function clears INTP8 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP8_Start(void)
{
    /* Clear INTP8 request and enable operation */
    INTC2.ICP8.BIT.RFP8 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP8.BIT.MKP8 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_INTP8_Stop
* Description  : This function disables INTP8 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP8_Stop(void)
{
    /* Disable INTP8 operation and clear request */
    INTC2.ICP8.BIT.MKP8 = _INT_PROCESSING_DISABLED;
    INTC2.ICP8.BIT.RFP8 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP8.UINT16;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_INTP9_Start
* Description  : This function clears INTP9 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP9_Start(void)
{
    /* Clear INTP9 request and enable operation */
    INTC2.ICP9.BIT.RFP9 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP9.BIT.MKP9 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_INTP9_Stop
* Description  : This function disables INTP9 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP9_Stop(void)
{
    /* Disable INTP9 operation and clear request */
    INTC2.ICP9.BIT.MKP9 = _INT_PROCESSING_DISABLED;
    INTC2.ICP9.BIT.RFP9 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP9.UINT16;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_INTP13_Start
* Description  : This function clears INTP13 interrupt flag and enables interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP13_Start(void)
{
    /* Clear INTP13 request and enable operation */
    INTC2.ICP13.BIT.RFP13 = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICP13.BIT.MKP13 = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_INTP13_Stop
* Description  : This function disables INTP13 interrupt and clears interrupt flag.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_INTP13_Stop(void)
{
    /* Disable INTP13 operation and clear request */
    INTC2.ICP13.BIT.MKP13 = _INT_PROCESSING_DISABLED;
    INTC2.ICP13.BIT.RFP13 = _INT_REQUEST_NOT_OCCUR;
    /* Synchronization processing */
    g_cg_sync_read = INTC2.ICP13.UINT16;
    __syncp();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
