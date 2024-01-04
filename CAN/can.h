
void CAN_INIT(void);
void CAN0_RxD(void);

#define TX_BUFFER 	1
#define TX_RX_FIFO	2

#define TX_MODE		TX_BUFFER

// Debug commands received in 0x10C id
#define CMD_ECU_RESET   0x00000001
#define CMD_PARA_SECPAT 0xFF55AA29

#define CMD_ACK         0xAC000001
#define CMD_NACK        0xAC000000

extern unsigned char rx_msg_DLC;
extern unsigned int rx_msg_ID;
extern unsigned long rx_msg_data0, rx_msg_data1;

extern uint8_t fo8a_en;

extern uint32_t eepromData0, eepromData1, eepromId, eeprom_write_flag;

extern uint32_t RxTimeStamp;