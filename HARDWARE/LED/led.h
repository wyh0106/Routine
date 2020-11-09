#ifndef __LED_H
#define __LED_H	 
#include "sys.h"

//LED端口定义
#define LED_Red 	PBout(5)	// DS0
#define LED_Green 	PEout(5)	// DS1

#define ON 			0
#define OFF 		1

//LED端口初始化
void LedInit(void);

#endif

















