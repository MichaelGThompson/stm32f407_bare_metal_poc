/*
 * led_hardware_implementation.c
 *
 *  Created on: Oct 5, 2026
 *      Author: mgt
 */


#include "led_implementation.h"
#include "stm32f4xx_hal.h"
#include "gpio.h"

void Led1On ( void ) { HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); }
void Led1Off ( void ) { HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); }
void Led1Toggle (void) { HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6); }
iLed Led1 = { Led1On, Led1Off, Led1Toggle };

void Led2On ( void ) { HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); }
void Led2Off ( void ) { HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET); }
void Led2Toggle (void) { HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7); }

iLed Led2 = { Led2On, Led2Off, Led2Toggle };

