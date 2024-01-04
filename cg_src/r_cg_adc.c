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
* File Name    : r_cg_adc.c
* Version      : Code Generator for RH850/F1K V1.01.02.02 [08 May 2018]
* Device(s)    : R7F701623(LQFP144pin)
* Tool-Chain   : CCRH
* Description  : This file implements device driver for ADCA module.
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
#include "r_cg_adc.h"
/* Start user code for include. Do not edit comment generated here */
uint16_t adc_buffer_raw[ADC0_SG1_nVCH + ADC1_SG1_nVCH];
uint32_t adc_buffer_sum[ADC0_SG1_nVCH + ADC1_SG1_nVCH];
uint16_t adc_buffer_avg[ADC0_SG1_nVCH + ADC1_SG1_nVCH];
uint8_t short_ckt_flag[ADC0_SG1_nVCH + ADC1_SG1_nVCH];

void getADC0n1_result()
{
    R_ADC0_ScanGroup1_GetResult(adc_buffer_raw);
    R_ADC1_ScanGroup1_GetResult(adc_buffer_raw+ADC0_SG1_nVCH);
}
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint32_t g_cg_sync_read;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_ADC0_Create
* Description  : This function initializes ADC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC0_Create(void)
{
    /* Disable ADC0 error interrupt (INTADCA0ERR) operation and clear request */
    INTC2.ICADCA0ERR.BIT.MKADCA0ERR = _INT_PROCESSING_DISABLED;
    INTC2.ICADCA0ERR.BIT.RFADCA0ERR = _INT_REQUEST_NOT_OCCUR;
    /* Disable ADC0 SG1 end interrupt (INTADCA0I0) operation and clear request */
    INTC1.ICADCA0I0.BIT.MKADCA0I0 = _INT_PROCESSING_DISABLED;
    INTC1.ICADCA0I0.BIT.RFADCA0I0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable ADC0 SG2 end interrupt (INTADCA0I1) operation and clear request */
    INTC1.ICADCA0I1.BIT.MKADCA0I1 = _INT_PROCESSING_DISABLED;
    INTC1.ICADCA0I1.BIT.RFADCA0I1 = _INT_REQUEST_NOT_OCCUR;
    /* Disable ADC0 SG3 end interrupt (INTADCA0I2) operation and clear request */
    INTC1.ICADCA0I2.BIT.MKADCA0I2 = _INT_PROCESSING_DISABLED;
    INTC1.ICADCA0I2.BIT.RFADCA0I2 = _INT_REQUEST_NOT_OCCUR;
    /* Set ADC0 global setting */
    ADCA0.ADCR.UINT32 = _ADC_12_BIT_MODE;
    ADCA0.SMPCR.UINT32 = _ADC_24_CYCLES;
    ADCA0.SFTCR.UINT32 = _ADC_READ_CLEAR_DISABLED;
    ADCA0.ULLMTBR0.UINT32 = _ADC0_UPPER_LIMIT_TABLE0 | _ADC0_LOWER_LIMIT_TABLE0;
    ADCA0.ULLMTBR1.UINT32 = _ADC0_UPPER_LIMIT_TABLE1 | _ADC0_LOWER_LIMIT_TABLE1;
    ADCA0.ULLMTBR2.UINT32 = _ADC0_UPPER_LIMIT_TABLE2 | _ADC0_LOWER_LIMIT_TABLE2;
    /* Set ADC0 scan group setting */
    ADCA0.SGVCSP1.UINT32 = _ADC0_SG1_START_POINTER;
    ADCA0.SGVCEP1.UINT32 = _ADC0_SG1_END_POINTER;
    ADCA0.SGCR1.UINT32 = _ADC_SG_SCAN_MODE_CONTINUOUS | _ADC_SG_SCAN_END_INT_DISABLE | _ADC_SG_HW_TRIGGER_DISABLE;
    /* Set ADC0 vitrual channel setting */
    ADCA0.VCR00.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN00;
    ADCA0.VCR01.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR02.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN01;
    ADCA0.VCR03.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR04.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN02;
    ADCA0.VCR05.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR06.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN03;
    ADCA0.VCR07.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR08.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN04;
    ADCA0.VCR09.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR10.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR11.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR12.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN06;
    ADCA0.VCR13.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR14.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN08;
    ADCA0.VCR15.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR16.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN13;
    ADCA0.VCR17.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR18.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN14;
    ADCA0.VCR19.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA0.VCR20.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN15;
    ADCA0.VCR21.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    /* Set T&H setting */
    ADCA0.THCR.UINT32 = _ADC_TH_SAMPLING_AUTOMATIC;
    ADCA0.THER.UINT32 = _ADC_TH5_DISABLED | _ADC_TH4_DISABLED | _ADC_TH3_DISABLED | _ADC_TH2_DISABLED | 
                        _ADC_TH1_DISABLED | _ADC_TH0_DISABLED;
    /* Synchronization processing */
    g_cg_sync_read = ADCA0.ADHALTR.UINT32;
    __syncp();
    /* Clear ADC0 error interrupt (INTADCA0ERR) request and enable operation */
    INTC2.ICADCA0ERR.BIT.RFADCA0ERR = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICADCA0ERR.BIT.MKADCA0ERR = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_ADC0_Halt
* Description  : This function halts ADC0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC0_Halt(void)
{
    ADCA0.ADHALTR.UINT32 = _ADC_HALT;
    /* Synchronization processing */
    g_cg_sync_read = ADCA0.ADHALTR.UINT32;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_ADC0_ScanGroup1_Start
* Description  : This function enables ADC0 scan group 1 end interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC0_ScanGroup1_Start(void)
{
}
/***********************************************************************************************************************
* Function Name: R_ADC0_ScanGroup1_OperationOn
* Description  : This function starts ADC0 scan group 1 convertion.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC0_ScanGroup1_OperationOn(void)
{
    /* Enable ADC0 SG1 operation */
    ADCA0.SGSTCR1.UINT32 = _ADC_START;
}
/***********************************************************************************************************************
* Function Name: R_ADC0_ScanGroup1_GetResult
* Description  : This function gets A/D conversion result for ADC0 scan group 1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC0_ScanGroup1_GetResult(uint16_t * const buffer)
{
    uint8_t count_num, count;    
    uint32_t *addr;
    uint32_t convert_data;
    
    count_num = ADCA0.SGVCEP1.UINT32;
    count_num = count_num - ADCA0.SGVCSP1.UINT32 + 1U;
    addr = (uint32_t*)(_ADC0_VCHANNEL_DATA_BASE + (2U * ADCA0.SGVCSP1.UINT32));

    for (count = 0U; count < count_num; count = count+2U)
    {
        convert_data = (uint32_t)*addr;
        buffer[count] = (uint16_t)(convert_data & 0x0000FFFFUL);
        if ( count_num - count > 1U)
        {
            buffer[count+1U] = (uint16_t)((convert_data & 0xFFFF0000UL) >> 16U);
        }
        addr++;
    }
}
/***********************************************************************************************************************
* Function Name: R_ADC0_TH_Sampling_Start
* Description  : This function start of sampling to all TH.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC0_TH_Sampling_Start(void)
{
    ADCA0.THSMPSTCR.UINT32 = _ADC_TH_SAMPLING_ALL_START;
}
/***********************************************************************************************************************
* Function Name: R_ADC1_Create
* Description  : This function initializes ADC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC1_Create(void)
{
    /* Disable ADC1 error interrupt (INTADCA1ERR) operation and clear request */
    INTC2.ICADCA1ERR.BIT.MKADCA1ERR = _INT_PROCESSING_DISABLED;
    INTC2.ICADCA1ERR.BIT.RFADCA1ERR = _INT_REQUEST_NOT_OCCUR;
    /* Disable ADC1 SG1 end interrupt (INTADCA1I0) operation and clear request */
    INTC2.ICADCA1I0.BIT.MKADCA1I0 = _INT_PROCESSING_DISABLED;
    INTC2.ICADCA1I0.BIT.RFADCA1I0 = _INT_REQUEST_NOT_OCCUR;
    /* Disable ADC1 SG2 end interrupt (INTADCA1I1) operation and clear request */
    INTC2.ICADCA1I1.BIT.MKADCA1I1 = _INT_PROCESSING_DISABLED;
    INTC2.ICADCA1I1.BIT.RFADCA1I1 = _INT_REQUEST_NOT_OCCUR;
    /* Disable ADC1 SG3 end interrupt (INTADCA1I2) operation and clear request */
    INTC2.ICADCA1I2.BIT.MKADCA1I2 = _INT_PROCESSING_DISABLED;
    INTC2.ICADCA1I2.BIT.RFADCA1I2 = _INT_REQUEST_NOT_OCCUR;
    /* Set ADC0 global setting */
    ADCA1.ADCR.UINT32 = _ADC_12_BIT_MODE;
    ADCA1.SMPCR.UINT32 = _ADC_24_CYCLES;
    ADCA1.SFTCR.UINT32 = _ADC_READ_CLEAR_DISABLED;
    ADCA1.ULLMTBR0.UINT32 = _ADC1_UPPER_LIMIT_TABLE0 | _ADC1_LOWER_LIMIT_TABLE0;
    ADCA1.ULLMTBR1.UINT32 = _ADC1_UPPER_LIMIT_TABLE1 | _ADC1_LOWER_LIMIT_TABLE1;
    ADCA1.ULLMTBR2.UINT32 = _ADC1_UPPER_LIMIT_TABLE2 | _ADC1_LOWER_LIMIT_TABLE2;
    /* Set ADC0 scan group setting */
    ADCA1.SGVCSP1.UINT32 = _ADC1_SG1_START_POINTER;
    ADCA1.SGVCEP1.UINT32 = _ADC1_SG1_END_POINTER;
    ADCA1.SGCR1.UINT32 = _ADC_SG_SCAN_MODE_CONTINUOUS | _ADC_SG_SCAN_END_INT_DISABLE | _ADC_SG_HW_TRIGGER_DISABLE;
    /* Set ADC0 vitrual channel setting */
    ADCA1.VCR00.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN00;
    ADCA1.VCR01.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN01;
    ADCA1.VCR02.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN02;
    ADCA1.VCR03.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN03;
    ADCA1.VCR04.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN04;
    ADCA1.VCR05.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN05;
    ADCA1.VCR06.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN06;
    ADCA1.VCR07.UINT32 = _ADC_VIRTUAL_CHANNEL_END_INT_DISABLE | _ADC_LIMIT_TABLE_SELECT_NONE | 
                         _ADC_PHYSICAL_CHANNEL_AN07;
    /* Synchronization processing */
    g_cg_sync_read = ADCA1.ADHALTR.UINT32;
    __syncp();
    /* Clear ADC1 error interrupt (INTADCA1ERR) request and enable operation */
    INTC2.ICADCA1ERR.BIT.RFADCA1ERR = _INT_REQUEST_NOT_OCCUR;
    INTC2.ICADCA1ERR.BIT.MKADCA1ERR = _INT_PROCESSING_ENABLED;    
}
/***********************************************************************************************************************
* Function Name: R_ADC1_Halt
* Description  : This function halts ADC1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC1_Halt(void)
{
    ADCA1.ADHALTR.UINT32 = _ADC_HALT;
    /* Synchronization processing */
    g_cg_sync_read = ADCA1.ADHALTR.UINT32;
    __syncp();
}
/***********************************************************************************************************************
* Function Name: R_ADC1_ScanGroup1_Start
* Description  : This function enables ADC1 scan group 1 end interrupt.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC1_ScanGroup1_Start(void)
{
}
/***********************************************************************************************************************
* Function Name: R_ADC1_ScanGroup1_OperationOn
* Description  : This function starts ADC1 scan group 1 convertion.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC1_ScanGroup1_OperationOn(void)
{
    /* Enable ADC1 SG1 operation */
    ADCA1.SGSTCR1.UINT32 = _ADC_START;
}
/***********************************************************************************************************************
* Function Name: R_ADC1_ScanGroup1_GetResult
* Description  : This function gets A/D conversion result for ADC1 scan group 1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_ADC1_ScanGroup1_GetResult(uint16_t * const buffer)
{
    uint8_t count_num, count;    
    uint32_t *addr;
    uint32_t convert_data;
    
    count_num = ADCA1.SGVCEP1.UINT32;
    count_num = count_num - ADCA1.SGVCSP1.UINT32 + 1U;
    addr = (uint32_t*)(_ADC1_VCHANNEL_DATA_BASE + (2U * ADCA1.SGVCSP1.UINT32));

    for (count = 0U; count < count_num; count = count+2U)
    {
        convert_data = (uint32_t)*addr;
        buffer[count] = (uint16_t)(convert_data & 0x0000FFFFUL);
        if ( count_num - count > 1U)
        {
            buffer[count+1U] = (uint16_t)((convert_data & 0xFFFF0000UL) >> 16U);
        }
        addr++;
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
