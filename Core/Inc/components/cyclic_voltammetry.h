/**
  ******************************************************************************
  * @file		cyclic_voltammetry.h
  * @brief		Archivo de encabezado del componente encargado de la gestión de
  *             la voltammetría cíclica.
  * @author		Albert Álvarez Carulla
  * @copyright	Copyright 2020 Albert Álvarez Carulla. All rights reserved.
  ******************************************************************************
  */

#ifndef INC_COMPONENTS_CYCLIC_VOLTAMMETRY_H_
#define INC_COMPONENTS_CYCLIC_VOLTAMMETRY_H_

#include "main.h"
#include "components/rele.h"
#include "components/adc.h"
#include "components/formulas.h"
#include "components/masb_comm_s.h"
#include "components/timers.h"
#include "components/mcp4725_driver.h"



struct CV_Configuration_S {

	double eBegin;
	double eVertex1;
	double eVertex2;
	uint8_t cycles;
	double scanRate;
	double eStep;

};


void get_CV_measure(struct CV_Configuration_S);

#endif /* INC_COMPONENTS_CYCLIC_VOLTAMMETRY_H_ */
