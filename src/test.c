#include "key.h"
#include "sys.h"
#include "led.h"
#include "delay.h"
#include "stm32f10x.h"

int main(void){
	delay_init();
	KeyInit();
	LED_Init();

	u8 flag=0;
	u32 i;

	while(1){
		for(i=0; i<13888*10;i++)
			if(KeyScan(0))
				flag++;
		
		if(flag%2==0){
			LED0 = !LED0;
			for(i=0; i<13888*20;i++)
				if(KeyScan(0))
					flag++;
			LED0 = !LED0;
			for(i=0; i<13888*10;i++)
				if(KeyScan(0))
					flag++;
		}
	}

}