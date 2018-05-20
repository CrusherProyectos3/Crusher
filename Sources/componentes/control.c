/* MODULOS */
#include "Cpu.h"
#include "componentes/control.h"

#define M_PI 3.1415926 //Constante PI

const float REFERENCIA_MAX = 2.0;
const float REFERENCIA_MIN = -2.0;
const float POSICION_REFERENCIA[2] = {0.0,12.0}; //POSICION VECTORIAL P = 0i + 10j

const float VELOCIDAD_MIN= 210;
const float VELOCIDAD_MAX1 = 500;
const float VELOCIDAD_MAX2 = 550;

float pError[2]={0.0, 0.0};
float dError[2]={0.0, 0.0};
float iError[2]={0.0, 0.0};

float posicionPelota[2]={0.0, 0.0};
float movimientoDeseado[2]={0.0, 0.0};
float ultimaPosicion[2]={0.0, 12.0};

float velocidades[2]={0.0, 0.0};


/*FUNCIONES PARA SEGUIR PELOTA DE COLOR*/
void seguirPelota(double sharpDistancia/*,datos de CMU*/){
	*posicionPelota = calculoPosicionPelota(sharpDistancia/*,datos de CMU*/);
	calculoMovimientoDeseado(posicionPelota, movimientoDeseado);   //CONTROL PID
	sharpDistancia =  movimientoDeseado[1];
	moverVehiculo(movimientoDeseado);
}

float calculoPosicionPelota(double sharpDistancia){
	posicionPelota[0] = 0.0;
	posicionPelota[1] = (float)sharpDistancia;
	return *posicionPelota;
}
void calculoMovimientoDeseado(float *posicionPelota, float *movimientoDeseado){
	int i;

	for (i=0;i<2;i++) {
		movimientoDeseado[i]= posicionPelota[i] - POSICION_REFERENCIA[i];
	}
	
	if(movimientoDeseado[1]>REFERENCIA_MIN && movimientoDeseado[1]<REFERENCIA_MAX){
		movimientoDeseado[0] = 0;
		movimientoDeseado[1] = 0;
	}


}
void moverVehiculo(float *movimientoDeseado){
	calcularVelocidades(movimientoDeseado[0],movimientoDeseado[1],velocidades);
	motores(velocidades);
}
void motores(float *velocidad){
	velocidad[0] = (short)velocidad[0]*VELOCIDAD_MAX1;
	velocidad[1] = (short)velocidad[1]*VELOCIDAD_MAX2;
	
	if (velocidad[0] > -VELOCIDAD_MIN && velocidad[0] < 0) velocidad[0] = -VELOCIDAD_MIN;
	else if(velocidad[1] > 0 && velocidad[1] < VELOCIDAD_MIN) velocidad[1] = VELOCIDAD_MIN;
	
	if (velocidad[1] > -VELOCIDAD_MIN && velocidad[1] < 0) velocidad[1] = -VELOCIDAD_MIN;
	else if(velocidad[1] > 0 && velocidad[1] < VELOCIDAD_MIN) velocidad[1] = VELOCIDAD_MIN;
	
	//Adelante
	if(velocidad[0] > 0){
		M1pwm_SetDutyUS(velocidad[0]);
		M2pwm_SetDutyUS(velocidad[1]);
		M1bit_PutVal(TRUE);
		M2bit_PutVal(TRUE);
		M1pwm_Enable();
		M2pwm_Enable();
	}
	//Retroceso
	else if(velocidad[0] < 0){
		M1pwm_SetDutyUS(-velocidad[0]);
		M2pwm_SetDutyUS(-velocidad[1]);
		M1bit_PutVal(FALSE);
		M2bit_PutVal(FALSE);
		M1pwm_Enable();
		M2pwm_Enable();
	}
	//Quieto
	else{
		M1pwm_Disable();
		M2pwm_Disable();	
	}
}
void calcularVelocidades(float x, float y, float *velocidades){
	if(y>0){
		if(x==0){
			velocidades[0]=1;
			velocidades[1]=1;
		}
		else if(x>0){
			velocidades[0]=1;
			velocidades[1]=(float)(atan(y/x)/M_PI/2);
		}
		else{
			velocidades[0]=(float)-(atan(y/x)/M_PI/2);
			velocidades[1]=1;
		}
	}else if(y<0){
		if(x==0){
			velocidades[0]=-1;
			velocidades[1]=-1;
		}
		else if(x>0){
			velocidades[0]=-1;
			velocidades[1]=(float)(atan(y/x)/M_PI/2);
		}
		else{
			velocidades[0]=(float)-(atan(y/x)/M_PI/2);
			velocidades[1]=-1;
		}
	}else{
		velocidades[0]=0;
		velocidades[1]=0;
	}
}
