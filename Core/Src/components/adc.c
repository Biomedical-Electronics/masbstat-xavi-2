/*
 * adc.c
 *
 *  Created on: May 30, 2023
 *      Author: XAVIER
 */

#include "components/adc.h"
extern ADC_HandleTypeDef hadc1;


double get_Voltage(void){
	HAL_ADC_Start(&hadc1); // iniciamos la conversion para el divisor de tension
	HAL_ADC_PollForConversion(&hadc1, 200); // esperamos que finalice la conversion    																				// si en 200 ms no termina, salimos
	return calculateVrefVoltage(HAL_ADC_GetValue(&hadc1));

}

double get_Intensity(void){
	HAL_ADC_Start(&hadc1); // iniciamos la conversion para el divisor de tension
	HAL_ADC_PollForConversion(&hadc1, 200); // esperamos que finalice la conversion  																				// si en 200 ms no termina, salimos
	return calculateIcellCurrent(HAL_ADC_GetValue(&hadc1));

}
