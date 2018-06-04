
#include "componentes/motores.h"

extern const int ERROR;
const int RANGO_X = 11;
const float RANGO_Y = 2.0;

void girarVehiculo(int posicionX){
	/**********************
	 * M1: MOTOR IZQUIERDO
	 * M2: MOTOR DERECHO
	 **********************/
	if(posicionX != ERROR){
		//Girar hacia la derecha
		if(posicionX > RANGO_X){
			M1bit_PutVal(TRUE);
			M2bit_PutVal(FALSE);
			M1pwm_Enable();
			M2pwm_Enable();
			Cpu_Delay100US(1500*posicionX/40);
		}
		//Girar hacia la izquierda
		else if(posicionX < -RANGO_X){
			M1bit_PutVal(FALSE);
			M2bit_PutVal(TRUE);
			M1pwm_Enable();
			M2pwm_Enable();
			Cpu_Delay100US(-1500*posicionX/40);
		}
	}
	//Centrado no girar
	M1bit_PutVal(FALSE);
	M2bit_PutVal(FALSE);
	M1pwm_Disable();
	M2pwm_Disable();
}

void desplazarVehiculo(float posicionY){
	/**********************
	 * M1: MOTOR IZQUIERDO
	 * M2: MOTOR DERECHO
	 **********************/
	
	//Avanzar
	if(posicionY > RANGO_Y){
		M1bit_PutVal(TRUE);
		M2bit_PutVal(TRUE);
		M1pwm_Enable();
		M2pwm_Enable();
		Cpu_Delay100US(5000);
	}
	//Retroceso
	else if(posicionY < -RANGO_Y){
		M1bit_PutVal(FALSE);
		M2bit_PutVal(FALSE);
		M1pwm_Enable();
		M2pwm_Enable();
		Cpu_Delay100US(3000);
	}
	//Centrado
	M1bit_PutVal(FALSE);
	M2bit_PutVal(FALSE);
	M1pwm_Disable();
	M2pwm_Disable();
}

