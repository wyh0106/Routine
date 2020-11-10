#ifndef __USE_H
#define __USE_H

#include "uart.h"

// 选择需要启用的USART串口
#define USART_1		1
#define USART_2		0
#define USART_3		0
#define UART_4		0
#define UART_5		0

#if USART_1
// 系统时钟频率
#define FCK	(u32)72000000

#else
// 系统时钟频率
#define FCK	(u32)36000000

#endif /* USART_1 */

#if USART_1

// 串口时钟使能
#define USARTx_CLK_EN		USART1_CLK_EN
// 串口所在GPIO时钟使能
#define	IOPx_CLK_EN			IOPA_CLK_EN
// 串口所在GPIO端口结构体
#define	GPIOx				GPIOA
// 选择CRH寄存器
#define CRx					CRH
//需要复位的位段
#define RESET 				~(0xFF<<4)
// 配置PA9复用推挽输出50MHz,PA10浮空输入
#define IO_Config			((AFPP_Output_50<<4) | (FL_Input<<8))
// 接收使能
#define USARTx_RE			USART1_CR1_RE
// 发送使能
#define USARTx_TE			USART1_CR1_TE
// 串口所在结构体
#define	USARTx				USART1
// 串口使能
#define USARTx_UE			USART1_CR1_UE
// 发送完成标志位
#define USARTx_TC			USART1_SR_TC
// 读寄存器非空标志位
#define USARTx_RXNE			USART1_SR_RXNE
// 半双工模式选择
#define USARTx_HDSEL		USART1_CR3_HDSEL
// 接收缓冲区非空中断使能
#define USARTx_RXNEIE		USART1_CR1_RXNEIE
// 中断通道
#define USARTx_IRQ			USART1_IRQn
// 中断服务函数名
#define USARTx_IRQHandler	USART1_IRQHandler


#elif USART_2

// 串口时钟使能
#define USARTx_CLK_EN		USART2_CLK_EN
// 串口所在GPIO时钟使能
#define	IOPx_CLK_EN			IOPA_CLK_EN
// 串口所在GPIO端口结构体
#define	GPIOx				GPIOA
//需要复位的位段
#define RESET 				~(0xFF<<8)
// 选择CRL寄存器
#define CRx					CRL
// 配置PA2复用推挽输出50MHz,PA3浮空输入
#define IO_Config			((AFPP_Output_50<<8) | (FL_Input<<12))
// 接收使能
#define USARTx_RE			USART2_CR1_RE
// 发送使能
#define USARTx_TE			USART2_CR1_TE
// 串口所在结构体
#define	USARTx				USART2
// 串口使能
#define USARTx_UE			USART2_CR1_UE
// 发送完成标志位
#define USARTx_TC			USART2_SR_TC
// 读寄存器非空标志位
#define USARTx_RXNE			USART2_SR_RXNE
// 半双工模式选择
#define USARTx_HDSEL		USART2_CR3_HDSEL
// 接收缓冲区非空中断使能
#define USARTx_RXNEIE		USART2_CR1_RXNEIE
// 中断通道
#define USARTx_IRQ			USART2_IRQn
// 中断服务函数名
#define USARTx_IRQHandler	USART2_IRQHandler


#elif USART_3

// 串口时钟使能
#define USARTx_CLK_EN		USART3_CLK_EN
// 串口所在GPIO时钟使能
#define	IOPx_CLK_EN			IOPB_CLK_EN
// 串口所在GPIO端口结构体
#define	GPIOx				GPIOB
//需要复位的位段
#define RESET 				~(0xFF<<8)
// 选择CRH寄存器
#define CRx					CRH
// 配置PB10复用推挽输出50MHz,PB11浮空输入
#define IO_Config			((AFPP_Output_50<<8) | (FL_Input<<12))
// 接收使能
#define USARTx_RE			USART3_CR1_RE
// 发送使能
#define USARTx_TE			USART3_CR1_TE
// 串口所在结构体
#define	USARTx				USART3
// 串口使能
#define USARTx_UE			USART3_CR1_UE
// 发送完成标志位
#define USARTx_TC			USART3_SR_TC
// 读寄存器非空标志位
#define USARTx_RXNE			USART3_SR_RXNE
// 半双工模式选择
#define USARTx_HDSEL		USART3_CR3_HDSEL
// 接收缓冲区非空中断使能
#define USARTx_RXNEIE		USART3_CR1_RXNEIE
// 中断通道
#define USARTx_IRQ			USART3_IRQn
// 中断服务函数名
#define USARTx_IRQHandler	USART1_IRQHandler


#elif UART_4

// 串口时钟使能
#define USARTx_CLK_EN		UART4_CLK_EN
// 串口所在GPIO时钟使能
#define	IOPx_CLK_EN			IOPC_CLK_EN
// 串口所在GPIO端口结构体
#define	GPIOx				GPIOC
//需要复位的位段
#define RESET 				~(0xFF<<8)
// 选择CRH寄存器
#define CRx					CRH
// 配置PC10复用推挽输出50MHz,PC11浮空输入
#define IO_Config			((AFPP_Output_50<<8) | (FL_Input<<12))
// 接收使能
#define USARTx_RE			UART4_CR1_RE
// 发送使能
#define USARTx_TE			UART4_CR1_TE
// 串口所在结构体
#define	USARTx				UART4
// 串口使能
#define USARTx_UE			UART4_CR1_UE
// 发送完成标志位
#define USARTx_TC			UART4_SR_TC
// 读寄存器非空标志位
#define USARTx_RXNE			UART4_SR_RXNE
// 半双工模式选择
#define USARTx_HDSEL		UART4_CR3_HDSEL
// 接收缓冲区非空中断使能
#define USARTx_RXNEIE		UART4_CR1_RXNEIE
// 中断通道
#define USARTx_IRQ			UART4_IRQn
// 中断服务函数名
#define USARTx_IRQHandler	UART4_IRQHandler


#elif UART_5

// 串口时钟使能
#define USARTx_CLK_EN		UART5_CLK_EN
// 串口所在GPIO时钟使能
#define	IOPx_CLK_EN			IOPC_CLK_EN
// TX端所在GPIO端口结构体
#define	TX_GPIOx			GPIOC
// TX端需要复位的位段
#define TX_RESET			~(0x0F<<16)
// TX端选择CRH寄存器
#define TX_CRx				CRH
// 配置PC12复用推挽输出50MHz
#define TXIO_Config			(AFPP_Output_50<<16)
// RX端所在GPIO端口结构体
#define	RX_GPIOx			GPIOD
// RX端需要复位的位段
#define RX_RESET			~(0x0F<<8)
// RX端选择CRL寄存器
#define RX_CRx				CRL
// 配置PD2浮空输入
#define RXIO_Config			(FL_Input<<8)
// 接收使能
#define USARTx_RE			UART5_CR1_RE
// 发送使能
#define USARTx_TE			UART5_CR1_TE
// 串口所在结构体
#define	USARTx				UART5
// 串口使能
#define USARTx_UE			UART5_CR1_UE
// 发送完成标志位
#define USARTx_TC			UART5_SR_TC
// 读寄存器非空标志位
#define USARTx_RXNE			UART5_SR_RXNE
// 半双工模式选择
#define USARTx_HDSEL		UART5_CR3_HDSEL
// 接收缓冲区非空中断使能
#define USARTx_RXNEIE		UART5_CR1_RXNEIE
// 中断通道
#define USARTx_IRQ			UART5_IRQn
// 中断服务函数名
#define USARTx_IRQHandler	UART5_IRQHandler


#endif /* U(S)ART(12345) */



#endif /* __USE_H */