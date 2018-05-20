/* MODULOS */
#include "Cpu.h"
#include "componentes/cmu.h"

const short BUFFER = 16;

enum RESPUESTAS {
		ACK, 	// recibido
		NCK, 	// no recibido
		C,		// color tracking
		F,		// frame packet
		M,		// color tracking with Middle Mass mode
		S		// statick packet, info about camera's view
};

unsigned short enviados;
unsigned short recibidos;
unsigned char respuesta[BUFFER];
byte tipoPaquete;


/* REGISTROS */
unsigned char r[1]={13};							//\r		  	ACK o NCK
unsigned char CR[9]={67,82,32,49,56,32,52,52,13}; 	//CR 18 44\r	Auto ajuste de la camara
unsigned char DM[5] = {68, 77, 32, 49, 13};			//DM 1\r		Delay 0 (One bit at the current baud rate) - de 0 a 255
unsigned char RS[3] = {82, 83, 13};					//RS\r			Reset
unsigned char GM[3] = {71, 77, 13};					//GM\r			Get Mean (Color medio y desviacion)
unsigned char MM0[5] = {77, 77, 32, 48, 13};		//MM 0\r		Middle Mass (Centroide) Apaga
unsigned char MM1[5] = {77, 77, 32, 49, 13};		//MM 1\r		Middle Mass (Centroide) Enciende
unsigned char PM1[5] = {80, 77, 32, 48, 13};		//PM 1\r		Poll Mode (Paquete Unico)
//unsigned char TC//color[9] = {84, 67, Rmin, Rmax, Gmin, Gmax, Bmin, Bmax, 13}	//TC Rmin Rmax Gmin Gmax Bmin Bmax\r	Track un Color especifico
unsigned char TC[3] = {84, 67, 13};           		//TC
unsigned char TW[3] = {84, 87, 13};					//TW\r			Track el color de la region central de la ventana escogida
unsigned char SM0[4] = {83, 77, 48, 13};			//SM 0\r		Modo del tracking de color normal tipo C
unsigned char SM1[4] = {83, 77, 49, 13};			//SM 1\r		Modo del tracking de color alternado tipo CS
unsigned char L11[5] = {76, 49, 32, 49, 13};		//L1 1\r		EnciendePrende Tracking LED
unsigned char L12[5] = {76, 49, 32, 48, 13};		//L1 0\r		Apaga Tracking LED


/* Funciones */
void ajusteInicialCMU(void){
	int i;
	
	//Reset Camara
	CMUserial_SendBlock(RS,sizeof(RS),&enviados);
	Cpu_Delay100US(1000);

	//Enciende LED
	CMUserial_SendBlock(L11,sizeof(L11),&enviados);
	Cpu_Delay100US(100);
	
	//Auto ajuste
	CMUserial_SendBlock(CR,sizeof(CR),&enviados);
	for(i=0;i<=5;i++){
		Cpu_Delay100US(10000);   //Pausa de 5 segundos para ajustar condiciones de luz
	}
	
	//Apaga LED
	CMUserial_SendBlock(L12,sizeof(L12),&enviados);
	Cpu_Delay100US(100);
}

byte comprobarRespuesta(unsigned char respuesta0){
	if(respuesta0 == 65){ //A
		return ACK;
	}
	else if(respuesta0 == 67){ //C
		return C;
	}
	else if(respuesta0 == 70){ //F
		return F;
	}
	else if(respuesta0 == 77){ //M
		return M;
	}
	else if(respuesta0 == 83){ //S
		return S;
	}
	else{ 
		return NCK;
	}
}

