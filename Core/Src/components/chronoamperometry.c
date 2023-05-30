/*
 * chronoamperometry.c
 *
 *  Created on: 30 may. 2023
 *      Author: xgome
 */

#include "components/chronoamperometry.h"


void get_CA_measure(struct CA_Configuration_S){

	eDC = CA_Configuration_S.eDC;
	samplingPeriod = CA_Configuration.samplingPeriodMs;
	measurementTime = CA_Configuration.measurementTime*1000;

	//Fijar tension Vcell a eDC

	close_rele();

	num_measurment_times = 0; //num
	Timer_start_config(samplingPeriod);

	while(num_measurment_times*samplingPeriod < measurementTime){
		if(Sampling_Period_Completed == TRUE){
			//Medir
			//Enviar datos
			Clear_Sample_Period_Ellapsed_Flag();
			++trigger_measurement_cycles;

		}
	}

	//Parar y resetear el timer
	Timer_Stop();

	open_rele();
}

