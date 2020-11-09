#include "systick.h"

// 微秒计时
void SysTick_us(uint32_t us){
	uint32_t i;
	SystickConfig(72);

	for(i=0; i<us; i++){
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
	}

	SysTick->CTRL &= ~1;
}

// 毫秒计时
void SysTick_ms(uint32_t ms){
	uint32_t i;
	SystickConfig(72000);

	for(i=0; i<ms; i++){
		while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
	}

	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

__STATIC_INLINE uint32_t SystickConfig(uint32_t ticks){
	/* 非法重装载值处理 */
	if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
		return (1UL);                                                   

	/* 设置重装载寄存器 */
	SysTick->LOAD  = (uint32_t)(ticks - 1UL);
	/* 设置中断优先级 */
	NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL);
	/* 重置Value寄存器的读取值 */
	SysTick->VAL   = 0UL;
	/* 选择时钟源并使能定时器 */
	SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

	return 0;
}
