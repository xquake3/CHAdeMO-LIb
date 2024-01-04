#include "iodefine.h"
#include "r_cg_userdefine.h"
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_ostm.h"

#define uint8_t unsigned char
#define uint16_t unsigned int
#define uint32_t unsigned long

//**************************************************************************************************************************

//unsigned long ver;
//unsigned char ver1;
//unsigned char my_i;
unsigned char self_test_done;
unsigned int i;

uint32_t eepromData0, eepromData1, eepromId, eeprom_write_flag = 0;

unsigned char RX_Fifo_empty,RX_fifo_full,RX_Fifo_msg_lost = 0; 

unsigned char rx_msg_DLC = 0;
unsigned int rx_msg_ID = 0;
unsigned long rx_msg_data0 = 0, rx_msg_data1 = 0;

unsigned int can_tx_counter = 0;

uint32_t RxTimeStamp = 0;

uint8_t fo8a_en = 0;

void can_parser();

//**************************************************************************************************************************
void CAN_INIT(void)
{
//---------- Set CAN0 port pins -------------------

   PORT.PMC10 |= 0x0003;//select alternate pin function for P10.0,P10.1
   PORT.PM10 &= 0xFFFD; //set output mode for P10.1 as it is CAN0TX
   PORT.PM10 |= 0x0001; //set  input mode for P10.0 as it is CAN0RX
   
   PORT.PFC10 |= 0x0003;
   PORT.PFCAE10 = 0x0000;
   PORT.PFCE10 = 0x0000;

//---------- Set CAN1 port pins -------------------

   PORT.PMC10 |= 0x00C0;//select alternate pin function for P10.6,P10.7
   PORT.PM10 |= 0x0040; //set output mode for P10.6 as it is CAN0RX
   PORT.PM10 &= ~0x0080; //set  input mode for P10.7 as it is CAN0TX

   PORT.PFC10 |= 0x00C0;	// P10.6,P10.7 Alt func 4
   PORT.PFCE10 = 0x00C0;
   PORT.PFCAE10 = 0x0000;

   //-------Set CAN clock-----------------------------
   
   
   my_protected_write(WPROTR.PROTCMD1,CLKCTL.CKSC_ICANOSCD_CTL,0x01);
   while(CLKCTL.CKSC_ICANOSCD_ACT!=0x01);
   // PLL -> CAN Clock
   
   my_protected_write(WPROTR.PROTCMD1,CLKCTL.CKSC_ICANS_CTL,0x01);
   while(CLKCTL.CKSC_ICANS_ACT!=0x01);
   
  
   //Global Status Register
   while((RCFDC0.CFDGSTS.UINT8[LL] && 0x04)==0x04); //wait until CAN RAM is
                                                    //initialized
                                                    //global stop status flag
   //Global Control Register 
   RCFDC0.CFDGCTR.UINT8[LL]      &= 0xF9;   //Transition to global reset mode 
   RCFDC0.CFDGCTR.UINT8[LL]      |= 0x01;   //Transition to global reset mode 
   //self_test_done = RCFDC0.CFDGCTR.UINT8[LL];
   while((RCFDC0.CFDGSTS.UINT8[LL] && 0x01)!=0x01)                                        //from global stop mode
	{
		 self_test_done = RCFDC0.CFDGSTS.UINT8[LL];	
	}
   
    RCFDC0.CFDGRMCFG.UINT32 |= 0x01;
   //Channel Control Register
   RSCFD0.CFDC0CTR.UINT8[LL] &= 0xFB;   //Transition to channel reset mode from channel stop mode
   RSCFD0.CFDC1CTR.UINT8[LL] &= 0xFB;   //Transition to channel reset mode from channel stop mode

//---------- Setting the baud from 16Mhz -------------------------------------  
   
     RSCFD0.CFDGCFG.UINT32 = 0x10;   //xin clock selected // clkc s buggy 
   
     RCFDC0.CFDC0FDCFG.UINT8[HH] |= 0x40; //0x40    //Classical CAN only mode is enabled(nop, all the lies) change in final
     RSCFD0.CFDC1FDCFG.UINT8[HH] |= 0x40; //0x40    //Classical CAN only mode is enabled
     
     RCFDC0.CFDC0NCFG.UINT32 = 0x04090801;     // 500kbps, 16Tq, 1,4,9, 68.75% sampling
     RSCFD0.CFDC1NCFG.UINT32 = 0x04090801;     // 500kbps, 16Tq, 1,4,9, 68.75% sampling
   

//--------- Receive Rule settings for RX FIFO -------------------------------------

        //Receive Rule Configuration Register
	
     RSCFD0.CFDGAFLCFG0.UINT8[HH] = 0x01;    // No. of rules for channel 0 //1
     RSCFD0.CFDGAFLCFG0.UINT8[HL] = 0x01;    // No. of rules for channel 1 //1
   
     RSCFD0.CFDGAFLECTR.UINT8[LH] = 0x01;   // Enable write to receive rule table   
   
     RSCFD0.CFDGAFLECTR.UINT8[LL] = 0x00;   // receive rule page no.configuration page0
         
// receive rule 0 CH0
        //Receive Rule ID Register
   //RSCAN0.GAFLID0.UINT16[0] = 0x0111;   // Standard, Data frame, 11 bit ID
     RCFDC0.CFDGAFLID0.UINT16[L] = 0x0111;   // Standard, Data frame, 11 bit ID
   //=============================================================================
     // Change here, it shouldn't be this welcoming. what it is ? An immgigration glitch ?
     RCFDC0.CFDGAFLM0.UINT32 = 0x00;//0x1FFFFFFF;   // ID bits are compared compared
   
     RCFDC0.CFDGAFLP0_0.UINT8[LH] = 0x80;   //Use messsage buffer no 0
     RCFDC0.CFDGAFLP0_0.UINT8[LL] = 0x08;   //DLC 8 bytes
   
     RCFDC0.CFDGAFLP1_0.UINT32 = 0x01;   // Receive FIFO 0 selected
   
// receive rule 1 CH1

   RCFDC0.CFDGAFLID1.UINT16[L] = 0x0222;   // Standard, Data frame, 11 bit ID (nop, all the lies )
   
   RCFDC0.CFDGAFLM1.UINT32 = 0x00000000;   // ID bits are compared compared
   
   RCFDC0.CFDGAFLP0_1.UINT8[LH] = 0x80;    //Use messsage buffer no 0
   RCFDC0.CFDGAFLP0_1.UINT8[LL] = 0x08;   //DLC 8 bytes
  
   RCFDC0.CFDGAFLP1_1.UINT32 = 0x02;       // Receive FIFO 1 selected
   
   //Receive rule entry control register
   //RSCAN0.GAFLECTR.UINT8[1] = 0x00;   // Disable write to receive rule table
   RCFDC0.CFDGAFLECTR.UINT8[LH] = 0x00;   // Disable write to receive rule table
   
   RCFDC0.CFDRFCC0.UINT16[L] = 0x1272;    // RFIGCV = xxx(don't care),RFIM = 1(An interrupt occurs each time a message has been received.)
                                          // RFDC =0x010 Receive FIFO Buffer Depth Configuration 
                      // RFPLS = 0x111 Receive FIFO Buffer Payload Storage Size Select
                      // RFIE =1 Receive FIFO Interrupt Enable
	RCFDC0.CFDRFCC1.UINT16[L] = 0x1272;    // RFIGCV = xxx(don't care),RFIM = 1(An interrupt occurs each time a message has been received.)
                                          // RFDC =0x010 Receive FIFO Buffer Depth Configuration 
                      // RFPLS = 0x111 Receive FIFO Buffer Payload Storage Size Select
                      // RFIE =1 Receive FIFO Interrupt Enable

//--------- Receive FIFO Buffer settings -------------------------------------
  // increase fifo deapth in Production versio..
   //RSCAN0.RFCC0.UINT8[1] = 0x13;      // Interrupt on every message, Receive FIFO has 16 message depth
   RCFDC0.CFDRFCC0.UINT8[1] = 0x13;      // Interrupt on 1/8 message received in FIFO, Receive FIFO has 16 message depth
   RCFDC0.CFDRFCC0.UINT8[0] = 0x03;      // Receive FIFO buffers used and interrupt enabled
  
   RCFDC0.CFDRFCC1.UINT8[1] = 0x13;      // Interrupt on 1/8 message received in FIFO, Receive FIFO has 16 message depth
   RCFDC0.CFDRFCC1.UINT8[0] = 0x03;      // Receive FIFO buffers used and interrupt enabled

//-----------Transmit/receive FIFO settings in Transmit mode -----------------
// If any ladies want to remove transmit period, its period ! Dont change it gets buggy ..
   RCFDC0.CFDCFCC0.UINT8[3] = 0xFF;     //transmit period
   RCFDC0.CFDCFCC0.UINT8[2] = 0x05;	//0x05 Transmit mode selected, transmit buffer 0/6 linked to FIFO
   RCFDC0.CFDCFCC0.UINT8[1] = 0x04;	 // for interrupt on every message transmitted |0x10, FIFO depth 32 messages
   //RCFDC0.CFCC0.UINT8[0] = 0x04;      // transmit/receive FIFO transmit interupt enabled
  
   RSCFD0.CFDCFCC3.UINT8[3] = 0xFF;	// msg transmission interval
   RSCFD0.CFDCFCC3.UINT8[2] = 0x05;	// Transmit mode selected, transmit buffer 0/6 linked to FIFO
   RSCFD0.CFDCFCC3.UINT8[1] = 0x04;	 // for interrupt on every message transmitted |0x10, FIFO depth 32 messages
   //RSCFD0.CFCC0.UINT8[0] = 0x04;      // transmit/receive FIFO transmit interupt enabled

   RCFDC0.CFDGCTR.UINT8[LH] = 0x07;      // Transmit history interrupt, FIFO msg lost interrupt & DLC error interrupt enabled
   
//------------ Interrupt setting -----------------------------------

//NDG commented
   INTC1.ICRCAN0ERR.BIT.TBRCAN0ERR = 1;      // 0-Direct jump method, 1-vector method
   INTC1.ICRCAN0ERR.BIT.MKRCAN0ERR = 0;
   INTC1.ICRCAN0ERR.BIT.RFRCAN0ERR = 0;
    
   INTC1.ICRCAN0TRX.BIT.TBRCAN0TRX = 1;
   INTC1.ICRCAN0TRX.BIT.MKRCAN0TRX = 0;
   INTC1.ICRCAN0TRX.BIT.RFRCAN0TRX = 0;
 
   INTC1.ICRCAN0REC.BIT.TBRCAN0REC = 1;
   INTC1.ICRCAN0REC.BIT.MKRCAN0REC = 0;
   INTC1.ICRCAN0REC.BIT.RFRCAN0REC = 0;
   
   INTC1.ICRCANGERR0.BIT.TBRCANGERR0 = 1;
   INTC1.ICRCANGERR0.BIT.MKRCANGERR0 = 0;
   INTC1.ICRCANGERR0.BIT.RFRCANGERR0 = 0;

   INTC1.ICRCANGRECC0.BIT.TBRCANGRECC0 = 1;
   INTC1.ICRCANGRECC0.BIT.MKRCANGRECC0 = 0;
   INTC1.ICRCANGRECC0.BIT.RFRCANGRECC0 = 0;
      
   
//------------ Operating mode --------------------------------------
   
   RCFDC0.CFDGCTR.UINT8[0] = 0x00;      //Other than global stop mode
                                           //Global operating mode
   for(i=0;i<0xfff;i++);   //wait for transistion
        
   //Set RFE bit in global operating mode 
   RCFDC0.CFDRFCC0.UINT8[0] |= 0x01;      // receive FIFO is used
   RCFDC0.CFDRFCC1.UINT8[0] |= 0x01;      // receive FIFO is used
   
   RCFDC0.CFDC0CTR.UINT8[0] = 0x00;   //other than channel stop mode//channel communication mode
   for(i=0;i<0xfff;i++);   //wait for transistion
   
   RSCFD0.CFDC1CTR.UINT8[0] = 0x00;   //other than channel stop mode//channel communication mode
	for(i=0;i<0xfff;i++);   //wait for transistion
   //commented because currently not using FIFO, Or am I ?
   RCFDC0.CFDCFCC0.UINT8[0] |= 0x01;      // transmit/receive FIFO is used
   RCFDC0.CFDCFCC3.UINT8[0] |= 0x01;      // transmit/receive FIFO is used
}

