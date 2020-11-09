#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define true 	1
#define false 	0
#define KEY0 	PEin(4)
#define KEY1 	PEin(3)
#define WakeUp 	PAin(0)

//初始化按键IO口
void KeyInit(void);
//扫描输入端口的按键状态，1为支持持续按下，0为不支持持续按下
u8 KeyScan(u8 mode);

#endif