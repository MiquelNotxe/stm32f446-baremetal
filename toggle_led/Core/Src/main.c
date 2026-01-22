#include "stm32f4xx.h"
#include "gpio.h"

#define GPIO_PIN_13 (1U << 13)

int main(void)
{
	//Enable clock GPIOA / GPIOC
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN;

	gpio_init(GPIOC, 13, MODE_INPUT, PULL_UP);
	gpio_init(GPIOA, 5, MODE_OUTPUT, PULL_NONE);

    while (1)
    {
    	if((GPIOC->IDR & (GPIO_PIN_13)) == 0)
    	{
    		GPIOA->BSRR = (1 << 5);			// set
    	}
    	else
    	{
    		GPIOA->BSRR = (1 << (5 + 16));	// reset
    	}
    }
}
