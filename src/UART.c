#include "uart.h"
#include "delay.h"
#include "led.h"
#include "beep.h"
#include "exti.h"

int main(void){
	UsartInit(9600);
	ExtiInit();
	BeepInit();
	delay_init();
	LedInit();

	// 数据发送测试
	printf("UpLink OK!\r");

	// 绿灯闪烁提示运行
	while(1){		
		LED_Green = !LED_Green;
		delay_ms(500);
	}
}