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
	MCP4725_SetOutputVoltage(hdac, calculateDacOutputVoltage(eDC)); // NUEVA TENSION

	close_rele();
	num_measurment_times = 0; //num
	Timer_start_config(samplingPeriod);

	while(num_measurment_times*samplingPeriod < measurementTime){
		if(Sampling_Period_Completed == TRUE){
			V_ref = get_V_CA();
			I_cell = get_I_CA();
			data.point = num_measurment_times;
			data.timeMs = num_measurment_times*samplingPeriod;
			data.voltage = V_ref;
			data.current = I_cell;
			MASB_COMM_S_sendData(data);

			Clear_Sample_Period_Ellapsed_Flag();
			++num_measurment_times;

		}
	}
	//Parar y resetear el timer
	Timer_Stop();
	HAL_ADC_Stop(&hadc1);
	open_rele();
}

