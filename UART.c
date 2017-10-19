#include "MK64F12.h"
#include "NVIC.h"
#include "UART.h"
#include "DataTypeDefinitions.h"

UART_MailBoxType UART0_MailBox = {0,0};

void UART0_Status_IRQHandler(void){
	if(0 == (UART0->C2 & UART_C2_RIE_MASK)){//Check RIE (Receiver Full Interrupt) end transmission
		UART0_MailBox.mailBox = UART0->D; //set the MailBox value
		UART0_MailBox.flag = 1;//activates the MailBox flag
	}
}

void UART_init(UART_ChannelType uartChannel, uint32 systemClk, UART_BaudRateType baudRate){
	switch(uartChannel){
		case UART_0:{
				SIM->SCGC4 |= UART0_BASE; //Activate UART0 Clock gating
				UART0->C2 &= ~(UART_C2_TIE_MASK); //Disable transmission and receptor of the UART

				uint16 BRFD = 0;//BRF starts with 0
				uint16 brfa = BRFD*32;

				uint16 SBR = ((systemClk/baudRate)-BRFD)/16;

				UART0->BDH =   (UART_BDH_SBR_MASK & ((uint16) SBR >> 8));
				UART0->BDL = (UART_BDL_SBR_MASK & ((uint8) SBR));

				UART0->C4 = (UART_C4_BRFA_MASK & brfa); //Copy brfa to UART0_C4[4:0]

				UART0->C2 &= (UART_C2_TIE_MASK); //Enable transmission and receptor of the UART
			break;
		}
		case UART_1:{
			SIM->SCGC4 |= UART1_BASE; //Activate UART0 Clock gating
			UART1->C2 &= ~(UART_C2_TIE_MASK); //Disable transmission and receptor of the UART

			uint16 BRFD = 0;//BRF starts with 0
			uint16 brfa = BRFD*32;

			//ufloat32 UART_baud_rate = (ufloat32) (systemClk/(16 * (1 + BRFD)));
			//ufloat32 UART_baud_rate = systemClk / (16 × (SBR[12:0] + BRFD));
			uint16 SBR = ((systemClk/baudRate)-BRFD)/16;

			UART1->BDH =   (UART_BDH_SBR_MASK & ((uint16) SBR >> 8));
			UART1->BDL = (UART_BDL_SBR_MASK & ((uint8) SBR));

			UART1->C4 = (UART_C4_BRFA_MASK & brfa); //Copy brfa to UART0_C4[4:0]

			UART1->C2 &= (UART_C2_TIE_MASK); //Enable transmission and receptor of the UART
		break;
		}
		case UART_2:{
			SIM->SCGC4 |= UART2_BASE; //Activate UART0 Clock gating
			UART2->C2 &= ~(UART_C2_TIE_MASK); //Disable transmission and receptor of the UART

			uint16 BRFD = 0;//BRF starts with 0
			uint16 brfa = BRFD*32;

			//ufloat32 UART_baud_rate = (ufloat32) (systemClk/(16 * (1 + BRFD)));
			//ufloat32 UART_baud_rate = systemClk / (16 × (SBR[12:0] + BRFD));
			uint16 SBR = ((systemClk/baudRate)-BRFD)/16;

			UART2->BDH =   (UART_BDH_SBR_MASK & ((uint16) SBR >> 8));
			UART2->BDL = (UART_BDL_SBR_MASK & ((uint8) SBR));

			UART2->C4 = (UART_C4_BRFA_MASK & brfa); //Copy brfa to UART0_C4[4:0]

			UART2->C2 &= (UART_C2_TIE_MASK); //Enable transmission and receptor of the UART
		break;
		}
		case UART_3:{
			SIM->SCGC4 |= UART3_BASE; //Activate UART0 Clock gating
			UART3->C2 &= ~(UART_C2_TIE_MASK); //Disable transmission and receptor of the UART

			uint16 BRFD = 0;//BRF starts with 0
			uint16 brfa = BRFD*32;

			//ufloat32 UART_baud_rate = (ufloat32) (systemClk/(16 * (1 + BRFD)));
			//ufloat32 UART_baud_rate = systemClk / (16 × (SBR[12:0] + BRFD));
			uint16 SBR = ((systemClk/baudRate)-BRFD)/16;

			UART3->BDH =   (UART_BDH_SBR_MASK & ((uint16) SBR >> 8));
			UART3->BDL = (UART_BDL_SBR_MASK & ((uint8) SBR));

			UART3->C4 = (UART_C4_BRFA_MASK & brfa); //Copy brfa to UART0_C4[4:0]

			UART3->C2 &= (UART_C2_TIE_MASK); //Enable transmission and receptor of the UART
		break;
		}
		case UART_4:{
			SIM->SCGC4 |= UART4_BASE; //Activate UART0 Clock gating
			UART4->C2 &= ~(UART_C2_TIE_MASK); //Disable transmission and receptor of the UART

			uint16 BRFD = 0;//BRF starts with 0
			uint16 brfa = BRFD*32;

			//ufloat32 UART_baud_rate = (ufloat32) (systemClk/(16 * (1 + BRFD)));
			//ufloat32 UART_baud_rate = systemClk / (16 × (SBR[12:0] + BRFD));
			uint16 SBR = ((systemClk/baudRate)-BRFD)/16;

			UART4->BDH =   (UART_BDH_SBR_MASK & ((uint16) SBR >> 8));
			UART4->BDL = (UART_BDL_SBR_MASK & ((uint8) SBR));

			UART4->C4 = (UART_C4_BRFA_MASK & brfa); //Copy brfa to UART0_C4[4:0]

			UART4->C2 &= (UART_C2_TIE_MASK); //Enable transmission and receptor of the UART
		break;
		}
		case UART_5:{
			SIM->SCGC4 |= UART5_BASE; //Activate UART0 Clock gating
			UART5->C2 &= ~(UART_C2_TIE_MASK); //Disable transmission and receptor of the UART

			uint16 BRFD = 0;//BRF starts with 0
			uint16 brfa = BRFD*32;

			//ufloat32 UART_baud_rate = (ufloat32) (systemClk/(16 * (1 + BRFD)));
			//ufloat32 UART_baud_rate = systemClk / (16 × (SBR[12:0] + BRFD));
			uint16 SBR = ((systemClk/baudRate)-BRFD)/16;

			UART5->BDH =   (UART_BDH_SBR_MASK & ((uint16) SBR >> 8));
			UART5->BDL = (UART_BDL_SBR_MASK & ((uint8) SBR));

			UART5->C4 = (UART_C4_BRFA_MASK & brfa); //Copy brfa to UART0_C4[4:0]

			UART5->C2 &= (UART_C2_TIE_MASK); //Enable transmission and receptor of the UART
		break;
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

//checks if you already transmited before you transmit something else
void UART_putChar (UART_ChannelType uartChannel, uint8 character)
{
	switch(uartChannel)
	{
	case UART_0:
		while(!(UART0->S1 & UART_S1_RDRF_MASK)) //checks the Receive data register full flag bit on the UART Status register 1
			{
				UART0->D = character; //writes the character on the Data register of the UART
			}
		break;
	case UART_1:
		while(!(UART1->S1 & UART_S1_RDRF_MASK))
			{
				UART1->D = character;
			}
		break;
	case UART_2:
		while(!(UART2->S1 & UART_S1_RDRF_MASK))
			{
				UART2->D = character;
			}
		break;
	case UART_3:
		while(!(UART3->S1 & UART_S1_RDRF_MASK))
			{
				UART3->D = character;
			}
		break;
	case UART_4:
		while(!(UART4->S1 & UART_S1_RDRF_MASK))
			{
				UART4->D = character;
			}
		break;
	case UART_5:
		while(!(UART5->S1 & UART_S1_RDRF_MASK))
			{
				UART5->D = character;
			}
		break;
	default:
		return;
	}
}

//writes a string by writing character by character until the string ends
void UART_putString(UART_ChannelType uartChannel, sint8* string)
{
	switch(uartChannel)
	{
	case UART_0:
		while(*string)  //checks while the string hasn't finished
			UART_putChar(UART_0, *string++);    //calls putChar to write the whole string while it moves character by character
		break;
	case UART_1:
		while(*string)
			UART_putChar(UART_1, *string++);
		break;
	case UART_2:
		while(*string)
			UART_putChar(UART_2, *string++);
		break;
	case UART_3:
		while(*string)
			UART_putChar(UART_3, *string++);
		break;
	case UART_4:
		while(*string)
			UART_putChar(UART_4, *string++);
		break;
	case UART_5:
		while(*string)
			UART_putChar(UART_5, *string++);
		break;
	default:
		return;
	}
}
