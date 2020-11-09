#include "led.h"
#include "key.h"
#include "delay.h"
#include "stm32f10x.h"

int main(void){
	delay_init();
	LED_Init();
	KeyInit();

	LED0 = 0;

	while(true){
		u8 key = 0;
		key = KeyScan(0);

		if(key){
			switch(key){
				case 1: LED0 = !LED0;//WK_UP触发
						break;
				case 2: LED1 = !LED1;//KEY1触发
						break;
				case 3: LED1 = !LED1;//KEY0触发
						LED0 = !LED0;
						break;
			}
		}
		else
			delay_ms(10);
		
	}
}