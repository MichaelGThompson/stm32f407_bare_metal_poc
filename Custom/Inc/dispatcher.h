
#include "mspc_event_queue.h"
/*
 * This is the project specific dispatcher where the dispatch table is created.
 *
 * TODO: Make a generic version and initiaize with an external dispatch table
 *
 */

// event handlers
void button_handler(float);
void temperature_handler(float);
void voltage_handler(float);

typedef void (*EventHandler)(float value);

static const EventHandler event_dispatch_table[EVENT_COUNT] = {
    [EVT_EXINT_BUTTON] 				= button_handler,
    [EVT_ADC_CONVERSION_SENSOR_1]   = temperature_handler,
    [EVT_ADC_CONVERSION_SENSOR_2]   = voltage_handler
};


void dispatch_event(eventType_t event_type, float value);

#ifdef __cplusplus
}
#endif

