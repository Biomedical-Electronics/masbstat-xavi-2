/*
 * stm32main.h
 *
 *  Created on: 23 may. 2023
 *      Author: XAVIER
 */

#ifndef INC_COMPONENTS_STM32MAIN_H_
#define INC_COMPONENTS_STM32MAIN_H_

#include "main.h"
#include "components/PMU.h"
#include "components/mcp4725_driver.h"
#include "components/chronoamperometry.c"
#include "components/cyclic_voltametry.c"

struct Handles_S {
    UART_HandleTypeDef *huart;
    // Aqui iriamos anadiendo los diferentes XXX_HandleTypeDef que necesitaramos anadir.
};



//Prototypes
void setup(struct Handles_S *handles);
void loop(void);

#endif /* INC_COMPONENTS_STM32MAIN_H_ */
