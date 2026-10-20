#include "finite_state_machine.h"
#include "gpio.h"
#include "led_implementation.h"

void display_all_off(void) {
	Led1.Off();
	Led2.Off();
}

void display_led1_on(void) {
	Led1.On();
	Led2.Off();
}

void display_led2_on(void) {
	Led1.Off();
	Led2.On();
}

void display_all_on(void) {
	Led1.On();
	Led2.On();
}