//**************************************************************************************************************************

void MY_CAN0_Tx(unsigned long data_1,unsigned long data_2,uint32_t id,unsigned int len)
{
//----------- trnasmit using transmit/receive FIFO ---------------------------------------------
   
   RCFDC0.CFDCFID0.UINT16[1] = (( id > 0x7FF)<<15) | (id >> 16);
   RCFDC0.CFDCFID0.UINT16[0] = id ;
 	// data frame, standard ID
   
   RCFDC0.CFDCFPTR0.UINT8[3] = 0x80;
	// DLC of 8 data bytes
   
   RCFDC0.CFDCFDF0_0.UINT32 = data_1; 
	// data bytes 0 to 3
   
   RCFDC0.CFDCFDF1_0.UINT32 = data_2;
 	// data bytes 4 to 7

   RCFDC0.CFDCFPCTR0.UINT8[0] = 0xFF;
  	// Next Pointer
   can_tx_counter++;
}

void MY_CAN1_Tx(unsigned long data_1,unsigned long data_2,unsigned int id,unsigned int len)
{
//----------- trnasmit using transmit/receive FIFO ---------------------------------------------
   
   RSCFD0.CFDCFID3.UINT16[1] = (( id > 0x7FF)<<15) | (id >> 16);
   RSCFD0.CFDCFID3.UINT16[0] = id ;
 	// data frame, standard ID
   
   RSCFD0.CFDCFPTR3.UINT8[3] = 0x80;
	// DLC of 8 data bytes
   
   RSCFD0.CFDCFDF0_3.UINT32 = data_1; 
	// data bytes 0 to 3
   
   RSCFD0.CFDCFDF1_3.UINT32 = data_2;
 	// data bytes 4 to 7

   RSCFD0.CFDCFPCTR3.UINT8[0] = 0xFF;
  	// Next Pointer
}
//**************************************************************************************************************************



