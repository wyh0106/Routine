#ifndef __UART_H
#define __UART_H

#include "sys.h"
#include "stdio.h"
#include "use.h"
#include "led.h"
#include "beep.h"


// 串口初始化，需要给定波特率
void UsartInit(u32 baud);
// 中断初始化
void NVIC_Configration(void);


// 通用串口寄存器地址映射

// USART1状态寄存器地址
#define USART1_SR_Addr		(USART1_BASE+0x00)
// USART1控制寄存器1地址
#define USART1_CR1_Addr		(USART1_BASE+0x0C)
// USART1控制寄存器2地址
#define USART1_CR2_Addr		(USART1_BASE+0x10)
// USART1控制寄存器3地址
#define USART1_CR3_Addr		(USART1_BASE+0x04)

// USART2状态寄存器地址
#define USART2_SR_Addr		(USART2_BASE+0x00)
// USART2控制寄存器1地址
#define USART2_CR1_Addr		(USART2_BASE+0x0C)
// USART2控制寄存器2地址
#define USART2_CR2_Addr		(USART2_BASE+0x10)
// USART2控制寄存器3地址
#define USART2_CR3_Addr		(USART2_BASE+0x04)

// USART3状态寄存器地址
#define USART3_SR_Addr		(USART3_BASE+0x00)
// USART3控制寄存器1地址
#define USART3_CR1_Addr		(USART3_BASE+0x0C)
// USART3控制寄存器2地址
#define USART3_CR2_Addr		(USART3_BASE+0x10)
// USART3控制寄存器3地址
#define USART3_CR3_Addr		(USART3_BASE+0x04)

// UART4状态寄存器地址
#define UART4_SR_Addr		(UART4_BASE+0x00)
// UART4控制寄存器1地址
#define UART4_CR1_Addr		(UART4_BASE+0x0C)
// UART4控制寄存器2地址
#define UART4_CR2_Addr		(UART4_BASE+0x10)
// UART4控制寄存器3地址
#define UART4_CR3_Addr		(UART4_BASE+0x04)

// UART5状态寄存器地址
#define UART5_SR_Addr		(UART5_BASE+0x00)
// UART5控制寄存器1地址
#define UART5_CR1_Addr		(UART5_BASE+0x0C)
// UART5控制寄存器2地址
#define UART5_CR2_Addr		(UART5_BASE+0x10)
// UART5控制寄存器3地址
#define UART5_CR3_Addr		(UART5_BASE+0x04)


/*
	0：不存在所述的错误或者标志/失能
	1：存在所述的错误或者标志/使能
*/

// 状态寄存器

// USART1状态寄存器校验错误位
#define USART1_SR_PE		BIT_ADDR(USART1_SR_Addr, 0)
// USART1状态寄存器帧错误位
#define USART1_SR_FE		BIT_ADDR(USART1_SR_Addr, 1)
// USART1状态寄存器噪声错误位
#define USART1_SR_NE		BIT_ADDR(USART1_SR_Addr, 2)
// USART1状态寄存器过载错误位
#define USART1_SR_ORE		BIT_ADDR(USART1_SR_Addr, 3)
// USART1状态寄存器总线空闲标志位
#define USART1_SR_IDLE		BIT_ADDR(USART1_SR_Addr, 4)
// USART1状态寄存器读寄存器非空标志位
#define USART1_SR_RXNE		BIT_ADDR(USART1_SR_Addr, 5)
// USART1状态寄存器发送完成标志位
#define USART1_SR_TC		BIT_ADDR(USART1_SR_Addr, 6)
// USART1状态寄存器发送寄存器空标志位
#define USART1_SR_TXE		BIT_ADDR(USART1_SR_Addr, 7)
// USART1状态寄存器LIN断开检测标志位
#define USART1_SR_LBD		BIT_ADDR(USART1_SR_Addr,  8)
// USART1状态寄存器请求对方发送数据寄存器标志位
#define USART1_SR_CTS		BIT_ADDR(USART1_SR_Addr,  9)

