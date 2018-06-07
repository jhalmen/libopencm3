/** @defgroup sdio_file SDIO

@ingroup STM32F4xx

@brief <b>libopencm3 STM32F4xx SDIO Interface</b>

@author @htmlonly &copy; @endhtmlonly 2012
Jonathan Halmen <jonathan@halmen.org>

@date 23 April 2018

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2018 Jonathan Halmen <jonathan@halmen.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/sdio.h>


void sdio_power_on(void)
{
	SDIO_POWER |= SDIO_POWER_PWRCTRL_PWRON;
}

void sdio_power_off(void)
{
	SDIO_POWER &= ~SDIO_POWER_PWRCTRL_PWRON;
}

void sdio_enable_hw_flow_control(void)
{
	SDIO_CLKCR |= SDIO_CLKCR_HWFC_EN;
}

void sdio_disable_hw_flow_control(void)
{
	SDIO_CLKCR &= ~SDIO_CLKCR_HWFC_EN;
}

void sdio_enable_dephase(void)
{
	SDIO_CLKCR |= SDIO_CLKCR_NEGEDGE;
}

void sdio_disable_dephase(void)
{
	SDIO_CLKCR &= ~SDIO_CLKCR_NEGEDGE;
}

void sdio_set_bus_width(enum sdio_bus_width w)
{
	//send SELECT/DESELECT_CARD (CMD7)
	//send SET_BUS_WIDTH(ACMD6)
	//put pins in respective states
		// enable PullUps on DAT lines
	SDIO_CLKCR |= w << SDIO_CLKCR_WIDBUS_SHIFT;
}

void sdio_enable_clk_bypass(void)
{
	SDIO_CLKCR |= SDIO_CLKCR_BYPASS;
}

void sdio_disable_clk_bypass(void)
{
	SDIO_CLKCR &= ~SDIO_CLKCR_BYPASS;
}

void sdio_enable_pwrsave(void)
{
	SDIO_CLKCR |= SDIO_CLKCR_PWRSAV;
}

void sdio_disable_pwrsave(void)
{
	SDIO_CLKCR &= ~SDIO_CLKCR_PWRSAV;
}

void sdio_enable_clock(void)
{
	SDIO_CLKCR |= SDIO_CLKCR_CLKEN;
}

void sdio_disable_clock(void)
{
	SDIO_CLKCR &= ~SDIO_CLKCR_CLKEN;
}

void sdio_set_clk_div(uint8_t div)
{
	/* SDIO_CK = SDIOCLK / (div + 2) */
	SDIO_CLKCR = (SDIO_CLKCR & 0xFFFFFF00) | div;
}

void sdio_enable_interrupts(uint32_t interrupts)
{
	SDIO_MASK |= interrupts;
}

void sdio_disable_interrupts(uint32_t interrupts)
{
	SDIO_MASK &= ~interrupts;
}