//**************************************************************************************************************************

void CAN0_RxD(void)
{
//-------------------- Rx by reading Rx FIFO buffer-------------------------------------------------------   
   RCFDC0.CFDRFSTS0.UINT8[0] &= 0xF7;   // CLEAR RFIF flag
   if((RCFDC0.CFDRFSTS0.UINT8[0] & 0x01) != 0x01)
   {
      do
      {
         rx_msg_ID = RCFDC0.CFDRFID0.UINT16[0]; //saving something here ? where is all the left MSB ?
         if(RCFDC0.CFDRFID0.UINT32 && 0x80000000){ //if extended
            rx_msg_ID |= (RCFDC0.CFDRFID0.UINT16[1] << 16);
            rx_msg_ID &= 0X7FFFFFFFU;
         }
         rx_msg_DLC = (RCFDC0.CFDRFPTR0.UINT8[3] & 0xf0) >> 4;
         
         rx_msg_data0 = RCFDC0.CFDRFDF0_0.UINT32;
         rx_msg_data1 = RCFDC0.CFDRFDF1_0.UINT32;    
	 
	 RxTimeStamp = RCFDC0.CFDRFPTR0.UINT16[L];
         
         RCFDC0.CFDRFPCTR0.UINT8[0] = 0xFF;

	 can_parser();
      
      }while((RCFDC0.CFDRFSTS0.UINT8[0] & 0x01) != 0x01);// check if FIFO empty
      SleepTimer = 0;   //reset sleep timer
   }

}