// USART2状态寄存器校验错误位
#define USART2_SR_PE		BIT_ADDR(USART2_SR_Addr,  0)
// USART2状态寄存器帧错误位
#define USART2_SR_FE		BIT_ADDR(USART2_SR_Addr,  1)
// USART2状态寄存器噪声错误位
#define USART2_SR_NE		BIT_ADDR(USART2_SR_Addr,  2)
// USART2状态寄存器过载错误位
#define USART2_SR_ORE		BIT_ADDR(USART2_SR_Addr,  3)
// USART2状态寄存器总线空闲标志位
#define USART2_SR_IDLE		BIT_ADDR(USART2_SR_Addr,  4)
// USART2状态寄存器读寄存器非空标志位
#define USART2_SR_RXNE		BIT_ADDR(USART2_SR_Addr,  5)
// USART2状态寄存器发送完成标志位
#define USART2_SR_TC		BIT_ADDR(USART2_SR_Addr,  6)
// USART2状态寄存器发送寄存器空标志位
#define USART2_SR_TXE		BIT_ADDR(USART2_SR_Addr,  7)
// USART2状态寄存器LIN断开检测标志位
#define USART2_SR_LBD		BIT_ADDR(USART2_SR_Addr,  8)
// USART2状态寄存器请求对方发送数据寄存器标志位
#define USART2_SR_CTS		BIT_ADDR(USART2_SR_Addr,  9)

// USART3状态寄存器校验错误位
#define USART3_SR_PE		BIT_ADDR(USART3_SR_Addr,  0)
// USART3状态寄存器帧错误位
#define USART3_SR_FE		BIT_ADDR(USART3_SR_Addr,  1)
// USART3状态寄存器噪声错误位
#define USART3_SR_NE		BIT_ADDR(USART3_SR_Addr,  2)
// USART3状态寄存器过载错误位
#define USART3_SR_ORE		BIT_ADDR(USART3_SR_Addr,  3)
// USART3状态寄存器总线空闲标志位
#define USART3_SR_IDLE		BIT_ADDR(USART3_SR_Addr,  4)
// USART3状态寄存器读寄存器非空标志位
#define USART3_SR_RXNE		BIT_ADDR(USART3_SR_Addr,  5)
// USART3状态寄存器发送完成标志位
#define USART3_SR_TC		BIT_ADDR(USART3_SR_Addr,  6)
// USART3状态寄存器发送寄存器空标志位
#define USART3_SR_TXE		BIT_ADDR(USART3_SR_Addr,  7)
// USART3状态寄存器LIN断开检测标志位
#define USART3_SR_LBD		BIT_ADDR(USART3_SR_Addr,  8)
// USART3状态寄存器请求对方发送数据寄存器标志位
#define USART3_SR_CTS		BIT_ADDR(USART3_SR_Addr,  9)

// UART4状态寄存器校验错误位
#define UART4_SR_PE			BIT_ADDR(UART4_SR_Addr,  0)
// UART4状态寄存器帧错误位
#define UART4_SR_FE			BIT_ADDR(UART4_SR_Addr,  1)
// UART4状态寄存器噪声错误位
#define UART4_SR_NE			BIT_ADDR(UART4_SR_Addr,  2)
// UART4状态寄存器过载错误位
#define UART4_SR_ORE		BIT_ADDR(UART4_SR_Addr,  3)
// UART4状态寄存器总线空闲标志位
#define UART4_SR_IDLE		BIT_ADDR(UART4_SR_Addr,  4)
// UART4状态寄存器读寄存器非空标志位
#define UART4_SR_RXNE		BIT_ADDR(UART4_SR_Addr,  5)
// UART4状态寄存器发送完成标志位
#define UART4_SR_TC			BIT_ADDR(UART4_SR_Addr,  6)
// UART4状态寄存器发送寄存器空标志位
#define UART4_SR_TXE		BIT_ADDR(UART4_SR_Addr,  7)
// UART4状态寄存器LIN断开检测标志位
#define UART4_SR_LBD		BIT_ADDR(UART4_SR_Addr,  8)

