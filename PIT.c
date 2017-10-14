#include "MK64F12.h"
#include "PIT.h"

void PIT0_IRQHandler(){
	uint8 bug_var;

	PIT->CHANNEL[0].TFLG |= (PIT_TFLG_TIF_MASK);
	PIT->CHANNEL[0].TCTRL &= 0x0;
	bug_var = PIT->CHANNEL[0].TCTRL;
	PIT_INTR_FLAG = TRUE;
}

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float period){

	ufloat32 LDVAL_trigger;
	LDVAL_trigger =(period/(1/(systemClock/2)))-1;

	PIT->MCR = 0x00;
	PIT->CHANNEL[pitTimer].LDVAL = LDVAL_trigger;
	PIT->CHANNEL[pitTimer].TCTRL |= PIT_TCTRL_TEN_MASK;
	PIT->CHANNEL[pitTimer].TCTRL |= PIT_TCTRL_TIE_MASK;
}

void PIT_clockGating(void){
	SIM->SCGC6 |= PIT_CLOCK_GATING;
}

uint8 PIT_interruptFlagStatus(void){
	//Omitir
}

uint8 PIT_getIntrStutus(void){
	return PIT_INTR_FLAG;
}

void PIT_clear(PIT_Timer_t pitTimer){
	PIT_INTR_FLAG = FALSE;
}
