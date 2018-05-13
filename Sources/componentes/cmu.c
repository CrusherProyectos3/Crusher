/* MODULOS */
#include "Cpu.h"
#include "componentes/cmu.h"

unsigned int num, i;
unsigned char recibir;
unsigned char recibido[]; 
unsigned char bloque1[1] = {13};					//\r		ACK o NCK
unsigned char bloque2[5] = {76, 49, 32, 49, 13};	//L1 1\r	Prende Tracking LED
unsigned char bloque3[5] = {76, 49, 32, 48, 13};	//L1 0\r	Apaga Tracking LED
unsigned char bloque4[5] = {68, 77, 32, 49, 13};	//DM 1\r	Delay 0 (One bit at the current baud rate) - de 0 a 255
unsigned char bloque5[3] = {71, 77, 13};			//GM\r		Get Mean (Color medio y desviacion)
unsigned char bloque6[3] = {77, 77, 13};			//MM\r		Middle Mass (Centroide)
unsigned char bloque7[3] = {80, 77, 13};			//PM\r		Poll Mode (Paquete Unico)
unsigned char bloque8[3] = {82, 83, 13};			//RS\r		Reset
//unsigned char bloque9[7] = {87, 83, x, y, x2, y2, 13} 	//WS x y x2 y2\r	Window Size (Max 1,1,80,143)		Esquina superior izquierda y esquina inferior derecha
//unsigned char bloque10[9] = {84, 67, Rmin, Rmax, Gmin, Gmax, Bmin, Bmax, 13}	//TC Rmin Rmax Gmin Gmax Bmin Bmax\r	Track un Color especifico
unsigned char bloque11[3] = {84, 87, 13};			//TW\r	Track el color de la region central de la ventana escogida
unsigned char bloque12[4] = {83, 77, 48, 13};		//SM 0\r	Modo del tracking de color normal tipo C
unsigned char bloque13[4] = {83, 77, 49, 13};		//SM 1\r	Modo del tracking de color alternado tipo CS

/* Funciones */
void mandarCMU(unsigned char bloque[],unsigned int tam){
	for(i=0;i<tam;i++){
		CMUserial_SendChar(bloque[i]);
	}
}

void mandarSerial(unsigned char bloque[],unsigned int tam){
	for(i=0;i<tam;i++){
		BLUETOOTHserial_SendChar(bloque[i]);
	}
}

unsigned char recibirCMU(void){
	do{
		CMUserial_RecvChar(&recibir);
		recibido[i] = recibir;
		i++;
	}while(CMUserial_RecvChar(&recibir) != 13);
	return *recibido;
}
