/*
 * adc.h
 *
 *  Created on: 30 may. 2023
 *      Author: xgome
 */

#ifndef INC_COMPONENTS_ADC_H_
#define INC_COMPONENTS_ADC_H_

#include "main.h"
#include "formulas.h"

 extern ADC_HandleTypeDef hadc1;

double get_Voltage(void);
double get_Intensity(void);


#endif /* INC_COMPONENTS_ADC_H_ */
