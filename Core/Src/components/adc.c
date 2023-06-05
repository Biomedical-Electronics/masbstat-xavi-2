/*
 * adc.c
 *
 *  Created on: May 30, 2023
 *      Author: XAVIER
 */

#include "components/adc.h"



double get_V_CA(void){
	HAL_ADC_Start(&hadc1); // iniciamos la conversion para el divisor de tension
	HAL_ADC_PollForConversion(&hadc1, 200); // esperamos que finalice la conversion    																				// si en 200 ms no termina, salimos
	V_ref = calculateVrefVoltage(HAL_ADC_GetValue(&hadc1));
	return V_ref;

}

double get_I_CA(void){
	HAL_ADC_Start(&hadc1); // iniciamos la conversion para el divisor de tension
	HAL_ADC_PollForConversion(&hadc1, 200); // esperamos que finalice la conversion  																				// si en 200 ms no termina, salimos
	I_cell = calculateIcellCurrent(HAL_ADC_GetValue(&hadc1));
	return I_cell;

}
