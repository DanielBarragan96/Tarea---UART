#include "MK64F12.h"
#include "NVIC.h"
#include "UART.h"

UART_MailBoxType UART0_MailBox = {0,0};

void UART0_Status_IRQHandler(void){
	if(0 == (UART0->C2 & UART_C2_RIE_MASK)){//Check RIE (Receiver Full Interrupt) end transmission
		UART0_MailBox.mailBox = UART0->D; //set the MailBox value
		UART0_MailBox.flag = 1;//activates the MailBox falg
	}
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
	switch(uartChannel){
		case UART_0:{
			UART0->C2 |= (UART_C2_TIE_MASK);
			NVIC_enableInterruptAndPriotity(UART0_IRQ, PRIORITY_3);
			break;
		}
		case UART_1:{
				UART1->C2 |= (UART_C2_TIE_MASK);
				NVIC_enableInterruptAndPriotity(UART1_IRQ, PRIORITY_3);
				break;
			}
		case UART_2:{
				UART2->C2 |= (UART_C2_TIE_MASK);
				NVIC_enableInterruptAndPriotity(UART2_IRQ, PRIORITY_3);
				break;
			}
		case UART_3:{
				UART3->C2 |= (UART_C2_TIE_MASK);
				NVIC_enableInterruptAndPriotity(UART3_IRQ, PRIORITY_3);
				break;
			}
		case UART_4:{
				UART4->C2 |= (UART_C2_TIE_MASK);
				NVIC_enableInterruptAndPriotity(UART4_IRQ, PRIORITY_3);
				break;
			}
		case UART_5:{
				UART5->C2 |= (UART_C2_TIE_MASK);
				NVIC_enableInterruptAndPriotity(UART5_IRQ, PRIORITY_3);
				break;
			}
		default: return;
	}
	EnableInterrupts;
}

void UART_putChar (UART_ChannelType uartChannel, uint8 character){

}

void UART_putString(UART_ChannelType uartChannel, sint8* string){

}
