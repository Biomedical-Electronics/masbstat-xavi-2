/*
 * cyclic_voltammetry.c
 *
 *  Created on: 29 may. 2023
 *      Author: XAVIER
 */

#include "components/cyclic_voltammetry.h"

extern volatile _Bool Sampling_Period_Completed;
struct CV_Configuration_S prvCvConfiguration;
struct Data_S cvData;
static MCP4725_Handle_T hdac = NULL;


void get_CV_measure(struct CV_Configuration_S prvCvConfiguration){

	double eBegin = prvCvConfiguration.eBegin;
	double V_cell = eBegin ;
	double eVertex1 = prvCvConfiguration.eVertex1;
	double eVertex2 = prvCvConfiguration.eVertex2;
	double V_objective = eVertex1;

	uint8_t cycles_objective = prvCvConfiguration.cycles;
	uint8_t actual_cycle = 1;
	uint8_t num_measurment_times = 1;

	double eStep = prvCvConfiguration.eStep;
	double scanRate = prvCvConfiguration.scanRate;
	//calcular_sampleperiod
	double samplingPeriod = (eStep/scanRate)*1000;

	//Fijar tension Vcell a eDC
	MCP4725_SetOutputVoltage(hdac, calculateDacOutputVoltage(V_cell)); // NUEVA TENSION


	close_rele();

	Timer_start_config(samplingPeriod);

	while (1){
		if(Sampling_Period_Completed){
			//medir
			double V_cell = get_Voltage();
			double I_cell = get_Intensity();

			//enviar datos al host
			cvData.point = num_measurment_times;
			cvData.timeMs = num_measurment_times*samplingPeriod;
			cvData.voltage = V_cell;
			cvData.current = I_cell;
			MASB_COMM_S_sendData(cvData);


			Clear_Sample_Period_Ellaspsed_Flag();
			++num_measurment_times;

			if(V_cell == V_objective){
				if(V_objective == eVertex1){
					V_objective = eVertex2;
				}
				else if(V_objective == eVertex2){
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




