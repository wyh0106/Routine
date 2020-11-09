#ifndef __SYSTICK_H
#define __SYSTICK_H

#include "stm32f10x.h"
#include "core_cm3.h"
#include "misc.h"

// systick时钟配置，需提供计数量tick
__STATIC_INLINE uint32_t SystickConfig(uint32_t ticks);
// 微秒级计时，需提供计时时长
void SysTick_us(uint32_t us);
// 毫秒级计时，需提供计时时长
void SysTick_ms(uint32_t ms);

#endif /*__SYSTICK_H*/