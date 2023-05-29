/*
 * PMU.h
 *
 *  Created on: May 29, 2023
 *      Author: XAVIER
 */

#ifndef INC_COMPONENTS_PMU_H_
#define INC_COMPONENTS_PMU_H_

#define EN_Pin GPIO_PIN_5
#define EN_GPIO_Port GPIOA

#include "stm32f4xx_hal.h"

void PMU_Init(void); //prototype function


#endif /* INC_COMPONENTS_PMU_H_ */
