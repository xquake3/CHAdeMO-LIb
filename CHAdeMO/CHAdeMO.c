#include "r_cg_macrodriver.h"
#include "r_cg_port.h"
#include "iodefine.h"
#include "r_cg_userdefine.h"
#include "can_out.h"
#include "can_in.h"
#include "r_cg_ostm.h"
#include "r_cg_taub.h"
#include "CHAdeMO.h"
#include "state.h"

int dummyErrorCounter = 0;
/*

uint8_t mainState_0_8_1537 ;
uint8_t Sub_8_8_1537 = '0' ;
uint8_t LastFunctionalState_16_8_1537 ;
uint8_t LastSubState_24_8_1537 ;
uint8_t CpPp_32_8_1537 ;
uint8_t EcuChgIgn_40_1_1537;
uint8_t ChgIsRunning_56_1_1537;
uint8_t VpDetected_57_1_1537;


//================1289 = 0x509
uint8_t ePtwProtocolNumber_0_8_1289 ;
uint8_t ratedOuputPowerValue_8_8_1289 ;
uint16_t presentOutputVoltageValue_16_16_1289 ; // 1 decimal, while parsing it has been multiplied by 10 to go till second decimal // as per scope of protocol ( page 7 ) is designed for maximum 100 Amps
uint16_t presentOutputCurrentValue_32_16_1289 ; //  1 decimal place while parsing it has been multiplied by 10 to go till second decimal // as per scope of protocol ( page 7 ) is designed for maximum 120 Volts
uint16_t remainingChargingTime_48_16_1289 ;


 //================1288 = 0x508 Charger
uint8_t chargingSystemError_0_1_1288 ;
uint8_t chargerError_1_1_1288;
uint8_t batteryIncompatibility_2_1_1288;
uint8_t chargerStopControl_8_1_1288 ;
uint8_t chargerStatus_9_1_1288 ;
uint8_t latchHolding_10_1_1288 ;
uint8_t chargerReady_11_1_1288 ;
uint8_t ChstdByBeforeChrgStarts_12_1_1288 ;
uint16_t availableOutputVoltageValue_16_16_1288 ; // 1 decimal place
uint16_t availableOutputCurrentValue_32_16_1288 ; // 1 decimal place
uint16_t outputVoltageUpThershold_48_16_1288 ;


//----0x500 == 1280 frame =======================================CHAdeMO CHADEMO chademo=======-
uint8_t chargingSystemError_0_1_1280 ;
uint8_t batteryOverVoltage_1_1_1280 ;
uint8_t batteryUnderVoltage_2_1_1280 ;
uint8_t batteryCurrentDeviation_3_1_1280 ;
uint8_t highBatteryTemprature_4_1_1280 ;
uint8_t voltageDeviation_5_1_1280 ;
uint8_t reserved_6_1_1280 ;
uint8_t reserved_7_1_1280 ;
uint8_t vehicleChargingEnabled_8_1_1280 ;
uint8_t vehicleStatus_9_1_1280 ;
uint8_t vehicleChargingPosition_10_1_1280 ;
uint8_t vehicleChargingStopControl_11_1_1280 ;
uint8_t standByRequestBeforeChargingStarts_12_1_1280 ;
uint8_t reserved_13_1_1280 ;
uint8_t charginCurrentRequestValue1_16_8_1280 ;
uint8_t charginCurrentRequestValue2_24_8_1280 ;
uint8_t charginVoltageTargetValue1_32_8_1280 ;
uint8_t charginVoltageTargetValue2_40_8_1280 ;
uint8_t batteryVoltageUpperLimit1_48_8_1280 ;
uint8_t batteryVoltageUpperLimit2_56_8_1280 ;


//----0x501 == 1281 frame ==============================================-
uint8_t ePtwProtocolNumber_0_8_1281 ;
uint8_t chargingRate_8_8_1281 ;
uint8_t maximumChargingTime1_16_8_1281 ;
uint8_t maximumChargingTime2_24_8_1281 ;
uint8_t estimatedChargingTime1_32_8_1281 ;
uint8_t estimatedChargingTime2_40_8_1281 ;

*/
uint8_t cp_ppPin = 0;

