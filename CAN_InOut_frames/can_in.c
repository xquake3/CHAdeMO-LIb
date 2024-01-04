#include "r_cg_macrodriver.h"
#include "can_out.h"
#include "can.h"
#include "state.h"
#include "r_cg_taub.h"
#include "r_cg_ostm.h"
uint8_t Stamped_508 = 0;
uint8_t Stamped_509 = 0;

int32_t Stamper138 = 0;
int32_t Stamper138_gap = 0;

// Debug cmd related
volatile uint8_t cmd_id = 0;
char in_frame_name[50];

//=======================================================
uint32_t bmsCurrentDemand_0_16_419385575;
uint32_t bmsVoltageDemand_16_16_419385575;
uint32_t chargerMode_32_8_419385575;  // 0:Master, 1:Slave
uint32_t chargerState_40_8_419385575; // 0:ChargerOff, 1: ChargerON

//================1289 = 0x509
uint8_t ePtwProtocolNumber_0_8_1289;
uint8_t ratedOuputPowerValue_8_8_1289;
uint16_t presentOutputVoltageValue_16_16_1289;
uint16_t presentOutputCurrentValue_32_16_1289;
uint16_t remainingChargingTime_48_16_1289;

//================1288 = 0x508
uint8_t chargingSystemError_0_1_1288;
uint8_t chargerError_1_1_1288;
uint8_t batteryIncompatibility_2_1_1288;
uint8_t chargerStopControl_8_1_1288;
uint8_t chargerStatus_9_1_1288;
uint8_t latchHolding_10_1_1288;
uint8_t chargerReady_11_1_1288;
uint8_t ChstdByBeforeChrgStarts_12_1_1288;
uint16_t availableOutputVoltageValue_16_16_1288;
uint16_t availableOutputCurrentValue_32_16_1288;
uint16_t outputVoltageUpThershold_48_16_1288;

int32_t TtcBuffer = 0;
int32_t TtcCounter = 0;

void can_in_parsing()
{

	if (rx_msg_ID == 0x509) // 1289
	{
		Stamped_509++;

		ePtwProtocolNumber_0_8_1289 = rx_msg_data0 & 0xFF;
		ratedOuputPowerValue_8_8_1289 = (rx_msg_data0 >> 8) & 0xFF;

		// Big2Little = ((rx_msg_data0 >> 24)) & 0xFF;
		// Big2Little |= ((rx_msg_data0 >>8)) & 0xFF00;
		presentOutputVoltageValue_16_16_1289 = ((rx_msg_data0 >> 16) & 0xFFFF) * 100;

		presentOutputCurrentValue_32_16_1289 = ((rx_msg_data1) & 0xFFFF) * 100;

		remainingChargingTime_48_16_1289 = (rx_msg_data1 >> 16) & 0xFFFF;
	}
	else if (rx_msg_ID == 0x508) // 1288
	{
		Stamped_508++;

		chargingSystemError_0_1_1288 = (rx_msg_data0 & (0x01)) > 0;
		chargerError_1_1_1288 = (rx_msg_data0 & (0x02)) > 0;
		batteryIncompatibility_2_1_1288 = (rx_msg_data0 & (0x04)) > 0;
		chargerStopControl_8_1_1288 = (rx_msg_data0 & 0x0100) > 0;
		chargerStatus_9_1_1288 = (rx_msg_data0 & (0x0200)) > 0;
		latchHolding_10_1_1288 = (rx_msg_data0 & (0x0400)) > 0;
		chargerReady_11_1_1288 = (rx_msg_data0 & (0x0800)) > 0;

		ChstdByBeforeChrgStarts_12_1_1288 = (rx_msg_data0 & (0x1000)) > 0;

		availableOutputVoltageValue_16_16_1288 = (rx_msg_data0 >> 16) & 0xFFFF;

		availableOutputCurrentValue_32_16_1288 = (rx_msg_data1) & 0xFFFF;

		outputVoltageUpThershold_48_16_1288 = (rx_msg_data1 >> 16) & 0xFFFF;
	}
}

/* Tabel for just wake-UP counters increments

1 : LastOdoCount

2 : DTE_16_8_257 = WattHour_0_32_419383248;

3 : CellDelta

Tabel ends Here */
///////////////////////////