// UART5状态寄存器校验错误位
#define UART5_SR_PE			BIT_ADDR(UART5_SR_Addr,  0)
// UART5状态寄存器帧错误位
#define UART5_SR_FE			BIT_ADDR(UART5_SR_Addr,  1)
// UART5状态寄存器噪声错误位
#define UART5_SR_NE			BIT_ADDR(UART5_SR_Addr,  2)
// UART5状态寄存器过载错误位
#define UART5_SR_ORE		BIT_ADDR(UART5_SR_Addr,  3)
// UART5状态寄存器总线空闲标志位
#define UART5_SR_IDLE		BIT_ADDR(UART5_SR_Addr,  4)
// UART5状态寄存器读寄存器非空标志位
#define UART5_SR_RXNE		BIT_ADDR(UART5_SR_Addr,  5)
// UART5状态寄存器发送完成标志位
#define UART5_SR_TC			BIT_ADDR(UART5_SR_Addr,  6)
// UART5状态寄存器发送寄存器空标志位
#define UART5_SR_TXE		BIT_ADDR(UART5_SR_Addr,  7)
// UART5状态寄存器LIN断开检测标志位
#define UART5_SR_LBD		BIT_ADDR(UART5_SR_Addr,  8)

/*
	0：不存在所述的错误或者标志/失能
	1：存在所述的错误或者标志/使能
*/
// 控制寄存器1

// USART1控制寄存器1发送断开帧标志寄存器
#define USART1_CR1_SBK		BIT_ADDR(USART1_CR1_Addr,  0)
// USART1控制寄存器1接收唤醒标志位
#define USART1_CR1_RWU		BIT_ADDR(USART1_CR1_Addr,  1)
// USART1控制寄存器1接收使能位
#define USART1_CR1_RE		BIT_ADDR(USART1_CR1_Addr,  2)
// USART1控制寄存器1发送使能位
#define USART1_CR1_TE		BIT_ADDR(USART1_CR1_Addr,  3)
// USART1控制寄存器1IDLE中断使能位
#define USART1_CR1_IDLEIE	BIT_ADDR(USART1_CR1_Addr,  4)
// USART1控制寄存器1接收缓冲区非空中断使能位
#define USART1_CR1_RXNEIE	BIT_ADDR(USART1_CR1_Addr,  5)
// USART1控制寄存器1发送完成中断使能位
#define USART1_CR1_TCIE		BIT_ADDR(USART1_CR1_Addr,  6)
// USART1控制寄存器1发送缓冲区空中断使能位
#define USART1_CR1_TXEIE	BIT_ADDR(USART1_CR1_Addr,  7)
// USART1控制寄存器1PE中断使能位
#define USART1_CR1_PEIE		BIT_ADDR(USART1_CR1_Addr,  8)
// USART1控制寄存器1校验选择位(0：偶校验；1：奇校验)
#define USART1_CR1_PS		BIT_ADDR(USART1_CR1_Addr,  9)
// USART1控制寄存器1检验控制使能位
#define USART1_CR1_PCE		BIT_ADDR(USART1_CR1_Addr,  10)
// USART1控制寄存器1唤醒方法位(0：被空闲总线唤醒；1：被地址标记唤醒)
#define USART1_CR1_WAKE		BIT_ADDR(USART1_CR1_Addr,  11)
// USART1控制寄存器1字长位(0：一个起始位，8个数据位，n个停止位；1：一个起始位，9个数据位，n个停止位)
#define USART1_CR1_M		BIT_ADDR(USART1_CR1_Addr,  12)
// USART1控制寄存器1USART使能位
#define USART1_CR1_UE		BIT_ADDR(USART1_CR1_Addr,  13)

