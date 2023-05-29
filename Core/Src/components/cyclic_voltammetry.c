/*
 * cyclic_voltammetry.c
 *
 *  Created on: 29 may. 2023
 *      Author: XAVIER
 */

#include "components/cyclic_voltammetry.h"




void get_CV_measure(struct CV_Configuration_S){

	eBegin = CV_Configuration_S.eBegin;
	V_cell = eBegin ;
	eVertex1 = CV_Configuration_S.eVertex1;
	eVertex2 = CV_Configuration_S.eVertex2;
	V_objective = eVertex1;
	cycles_objective = CV_Configuration_S.cycles;
	actual_cycle = 1;
	eStep = CV_Configuration_S.eStep;
	//falta definir sampling period

	close_rele();

	while (1){
		if(Sampling_Period_Completed){
			//medir
			//enviar datos al host
			Sampling_Period_Completed == FALSE;
		}

		else if(V_cell == V_objective){
			if(V_objective == eVertex1){
				V_objective = eVertex2;
			}
			else if(V_objective = eVertex2){
				V_objective = eBegin;
			}
			else if(V_objective == eBegin){
				if(actual_cycle == cycles_objective){
					break;

					}
				else if(actual_cycle < cycles_objective){
					V_objective = eVertex1;
					actual_cycle++; //si estoy en el penultimo y se me suma
					//el siguiente elseif lo cumplira o lo saltara?
				}
			}
		}
		else if(V_cell != V_objective){
			if(V_cell + eStep >= V_objective){
				V_cell = V_objective;
			}
			else{
				V_cell = V_cell + eStep;
			}

		}


	}
}




