#include "uart.h"

void UsartInit(u32 baud){
	u16 DIV_M = 0, DIV_F = 0;
	float DIV;

	// 串口、端口时钟使能
	USARTx_CLK_EN = 1;
	IOPx_CLK_EN = 1;

	#if UART_5
		// 配置TX复用推挽输出
		TX_GPIOx->TX_CRx &= TX_RESET;
		TX_GPIOx->TX_CRx |= TXIO_Config;
		// 配置RX端浮空输入
		RX_GPIOx->RX_CRx &= RX_RESET;
		RX_GPIOx->RX_CRx |= RXIO_Config;

	#else
		// 配置TX端复用推挽输出,RX端浮空输入
		GPIOx->CRx &= RESET;
		GPIOx->CRx |= IO_Config;
	#endif

	// 发送、接受位使能
	USARTx_RE = 1;
	USARTx_TE = 1;

	// 设置波特率
	DIV = (float)FCK / (16*baud);
	DIV_M = DIV;
	DIV_F = (DIV-DIV_M) * 16;
	USARTx->BRR |= (DIV_M<<4) | DIV_F;

	// 中断初始化
	NVIC_Configration();
	// 使能中断
	USARTx_RXNEIE = 1;

	// 工作在半双工模式
	USARTx_HDSEL = 1;

	// 串口外设使能
	USARTx_UE = 1;
}

// 中断服务函数
void USARTx_IRQHandler(void){
	u8 ch;
	while(!USARTx_RXNE);
	ch = USARTx->DR;

	switch (ch)
		{
			case 1: BEEP = !BEEP;
					LED_Red = !LED_Red;
					puts("LED_red&Beep switch changed\r");
					break;
			case 2: BEEP = 0;
					LED_Red = 1;
					puts("LED_red&Beep turn off\r");
					break;
		}
}

void NVIC_Configration(void){
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQ;				// 设置中断源
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;	// 抢占优先级1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			// 响应优先级1
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					// 使能接收串口接受中断通道
	NVIC_Init(&NVIC_InitStructure);									// 根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
}
