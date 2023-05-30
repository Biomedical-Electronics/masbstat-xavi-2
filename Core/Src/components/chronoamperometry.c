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

	trigger_measurement_cycles = 0;


	while(trigger_measurement_cycles*Sampling_Period_Completed < measurementTime){
		if(Sampling_Period_Completed == TRUE){

			//Medir
			//Enviar datos
			Sample_Period_Ellaspsed();
			++trigger_measurement_cycles;

		}
	}

	//Parar y resetear el timer

	open_rele();
}