// USART2控制寄存器1发送断开帧标志寄存器
#define USART2_CR1_SBK		BIT_ADDR(USART2_CR1_Addr,  0)
// USART2控制寄存器1接收唤醒标志位
#define USART2_CR1_RWU		BIT_ADDR(USART2_CR1_Addr,  1)
// USART2控制寄存器1接收使能位
#define USART2_CR1_RE		BIT_ADDR(USART2_CR1_Addr,  2)
// USART2控制寄存器1发送使能位
#define USART2_CR1_TE		BIT_ADDR(USART2_CR1_Addr,  3)
// USART2控制寄存器1IDLE中断使能位
#define USART2_CR1_IDLEIE	BIT_ADDR(USART2_CR1_Addr,  4)
// USART2控制寄存器1接收缓冲区非空中断使能位
#define USART2_CR1_RXNEIE	BIT_ADDR(USART2_CR1_Addr,  5)
// USART2控制寄存器1发送完成中断使能位
#define USART2_CR1_TCIE		BIT_ADDR(USART2_CR1_Addr,  6)
// USART2控制寄存器1发送缓冲区空中断使能位
#define USART2_CR1_TXEIE	BIT_ADDR(USART2_CR1_Addr,  7)
// USART2控制寄存器1PE中断使能位
#define USART2_CR1_PEIE		BIT_ADDR(USART2_CR1_Addr,  8)
// USART2控制寄存器1校验选择位(0：偶校验；1：奇校验)
#define USART2_CR1_PS		BIT_ADDR(USART2_CR1_Addr,  9)
// USART2控制寄存器1检验控制使能位
#define USART2_CR1_PCE		BIT_ADDR(USART2_CR1_Addr,  10)
// USART2控制寄存器1唤醒方法位(0：被空闲总线唤醒；1：被地址标记唤醒)
#define USART2_CR1_WAKE		BIT_ADDR(USART2_CR1_Addr,  11)
// USART2控制寄存器1字长位(0：一个起始位，8个数据位，n个停止位；1：一个起始位，9个数据位，n个停止位)
#define USART2_CR1_M		BIT_ADDR(USART2_CR1_Addr,  12)
// USART2控制寄存器1USART使能位
#define USART2_CR1_UE		BIT_ADDR(USART2_CR1_Addr,  13)

// USART3控制寄存器1发送断开帧标志寄存器
#define USART3_CR1_SBK		BIT_ADDR(USART3_CR1_Addr,  0)
// USART3控制寄存器1接收唤醒标志位
#define USART3_CR1_RWU		BIT_ADDR(USART3_CR1_Addr,  1)
// USART3控制寄存器1接收使能位
#define USART3_CR1_RE		BIT_ADDR(USART3_CR1_Addr,  2)
// USART3控制寄存器1发送使能位
#define USART3_CR1_TE		BIT_ADDR(USART3_CR1_Addr,  3)
// USART3控制寄存器1IDLE中断使能位
#define USART3_CR1_IDLEIE	BIT_ADDR(USART3_CR1_Addr,  4)
// USART3控制寄存器1接收缓冲区非空中断使能位
#define USART3_CR1_RXNEIE	BIT_ADDR(USART3_CR1_Addr,  5)
// USART3控制寄存器1发送完成中断使能位
#define USART3_CR1_TCIE		BIT_ADDR(USART3_CR1_Addr,  6)
// USART3控制寄存器1发送缓冲区空中断使能位
#define USART3_CR1_TXEIE	BIT_ADDR(USART3_CR1_Addr,  7)
// USART3控制寄存器1PE中断使能位
#define USART3_CR1_PEIE		BIT_ADDR(USART3_CR1_Addr,  8)
// USART3控制寄存器1校验选择位(0：偶校验；1：奇校验)
#define USART3_CR1_PS		BIT_ADDR(USART3_CR1_Addr,  9)
// USART3控制寄存器1检验控制使能位
#define USART3_CR1_PCE		BIT_ADDR(USART3_CR1_Addr,  10)
// USART3控制寄存器1唤醒方法位(0：被空闲总线唤醒；1：被地址标记唤醒)
#define USART3_CR1_WAKE		BIT_ADDR(USART3_CR1_Addr,  11)
// USART3控制寄存器1字长位(0：一个起始位，8个数据位，n个停止位；1：一个起始位，9个数据位，n个停止位)
#define USART3_CR1_M		BIT_ADDR(USART3_CR1_Addr,  12)
// USART3控制寄存器1USART使能位
#define USART3_CR1_UE		BIT_ADDR(USART3_CR1_Addr,  13)

