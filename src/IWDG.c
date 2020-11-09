#include "led.h"
#include "key.h"
#include "delay.h"
#include "sys.h"
#include "iwdg.h"

int main(void){
	delay_init();
	LedInit();
	KeyInit();
	IwdgInit(4, 625);

	delay_ms(200);
	LED0 = 0;

	while(true){
		if(KeyScan(0) == 1){
			IwdgRld;
		}
	}
}