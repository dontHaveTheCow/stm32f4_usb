#ifndef DELAY_LIBRARY
#define DELAY_LIBRARY

//These are the Includes
#include <stm32f4xx.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>

//These are the Define statements
static __IO uint32_t sysTickCounter;
//These are the prototypes for the routines
void initialiseSysTick(void);
void delayMs(int ms);

#endif