// UART4控制寄存器1发送断开帧标志寄存器
#define UART4_CR1_SBK		BIT_ADDR(UART4_CR1_Addr,  0)
// UART4控制寄存器1接收唤醒标志位
#define UART4_CR1_RWU		BIT_ADDR(UART4_CR1_Addr,  1)
// UART4控制寄存器1接收使能位
#define UART4_CR1_RE		BIT_ADDR(UART4_CR1_Addr,  2)
// UART4控制寄存器1发送使能位
#define UART4_CR1_TE		BIT_ADDR(UART4_CR1_Addr,  3)
// UART4控制寄存器1IDLE中断使能位
#define UART4_CR1_IDLEIE	BIT_ADDR(UART4_CR1_Addr,  4)
// UART4控制寄存器1接收缓冲区非空中断使能位
#define UART4_CR1_RXNEIE	BIT_ADDR(UART4_CR1_Addr,  5)
// UART4控制寄存器1发送完成中断使能位
#define UART4_CR1_TCIE		BIT_ADDR(UART4_CR1_Addr,  6)
// UART4控制寄存器1发送缓冲区空中断使能位
#define UART4_CR1_TXEIE		BIT_ADDR(UART4_CR1_Addr,  7)
// UART4控制寄存器1PE中断使能位
#define UART4_CR1_PEIE		BIT_ADDR(UART4_CR1_Addr,  8)
// UART4控制寄存器1校验选择位(0：偶校验；1：奇校验)
#define UART4_CR1_PS		BIT_ADDR(UART4_CR1_Addr,  9)
// UART4控制寄存器1检验控制使能位
#define UART4_CR1_PCE		BIT_ADDR(UART4_CR1_Addr,  10)
// UART4控制寄存器1唤醒方法位(0：被空闲总线唤醒；1：被地址标记唤醒)
#define UART4_CR1_WAKE		BIT_ADDR(UART4_CR1_Addr,  11)
// UART4控制寄存器1字长位(0：一个起始位，8个数据位；1：一个起始位，9个数据位)
#define UART4_CR1_M			BIT_ADDR(UART4_CR1_Addr,  12)
// UART4控制寄存器1USART使能位
#define UART4_CR1_UE		BIT_ADDR(UART4_CR1_Addr,  13)

// UART5控制寄存器1发送断开帧标志寄存器
#define UART5_CR1_SBK		BIT_ADDR(UART5_CR1_Addr,  0)
// UART5控制寄存器1接收唤醒标志位
#define UART5_CR1_RWU		BIT_ADDR(UART5_CR1_Addr,  1)
// UART5控制寄存器1接收使能位
#define UART5_CR1_RE		BIT_ADDR(UART5_CR1_Addr,  2)
// UART5控制寄存器1发送使能位
#define UART5_CR1_TE		BIT_ADDR(UART5_CR1_Addr,  3)
// UART5控制寄存器1IDLE中断使能位
#define UART5_CR1_IDLEIE	BIT_ADDR(UART5_CR1_Addr,  4)
// UART5控制寄存器1接收缓冲区非空中断使能位
#define UART5_CR1_RXNEIE	BIT_ADDR(UART5_CR1_Addr,  5)
// UART5控制寄存器1发送完成中断使能位
#define UART5_CR1_TCIE		BIT_ADDR(UART5_CR1_Addr,  6)
// UART5控制寄存器1发送缓冲区空中断使能位
#define UART5_CR1_TXEIE		BIT_ADDR(UART5_CR1_Addr,  7)
// UART5控制寄存器1PE中断使能位
#define UART5_CR1_PEIE		BIT_ADDR(UART5_CR1_Addr,  8)
// UART5控制寄存器1校验选择位(0：偶校验；1：奇校验)
#define UART5_CR1_PS		BIT_ADDR(UART5_CR1_Addr,  9)
// UART5控制寄存器1检验控制使能位
#define UART5_CR1_PCE		BIT_ADDR(UART5_CR1_Addr,  10)
// UART5控制寄存器1唤醒方法位(0：被空闲总线唤醒；1：被地址标记唤醒)
#define UART5_CR1_WAKE		BIT_ADDR(UART5_CR1_Addr,  11)
// UART5控制寄存器1字长位(0：一个起始位，8个数据位，n个停止位；1：一个起始位，9个数据位，n个停止位)
#define UART5_CR1_M			BIT_ADDR(UART5_CR1_Addr,  12)
// UART5控制寄存器1USART使能位
#define UART5_CR1_UE		BIT_ADDR(UART5_CR1_Addr,  13)

