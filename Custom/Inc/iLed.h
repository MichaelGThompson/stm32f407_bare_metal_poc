/*
 * iLed.h
 *
 *  Created on: Oct 5, 2026
 *      Author: mgt
 */

#ifndef INC_ILED_H_
#define INC_ILED_H_

typedef void (*iLedOperation)(void);

typedef struct {
	const iLedOperation On;
	const iLedOperation Off;
	const iLedOperation Toggle;

} iLed;

#endif /* INC_ILED_H_ */
