#include "BEEP.h"

void BeepInit(void){
	RCC->APB2ENR|=1<<3;    //使能PORTB时钟

	GPIOB->CRH &= 0xFFFFFFF0;
	GPIOB->CRH |= 0x00000003;

	PBout(8) = 0;
}