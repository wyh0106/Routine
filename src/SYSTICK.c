#include "systick.h"
#include "led.h"

int main(void){
	LedInit();

	while(1){
		LED0 = ~LED0;
		SysTick_ms(500);
		LED1 = ~LED1;
	}
}