void CAN1_RxD(void)
{
//-------------------- Rx by reading Rx FIFO buffer-------------------------------------------------------   
   RCFDC0.CFDRFSTS1.UINT8[0] &= 0xF7;   // CLEAR RFIF flag
   if((RCFDC0.CFDRFSTS1.UINT8[0] & 0x01) != 0x01)
   {
      do
      {
         rx_msg_ID = RCFDC0.CFDRFID1.UINT16[0]; //saving something here ? where is all the left MSB ?
         if(RCFDC0.CFDRFID1.UINT32 && 0x80000000U){ //if extended
            rx_msg_ID |= (RCFDC0.CFDRFID1.UINT16[1] << 16);
            rx_msg_ID &= 0X7FFFFFFFU;
         }
         rx_msg_DLC = (RCFDC0.CFDRFPTR1.UINT8[3] & 0xf0) >> 4;
         
         rx_msg_data0 = RCFDC0.CFDRFDF0_1.UINT32;
         rx_msg_data1 = RCFDC0.CFDRFDF1_1.UINT32;    
	 
	 RxTimeStamp = RCFDC0.CFDRFPTR1.UINT16[L];
         
         RCFDC0.CFDRFPCTR1.UINT8[0] = 0xFF;

	 can_parser();
      
      }while((RCFDC0.CFDRFSTS1.UINT8[0] & 0x01) != 0x01);// check if FIFO empty
      SleepTimer = 0;   //reset sleep timer
   }

}
//**************************************************************************************************************************