/*
	0：不存在所述的错误或者标志/失能
	1：存在所述的错误或者标志/使能
*/
// 控制寄存器2

// USART1控制寄存器2LIN断开符检测长度(0：10位；1：11位)
#define USART1_CR2_LBDL		BIT_ADDR(USART1_CR2_Addr,  5)
// USART1控制寄存器2LIN断开符检测中断使能位
#define USART1_CR2_LBDIE	BIT_ADDR(USART1_CR2_Addr,  6)
// USART1控制寄存器2最后一位时钟脉冲(0：不从CK输出；1：会从CK输出)
#define USART1_CR2_LBCL		BIT_ADDR(USART1_CR2_Addr,  8)
// USART1控制寄存器2时钟相位(0：第一个边沿捕获；1：第二个边沿捕获)
#define USART1_CR2_CPHA		BIT_ADDR(USART1_CR2_Addr,  9)
// USART1控制寄存器2时钟极性位(0：空闲时低电平；1：空闲时高电平)
#define USART1_CR2_CPOL		BIT_ADDR(USART1_CR2_Addr,  10)
// USART1控制寄存器2时钟使能位(CK脚)
#define USART1_CR2_CLKEN	BIT_ADDR(USART1_CR2_Addr,  11)
// USART1控制寄存器2LIN模式使能
#define USART1_CR2_LINEN	BIT_ADDR(USART1_CR2_Addr,  14)

// USART2控制寄存器2LIN断开符检测长度(0：10位；1：11位)
#define USART2_CR2_LBDL		BIT_ADDR(USART2_CR2_Addr,  5)
// USART2控制寄存器2LIN断开符检测中断使能位
#define USART2_CR2_LBDIE	BIT_ADDR(USART2_CR2_Addr,  6)
// USART2控制寄存器2最后一位时钟脉冲(0：不从CK输出；1：会从CK输出)
#define USART2_CR2_LBCL		BIT_ADDR(USART2_CR2_Addr,  8)
// USART2控制寄存器2时钟相位(0：第一个边沿捕获；1：第二个边沿捕获)
#define USART2_CR2_CPHA		BIT_ADDR(USART2_CR2_Addr,  9)
// USART2控制寄存器2时钟极性位(0：空闲时低电平；1：空闲时高电平)
#define USART2_CR2_CPOL		BIT_ADDR(USART2_CR2_Addr,  10)
// USART2控制寄存器2时钟使能位(CK脚)
#define USART2_CR2_CLKEN	BIT_ADDR(USART2_CR2_Addr,  11)
// USART2控制寄存器2LIN模式使能
#define USART2_CR2_LINEN	BIT_ADDR(USART2_CR2_Addr,  14)

