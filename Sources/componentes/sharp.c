/* MODULOS */
#include "Cpu.h"
#include "componentes/sharp.h"

/* CONSTANTES */
const float REFERENCIA_Y = 10;  //Referencia de posicion en profundidad

/*Variables*/
unsigned short sharpValor;
float sharpNormal;
float posicion_y = 0;

void medirSharp(void){
	SHARPadc_Measure(TRUE);
	SHARPadc_GetValue(&sharpValor);
	sharpNormal = (float)sharpValor/4096;
	//Posicion del color en el eje "y" sera la resta entre el valor del sharp y la referencia
	posicion_y = (float) ((-597.6*pow(sharpNormal,3) + 810.97*pow(sharpNormal,2) - 383.94*sharpNormal + 73.601)-(REFERENCIA_Y));
}
