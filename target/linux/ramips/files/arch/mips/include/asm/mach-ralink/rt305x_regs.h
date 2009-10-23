/*
 *  Ralink RT305 SoC register definitions
 *
 *  Copyright (C) 2009 Gabor Juhos <juhosg@openwrt.org>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License version 2 as published
 *  by the Free Software Foundation.
 */

#ifndef _RT305X_REGS_H_
#define _RT305X_REGS_H_

#include <linux/bitops.h>

#define RT305X_SDRAM_BASE	0x00000000
#define RT305X_SYSC_BASE	0x10000000
#define RT305X_TIMER_BASE	0x10000100
#define RT305X_INTC_BASE	0x10000200
#define RT305X_MEMC_BASE	0x10000300
#define RT305X_PCM_BASE		0x10000400
#define RT305X_UART0_BASE	0x10000500
#define RT305X_GDMA_BASE	0x10000700
#define RT305X_NANDC_BASE	0x10000800
#define RT305X_I2C_BASE		0x10000900
#define RT305X_I2S_BASE		0x10000a00
#define RT305X_SPI_BASE		0x10000b00
#define RT305X_UART1_BASE	0x10000c00
#define RT305X_FE_BASE		0x10100000
#define RT305X_SWITCH_BASE	0x10110000
#define RT305X_WMAC_BASE	0x00180000
#define RT305X_OTG_BASE		0x101c0000
#define RT305X_ROM_BASE		0x00400000
#define RT305X_FLASH1_BASE	0x1b000000
#define RT305X_FLASH0_BASE	0x1f000000

#define RT305X_SYSC_SIZE	0x100
#define RT305X_TIMER_SIZE	0x100
#define RT305X_INTC_SIZE	0x100
#define RT305X_MEMC_SIZE	0x100
#define RT305X_UART0_SIZE	0x100
#define RT305X_UART1_SIZE	0x100
#define RT305X_FLASH1_SIZE	(16 * 1024 * 1024)
#define RT305X_FLASH0_SIZE	(4 * 1024 * 1024)

/* SYSC registers */
#define SYSC_REG_CHIP_NAME0	0x000	/* Chip Name 0 */
#define SYSC_REG_CHIP_NAME1	0x004	/* Chip Name 1 */
#define SYSC_REG_CHIP_ID	0x00c	/* Chip Identification */
#define SYSC_REG_SYSTEM_CONFIG	0x010	/* System Configuration */
#define SYSC_REG_RESET_CTRL	0x034	/* Reset Control*/
#define SYSC_REG_RESET_STATUS	0x038	/* Reset Status*/
#define SYSC_REG_GPIO_MODE	0x060	/* GPIO Purpose Select */
#define SYSC_REG_IA_ADDRESS	0x310	/* Illegal Access Address */
#define SYSC_REG_IA_TYPE	0x314	/* Illegal Access Type */

#define CHIP_ID_ID_MASK		0xff
#define CHIP_ID_ID_SHIFT	8
#define CHIP_ID_REV_MASK	0xff

#define SYSTEM_CONFIG_CPUCLK_SHIFT	18
#define SYSTEM_CONFIG_CPUCLK_MASK	0x1
#define SYSTEM_CONFIG_CPUCLK_320	0x0
#define SYSTEM_CONFIG_CPUCLK_384	0x1

#define RT305X_GPIO_MODE_I2C		BIT(0)
#define RT305X_GPIO_MODE_SPI		BIT(1)
#define RT305X_GPIO_MODE_UART0_SHIFT	2
#define RT305X_GPIO_MODE_UART0_MASK	0x7
#define RT305X_GPIO_MODE_UART0(x)	((x) << RT305X_GPIO_MODE_UART0_SHIFT)
#define RT305X_GPIO_MODE_UARTF		0x0
#define RT305X_GPIO_MODE_PCM_UARTF	0x1
#define RT305X_GPIO_MODE_PCM_I2S	0x2
#define RT305X_GPIO_MODE_I2S_UARTF	0x3
#define RT305X_GPIO_MODE_PCM_GPIO	0x4
#define RT305X_GPIO_MODE_GPIO_UARTF	0x5
#define RT305X_GPIO_MODE_GPIO_I2S	0x6
#define RT305X_GPIO_MODE_GPIO		0x7
#define RT305X_GPIO_MODE_UART1		BIT(5)
#define RT305X_GPIO_MODE_JTAG		BIT(6)
#define RT305X_GPIO_MODE_MDIO		BIT(7)
#define RT305X_GPIO_MODE_SDRAM		BIT(8)
#define RT305X_GPIO_MODE_RGMII		BIT(9)

#define RT305X_RESET_SYSTEM	BIT(0)
#define RT305X_RESET_TIMER	BIT(8)
#define RT305X_RESET_INTC	BIT(9)
#define RT305X_RESET_MEMC	BIT(10)
#define RT305X_RESET_PCM	BIT(11)
#define RT305X_RESET_UART0	BIT(12)
#define RT305X_RESET_PIO	BIT(13)
#define RT305X_RESET_DMA	BIT(14)
#define RT305X_RESET_I2C	BIT(16)
#define RT305X_RESET_I2S	BIT(17)
#define RT305X_RESET_SPI	BIT(18)
#define RT305X_RESET_UART1	BIT(19)
#define RT305X_RESET_WNIC	BIT(20)
#define RT305X_RESET_FE		BIT(21)
#define RT305X_RESET_OTG	BIT(22)
#define RT305X_RESET_ESW	BIT(23)

#define RT305X_INTC_INT_SYSCTL	BIT(0)
#define RT305X_INTC_INT_TIMER0	BIT(1)
#define RT305X_INTC_INT_TIMER1	BIT(2)
#define RT305X_INTC_INT_IA	BIT(3)
#define RT305X_INTC_INT_PCM	BIT(4)
#define RT305X_INTC_INT_UART0	BIT(5)
#define RT305X_INTC_INT_PIO	BIT(6)
#define RT305X_INTC_INT_DMA	BIT(7)
#define RT305X_INTC_INT_NAND	BIT(8)
#define RT305X_INTC_INT_PERFC	BIT(9)
#define RT305X_INTC_INT_I2S	BIT(10)
#define RT305X_INTC_INT_UART1	BIT(12)
#define RT305X_INTC_INT_ESW	BIT(17)
#define RT305X_INTC_INT_OTG	BIT(18)
#define RT305X_INTC_INT_GLOBAL	BIT(31)

/* MEMC registers */
#define MEMC_REG_SDRAM_CFG0	0x00
#define MEMC_REG_SDRAM_CFG1	0x04
#define MEMC_REG_FLASH_CFG0	0x08
#define MEMC_REG_FLASH_CFG1	0x0c
#define MEMC_REG_IA_ADDR	0x10
#define MEMC_REG_IA_TYPE	0x14

#define FLASH_CFG_WIDTH_SHIFT	26
#define FLASH_CFG_WIDTH_MASK	0x3
#define FLASH_CFG_WIDTH_8BIT	0x0
#define FLASH_CFG_WIDTH_16BIT	0x1
#define FLASH_CFG_WIDTH_32BIT	0x2

/* UART registers */
#define UART_REG_RX	0
#define UART_REG_TX	1
#define UART_REG_IER	2
#define UART_REG_IIR	3
#define UART_REG_FCR	4
#define UART_REG_LCR	5
#define UART_REG_MCR	6
#define UART_REG_LSR	7

#endif /* _RT305X_REGS_H_ */