#pragma interrupt CAN_Global_Error_ISR(enable=false, channel=22, fpu=false, callt=false)
 void CAN_Global_Error_ISR(void)
{
	CAN_INIT();
     if(RCFDC0.CFDRFSTS0.UINT8[0] & 0x04)  // check if FIFO message is lost
     {
        RX_Fifo_msg_lost = 1;
     }
     
}

//**************************************************************************************************************************

#pragma interrupt CAN_Rx_FIFO_ISR(enable=false, channel=23, fpu=false, callt=false)
 void CAN_Rx_FIFO_ISR(void)
{

     if(!(RSCFD0.CFDRFSTS0.UINT8[0] & 0x01))  // check if FIFO not empty
     {
         CAN0_RxD();
	     //RX_Fifo_empty = 1;   
        //return;
     }
     if(!(RSCFD0.CFDRFSTS1.UINT8[0] & 0x01))  // check if FIFO not empty
     {
         CAN1_RxD();
	     //RX_Fifo_empty = 1;   
        //return;
     }
     else if(RSCFD0.CFDRFSTS0.UINT8[0] & 0x02) // check if both FIFO full
     {
        //RX_fifo_full = 1;     
     }
     
}

//**************************************************************************************************************************

#pragma interrupt CAN0_Error_ISR(enable=false, channel=24, fpu=false, callt=false)
 void CAN0_Error_ISR(void)
{
	 /* Dude Write the error handlor here, else you are next to fired */
	 CAN_INIT();
     __nop();
}

//**************************************************************************************************************************

#pragma interrupt CAN0_TxD_RxD_FIFO_Receive_ISR(enable=false, channel=25, fpu=false, callt=false)
 void CAN0_TxD_RxD_FIFO_Receive_ISR(void)
{
     __nop();
     CAN0_RxD();
     RCFDC0.CFDCFSTS0.UINT8[0] &= 0xF7;   // CLEAR Interrupt flag   
}

//**************************************************************************************************************************

#pragma interrupt CAN0_TxD_ISR(enable=false)
 void CAN0_TxD_ISR(void)
{
   INTC1.ICRCAN0TRX.BIT.RFRCAN0TRX = 0;
   __nop();
     
}

void can_parser()
{
	can_in_parsing();
	
	if( (0xF08A == (rx_msg_ID & 0xFFFF)) && (0xF08A == rx_msg_data0) && (0xF08A == rx_msg_data1) )
	{
      fo8a_en = 1;
	}
	else if( (rx_msg_ID & 0xFF00) == 0x0900	)
	{
		
		eepromData0 = rx_msg_data0;
		eepromData1 = rx_msg_data1;
		eepromId = rx_msg_ID;
		eeprom_write_flag = 1;
	}
   else if( (rx_msg_ID & 0x1FFF0000) == 0x18FF0000	)  //if BMS frame send it on CAN1
   {
      MY_CAN1_Tx(rx_msg_data0, rx_msg_data1, rx_msg_ID,rx_msg_DLC);
   }
	/*else if( (rx_msg_ID & 0xFFFF) == 0xF08D	)
	{
		MY_CAN0_Tx(0,0,0x10F,8);
	}*/
	
}

//**************************************************************************************************************************

