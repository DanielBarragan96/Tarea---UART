#include "DataTypeDefinitions.h"
#include "UART.h"
#include "MK64F12.h"



void UART0_Status_IRQHandler(void){

}

void UART_init(UART_ChannelType uartChannel, uint32 systemClk, UART_BaudRateType baudRate){

}

void UART0_interruptEnable(UART_ChannelType uartChannel){

}

void UART_putChar (UART_ChannelType uartChannel, uint8 character)
{
	switch(uartChannel)
	{
	case UART_0:
		while(!(UART0->S1 & UART_S1_RDRF_MASK))
			{
				UART0->D = character;
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

void UART_putString(UART_ChannelType uartChannel, sint8* string)
{
	uint16 end_word = 0;
	switch(uartChannel)
	{
	case UART_0:
		while(!(UART0->S1 & UART_S1_RDRF_MASK))
			{
				while(NULL != string[end_word])
				{
					UART0->D = string[end_word];
					end_word++;
				}
			}
		break;
	case UART_1:
		while(!(UART1->S1 & UART_S1_RDRF_MASK))
			{
				while(NULL != string[end_word])
				{
					UART1->D = string[end_word];
					end_word++;
				}
			}
		break;
	case UART_2:
		while(!(UART2->S1 & UART_S1_RDRF_MASK))
			{
				while(NULL != string[end_word])
				{
					UART2->D = string[end_word];
					end_word++;
				}
			}
		break;
	case UART_3:
		while(!(UART3->S1 & UART_S1_RDRF_MASK))
			{
				while(NULL != string[end_word])
				{
					UART3->D = string[end_word];
					end_word++;
				}
			}
		break;
	case UART_4:
		while(!(UART4->S1 & UART_S1_RDRF_MASK))
			{
				while(NULL != string[end_word])
				{
					UART4->D = string[end_word];
					end_word++;
				}
			}
		break;
	case UART_5:
		while(!(UART5->S1 & UART_S1_RDRF_MASK))
			{
				while(NULL != string[end_word])
				{
					UART5->D = string[end_word];
					end_word++;
				}
			}
		break;
	default:
		return;
	}
}
