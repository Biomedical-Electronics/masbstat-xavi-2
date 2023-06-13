/*
 * chronoamperometry.c
 *
 *  Created on: 30 may. 2023
 *      Author: xgome
 */

#include "components/chronoamperometry.h"
#include "components/mcp4725_driver.h"

MCP4725_Handle_T hdac;
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim;

extern volatile _Bool Sampling_Period_Completed;
struct CA_Configuration_S CaConfiguration;
struct Data_S caData;


void get_CA_measure(struct CA_Configuration_S CaConfiguration){

	uint32_t measurementTime = CaConfiguration.measurementTime*1000;

	//Fijar tension Vcell a eDC
	MCP4725_SetOutputVoltage(hdac, calculateDacOutputVoltage(CaConfiguration.eDC)); // NUEVA TENSION
	__NOP();

	close_rele();
	uint32_t num_measurment_times = 1; //num
	Timer_start_config(CaConfiguration.samplingPeriodMs);

	while(num_measurment_times*CaConfiguration.samplingPeriodMs < measurementTime){
		if(Sampling_Period_Completed == TRUE){
			caData.point = num_measurment_times;
			caData.timeMs = num_measurment_times*CaConfiguration.samplingPeriodMs;
			caData.voltage = get_Voltage();
			caData.current = get_Intensity();
			MASB_COMM_S_sendData(caData);

			Clear_Sample_Period_Ellaspsed_Flag();
			++num_measurment_times;

		}
	}
	//Parar y resetear el timer
	Timer_Stop();
	HAL_ADC_Stop(&hadc1);
	open_rele();
}

