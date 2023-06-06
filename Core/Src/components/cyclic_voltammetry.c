/*
 * cyclic_voltammetry.c
 *
 *  Created on: 29 may. 2023
 *      Author: XAVIER
 */

#include "components/cyclic_voltammetry.h"

extern Sampling_Period_Completed;


void get_CV_measure(struct CV_Configuration_S){

	double eBegin = CV_Configuration_S.eBegin;
	double V_cell = eBegin ;
	double eVertex1 = CV_Configuration_S.eVertex1;
	double eVertex2 = CV_Configuration_S.eVertex2;
	double V_objective = eVertex1;

	uint8_t cycles_objective = CV_Configuration_S.cycles;
	uint8_t actual_cycle = 1;
	uint8_t num_measurment_times = 1;

	double eStep = CV_Configuration_S.eStep;
	double scanRate = CV_Configuration_S.scanRate;
	//calcular_sampleperiod
	double samplingPeriod = (eStep/scanRate)*1000;

	//Fijar tension Vcell a eDC
	MCP4725_SetOutputVoltage(hdac, calculateDacOutputVoltage(V_cell)); // NUEVA TENSION


	close_rele();

	Timer_start_config(samplingPeriod);

	while (1){
		if(Sampling_Period_Completed){
			//medir
			V_cell = get_Voltage();
			I_cell = get_Intensity();

			//enviar datos al host
			data.point = num_measurment_times;
			data.timeMs = num_measurment_times*samplingPeriod;
			data.voltage = V_cell;
			data.current = I_cell;
			MASB_COMM_S_sendData(data);


			Clear_Sample_Period_Ellapsed_Flag();
			++num_measurment_times;

			if(V_cell == V_objective){
				if(V_objective == eVertex1){
					V_objective = eVertex2;
				}
				else if(V_objective = eVertex2){
					V_objective = eBegin;
				}
				else if(V_objective == eBegin){
					if(actual_cycle == cycles_objective){
						open_rele();
						break;

						}
					else if(actual_cycle < cycles_objective){
						V_objective = eVertex1;
						actual_cycle++; //si estoy en el penultimo y se me suma
						//el siguiente elseif lo cumplira o lo saltara?
					}
				}
			}
			else{
				if(V_cell + eStep > V_objective){
					V_cell = V_objective;
				}
				else{
					V_cell = V_cell + eStep;
				}

			}
		}


	}
}




