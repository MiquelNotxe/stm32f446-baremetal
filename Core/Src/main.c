#include "stm32f4xx.h"

volatile uint32_t systick_ms = 0;

void delay_ms(uint32_t ms)
{
	uint32_t start = systick_ms;
	while ((systick_ms - start) < ms);
}

int main(void)
{
	// 1. SysTick a 1 ms (HSI = 16 MHz)
	SysTick_Config(SystemCoreClock / 1000);

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));



    while (1)
    {
        GPIOA->ODR ^= (1U << 5);
        delay_ms(250);
    }
}