uint8_t Chad_StopCharging = 0;

uint32_t LoopCounter = 0;

#define BattVoltForCharger BatVolt_0_32_256			  /* 2 decimal place */
#define BattCurrentForCharger BatteryCurrent_0_32_261 /* 2 decimal place */
#define BattOverVoltageFlag overVolt_0_1_289
#define BattUnderVoltageFlag underVolt_1_1_289
#define BattOverTempFlag overTemp_2_1_289
#define BattUnderTempFlag underTemp_3_1_289

uint16_t currentOffset = 200;
uint16_t voltageOffset = 200;

uint8_t errorFlag = 0;

uint8_t VP_ON = 1;

uint8_t ChargeInterrupt = 0;

/* ChadSubTimeOut ; defined and incremented in r_cg_ostm */
/* chargerConnectedOnCAN; defined in state.c & maintained in taub_user */

uint8_t vhSubroutines[10]; // space 0 is reserved for vH CAN transmission 500 & 501,
						   // space 9 is reserved for VP high detection. space 8 is reserved for VP low detection;

void ChargerRunning()
{

	ChgIsRunning_56_1_1537 = Chad_ChargerIsRunning;
	VpDetected_57_1_1537 = vehicle_state[VPorCHRG2Detected];

	if (vhSubroutines[8] == 1)
	{
		vh_sub_08();
	}
	if (vhSubroutines[9] == 1)
	{
		vh_sub_09();
	}
	if (vhSubroutines[4] == 1)
	{
		vh_sub_04();
	}
	if (vhSubroutines[2] == 1)
	{
		vh_sub_02();
	}
	if (vhSubroutines[3] == 1)
	{
		vh_sub_03();
	}

	//==================================== STOP SEQUENCE ========================================================

	if ((Chad_StopCharging == 1))
	{

		Chad_StopCharging = 0;
		Sub_8_8_1537 = 'S';
		mainState_0_8_1537 = 'H';
		vehicleChargingStopControl_11_1_1280 = 1;
		vhSubroutines[4] = 0;

		/* TO-DO
		 CP-PP pulled low  : Emergency stop conrol at OT and OC, or BMS CAN missing
		 CP_PP_OF;
		 CpPp_32_8_1537 = 0;
		*/

		/* TO-DO
		 define error flags here and set it to CAN frame
		*/

		vhSubroutines[3] = 0;
		ChadSubTimeOut = 0;
	}
	if ((mainState_0_8_1537 == 'H') && (Sub_8_8_1537 == 'S'))
	{
		if ((chargerStopControl_8_1_1288 == 1) && (ChstdByBeforeChrgStarts_12_1_1288 == 0))
		{
			Sub_8_8_1537 = '7';

			chargingSystemError_0_1_1280 = 1;
			vehicleChargingStopControl_11_1_1280 = 1; // E6

			vehicleChargingStopControl_11_1_1280 = 1;
			vehicleChargingEnabled_8_1_1280 = 0;
			charginCurrentRequestValue1_16_8_1280 = 0;
			charginCurrentRequestValue2_24_8_1280 = 0;
			standByRequestBeforeChargingStarts_12_1_1280 = 0;
			ChadSubTimeOut = 0;
		}
		if (ChadSubTimeOut > 150)
		{
			CHAdeMO_hardStop();
		}
	}

	if ((mainState_0_8_1537 == 'H') && (Sub_8_8_1537 == '7'))
	{
		if (ChadSubTimeOut < 15)
		{
		}
		else if (ChadSubTimeOut < 35)
		{
			if (chargerStatus_9_1_1288 == 0)
			{
				CP_PP_OF;
				CpPp_32_8_1537 = 0;

				mainState_0_8_1537 = 'I';
				Sub_8_8_1537 = '8';

				ChadSubTimeOut = 0;
			}
		}
		else
		{

			CHAdeMO_hardStop();
		}
	}
	if ((mainState_0_8_1537 == 'I'))
	{
		/*
		contactor weld diagnosis
		*/

		EcuChgIgn_40_1_1537 = 0;

		if (ChadSubTimeOut < 25)
		{

			if (chargerStopControl_8_1_1288 == 0)
			{
				mainState_0_8_1537 = 'J';

				vehicleStatus_9_1_1280 = 1;

				vehicleChargingStopControl_11_1_1280 = 0;

				ChadSubTimeOut = 0;

				vhSubroutines[4] = 0;
			}
		}
		else
		{
			CHAdeMO_hardStop();
		}
	}
	if ((mainState_0_8_1537 == 'J'))
	{
		if (ChadSubTimeOut < 55)
		{
			if ((chargerReady_11_1_1288 == 0) && (Stamping_50x != 1))
			{
				vhSubroutines[0] = 0;

				CHAdeMO_hardStop();
			}
		}
		else
		{
			CHAdeMO_hardStop();
		}
	}
}