// USART3控制寄存器2LIN断开符检测长度(0：10位；1：11位)
#define USART3_CR2_LBDL		BIT_ADDR(USART3_CR2_Addr,  5)
// USART3控制寄存器2LIN断开符检测中断使能位
#define USART3_CR2_LBDIE	BIT_ADDR(USART3_CR2_Addr,  6)
// USART3控制寄存器2最后一位时钟脉冲(0：不从CK输出；1：会从CK输出)
#define USART3_CR2_LBCL		BIT_ADDR(USART3_CR2_Addr,  8)
// USART3控制寄存器2时钟相位(0：第一个边沿捕获；1：第二个边沿捕获)
#define USART3_CR2_CPHA		BIT_ADDR(USART3_CR2_Addr,  9)
// USART3控制寄存器2时钟极性位(0：空闲时低电平；1：空闲时高电平)
#define USART3_CR2_CPOL		BIT_ADDR(USART3_CR2_Addr,  10)
// USART3控制寄存器2时钟使能位(CK脚)
#define USART3_CR2_CLKEN	BIT_ADDR(USART3_CR2_Addr,  11)
// USART3控制寄存器2LIN模式使能
#define USART3_CR2_LINEN	BIT_ADDR(USART3_CR2_Addr,  14)

// UART4控制寄存器2LIN断开符检测长度(0：10位；1：11位)
#define UART4_CR2_LBDL		BIT_ADDR(UART4_CR2_Addr,  5)
// UART4控制寄存器2LIN断开符检测中断使能位
#define UART4_CR2_LBDIE		BIT_ADDR(UART4_CR2_Addr,  6)
// UART4控制寄存器2LIN模式使能
#define UART4_CR2_LINEN		BIT_ADDR(UART4_CR2_Addr,  14)

// UART5控制寄存器2LIN断开符检测长度(0：10位；1：11位)
#define UART5_CR2_LBDL		BIT_ADDR(UART5_CR2_Addr,  5)
// UART5控制寄存器2LIN断开符检测中断使能位
#define UART5_CR2_LBDIE		BIT_ADDR(UART5_CR2_Addr,  6)
// UART5控制寄存器2LIN模式使能
#define UART5_CR2_LINEN		BIT_ADDR(UART5_CR2_Addr,  14)

/*
	0：不存在所述的错误或者标志/失能
	1：存在所述的错误或者标志/使能
*/
// 控制寄存器3

// USART1控制寄存器3错误中断使能位
#define USART1_CR3_EIE		BIT_ADDR(USART1_CR3_Addr,  0)
// USART1控制寄存器3红外模式使能
#define USART1_CR3_IREN		BIT_ADDR(USART1_CR3_Addr,  1)
// USART1控制寄存器3红外模式低功耗位
#define USART1_CR3_IRLP		BIT_ADDR(USART1_CR3_Addr,  2)
// USART1控制寄存器3半双工选择位
#define USART1_CR3_HDSEL	BIT_ADDR(USART1_CR3_Addr,  3)
// USART1控制寄存器3智能卡NACK使能位
#define USART1_CR3_NACK		BIT_ADDR(USART1_CR3_Addr,  4)
// USART1控制寄存器3智能卡模式使能位
#define USART1_CR3_SCEN		BIT_ADDR(USART1_CR3_Addr,  5)
// USART1控制寄存器3DMA使能接收位
#define USART1_CR3_DMAR		BIT_ADDR(USART1_CR3_Addr,  6)
// USART1控制寄存器3DMA使能发送位
#define USART1_CR3_DMAT		BIT_ADDR(USART1_CR3_Addr,  7)
// USART1控制寄存器3RTS使能位
#define USART1_CR3_RTSE		BIT_ADDR(USART1_CR3_Addr,  8)
// USART1控制寄存器3CTS使能位
#define USART1_CR3_CTSE		BIT_ADDR(USART1_CR3_Addr,  9)
// USART1控制寄存器3CTS中断使能位
#define USART1_CR3_CTSIE	BIT_ADDR(USART1_CR3_Addr,  10)

