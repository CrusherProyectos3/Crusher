
#include "componentes/motores.h"

extern const int ERROR;
const int RANGO_X = 11;    //rango de estabilidad en x
const float RANGO_Y = 2.0; //Rango de estabilidad en y

void girarVehiculo(int posicionX){
	/**********************
	 * M1: MOTOR IZQUIERDO
	 * M2: MOTOR DERECHO
	 **********************/
	// Si la posicion en x es distinta al valor ERROR entonces has la rutina
	if(posicionX != ERROR){
		//Girar hacia la derecha
		if(posicionX > RANGO_X){
			M1bit_PutVal(TRUE);
			M2bit_PutVal(FALSE);
			M1pwm_Enable();
			M2pwm_Enable();
			//Pausa para girar
			Cpu_Delay100US(1500*posicionX/40); //mientras mas lejos del centro mas giras
		}
		//Girar hacia la izquierda
		else if(posicionX < -RANGO_X){
			M1bit_PutVal(FALSE);
			M2bit_PutVal(TRUE);
			M1pwm_Enable();
			M2pwm_Enable();
			//Pausa para girar
			Cpu_Delay100US(-1500*posicionX/40); //mientras mas lejos del centro mas giras
		}
	}
	//Detener Vehiculo
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
		//Pausa para avanzar
		Cpu_Delay100US(5000);
	}
	//Retroceso
	else if(posicionY < -RANGO_Y){
		M1bit_PutVal(FALSE);
		M2bit_PutVal(FALSE);
		M1pwm_Enable();
		M2pwm_Enable();
		//Pausa para retroceder
		Cpu_Delay100US(3000);
	}
	//Deten el vehiculo
	M1bit_PutVal(FALSE);
	M2bit_PutVal(FALSE);
	M1pwm_Disable();
	M2pwm_Disable();
}

