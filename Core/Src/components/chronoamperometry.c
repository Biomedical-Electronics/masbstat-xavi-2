/*
 * chronoamperometry.c
 *
 *  Created on: 30 may. 2023
 *      Author: xgome
 */

#include "components/chronoamperomety.h"


void get_CA_measure(struct CA_Configuration_S){

	eDC = CA_Configuration_S.eDC;
	samplingPeriod = CA_Configuration.samplingPeriodMs;
	measurementTime = CA_Configuration.measurementTime;


	//Fijar tension Vcell a eDC

	close_rele();

	//Llamar funcion timer para que inicie el timer_2 y nos diga el tiempo

	//TimeMs = funcion_timer();

	while(TimeMs < measurementTime){
		if(TimeMs % samplingPeriod == 0){

			//Medir
			//Enviar datos

		}
	}

	//Parar y resetear el timer

	open_rele();
}

