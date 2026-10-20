#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "stm32f4xx.h"

#ifdef __cplusplus
extern "C" {
#endif

// fsm for displaying sequence of 2 leds
typedef enum {
    STATE_ALL_OFF,
    STATE_LED1_ON,
    STATE_LED2_ON,
    STATE_ALL_ON
} fsm_state_t;

// TODO: Next iteration, the FSM will be driven by an external VTable so these functions won't be defined here
void display_all_off(void);
void display_led1_on(void);
void display_led2_on(void);
void display_all_on(void);

typedef struct {
    fsm_state_t next_state;
    void (*state_action)(void);
} fsm_transition_t;

/**
 * TODO: Make this more generic (use an externally provided VTable)
 */
static const fsm_transition_t fsm_table[STATE_ALL_ON + 1] = {
    [STATE_ALL_OFF]  = { .next_state = STATE_LED1_ON,    .state_action = display_all_off   },
    [STATE_LED1_ON]   = { .next_state = STATE_LED2_ON,  .state_action = display_led1_on    },
    [STATE_LED2_ON] = { .next_state = STATE_ALL_ON,    .state_action = display_led2_on  },
    [STATE_ALL_ON]   = { .next_state = STATE_ALL_OFF,   .state_action = display_all_on    }
};

// Global state tracker
static fsm_state_t current_state = STATE_ALL_OFF;

#ifdef __cplusplus
}
#endif
