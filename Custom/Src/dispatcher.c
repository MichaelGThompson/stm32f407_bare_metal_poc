#include <dispatcher.h>
#include "gpio.h"
#include "tim.h"
#include "finite_state_machine.h"

/**
 * Just an excuse to use a finite state machine. Pressing the button will trigger four possible states represented by 2 LEDs.
 */
void button_handler(float value) {
	fsm_state_t next = fsm_table[current_state].next_state;
	current_state = next;
	if (fsm_table[current_state].state_action != NULL) {
		fsm_table[current_state].state_action();
	}
}

/**
 * TODO: Add handler for processing temperature measurements
 */
void temperature_handler(float value) {

}

/**
 * Convert 0-4095 digital representation of input voltage (just the voltage from adjusting a potentiometer) to control
 * the duty cycle if the PWM (tiemr).
 *
 */
void voltage_handler(float value) {
	uint32_t pwm_duty_cycle = (value * 999) / 4095; //
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, pwm_duty_cycle);
}

void dispatch_event(eventType_t event_type, float value) {
    if (event_type >= 0 && event_type < EVENT_COUNT) {
        event_dispatch_table[event_type](value);
    } else {
    	// TODO: Create an error type and define functions to facilitate app-wide error management.
    }
}
