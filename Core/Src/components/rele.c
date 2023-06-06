/*
 * rele.c
 *
 *  Created on: 29 may. 2023
 *      Author: XAVIER
 */

#include "components/rele.h"

void close_rele(void){
	HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_SET); // cerramos el rele
}

void open_rele(void){
	HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_RESET); // abrimos el rele
}
