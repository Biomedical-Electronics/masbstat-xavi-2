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

 double V_ref = 0;
 double I_cell = 0;
 extern ADC_HandleTypeDef hadc1;

double get_V_CA(void);
double get_I_CA(void);


#endif /* INC_COMPONENTS_ADC_H_ */
