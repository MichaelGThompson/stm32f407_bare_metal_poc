#include "mspc_event_queue.h"

static event_queue_t system_queue;

void queue_init(void) {
    system_queue.head = 0;
    system_queue.tail = 0;
}

/**
 * @brief Thread-safe push for multiple STM32 ISRs & Main thread.
 */
bool queue_push_from_isr(eventType_t type, uint32_t payload) {
    // Snapshot and disable interrupts to preserve the state of other ISRs
    uint32_t primask_state = __get_PRIMASK();
    __disable_irq(); // Blocks all configurable interrupts (Cortex-M4 PRIMASK = 1)

    uint32_t next_head = (system_queue.head + 1) % EVT_Q_SIZE;

    if (next_head == system_queue.tail) {
        // Queue is Full! Restore original interrupt state and exit safely
        __set_PRIMASK(primask_state);
        return false;
    }

    // Write data into buffer
    system_queue.buffer[system_queue.head].type = type;
    system_queue.buffer[system_queue.head].payload = payload;
    system_queue.head = next_head;

    // Restore original interrupt state (safely handles nested environments)
    __set_PRIMASK(primask_state);
    return true;
}

/**
 * @brief Single-consumer pop used ONLY in the main processing super-loop.
 */
bool queue_pop_main(event_t *out_evt) {
    if (system_queue.tail == system_queue.head) {
        return false; // Queue is empty
    }

    *out_evt = system_queue.buffer[system_queue.tail];
    system_queue.tail = (system_queue.tail + 1) % EVT_Q_SIZE;

    return true;
}
