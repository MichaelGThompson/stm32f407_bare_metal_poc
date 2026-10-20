#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "stm32f4xx.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Event queue that is thread safe when enqueuing multiple sensor values.
 */

#define EVT_Q_SIZE 32

typedef enum {
    EVT_NONE = 0,
    EVT_EXINT_BUTTON,
    EVT_ADC_CONVERSION_SENSOR_1,
	EVT_ADC_CONVERSION_SENSOR_2,
	EVENT_COUNT // Total number of events
} eventType_t;

typedef struct {
    eventType_t type;
    float payload;
} event_t;

typedef struct {
    volatile event_t buffer[EVT_Q_SIZE];
    volatile uint32_t head;
    volatile uint32_t tail;
} event_queue_t;

void queue_init(void);
bool queue_push_from_isr(eventType_t type, uint32_t payload);
bool queue_pop_main(event_t *out_evt);

#ifdef __cplusplus
}
#endif
