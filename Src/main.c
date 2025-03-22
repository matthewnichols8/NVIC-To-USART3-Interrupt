/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define USART3_IRQ_NUM 39

void USART3_IRQHandler(void);

/*
 * USART3 is position 39 of NVIC
 * USART3 NVIC Address is 0x0000 00DC
 * NVIC_ISPR0 starting address is 0XE000E200 --> NVIC_ISPR1 address is 0XE000E204
 * NVIC_ISER0 starting address is  0xE000E100 --> NVIC_ISER1 address is  0xE000E104
 * USART3 global interrupt name is: USART3_IRQHandler
 *
 * Set Priority first, then enable IRQ.
 * When Interrupt is detected on USART3 --> Set to pending Interrupt --> Interrupt executed
 */

int main(void)
{

	//1) Pend the pending bit for USART3 IRQ number in NVIC
	uint32_t* volatile pISPR1 = (uint32_t*) 0XE000E204;

	*pISPR1 |= (1 << (USART3_IRQ_NUM % 32)); //Sets the 39 bit of NVIC_ISPR1
	//*pISPR1 |= (1 << 7); //Sets the 39th bit of NVIC

	//2) Enable USART3 IRQ number in NVIC to trigger Interrupt
	uint32_t* volatile pISER1 = (uint32_t*)  0xE000E104;

	*pISER1 |= (1 << (USART3_IRQ_NUM % 32)); //Sets the 39 bit of NVIC_ISER1

    /* Loop forever */
	for(;;);
}

void USART3_IRQHandler(void) {
	printf("In the USART3 ISR\n");
}
