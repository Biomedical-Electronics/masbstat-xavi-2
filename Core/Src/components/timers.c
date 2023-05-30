/*
 * timers.c
 *
 *  Created on: 23 may. 2023
 *      Author: xgome
 */

#include "components/timers.h"

void Timer_start_config(void){

	MX_TIM2_Init();
	HAL_TIM_Base_Start_IT(&htim2);

	HAL_TIM_SET_AUTORELOAD(TIM_HandleTypeDef*htim2, samplingPeriodMs*10);

	void HAL_TIMPeriodElapsedCallback(TIM_HandleTypeDef*htim){
		Sampling_Period_Completed = TRUE;

		}
}


void Sample_Period_Ellaspsed(void){
	Sampling_Period_Completed = FALSE;
}
