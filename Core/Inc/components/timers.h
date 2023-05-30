/*
 * timers.h
 *
 *  Created on: 23 may. 2023
 *      Author: xgome
 */

#ifndef INC_COMPONENTS_TIMERS_H_
#define INC_COMPONENTS_TIMERS_H_

#include "main.h"
#include "stm32f4xx_hal.h"

#define TRUE 1
#define FALSE 0

volatile _Bool Sampling_Period_Completed;

void Sample_Period_Ellaspsed(void);
void Timer_start_config(uint32_t samplingPeriodMs);

#endif /* INC_COMPONENTS_TIMERS_H_ */
