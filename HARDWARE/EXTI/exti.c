#include "exti.h"

void ExtiInit(void){
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	KeyInit();

	AFIO_CLK_EN = 1;
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);

	// KEY0
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);									//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;				//使能按键KEY0所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;			//子优先级0
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);									//根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	// KEY1
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	  								//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;				//使能按键KEY1所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	//抢占优先级2
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			//响应优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);

	// WakeUP
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	  								//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;				//使能按键Weak_Up所在的外部中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;			//响应优先级2
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI4_IRQHandler(void){
	delay_ms(10);							//消抖
	if(KEY0==0){	 						//按键KEY0
		printf("KEY0 was pressed\r");
	}

	EXTI_ClearITPendingBit(EXTI_Line4); 	//清除LINE4上的中断标志位  
}

void EXTI3_IRQHandler(void){
	delay_ms(10);							//消抖
	if(KEY1==0){	 						//按键KEY1
		printf("KEY1 was pressed\r");
	}

	EXTI_ClearITPendingBit(EXTI_Line3); 	//清除LINE3上的中断标志位  
}

void EXTI0_IRQHandler(void){
	delay_ms(50);							//消抖
	if(WakeUp==1){							//按键KEY1
		printf("WAKE_UP!\r");
	}

	EXTI_ClearITPendingBit(EXTI_Line0); 	//清除LINE0上的中断标志位  
}