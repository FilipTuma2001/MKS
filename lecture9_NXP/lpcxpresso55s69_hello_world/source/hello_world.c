/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017, 2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"

#include <stddef.h>
#include <stdio.h>

#include "fsl_power.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int constant_time(const char *a, const char *b) {
	size_t i = 0;
	unsigned char result = 0;

	while(a[i] != '\0' || b[i] != '\0') {
		result |= (unsigned char)(a[i] ^ b[i]);
		i++;
	}
	return result;
}

int main(void)
{
	char ch;

	/* Init board hardware. */
	/* set BOD VBAT level to 1.65V */
	POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
	/* attach main clock divide to FLEXCOMM0 (debug console) */
	CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();
#if !defined(DONT_ENABLE_FLASH_PREFETCH)
	/* enable flash prefetch for better performance */
	SYSCON->FMCCR |= SYSCON_FMCCR_PREFEN_MASK;
#endif

	uint32_t DWT1, DWT2;
	char password_stored[20] = "1234";
	char input[20];


	while (1)
	{
		PRINTF("\r\nEnter password: ");
		SCANF("%s", input);

		DWT1=DWT->CYCCNT;
		//uint8_t status = strcmp(input, password_stored);
		uint8_t status = constant_time(input, password_stored);
		DWT2=DWT->CYCCNT;

		PRINTF("\r\nCycles in function: %d", DWT2-DWT1);
		PRINTF("\r\nInput: %s", input);

		if(status==0)
		{
			PRINTF("\r\nInput is correct");
		}
		else
		{
			PRINTF("\r\nInput is wrong");
		}
	}
}
