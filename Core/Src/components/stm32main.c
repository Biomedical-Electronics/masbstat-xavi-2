/*
 * stm32main.c
 *
 *  Created on: 23 may. 2023
 *      Author: XAVIER
 */


#include "components/stm32main.h"
#include "components/masb_comm_s.h"

struct CV_Configuration_S cvConfiguration;
struct CA_Configuration_S caConfiguration;
struct Data_S data;
static MCP4725_Handle_T hdac = NULL;
extern I2C_HandleTypeDef hi2c1;

volatile enum State_type{IDLE = 0, CV, CA}State;

void setup(struct Handles_S *handles) {
	PMU_Init();

	I2C_init(handles -> hi2c);

	AD5280_Handle_T hpot = NULL;

	hpot = AD5280_Init();

	// Configuramos su direccion I2C de esclavo, su resistencia total (hay
	// diferentes modelos; este tiene 50kohms) e indicamos que funcion queremos que
	// se encargue de la escritura a traves del I2C. Utilizaremos la funcion
	// I2C_Write de la libreria i2c_lib.
	AD5280_ConfigSlaveAddress(hpot, 0x2C);
	AD5280_ConfigNominalResistorValue(hpot, 50e3f);
	AD5280_ConfigWriteFunction(hpot, I2C_write);

	// Fijamos la resistencia de 50 kohms.
	AD5280_SetWBResistance(hpot, 50e3f);


	hdac = MCP4725_Init();

	MCP4725_ConfigSlaveAddress(hdac, 0x66); // DIRECCION DEL ESCLAVO
	MCP4725_ConfigVoltageReference(hdac, 4.0f); // TENSION DE REFERENCIA
	MCP4725_ConfigWriteFunction(hdac, I2C_write); // FUNCION DE ESCRITURA (libreria I2C_lib)



	MASB_COMM_S_setUart(handles->huart);
	MASB_COMM_S_waitForMessage();

	State = IDLE;


}


void loop(void) {
    if (MASB_COMM_S_dataReceived()) { // Si se ha recibido un mensaje...

 		switch(MASB_COMM_S_command()) { // Miramos que comando hemos recibido

 			case START_CV_MEAS: // Si hemos recibido START_CV_MEAS

				cvConfiguration = MASB_COMM_S_getCvConfiguration();

 				__NOP(); // Esta instruccion no hace nada y solo sirve para poder anadir un breakpoint

 				State = CV;

 				break;
 			case START_CA_MEAS:

 				caConfiguration = MASB_COMM_S_getCaConfiguration();

 				__NOP();

 				State = CA;

 				break;

			case STOP_MEAS: // Si hemos recibido STOP_MEAS

 				__NOP(); // Esta instruccion no hace nada y solo sirve para poder anadir un breakpoint

 				State = IDLE;

 				// Aqui iria el codigo para tener la medicion si implementais el comando stop.

 				break;

 			default:

 				break;

 		}

       // Una vez procesado los comando, esperamos el siguiente
 		MASB_COMM_S_waitForMessage();

 	}else{
 		switch(State){
 		 		case CV:

 					get_CV_measure(cvConfiguration);

 					__NOP();

 					State = IDLE;

 					break;

 		 		case CA:

 		 			get_CA_measure(caConfiguration);

 		 			__NOP();

 		 			State = IDLE;

 		 			break;

 		 		default:
 		 			break;


 		 	}
 	}



 	// Aqui es donde deberia de ir el codigo de control de las mediciones si se quiere implementar
   // el comando de STOP.
}