void BeginCHAdemo()
{
	vhSubroutines[9] = 1;
}

void vh_sub_08() // CHAdeMO/SUB09 reserved for VP detection as low
{

	if ((vehicle_state[VPorCHRG2Detected] == 0) && (Sub_8_8_1537 != '9'))
	{

		ChadSubTimeOut = 0;

		Sub_8_8_1537 = '9';
	}
	if (Sub_8_8_1537 == '9')
	{
		if (ChadSubTimeOut > 20)
		{
			vhSubroutines[8] = 0;
			Chad_ChargerIsRunning = 0;
		}
	}
}

void vh_sub_09() // CHAdeMO/SUB09 reserved for VP detection as high
{
	if (vehicle_state[VPorCHRG2Detected])
	{
		EcuChgIgn_40_1_1537 = 0;
		Stamped_508 = 0;
		Stamped_509 = 0;

		Chad_ChargerIsRunning = 1;

		ePtwProtocolNumber_0_8_1281 = 3;

		charginCurrentRequestValue1_16_8_1280 = 0;
		charginCurrentRequestValue2_24_8_1280 = 0;
		charginVoltageTargetValue1_32_8_1280 = 0;
		charginVoltageTargetValue2_40_8_1280 = 0;

		vehicleChargingEnabled_8_1_1280 = 0;
		chargingSystemError_0_1_1280 = 0;

		CP_PP_OF;
		CpPp_32_8_1537 = 0;

		errorFlag = 0;
		ChadSubTimeOut = 0;
		chargingRate_8_8_1281 = 5;

		standByRequestBeforeChargingStarts_12_1_1280 = 1;

		vehicleChargingStopControl_11_1_1280 = 0;

		vehicleStatus_9_1_1280 = 1;

		mainState_0_8_1537 = 'B';
		Sub_8_8_1537 = '0';

		vhSubroutines[4] = 1;
		vhSubroutines[0] = 1;

		LoopCounter = 0;

		vhSubroutines[9] = 0;
	}
}

