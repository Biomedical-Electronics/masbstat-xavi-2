/**
  ******************************************************************************
  * @file		chronoamperometry.h
  * @brief		Archivo de encabezado del componente encargado de la gestión de
  *             la cronoamperometría.
  * @author		Albert Álvarez Carulla
  * @copyright	Copyright 2020 Albert Álvarez Carulla. All rights reserved.
  ******************************************************************************
  */

#ifndef INC_COMPONENTS_CHRONOAMPEROMETRY_H_
#define INC_COMPONENTS_CHRONOAMPEROMETRY_H_

#include "main.h"
#include "components/rele.h"
#include "components/timers.h"
#include "components/formulas.h"
#include "components/masb_comm_s.h"
#include "components/adc.h"
#include "components/mcp4725_driver.h"
#include "components/ad5280_driver.h"
#include "components/i2c_lib.h"




struct CA_Configuration_S {

	double eDC;
	uint32_t samplingPeriodMs;
	uint32_t measurementTime;

};


void get_CA_measure(struct CA_Configuration_S CaConfiguration);

#endif /* INC_COMPONENTS_CHRONOAMPEROMETRY_H_ */




