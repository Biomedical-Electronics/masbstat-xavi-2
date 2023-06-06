/*
 * timers.c
 *
 *  Created on: 23 may. 2023
 *      Author: xgome
 */


#include "components/timers.h"

extern TIM_HandleTypeDef htim2;
volatile _Bool Sampling_Period_Completed;

void Timer_start_config(uint32_t samplingPeriodMs) {

	__HAL_TIM_SET_AUTORELOAD(&htim2, samplingPeriodMs * 10);
	__HAL_TIM_SET_COUNTER(&htim2, 0);
	Clear_Sample_Period_Ellaspsed_Flag();
	HAL_TIM_Base_Start_IT(&htim2);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	Sampling_Period_Completed = TRUE;
}

void Clear_Sample_Period_Ellaspsed_Flag(void) {
	Sampling_Period_Completed = FALSE;
}

void Timer_Stop(void) {
	HAL_TIM_Base_Stop_IT(&htim2);
}

