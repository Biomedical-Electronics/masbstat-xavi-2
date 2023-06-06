/*
 * PMU.c
 *
 *  Created on: May 29, 2023
 *      Author: XAVIER
 */

#include "components/PMU.h"


void PMU_Init(void){
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_SET); //Encendemos el PMU
	HAL_Delay(500);
}
