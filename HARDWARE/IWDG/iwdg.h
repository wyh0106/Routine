#ifndef __IWDG_H
#define __IWDG_H

#include "sys.h"

#define WrtEnr		0x5555				// KR寄存器写入使能
#define ENR			0xCCCC				// IWDG使能
#define IwdgRld	IWDG->KR = 0xAAAA		// RLR寄存器重载数值

// 初始化独立看门狗,Prer预分频系数,Rlr为重装载值
void IwdgInit(u8 Prer, u16 Rlr);

#endif /*__IWDG_H*/