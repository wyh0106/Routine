#ifndef __RCC_H
#define __RCC_H

#include "sys.h"

#define AHB_BASE ((u32)0x40018000)


#define RCC_CR_Addr         (RCC_BASE + 0)
#define RCC_CFGR_Addr       (RCC_BASE + 4)
#define RCC_CIR_Addr        (RCC_BASE + 8)
#define RCC_APB2RSTR_Addr   (RCC_BASE + 12)
#define RCC_APB1RSTR_Addr   (RCC_BASE + 16)
#define RCC_AHBENR_Addr     (RCC_BASE + 20)
#define RCC_APB2ENR_Addr    (RCC_BASE + 24)
#define RCC_APB1ENR_Addr    (RCC_BASE + 28)
#define RCC_BDCR_Addr       (RCC_BASE + 32)
#define RCC_CSR_Addr        (RCC_BASE + 36)

#define RCCcr(n)            BIT_ADDR(RCC_CR_Addr,n)
#define RCCcfgr(n)          BIT_ADDR(RCC_CFGR_Addr ,n)
#define RCCcir(n)           BIT_ADDR(RCC_CIR_Addr,n)
#define RCCapb2rstr(n)      BIT_ADDR(RCC_APB2RSTR_Addr,n)
#define RCCapb1rstr(n)      BIT_ADDR(RCC_APB1RSTR_Addr,n)
#define RCCahbenr(n)        BIT_ADDR(RCC_AHBENR_Addr,n)
#define RCCapb2enr(n)       BIT_ADDR(RCC_APB2ENR_Addr,n)
#define RCCapb1enr(n)       BIT_ADDR(RCC_APB1ENR_Addr ,n)
#define RCCbdcr(n)          BIT_ADDR(RCC_BDCR_Addr,n)
#define RCCcsr(n)           BIT_ADDR(RCC_CSR_Addr ,n)


// RCC-CR寄存器（时钟控制寄存器）
#define HSION               RCCcr(0)
#define HSIRDY              RCCcr(1)
#define HSEON               RCCcr(16)
#define HSERDY              RCCcr(17)
#define HSEBYP              RCCcr(18)
#define CSSON               RCCcr(19)
#define PLLON               RCCcr(24)
#define PLLRDY              RCCcr(25)

// RCC-CFGR寄存器（时钟配置寄存器）
#define PLLSRC              RCCcfgr(16)
#define PLLXTPRE            RCCcfgr(17)
#define USBPRE              RCCcfgr(22)

// RCC-CIR寄存器（时钟中断寄存器）
#define LSIRDYF             RCCcir(0)
#define LSERDYF             RCCcir(1)
#define HSIRDYF             RCCcir(2)
#define HSERDYF             RCCcir(3)
#define PLLRDYF             RCCcir(4)
#define CSSF                RCCcir(7)
#define LSIRDYIE            RCCcir(8)
#define LSERDYIE            RCCcir(9)
#define HSIRDYIE            RCCcir(10)
#define HSERDYIE            RCCcir(11)
#define PLLRDYIE            RCCcir(12)
#define LSIRDYC             RCCcir(16)
#define LSERDYC             RCCcir(17)
#define HSIRDYC             RCCcir(18)
#define HSERDYC             RCCcir(19)
#define PLLRDYC             RCCcir(20)
#define CSSC                RCCcir(23)

// RCC-APB2RSTR寄存器（APB2外设复位寄存器）
#define AFIORST             RCCapb2rstr(0)
#define IOPARST             RCCapb2rstr(2)
#define IOPBRST             RCCapb2rstr(3)
#define IOPCRST             RCCapb2rstr(4)
#define IOPDRST             RCCapb2rstr(5)
#define IOPERST             RCCapb2rstr(6)
#define IOPFRST             RCCapb2rstr(7)
#define IOPGRST             RCCapb2rstr(8)
#define ADC1RST             RCCapb2rstr(9)
#define AD2CRST             RCCapb2rstr(10)
#define TIM1RST             RCCapb2rstr(11)
#define SPI1RST             RCCapb2rstr(12)
#define TIM8RST             RCCapb2rstr(13)
#define USART1RST           RCCapb2rstr(14)
#define ADC3RST             RCCapb2rstr(15)

// RCC-APB1RSTR寄存器（APB1外设复位寄存器）
#define TIM2RST             RCCapb1rstr(0)
#define TIM3RST             RCCapb1rstr(1)
#define TIM4RST             RCCapb1rstr(2)
#define TIM5RST             RCCapb1rstr(3)
#define TIM6RST             RCCapb1rstr(4)
#define TIM7RST             RCCapb1rstr(5)
#define WWDGRST             RCCapb1rstr(11)
#define SPI2RST             RCCapb1rstr(14)
#define SPI3RST             RCCapb1rstr(15)
#define USART2RST           RCCapb1rstr(17)
#define USART3RST           RCCapb1rstr(18)
#define UART4RST            RCCapb1rstr(19)
#define UART5RST            RCCapb1rstr(20)
#define I2C1RST             RCCapb1rstr(21)
#define I2C2RST             RCCapb1rstr(22)
#define USBRST              RCCapb1rstr(23)
#define CANRST              RCCapb1rstr(25)
#define BKPRST              RCCapb1rstr(27)
#define PWRRST              RCCapb1rstr(28)
#define DACRST              RCCapb1rstr(29)