void vh_sub_04() // CHAdeMO/SUB04.png
{
	if (mainState_0_8_1537 == 'B')
	{
		if (ChadSubTimeOut < 4)
		{
			mainState_0_8_1537 = 'C';
			Sub_8_8_1537 = '1';
		}
	}
	else if (mainState_0_8_1537 == 'C')
	{
		if (ChadSubTimeOut < 25)
		{

			if ((Stamped_508 > 0) && (Stamped_509 > 0))
			{

				mainState_0_8_1537 = 'D';
				vhSubroutines[2] = 1;

				ChadSubTimeOut = 0;
			}
		}
		else
		{
			chargingSystemError_0_1_1280 = 1;
			vehicleChargingStopControl_11_1_1280 = 1; // E6

			errorFlag = 'O';
			raiseChademoError();
		}
	}
	else if ((mainState_0_8_1537 > 'C') && (mainState_0_8_1537 < 'K'))
	{

		// Check if VP is ON
		if (LoopCounter++ > 0x5FFFF)
			if (mainState_0_8_1537 > 'G')
				if ((Stamping_50x != 1))
				{
					errorFlag = 'M';
				}
		if (VP_ON != 1)
		{
			errorFlag = 'P';
		}
		if (chargerStopControl_8_1_1288 != 0)
		{
			errorFlag = 'S';
		}
		if (chargingSystemError_0_1_1288 != 0)
		{
			errorFlag = 'E';
		}
		if (batteryIncompatibility_2_1_1288 != 0)
		{
			errorFlag = 'I';
		}
		if (BattOverVoltageFlag != 0)
		{
			errorFlag = 'V';
		}
		if (BattUnderVoltageFlag != 0)
		{
			errorFlag = 'v';
		}
		if (BattOverTempFlag != 0)
		{
			errorFlag = 'T';
		}
		if (BattUnderTempFlag != 0)
		{
			errorFlag = 'T';
		}
		if (mainState_0_8_1537 == 'F')
		{
			if (ChadSubTimeOut > 120)
			{
				errorFlag = 't';

				chargingSystemError_0_1_1280 = 1;
				vehicleChargingStopControl_11_1_1280 = 1; // E6
			}
			if (chargerReady_11_1_1288 == 1)
			{
				charginCurrentRequestValue1_16_8_1280 = 0;
				charginCurrentRequestValue2_24_8_1280 = 0;

				vehicleStatus_9_1_1280 = 0;

				mainState_0_8_1537 = 'G';

				Sub_8_8_1537 = '5';

				ChadSubTimeOut = 0;
			}
		}
		if (mainState_0_8_1537 == 'G')
		{
			if (chargerStatus_9_1_1288 == 1)
			{
				Sub_8_8_1537 = '5';
				mainState_0_8_1537 = 'H';
				vhSubroutines[3] = 1; // Subroutine 3 begins here
			}
			if (ChadSubTimeOut > 45)
			{
				chargingSystemError_0_1_1280 = 1;
				vehicleChargingStopControl_11_1_1280 = 1; // E6
				errorFlag = 't';
			}
		}
		if (mainState_0_8_1537 > 'G')
		{
			// compare BMS voltage to charger voltage ( presentOutputVoltageValue_16_16_1289 )
			if (((presentOutputVoltageValue_16_16_1289 + voltageOffset) < BattVoltForCharger) || ((presentOutputVoltageValue_16_16_1289 - voltageOffset) > BattVoltForCharger))
			{
				// errorFlag = 'V';
			}
			// compare BMS current to charger current  ( presentOutputCurrentValue_32_16_1289 )
			if (((presentOutputCurrentValue_32_16_1289 + currentOffset) < BattCurrentForCharger) || ((presentOutputCurrentValue_32_16_1289 - currentOffset) > BattCurrentForCharger))
			{
				// errorFlag = 'C';
			}
		}
		if (errorFlag != 0)
		{
			raiseChademoError();
		}
		else
		{
		}
	}
}

