#ifndef GPIO_H
#define GPIO_H

#include "stm32f4xx.h"

// MODER values (2 bits per pin)
#define MODE_INPUT     0x0U
#define MODE_OUTPUT    0x1U
#define MODE_ALTER     0x2U
#define MODE_ANALOG    0x3U

// PUPDR values (2 bits per pin)
#define PULL_NONE		0x0U
#define PULL_UP			0x1U
#define PULL_DOWN		0x2U

static inline void gpio_init(GPIO_TypeDef *port, uint32_t pin, uint32_t mode, uint32_t pull)
{
    port->MODER &= ~(3U << (2U * pin));
    port->MODER |=  (mode << (2U * pin));

    port->PUPDR &= ~(3U << (2U * pin));
    port->PUPDR |=  (pull << (2U * pin));
}

#endif /* GPIO_H */
