#include "sys.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "exti.h"
#include "beep.h"

int main(void){
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LedInit();
	KeyInit();
	BeepInit();
	UsartInit(115200);
	ExtiInit();
	LED_Red = 0;
	BEEP = 0;

	while(1){
		printf("OK\n");
		delay_ms(1500);
	}

}