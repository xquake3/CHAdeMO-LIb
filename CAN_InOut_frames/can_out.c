#include <stdio.h>

#include "r_cg_port.h"
#include "r_cg_macrodriver.h"
#include "state.h"
#include "can_in.h"
#include "r_cg_ostm.h"
#include "CHAdeMO.h"
#include "r_cg_taub.h"

uint8_t DebugStamping = 0; // stamping is 3

char out_frame_name[50];
void out_frame_setter(void *);
void add_frame_here();

#define addFrame(var)                        \
	{                                        \
		sprintf(out_frame_name, "%s", #var); \
		out_frame_setter(&var);              \
	}

uint32_t can_out_temp0;

// if adding new ID add a if block at end of code

//----0x500 == 1280 frame =======================================CHAdeMO CHADEMO chademo=======-
uint8_t chargingSystemError_0_1_1280;
uint8_t batteryOverVoltage_1_1_1280;
uint8_t batteryUnderVoltage_2_1_1280;
uint8_t batteryCurrentDeviation_3_1_1280;
uint8_t highBatteryTemprature_4_1_1280;
uint8_t voltageDeviation_5_1_1280;
uint8_t reserved_6_1_1280;
uint8_t reserved_7_1_1280;
uint8_t vehicleChargingEnabled_8_1_1280;
uint8_t vehicleStatus_9_1_1280;
uint8_t vehicleChargingPosition_10_1_1280;
uint8_t vehicleChargingStopControl_11_1_1280;
uint8_t standByRequestBeforeChargingStarts_12_1_1280;
uint8_t reserved_13_1_1280;
uint8_t charginCurrentRequestValue1_16_8_1280;
uint8_t charginCurrentRequestValue2_24_8_1280;
uint8_t charginVoltageTargetValue1_32_8_1280;
uint8_t charginVoltageTargetValue2_40_8_1280;
uint8_t batteryVoltageUpperLimit1_48_8_1280;
uint8_t batteryVoltageUpperLimit2_56_8_1280;

//----------------------------------  variable done now addresss
uint8_t noOfmembers_1280 = 0;
uint8_t startBit_1280[64];
uint8_t length_1280[64];
uint32_t *address_1280[64];
//  ^^^^^ increase all these values too, we wouldn't be able to judge RAM uses by using malloc
uint32_t data0_1280;
uint32_t data1_1280;
uint16_t id_1280 = 1280;

//----0x501 == 1281 frame ==============================================-
uint8_t ePtwProtocolNumber_0_8_1281;
uint8_t chargingRate_8_8_1281;
uint8_t maximumChargingTime1_16_8_1281;
uint8_t maximumChargingTime2_24_8_1281;
uint8_t estimatedChargingTime1_32_8_1281;
uint8_t estimatedChargingTime2_40_8_1281;

//----------------------------------  variable done now addresss
uint8_t noOfmembers_1281 = 0;
uint8_t startBit_1281[64];
uint8_t length_1281[64];
uint32_t *address_1281[64];
//  ^^^^^ increase all these values too, we wouldn't be able to judge RAM uses by using malloc
uint32_t data0_1281;
uint32_t data1_1281;
uint16_t id_1281 = 1281;

//----0x601 == 1537 frame ==============================================-
uint8_t mainState_0_8_1537;
uint8_t Sub_8_8_1537 = 'S';
uint8_t LastFunctionalState_16_8_1537;
uint8_t LastSubState_24_8_1537;
uint8_t CpPp_32_8_1537;
uint8_t EcuChgIgn_40_1_1537;
uint8_t ChgIsRunning_56_1_1537;
uint8_t VpDetected_57_1_1537;
//----------------------------------  variable done now addresss
uint8_t noOfmembers_1537 = 0;
uint8_t startBit_1537[64];
uint8_t length_1537[64];
uint32_t *address_1537[64];
//  ^^^^^ increase all these values too, we wouldn't be able to judge RAM uses by using malloc
uint32_t data0_1537;
uint32_t data1_1537;
uint16_t id_1537 = 1537;

//-----0x18FF50E5 == 419385573 --------------------------BMS CHARGER OVER CAN-----------------------------------
uint32_t BmsHeartBeat1_0_64_419385573 = 0x4F00B001;	 // 0x00EA3024;
uint32_t BmsHeartBeat2_32_32_419385573 = 0x2430EA00; // 0x01B0004F;
//=========================================================  variable done now addresss
uint8_t noOfmembers_419385573 = 0;
uint8_t startBit_419385573[8];
uint8_t length_419385573[8];
uint32_t *address_419385573[8];
//  ^^^^^ increase all these values too, we wouldn't be able to judge RAM uses by using malloc
uint32_t data0_419385573;
uint32_t data1_419385573;
uint32_t id_419385573 = 419385573;

//-----0x18FF50E6 == 419385574 --------------------------BMS CHARGER OVER CAN-----------------------------------
uint32_t chargerErrorFrame1_0_32_419385574 = 0x01000000;  // 0x00EA3024;
uint32_t chargerErrorFrame2_32_32_419385574 = 0x01000000; // 0x01B0004F;
//=========================================================  variable done now addresss
uint8_t noOfmembers_419385574 = 0;
uint8_t startBit_419385574[8];
uint8_t length_419385574[8];
uint32_t *address_419385574[8];
//  ^^^^^ increase all these values too, we wouldn't be able to judge RAM uses by using malloc
uint32_t data0_419385574;
uint32_t data1_419385574;
uint32_t id_419385574 = 419385574;

void add_frame_here()
{
	addFrame(chargingSystemError_0_1_1280);
	addFrame(batteryOverVoltage_1_1_1280);
	addFrame(batteryUnderVoltage_2_1_1280);
	addFrame(batteryCurrentDeviation_3_1_1280);
	addFrame(highBatteryTemprature_4_1_1280);
	addFrame(voltageDeviation_5_1_1280);
	addFrame(reserved_6_1_1280);
	addFrame(reserved_7_1_1280);
	addFrame(vehicleChargingEnabled_8_1_1280);
	addFrame(vehicleStatus_9_1_1280);
	addFrame(vehicleChargingPosition_10_1_1280);
	addFrame(vehicleChargingStopControl_11_1_1280);
	addFrame(standByRequestBeforeChargingStarts_12_1_1280);
	addFrame(reserved_13_1_1280);
	addFrame(charginCurrentRequestValue1_16_8_1280);
	addFrame(charginCurrentRequestValue2_24_8_1280);
	addFrame(charginVoltageTargetValue1_32_8_1280);
	addFrame(charginVoltageTargetValue2_40_8_1280);
	addFrame(batteryVoltageUpperLimit1_48_8_1280);
	addFrame(batteryVoltageUpperLimit2_56_8_1280);

	addFrame(ePtwProtocolNumber_0_8_1281);
	addFrame(chargingRate_8_8_1281);
	addFrame(maximumChargingTime1_16_8_1281);
	addFrame(maximumChargingTime2_24_8_1281);
	addFrame(estimatedChargingTime1_32_8_1281);
	addFrame(estimatedChargingTime2_40_8_1281);

	addFrame(mainState_0_8_1537);
	addFrame(Sub_8_8_1537);
	addFrame(LastFunctionalState_16_8_1537);
	addFrame(LastSubState_24_8_1537);
	addFrame(CpPp_32_8_1537);
	addFrame(EcuChgIgn_40_1_1537);
	addFrame(ChgIsRunning_56_1_1537);
	addFrame(VpDetected_57_1_1537);

	addFrame(BmsHeartBeat1_0_64_419385573);
	addFrame(BmsHeartBeat2_32_32_419385573);

	addFrame(chargerErrorFrame1_0_32_419385574);
	addFrame(chargerErrorFrame2_32_32_419385574);
}

void out_frame_setter(void *address)
{
	int fill_to_frame_counter0 = 0;
	int fill_to_frame_counter1 = 0;

	char start_bit_str[4];
	uint8_t start_bit_value;

	char bit_length_str[4];
	uint8_t bit_length_value;

	char id_str[12];
	uint32_t id_value;

	while (out_frame_name[fill_to_frame_counter0++] != '_')
		; // name coverd

	fill_to_frame_counter1 = 0;
	do
	{
		start_bit_str[fill_to_frame_counter1++] = out_frame_name[fill_to_frame_counter0];

	} while (out_frame_name[++fill_to_frame_counter0] != '_');
	start_bit_str[fill_to_frame_counter1] = '\0';
	start_bit_value = atoi(start_bit_str); //***-------------- Start Bit

	fill_to_frame_counter1 = 0;
	while (out_frame_name[++fill_to_frame_counter0] != '_')
	{
		bit_length_str[fill_to_frame_counter1++] = out_frame_name[fill_to_frame_counter0];
	}
	bit_length_str[fill_to_frame_counter1] = '\0';
	bit_length_value = atoi(bit_length_str); //***---------------- Bit Length

	fill_to_frame_counter1 = 0;
	while (out_frame_name[++fill_to_frame_counter0] != '\0')
	{
		id_str[fill_to_frame_counter1++] = out_frame_name[fill_to_frame_counter0];
	}
	id_str[fill_to_frame_counter1] = '\0';
	id_value = atoi(id_str);

	
	if (id_value == 1280)
	{
		startBit_1280[noOfmembers_1280] = start_bit_value;
		length_1280[noOfmembers_1280] = 32 - bit_length_value; // minus lenghth becuase to quick 1's left shift
															   // as (0xFFFFFFFF >> ( 32 - length ))
		address_1280[noOfmembers_1280] = address;
		noOfmembers_1280++;
	}
	else if (id_value == 1281)
	{
		startBit_1281[noOfmembers_1281] = start_bit_value;
		length_1281[noOfmembers_1281] = 32 - bit_length_value; // minus lenghth becuase to quick 1's left shift
															   // as (0xFFFFFFFF >> ( 32 - length ))
		address_1281[noOfmembers_1281] = address;
		noOfmembers_1281++;
	}
	else if (id_value == 1537)
	{
		startBit_1537[noOfmembers_1537] = start_bit_value;
		length_1537[noOfmembers_1537] = 32 - bit_length_value; // minus lenghth becuase to quick 1's left shift
															   // as (0xFFFFFFFF >> ( 32 - length ))
		address_1537[noOfmembers_1537] = address;
		noOfmembers_1537++;
	}
	else if (id_value == 419385573)
	{
		startBit_419385573[noOfmembers_419385573] = start_bit_value;
		length_419385573[noOfmembers_419385573] = 32 - bit_length_value; // minus lenghth becuase to quick 1's left shift
																		 // as (0xFFFFFFFF >> ( 32 - length ))
		address_419385573[noOfmembers_419385573] = address;
		noOfmembers_419385573++;
	}
	else if (id_value == 419385574)
	{
		startBit_419385574[noOfmembers_419385574] = start_bit_value;
		length_419385574[noOfmembers_419385574] = 32 - bit_length_value; // minus lenghth becuase to quick 1's left shift
																		 // as (0xFFFFFFFF >> ( 32 - length ))
		address_419385574[noOfmembers_419385574] = address;
		noOfmembers_419385574++;
	}
}

void out_frame_maker()
{
	static int out_frame_maker_counter0;
	static uint8_t start_bit;
	static uint8_t length;

	// 1280 begins here=================================================================== 0x1840F400

	data1_1280 = 0;
	data0_1280 = 0;
	for (out_frame_maker_counter0 = 0; out_frame_maker_counter0 < noOfmembers_1280; out_frame_maker_counter0++)
	{
		start_bit = startBit_1280[out_frame_maker_counter0];
		length = length_1280[out_frame_maker_counter0];

		if (start_bit > 31)
		{

			data1_1280 |= ((*address_1280[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << (start_bit - 32);
		}
		else
		{

			data0_1280 |= ((*address_1280[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << start_bit;
		}
	}
	if (vhSubroutines[0] == 1)
		MY_CAN1_Tx(data0_1280, data1_1280, 1280, 8);

	// ^^^^ 1280 ending here

	// 1281 begins here===================================================================

	data1_1281 = 0;
	data0_1281 = 0;
	for (out_frame_maker_counter0 = 0; out_frame_maker_counter0 < noOfmembers_1281; out_frame_maker_counter0++)
	{
		start_bit = startBit_1281[out_frame_maker_counter0];
		length = length_1281[out_frame_maker_counter0];

		if (start_bit > 31)
		{

			data1_1281 |= ((*address_1281[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << (start_bit - 32);
		}
		else
		{

			data0_1281 |= ((*address_1281[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << start_bit;
		}
	}
	if (vhSubroutines[0] == 1)
		MY_CAN1_Tx(data0_1281, data1_1281, 1281, 8);

	// ^^^^ 1281 ending here

	// 1537 begins here=================================================================== 0x1840F400

	data1_1537 = 0;
	data0_1537 = 0;
	for (out_frame_maker_counter0 = 0; out_frame_maker_counter0 < noOfmembers_1537; out_frame_maker_counter0++)
	{
		start_bit = startBit_1537[out_frame_maker_counter0];
		length = length_1537[out_frame_maker_counter0];

		if (start_bit > 31)
		{

			data1_1537 |= ((*address_1537[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << (start_bit - 32);
		}
		else
		{

			data0_1537 |= ((*address_1537[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << start_bit;
		}
	}
	MY_CAN1_Tx(data0_1537, data1_1537, 1537, 8);

	// ^^^^ 1537 ending here

	// 419385573 begins here=================================================================== 0x18FF50E5

	data1_419385573 = 0;
	data0_419385573 = 0;
	for (out_frame_maker_counter0 = 0; out_frame_maker_counter0 < noOfmembers_419385573; out_frame_maker_counter0++)
	{
		start_bit = startBit_419385573[out_frame_maker_counter0];
		length = length_419385573[out_frame_maker_counter0];

		if (start_bit > 31)
		{

			data1_419385573 |= ((*address_419385573[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << (start_bit - 32);
		}
		else
		{

			data0_419385573 |= ((*address_419385573[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << start_bit;
		}
	}
	// 0x18FF50E5
	//  if(    ( Sub_8_8_1537 >= '2' ) && ( mainState_0_8_1537 >= 'E' ) && ( mainState_0_8_1537 < 'J' ) ){
	if (EcuChgIgn_40_1_1537 == 1)
	{
		MY_CAN0_Tx(data0_419385573, data1_419385573, 419385573, 8);
	}

	// ^^^^ 419385573 ending here

	// 419385574 begins here=================================================================== 0x18FF50E5

	data1_419385574 = 0;
	data0_419385574 = 0;
	for (out_frame_maker_counter0 = 0; out_frame_maker_counter0 < noOfmembers_419385574; out_frame_maker_counter0++)
	{
		start_bit = startBit_419385574[out_frame_maker_counter0];
		length = length_419385574[out_frame_maker_counter0];

		if (start_bit > 31)
		{

			data1_419385574 |= ((*address_419385574[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << (start_bit - 32);
		}
		else
		{

			data0_419385574 |= ((*address_419385574[out_frame_maker_counter0]) & (0xFFFFFFFF >> length)) << start_bit;
		}
	}
	// 0x18FF50E6 EcuChgIgn_40_1_1537
	// if(    ( Sub_8_8_1537 >= '2' ) && ( mainState_0_8_1537 >= 'E' ) && ( mainState_0_8_1537 < 'J' ) ){
	if (EcuChgIgn_40_1_1537 == 1)
	{
		MY_CAN0_Tx(data0_419385574, data1_419385574, 419385574, 8);
	}

	// ^^^^ 419385574 ending here
}
