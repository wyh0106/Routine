#include "stm32f10x.h"
#include "delay.h"
#include "led.h"

#define true 1

int main(void)
{
    delay_init();
	LED_Init();

	while(true){
		PBout(5) = 1;
		PEout(5) = 1;
		delay_ms(500);

		PBout(5) = 0;
		PEout(5) = 0;
		delay_ms(500);
	}
}
