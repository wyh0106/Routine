#include "stm32f10x.h"
#include "BEEP.h"
#include "led.h"
#include "delay.h"

int main(void){
	delay_init();
	BeepInit();
	LED_Init();

	while(true){
		BEEP = 1;
		PEout(5) = 0;
		delay_ms(500);

		BEEP = 0;
		PEout(5) = 1;
		delay_ms(500);
	}
}