// RCC-AHBENR寄存器（AHB外设时钟使能寄存器）

// DMA1时钟使能位
#define DMA1_CLK_EN				RCCahbenr(0)
// DMA1时钟使能位
#define DMA2_CLK_EN				RCCahbenr(1)
// SRAM时钟使能位
#define SRAM_CLK_EN				RCCahbenr(2)
// 闪存接口电路时钟使能
#define FLITF_CLK_EN				RCCahbenr(4)
// CRC时钟使能
#define CRC_CLK_EN				RCCahbenr(6)
// FSMC时钟使能
#define FSMC_CLK_EN				RCCahbenr(8)
// SDIO时钟使能
#define SDIO_CLK_EN				RCCahbenr(10)

// RCC-APB2ENR寄存器（APB2外设时钟使能寄存器）

// 辅助功能IO时钟使能
#define AFIO_CLK_EN              RCCapb2enr(0)
// IO端口A时钟使能
#define IOPA_CLK_EN              RCCapb2enr(2)
// IO端口B时钟使能
#define IOPB_CLK_EN              RCCapb2enr(3)
// IO端口C时钟使能
#define IOPC_CLK_EN              RCCapb2enr(4)
// IO端口D时钟使能
#define IOPD_CLK_EN              RCCapb2enr(5)
// IO端口E时钟使能
#define IOPE_CLK_EN              RCCapb2enr(6)
// IO端口F时钟使能
#define IOPF_CLK_EN              RCCapb2enr(7)
// IO端口G时钟使能
#define IOPG_CLK_EN              RCCapb2enr(8)
// ADC1时钟使能
#define ADC1_CLK_EN              RCCapb2enr(9)
// ADC2时钟使能
#define ADC2_CLK_EN              RCCapb2enr(10)
// TIM1时钟使能
#define TIM1_CLK_EN              RCCapb2enr(11)
// SPI1时钟使能
#define SPI1_CLK_EN              RCCapb2enr(12)
// TIM8定时器时钟使能
#define TIM8_CLK_EN              RCCapb2enr(13)
// USART1时钟使能
#define USART1_CLK_EN            RCCapb2enr(14)
// ADC3接口时钟使能
#define ADC3_CLK_EN              RCCapb2enr(15)

// RCC-APB1ENR寄存器（APB1外设时钟使能寄存器）

// 定时器2时钟使能
#define TIM2_CLK_EN              RCCapb1enr(0)
// 定时器3时钟使能
#define TIM3_CLK_EN              RCCapb1enr(1)
// 定时器4时钟使能
#define TIM4_CLK_EN              RCCapb1enr(2)
// 定时器5时钟使能
#define TIM5_CLK_EN              RCCapb1enr(3)
// 定时器6时钟使能
#define TIM6_CLK_EN              RCCapb1enr(4)
// 定时器7时钟使能
#define TIM7_CLK_EN              RCCapb1enr(5)
// 窗口看门狗时钟使能
#define WWDG_CLK_EN              RCCapb1enr(11)
// SPI 2时钟使能
#define SPI2_CLK_EN              RCCapb1enr(14)
// SPI 3时钟使能
#define SPI3_CLK_EN              RCCapb1enr(15)
// USART2时钟使能
#define USART2_CLK_EN            RCCapb1enr(17)
// USART3时钟使能
#define USART3_CLK_EN            RCCapb1enr(18)
// UART4时钟使能
#define UART4_CLK_EN             RCCapb1enr(19)
// UART5时钟使能
#define UART5_CLK_EN             RCCapb1enr(20)
// I2C 1时钟使能
#define I2C1_CLK_EN              RCCapb1enr(21)
// I2C 2时钟使能
#define I2C2_CLK_EN              RCCapb1enr(22)
// USB时钟使能
#define USB_CLK_EN               RCCapb1enr(23)
// CAN时钟使能
#define CAN_CLK_EN               RCCapb1enr(25)
// 备份接口时钟使能
#define BKP_CLK_EN               RCCapb1enr(27)
// 电源接口时钟使能
#define PWR_CLK_EN               RCCapb1enr(28)
// DAC接口时钟使能
#define DAC_CLK_EN               RCCapb1enr(29)

// RCC-BDCR寄存器（备份域控制寄存）
#define LSEON               RCCbdcr(0)
#define LSERDY              RCCbdcr(1)
#define LSEBYP              RCCbdcr(2)
#define RTCEN               RCCbdcr(15)
#define BDRST               RCCbdcr(16)

// RCC-CSR寄存器（控制/状态寄存器）
#define LSION               RCCcsr(0)
#define LSIRDY              RCCcsr(1)
#define RMVF                RCCcsr(24)
#define PINRSTF             RCCcsr(26)
#define PORRSTF             RCCcsr(27)
#define SFTRSTF             RCCcsr(28)
#define IWDGRSTF            RCCcsr(29)
#define WWDGRSTF            RCCcsr(30)
#define LPWRRSTF            RCCcsr(31)


#endif /* __RCC_H */