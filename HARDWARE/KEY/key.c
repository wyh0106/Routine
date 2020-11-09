#include "key.h"
#include "sys.h"
#include "delay.h"

u8 KeyScan(u8 mode){
	//KeyUp==1，代表按键没有按下去过
	static u8 KeyUp = 1;
	//mode==1，把KeyUp固定在1，可以一直判断
	if(mode)
		KeyUp = 1;
	//KeyUp==1（按键在过去历史中没有按下），就对GPIO端口进行扫描
	if(KeyUp){
		//判断3个按键中是否有被按下
		if(KeyUp && (PAin(0)==1 || PEin(3)==0 || PEin(4)==0)){
			//消抖
			delay_ms(10);
			KeyUp = 0;
			//如果存在被按下的，将KeyUp置0，代表已经按下过了，然后判断并输出具体是哪个被按下
			if(PAin(0)==1)
				return 1;
			else if(PEin(3)==0)
				return 2;
			else if(PEin(4)==0)
				return 3;
		}
	}
	//没有任何按键被按下
	else if(PEin(3)==1 && PEin(4)==1 && PAin(0)==0)
		KeyUp = 1;//把keyUp置回1，标示没有按键曾经按下
	//返回0
	return 0;
}

void KeyInit(void){
	RCC->APB2ENR |= 1<<2;
	RCC->APB2ENR |= 1<<6;
	//PA第0个io口初始化
	GPIOA->CRL &= 0xFFFFFFF0;
	GPIOA->CRL |= 0x00000008;
	//PE的第3、4个io口初始化
	GPIOE->CRL &= 0xFFF00FFF;
	GPIOE->CRL |= 0x00088000;

	GPIOE->ODR |= 3<<3;	   	//PE3、4 上拉
}