#include "MK64F12.h"
#include "UART.h"

uint8 UART0_MailBox = 0;

void UART0_Status_IRQHandler(void){

}

void UART_init(UART_ChannelType uartChannel, uint32 systemClk, UART_BaudRateType baudRate){
	switch(uartChannel){
		case UART_0:{
				SIM->SCGC4 |= UART0_BASE; //Activate UART0 Clock gating
				UART0->C2 &= ~(UART_C2_TIE_MASK); //Disable transmission and receptor of the UART

				uint16 brfa;
				uint16 BRFD = brfa/32;

				ufloat32 UART_baud_rate = (ufloat32) (systemClk/(16 * (1 + BRFD)));
				//ufloat32 UART_baud_rate = systemClk / (16 × (SBR[12:0] + BRFD));

				UART0->BDH =   (UART_BDH_SBR_MASK & ((uint16) UART_baud_rate[12:8] << 8));
				UART0->BDL = (uint8) UART_baud_rate;

				UART0->C4 ; //Copy brfa to UART0_C4[4:0]

				UART0->C2 &= (UART_C2_TIE_MASK); //Enable transmission and receptor of the UART
			break;
		}
		case UART_1:{

		}
		case UART_2:{

		}
		case UART_3:{

		}
		case UART_4:{

		}
		case UART_5:{

		}
		default: return;
	}

}

void UART0_interruptEnable(UART_ChannelType uartChannel){

}

void UART_putChar (UART_ChannelType uartChannel, uint8 character){

}

void UART_putString(UART_ChannelType uartChannel, sint8* string){

}
