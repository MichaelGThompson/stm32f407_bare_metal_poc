/*
 * observer.h
 *
 * TODO: Create another version of this project using observers...or add another sensor/input that can be observed.
 *  Created on: Oct 12, 2026
 *      Author: mgt
 */

#ifndef INC_OBSERVER_H_
#define INC_OBSERVER_H_

// Forward declaration of the observer struct
typedef struct Observer Observer;

struct Observer {
    // Function pointer representing the "Update" method
    void (*update)(Observer* self, int event_data);
};

#define OBSERVER_MAX_SUBSCRIBERS 4

#endif /* INC_OBSERVER_H_ */
