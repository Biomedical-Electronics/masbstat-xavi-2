/*
 * timers.h
 *
 *  Created on: 23 may. 2023
 *      Author: xgome
 */

#ifndef INC_COMPONENTS_TIMERS_H_
#define INC_COMPONENTS_TIMERS_H_

#define TRUE 1
#define FALSE 0

#include "stm32f4xx_hal.h"
uint32_t samplingPeriodMs;
_Bool Sampling_Period_Completed;

void Sample_Period_Ellaspsed(void);


#endif /* INC_COMPONENTS_TIMERS_H_ */
