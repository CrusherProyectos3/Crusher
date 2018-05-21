/* MODULOS */
#include "Cpu.h"
#include "componentes/control.h"

#define M_PI 3.1415926 //Constante PI

const float POSICION_REFERENCIA[2] = {0.0,12.0}; //POSICION VECTORIAL P = 0i + 10j

const float MAGNITUD_MAX = 10;
const float MAGNITUD_MIN = 5;
const float LIMITE = 70;

const float VELOCIDAD_MIN= 300;
const float VELOCIDAD_MAX1 = 550;
const float VELOCIDAD_MAX2 = 600;

float pError[2]={0.0, 0.0};
float dError[2]={0.0, 0.0};
float iError[2]={0.0, 0.0};

float posicionPelota[2]={0.0, 0.0};
float movimientoDeseado[2]={0.0, 0.0};
float ultimaPosicion[2]={0.0, 12.0};

float velocidades[2]={0.0, 0.0};

float magnitud;
float magnitudNorm;

/*FUNCIONES PARA SEGUIR PELOTA DE COLOR*/
void seguirPelota(double sharpDistancia,float CMUx){
	posicionPelota[0] = CMUx;
	posicionPelota[1] = (float)sharpDistancia;
	calculoMovimientoDeseado(posicionPelota, movimientoDeseado);   //CONTROL PID
	//motoresSimple(movimientoDeseado[0],movimientoDeseado[1]);
	moverVehiculo(movimientoDeseado);
}

void calculoMovimientoDeseado(float *posicionPelota, float *movimientoDeseado){
	movimientoDeseado[0] = posicionPelota[0];
	movimientoDeseado[1]= posicionPelota[1] - POSICION_REFERENCIA[1];
}
void moverVehiculo(float *movimientoDeseado){
	calcularVelocidades(movimientoDeseado[0],movimientoDeseado[1],velocidades);
	motores(velocidades);
}
void motores(float *velocidad){
	velocidad[0] = velocidad[0]*VELOCIDAD_MAX1;
	velocidad[1] = velocidad[1]*VELOCIDAD_MAX2;
	
	if (velocidad[0] > -VELOCIDAD_MIN && velocidad[0] < 0) velocidad[0] = -VELOCIDAD_MIN;
	else if(velocidad[1] > 0 && velocidad[1] < VELOCIDAD_MIN) velocidad[1] = VELOCIDAD_MIN;
	
	if (velocidad[1] > -VELOCIDAD_MIN && velocidad[1] < 0) velocidad[1] = -VELOCIDAD_MIN;
	else if(velocidad[1] > 0 && velocidad[1] < VELOCIDAD_MIN) velocidad[1] = VELOCIDAD_MIN;
	
	//Adelante
	if(velocidad[0] > 0){
		M1pwm_SetDutyUS(velocidad[0]);
		M2pwm_SetDutyUS(velocidad[1]);
		
		M1pwm_Enable();
		M2pwm_Enable();
		
		M1bit_PutVal(TRUE);
		M2bit_PutVal(TRUE);
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
	magnitud = (float)sqrt(pow(x,2)+pow(y,2));
	
	if(magnitud < MAGNITUD_MIN) magnitud = 0;
	else if(magnitud > LIMITE) magnitud = MAGNITUD_MIN;
	else if(magnitud > MAGNITUD_MAX) magnitud = MAGNITUD_MAX;
	
	magnitudNorm = magnitud/MAGNITUD_MAX;
	if(y>=0){
		if(x==0){
			velocidades[0]=magnitudNorm;
			velocidades[1]=magnitudNorm;
		}
		else if(x>0){
			velocidades[0]=magnitudNorm;
			velocidades[1]=(float)(atan(y/x)/(M_PI/2))*magnitudNorm;
		}
		else{
			velocidades[0]=(float)-(atan(y/x)/(M_PI/2))*magnitudNorm;
			velocidades[1]=magnitudNorm;
		}
	}else {
		if(x==0){
			velocidades[0]=-magnitudNorm;
			velocidades[1]=-magnitudNorm;
		}
		else if(x>0){
			velocidades[0]=-magnitudNorm;
			velocidades[1]=(float)(atan(y/x)/(M_PI/2))*magnitudNorm;
		}
		else{
			velocidades[0]=(float)-(atan(y/x)/(M_PI/2))*magnitudNorm;
			velocidades[1]=-magnitudNorm;
		}
	}
}

void motoresSimple(float x, float y){
	//Adelante
	if(y>MAGNITUD_MIN){
		if (x>MAGNITUD_MIN){
			M1pwm_SetDutyUS(500);
			M2pwm_SetDutyUS(250);
			
			M1bit_PutVal(TRUE);
			M2bit_PutVal(TRUE);
			
			M1pwm_Enable();
			M2pwm_Enable();
		}else if(x<-MAGNITUD_MIN){
			M1pwm_SetDutyUS(250);
			M2pwm_SetDutyUS(500);
						
			M1bit_PutVal(TRUE);
			M2bit_PutVal(TRUE);
			
			M1pwm_Enable();
			M2pwm_Enable();
		}else{
			M1pwm_SetDutyUS(350);
			M2pwm_SetDutyUS(350);
			
			M1bit_PutVal(TRUE);
			M2bit_PutVal(TRUE);
			
			M1pwm_Enable();
			M2pwm_Enable();
		}
	}else if(y<-MAGNITUD_MIN){
		if (x>MAGNITUD_MIN){
			M1pwm_SetDutyUS(250);
			M2pwm_SetDutyUS(500);
			
			M1bit_PutVal(FALSE);
			M2bit_PutVal(FALSE);
			
			M1pwm_Enable();
			M2pwm_Enable();
		}else if(x<-MAGNITUD_MIN){
			M1pwm_SetDutyUS(500);
			M2pwm_SetDutyUS(250);
						
			M1bit_PutVal(FALSE);
			M2bit_PutVal(FALSE);
			
			M1pwm_Enable();
			M2pwm_Enable();
		}else{
			M1pwm_SetDutyUS(350);
			M2pwm_SetDutyUS(350);
			
			M1bit_PutVal(FALSE);
			M2bit_PutVal(FALSE);
			
			M1pwm_Enable();
			M2pwm_Enable();
		}
	}else{
		M1pwm_Disable();
		M2pwm_Disable();
	}
}

