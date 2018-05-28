/* MODULOS */
#include "Cpu.h"
#include "componentes/sharp.h"

/* CONSTANTES */
unsigned short sharpValor;
float sharpNormal;

float MedirSharp(void){
	SHARPadc_Measure(TRUE);
	SHARPadc_GetValue(&sharpValor);
	sharpNormal = (float)sharpValor/4096;
	return (float) -597.6*pow(sharpNormal,3) + 810.97*pow(sharpNormal,2) - 383.94*sharpNormal + 73.601;
}
