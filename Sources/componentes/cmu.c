/* MODULOS */
#include "Cpu.h"
#include "componentes/cmu.h"

/* REGISTROS */
const unsigned char r[1]={13};							//\r		  	ACK o NCK
const unsigned char CR[9]={67,82,32,49,56,32,52,52,13}; 	//CR 18 44\r	Auto ajuste de la camara
const unsigned char DM[5] = {68, 77, 32, 49, 13};			//DM 1\r		Delay 0 (One bit at the current baud rate) - de 0 a 255
const unsigned char GM[3] = {71, 77, 13};					//GM\r			Get Mean (Color medio y desviacion)
const unsigned char MM0[5] = {77, 77, 32, 48, 13};		//MM 0\r		Middle Mass (Centroide) Apaga
const unsigned char MM1[5] = {77, 77, 32, 49, 13};		//MM 1\r		Middle Mass (Centroide) Enciende
const unsigned char PM0[5] = {80, 77, 32, 48, 13};		//PM 0\r		Poll Mode off(Paquete Unico)
const unsigned char PM1[5] = {80, 77, 32, 49, 13};		//PM 1\r		Poll Mode on(Paquete Unico)
//const unsigned char TC//color[9] = {84, 67, Rmin, Rmax, Gmin, Gmax, Bmin, Bmax, 13}	//TC Rmin Rmax Gmin Gmax Bmin Bmax\r	Track un Color especifico
const unsigned char TC[3] = {84, 67, 13};           		//TC
const unsigned char TW[3] = {84, 87, 13};					//TW\r			Track el color de la region central de la ventana escogida
const unsigned char RM3[5] = {82, 77, 32, 51, 13};		//RM 3\r		Set Raw data mode 3
const unsigned char RS[3] = {82, 83, 13};					//RS\r			Reset
const unsigned char SM0[4] = {83, 77, 48, 13};			//SM 0\r		Modo del tracking de color normal tipo C
const unsigned char SM1[4] = {83, 77, 49, 13};			//SM 1\r		Modo del tracking de color alternado tipo CS
const unsigned char L11[5] = {76, 49, 32, 49, 13};		//L1 1\r		EnciendePrende Tracking LED
const unsigned char L12[5] = {76, 49, 32, 48, 13};		//L1 0\r		Apaga Tracking LED

/*Variables*/
const short BUFFER = 11;
unsigned short enviados;
unsigned short recibidos;
unsigned char respuesta[BUFFER];

int posicion_x = 0;
int posicionAnterior = 0;
const int ERROR = 1000;

/* Funciones */
void ajusteInicialCMU(void){
	//Reset Camara
	CMUserial_SendBlock(RS,sizeof(RS),&enviados);
	Cpu_Delay100US(20000);

	//Enciende LED
	CMUserial_SendBlock(L11,sizeof(L11),&enviados);
	Cpu_Delay100US(20000);

	//Auto ajuste
	//Pausa de 5 segundos para ajustar condiciones de luz
	CMUserial_SendBlock(CR,sizeof(CR),&enviados);
	Cpu_Delay100US(50000);   
	
	//Apaga LED
	CMUserial_SendBlock(L12,sizeof(L12),&enviados);
	Cpu_Delay100US(10000);
}

void seleccionColor(void){
	//Pausa 4 de  Segundos para que el usuario ponga el color en de frente a la camara
	
	//Poll Mode, un solo envio por vez
	CMUserial_SendBlock(PM1,sizeof(PM1),&enviados);
	Cpu_Delay100US(10000);
	
	//Raw data mode 3, suprime ACK/NCK
	CMUserial_SendBlock(RM3,sizeof(RM3),&enviados);
	Cpu_Delay100US(10000);
	
	//Enciende LED
	CMUserial_SendBlock(L11,sizeof(L11),&enviados);
	Cpu_Delay100US(20000);
	
	//Sigue el color frente a la camara
	CMUserial_ClearRxBuf();
	CMUserial_SendBlock(TW,sizeof(TW),&enviados);
	Cpu_Delay100US(10000);
	CMUserial_RecvBlock(respuesta,BUFFER,&recibidos);
}

void ubicarColor(void){
	/****************************************
	 * 0 Byte always 255
	 * 1 Byte always Character M
	 * 2 Byte Middle Mass X
	 * 3 Byte Middle Mass Y
	 * 4 Left corner X
	 * 5 Left corner Y
	 * 6 Right corner X
	 * 7 Right corner Y
	 * 8 Byte is Pixels
	 * 9 Byte is Confidence
	 ****************************************/
	//Seguir color
	//Ejecuta la siguiente rutina hasta que recibas un paquete tipo M
	do{
		CMUserial_SendBlock(TC,sizeof(TC),&enviados);
		Cpu_Delay100US(1000);
		CMUserial_RecvBlock(respuesta,BUFFER,&recibidos);
	}
	while(respuesta[1]!= 77);
	
	//color no esta frente a la camara
	if (respuesta[2] == 0&& respuesta[4] == 0){
		posicion_x = posicionAnterior; 
		posicionAnterior = ERROR; // Posicion de error para detener el vehiculo
	}
	else{
		// Posicion del color respecto a la camara
		posicion_x = 40 - respuesta[2]; //Mitad de la camara es en el pixel 40, segun pruebas del 03/06/2018
		posicionAnterior = posicion_x;
	}
}