// USART2控制寄存器3错误中断使能位
#define USART2_CR3_EIE		BIT_ADDR(USART2_CR3_Addr,  0)
// USART2控制寄存器3红外模式使能
#define USART2_CR3_IREN		BIT_ADDR(USART2_CR3_Addr,  1)
// USART2控制寄存器3红外模式低功耗位
#define USART2_CR3_IRLP		BIT_ADDR(USART2_CR3_Addr,  2)
// USART2控制寄存器3半双工选择位
#define USART2_CR3_HDSEL	BIT_ADDR(USART2_CR3_Addr,  3)
// USART2控制寄存器3智能卡NACK使能位
#define USART2_CR3_NACK		BIT_ADDR(USART2_CR3_Addr,  4)
// USART2控制寄存器3智能卡模式使能位
#define USART2_CR3_SCEN		BIT_ADDR(USART2_CR3_Addr,  5)
// USART2控制寄存器3DMA使能接收位
#define USART2_CR3_DMAR		BIT_ADDR(USART2_CR3_Addr,  6)
// USART2控制寄存器3DMA使能发送位
#define USART2_CR3_DMAT		BIT_ADDR(USART2_CR3_Addr,  7)
// USART2控制寄存器3RTS使能位
#define USART2_CR3_RTSE		BIT_ADDR(USART2_CR3_Addr,  8)
// USART2控制寄存器3CTS使能位
#define USART2_CR3_CTSE		BIT_ADDR(USART2_CR3_Addr,  9)
// USART2控制寄存器3CTS中断使能位
#define USART2_CR3_CTSIE	BIT_ADDR(USART2_CR3_Addr,  10)

// USART3控制寄存器3错误中断使能位
#define USART3_CR3_EIE		BIT_ADDR(USART3_CR3_Addr,  0)
// USART3控制寄存器3红外模式使能
#define USART3_CR3_IREN		BIT_ADDR(USART3_CR3_Addr,  1)
// USART3控制寄存器3红外模式低功耗位
#define USART3_CR3_IRLP		BIT_ADDR(USART3_CR3_Addr,  2)
// USART3控制寄存器3半双工选择位
#define USART3_CR3_HDSEL	BIT_ADDR(USART3_CR3_Addr,  3)
// USART3控制寄存器3智能卡NACK使能位
#define USART3_CR3_NACK		BIT_ADDR(USART3_CR3_Addr,  4)
// USART3控制寄存器3智能卡模式使能位
#define USART3_CR3_SCEN		BIT_ADDR(USART3_CR3_Addr,  5)
// USART3控制寄存器3DMA使能接收位
#define USART3_CR3_DMAR		BIT_ADDR(USART3_CR3_Addr,  6)
// USART3控制寄存器3DMA使能发送位
#define USART3_CR3_DMAT		BIT_ADDR(USART3_CR3_Addr,  7)
// USART3控制寄存器3RTS使能位
#define USART3_CR3_RTSE		BIT_ADDR(USART3_CR3_Addr,  8)
// USART3控制寄存器3CTS使能位
#define USART3_CR3_CTSE		BIT_ADDR(USART3_CR3_Addr,  9)
// USART3控制寄存器3CTS中断使能位
#define USART3_CR3_CTSIE	BIT_ADDR(USART3_CR3_Addr,  10)

// UART4控制寄存器3错误中断使能位
#define UART4_CR3_EIE		BIT_ADDR(UART4_CR3_Addr,  0)
// UART4控制寄存器3红外模式使能
#define UART4_CR3_IREN		BIT_ADDR(UART4_CR3_Addr,  1)
// UART4控制寄存器3红外模式低功耗位
#define UART4_CR3_IRLP		BIT_ADDR(UART4_CR3_Addr,  2)
// UART4控制寄存器3半双工选择位
#define UART4_CR3_HDSEL		BIT_ADDR(UART4_CR3_Addr,  3)

// UART5控制寄存器3错误中断使能位
#define UART5_CR3_EIE		BIT_ADDR(UART5_CR3_Addr,  0)
// UART5控制寄存器3红外模式使能
#define UART5_CR3_IREN		BIT_ADDR(UART5_CR3_Addr,  1)
// UART5控制寄存器3红外模式低功耗位
#define UART5_CR3_IRLP		BIT_ADDR(UART5_CR3_Addr,  2)
// UART5控制寄存器3半双工选择位
#define UART5_CR3_HDSEL		BIT_ADDR(UART5_CR3_Addr,  3)


#endif /* __UART_H */