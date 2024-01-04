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
* File Name    : r_cg_taub_user.c
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
#include "r_cg_port.h"
#include "state.h"
#include "can_out.h"
#include "eeprom_tork.h"
#include "r_cg_adc.h"
#include "can_in.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint8_t tsl_R_counter = 0;
uint8_t tsl_R_counterMAX = 250;
uint8_t tsl_L_counter = 0;
uint8_t tsl_L_counterMAX = 250;
uint8_t led_counter = 0;
uint8_t send_CAN_counter = 0;
uint32_t odo_counter = 0;
uint32_t odo_averager = 0;
uint32_t odo_remainder = 0;
uint8_t enableOutFrameMaker = 1;
uint16_t chargerFrameAckCounter = 0;
uint16_t lastChargerFrameCounter = 0;
uint16_t cMotConFrameAckCounter = 0;
uint16_t lastCMotConFrameCounter = 0;
uint16_t bmsFrameAckCounter = 0;
uint16_t lastbmsFrameCounter = 0;
uint8_t canIdCounter = 0;
uint8_t sleepTest = 0;
uint16_t tsl_L_Amps = 0;
uint16_t tsl_R_Amps = 0;
uint16_t tsl_L_avg = 0;
uint16_t tsl_R_avg = 0;
uint16_t tsl_R_avgCounter = 0;
uint16_t tsl_L_avgCounter = 0;
uint32_t LastOdoCount = 0;
uint32_t LastSOCwatHr = 0;
uint32_t aKilometer = 0;

uint32_t ChargerADC = 0;
uint32_t ChargerADCSampler = 0;

uint8_t Stamping_50x = 0;
uint8_t lastStamped_508 = 0 ;
uint8_t lastStamped_509 = 0; 
uint16_t chademoFrameAckCounter = 0;
uint32_t taub_count = 0;

uint8_t can_group_180ms = 0;

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_taub0_channel0_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_taub0_channel0_interrupt(enable=false, channel=142, fpu=true, callt=false)
void r_taub0_channel0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_taub0_channel1_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_taub0_channel1_interrupt(enable=false, channel=143, fpu=true, callt=false)
void r_taub0_channel1_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	// 3600 micro seconds 
	taub_count++;
	//========================== CHarger Alive Begins =================================
    
     if(chargerFrameAckCounter++ == 200)
	{
		chargerFrameAckCounter = 0;
		if(lastChargerFrameCounter == chargerFrameCounter)
		{	chargerConnectedOnCAN = 0;			}
		else
		{
			chargerConnectedOnCAN = 1;
			lastChargerFrameCounter = chargerFrameCounter;
		}
	
	}
	
	//============================== Chademo Alive begins =============================
	
	if(chademoFrameAckCounter++ == 200)
	{
		chademoFrameAckCounter = 0;
		
		if( (Stamped_508 == lastStamped_508 ) ||  (Stamped_509 == lastStamped_509 ) )
		{
			Stamping_50x = 0;
			
		}
		else
		{
			Stamping_50x = 1;
			
			lastStamped_508 = Stamped_508;
			lastStamped_509 = Stamped_509;
		}
	
	}

        /* End user code. Do not edit comment generated here */
}
/***********************************************************************************************************************
* Function Name: r_taub0_channel13_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma interrupt r_taub0_channel13_interrupt(enable=false, channel=155, fpu=true, callt=false)
void r_taub0_channel13_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
