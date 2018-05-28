/* MODULOS */
#include "Cpu.h"
#include "componentes/control.h"

#define M_PI 3.1415926 //Constante PI

/* Variables para Seguir Pelota */


const float POSICION_REFERENCIA[2] = {0.0,10.0}; //POSICION VECTORIAL P = 0i + 10j

const float MAGNITUD_MAX = 6;
const float MAGNITUD_MIN = 4;
const float LIMITE = 70;

const float VELOCIDAD_MIN= 250;
const float VELOCIDAD_MAX1 = 550;
const float VELOCIDAD_MAX2 = 600;

const float RANGO_ESTABLE = 2;
const float RANGO_X = 15;

float pError[2]={0.0, 0.0};
float dError[2]={0.0, 0.0};
float iError[2]={0.0, 0.0};

float posicionPelota[2]={0.0, 0.0};
float movimientoDeseado[2]={0.0, 0.0};
float ultimaPosicion[2]={0.0, 12.0};

float velocidades[2]={0.0, 0.0};

float magnitud;
float magnitudNorm;

extern float posicionX;
float posicionY;

/*FUNCIONES PARA SEGUIR PELOTA DE COLOR*/
void seguirPelota(){
	M1pwm_SetDutyUS(0.5*VELOCIDAD_MAX1);
	M2pwm_SetDutyUS(0.5*VELOCIDAD_MAX2);
	do{
		seguirColor();
		girarVehiculo(posicionX);
		Cpu_Delay100US(100);
	}
	while(posicionX < -RANGO_X || posicionX > RANGO_X);
	
	/*
	do{
		posicionY = MedirSharp();
		posicionY = posicionY - POSICION_REFERENCIA[1];
		desplazarVehiculo(posicionY);
	}
	while(posicionY < -RANGO_ESTABLE || posicionY > RANGO_ESTABLE);*/
}

void girarVehiculo(float posicionX){
	/**********************
	 * M1: MOTOR IZQUIERDO
	 * M2: MOTOR DERECHO
	 **********************/
	
	//Girar hacia la derecha
	if(posicionX > RANGO_X){
		M1bit_PutVal(TRUE);
		M2bit_PutVal(FALSE);
		M1pwm_Enable();
		M2pwm_Enable();
	}
	//Girar hacia la izquierda
	else if(posicionX < -RANGO_X){
		M1bit_PutVal(FALSE);
		M2bit_PutVal(TRUE);
		M1pwm_Enable();
		M2pwm_Enable();
	}
	//Centrado no girar
	else{
		M1bit_PutVal(FALSE);
		M2bit_PutVal(FALSE);
		M1pwm_Disable();
		M2pwm_Disable();
	}
	
}

void desplazarVehiculo(float posicionY){
	/**********************
	 * M1: MOTOR IZQUIERDO
	 * M2: MOTOR DERECHO
	 **********************/
	
	//Avanzar
	if(posicionY > RANGO_ESTABLE){
		M1bit_PutVal(TRUE);
		M2bit_PutVal(TRUE);
		M1pwm_Enable();
		M2pwm_Enable();
	}
	//Retroceso
	else if(posicionY < -RANGO_ESTABLE){
		M1bit_PutVal(FALSE);
		M2bit_PutVal(FALSE);
		M1pwm_Enable();
		M2pwm_Enable();
	}
	//Centrado
	else{
		M1bit_PutVal(FALSE);
		M2bit_PutVal(FALSE);
		M1pwm_Disable();
		M2pwm_Disable();
	}
}


void calculoMovimientoDeseado(float *posicionPelota, float *movimientoDeseado){
	float test;
	
	movimientoDeseado[0] = posicionPelota[0]; //posicion x
	movimientoDeseado[1] = posicionPelota[1]-POSICION_REFERENCIA[1];//posicion y
	test = movimientoDeseado[1];

}
void moverVehiculo(float *movimientoDeseado){
	calcularVelocidades(movimientoDeseado[0],movimientoDeseado[1],velocidades);
	motores(velocidades);
}
void calcularVelocidades(float x, float y, float *velocidades){
	magnitud = (float)sqrt(pow(x,2)+pow(y,2));
	
	if(magnitud < MAGNITUD_MIN) magnitud = 0; // condicion para detener el vehiculo
	else if(magnitud > LIMITE) magnitud = MAGNITUD_MIN; //Condicion no sobre-acelerar
	else if(magnitud > MAGNITUD_MAX) magnitud = MAGNITUD_MAX; // Limitar velocidad
	
	magnitudNorm = magnitud/MAGNITUD_MAX; //normaliza la magnitud
	
	if(y>=0){ //distancia positiva
		if(x==0){ //objetivo centro
			velocidades[0]=magnitudNorm; //Izquierda
			velocidades[1]=magnitudNorm; //Derecha
		}
		else if(x>0){ // objetivo a la derecha
			velocidades[0]=magnitudNorm;
			velocidades[1]=(float)(atan(y/x)/(M_PI))*magnitudNorm;
		}
		else{ //objetivo a la izquierda
			velocidades[0]=(float)(atan(y/(-x))/(M_PI))*magnitudNorm;
			velocidades[1]=magnitudNorm;
		}
	}else {//distancia negativa
		if(x==0){
			velocidades[0]=-magnitudNorm;
			velocidades[1]=-magnitudNorm;
		}
		else if(x>0){
			velocidades[0]=(float)(atan(y/x)/(M_PI))*magnitudNorm;
			velocidades[1]=-magnitudNorm;
		}
		else{
			velocidades[0]=-magnitudNorm;
			velocidades[1]=(float)(atan(y/(-x))/(M_PI))*magnitudNorm;
		}
	}
}

void motores(float *velocidad){
	velocidad[0] = velocidad[0]*VELOCIDAD_MAX1; //Motor Izquierdo
	velocidad[1] = velocidad[1]*VELOCIDAD_MAX2; //Motor Derecho
	/*
	if (velocidad[0] > -VELOCIDAD_MIN && velocidad[0] < 0) velocidad[0] = -VELOCIDAD_MIN;
	else if(velocidad[1] > 0 && velocidad[1] < VELOCIDAD_MIN) velocidad[1] = VELOCIDAD_MIN;
	
	if (velocidad[1] > -VELOCIDAD_MIN && velocidad[1] < 0) velocidad[1] = -VELOCIDAD_MIN;
	else if(velocidad[1] > 0 && velocidad[1] < VELOCIDAD_MIN) velocidad[1] = VELOCIDAD_MIN;
	*/
	//Adelante
	if(velocidad[0] > 0){
		M1pwm_SetDutyUS(velocidad[0]);
		M2pwm_SetDutyUS(velocidad[1]);
		
		M1pwm_Enable();
		M2pwm_Enable();
		
		M1bit_PutVal(FALSE);
		M2bit_PutVal(FALSE);
	}
	//Retroceso
	else if(velocidad[0] < 0){
		M1pwm_SetDutyUS(-velocidad[0]);
		M2pwm_SetDutyUS(-velocidad[1]);
		
		M1bit_PutVal(TRUE);
		M2bit_PutVal(TRUE);
		
		M1pwm_Enable();
		M2pwm_Enable();
	}
	//Quieto
	else{
		M1pwm_Disable();
		M2pwm_Disable();	
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