void vh_sub_02()
{
	static uint32_t calculated_ttc;
	if (mainState_0_8_1537 == 'D')
	{
		if ((ChadSubTimeOut < 2))
		{
			if (actualSOC > 10)
			{
				calculated_ttc = 240 - (((actualSOC / 10) * 240) / 100);
			}
			else
			{
				calculated_ttc = 240;
			}
			maximumChargingTime1_16_8_1281 = calculated_ttc;
			maximumChargingTime2_24_8_1281 = calculated_ttc >> 8;

			// maximumChargingTime1_16_8_1281 = (TimeToCharge_55_9_262 & 0xFF);
			// maximumChargingTime2_24_8_1281 = ((TimeToCharge_55_9_262 >> 8) & 0xFF);

			estimatedChargingTime1_32_8_1281 = 0xff;
			estimatedChargingTime2_40_8_1281 = 0xff;
		}
		else if ((ChadSubTimeOut < 5))
		{
		}
		else if ((ChadSubTimeOut < 120))
		{
			if (latchHolding_10_1_1288 == 1)
			{
				standByRequestBeforeChargingStarts_12_1_1280 = 0;
				mainState_0_8_1537 = 'E';
				Sub_8_8_1537 = '2';
				ChadSubTimeOut = 0;
				CP_PP_ON;
				CpPp_32_8_1537 = 1;
				vehicleChargingStopControl_11_1_1280 = 0;

				charginCurrentRequestValue1_16_8_1280 = 0;
				charginCurrentRequestValue2_24_8_1280 = 0;

				vehicleStatus_9_1_1280 = 0;

				EcuChgIgn_40_1_1537 = 1;
			}
		}
		else
		{
			chargingSystemError_0_1_1280 = 1;
			vehicleChargingStopControl_11_1_1280 = 1; // E6
			errorFlag = 'L';
			raiseChademoError();
		}
	}
	//===========================================================================
	if ((ChadSubTimeOut > 25) && (Sub_8_8_1537 == '2'))
	{
		errorFlag = 'T';
		raiseChademoError();
	}
	if ((ChstdByBeforeChrgStarts_12_1_1288 == 0) && (mainState_0_8_1537 == 'E'))
	{

		standByRequestBeforeChargingStarts_12_1_1280 = 0;
		Sub_8_8_1537 = '3';
	}
	if ((Sub_8_8_1537 == '3') && (mainState_0_8_1537 == 'E') && (ChstdByBeforeChrgStarts_12_1_1288 == 0))
	{

		Sub_8_8_1537 = '4';
		vhSubroutines[2] = 0;

		charginVoltageTargetValue1_32_8_1280 = 0x48;
		charginVoltageTargetValue2_40_8_1280 = 0x02;
		batteryVoltageUpperLimit1_48_8_1280 = 0x50;
		batteryVoltageUpperLimit2_56_8_1280 = 0x02;

		vehicleChargingEnabled_8_1_1280 = 1;

		mainState_0_8_1537 = 'F';

		ChadSubTimeOut = 0;
	}
}

void vh_sub_03()
{

	/*
	 uint32_t bmsCurrentDemand_0_16_419385575;
	 uint32_t bmsVoltageDemand_16_16_419385575;
	 uint32_t chargerMode_32_8_419385575; // 0:Master, 1:Slave
	 uint32_t chargerState_40_8_419385575; // 0:ChargerOff, 1: ChargerON
	*/

	charginCurrentRequestValue1_16_8_1280 = bmsCurrentDemand_0_16_419385575 & 0xFF;
	charginCurrentRequestValue2_24_8_1280 = (bmsCurrentDemand_0_16_419385575 >> 8) & 0xFF;

	charginVoltageTargetValue1_32_8_1280 = bmsVoltageDemand_16_16_419385575 & 0xFF;
	charginVoltageTargetValue2_40_8_1280 = (bmsVoltageDemand_16_16_419385575 >> 8) & 0xFF;
}

void raiseChademoError()
{
	LastFunctionalState_16_8_1537 = mainState_0_8_1537;
	LastSubState_24_8_1537 = Sub_8_8_1537;

	vhSubroutines[2] = 0;
	vhSubroutines[4] = 0;
	vhSubroutines[3] = 0;

	Chad_StopCharging = 1;

	dummyErrorCounter++;
}

void CHAdeMO_hardStop()
{

	// mainState_0_8_1537 = 0;
	// Sub_8_8_1537 = 0;

	CP_PP_OF;
	CpPp_32_8_1537 = 0;

	vhSubroutines[0] = 0;

	Chad_StopCharging = 0;

	vhSubroutines[8] = 1;

	EcuChgIgn_40_1_1537 = 0;
}