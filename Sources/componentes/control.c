/* MODULOS */
#include "Cpu.h"
#include "componentes/control.h"

#define REFERENCIA_MAX 15
#define REFERENCIA_MIN 12

void distanciaConstante(double sharpDistancia){
	if(sharpDistancia > REFERENCIA_MAX){
		M1pwm_Enable();
		M2pwm_Enable();
		M1bit_PutVal(TRUE);
		M2bit_PutVal(TRUE);
	}else if(sharpDistancia < REFERENCIA_MIN){
		M1pwm_Enable();
		M2pwm_Enable();
		M1bit_PutVal(FALSE);
		M2bit_PutVal(FALSE);
	}else{
		M1pwm_Disable();
		M2pwm_Disable();
	}
}
