/* MODULOS */
#include "Cpu.h"
#include "componentes/control.h"

extern const int RANGO_X;
extern const int ERROR;
/* Variables para Seguir Color */
extern int posicion_x;
extern float posicion_y;

/*FUNCIONES PARA SEGUIR PELOTA DE COLOR*/
void seguirPelota(){
	medirSharp();
	seguirColor();
	girarVehiculo(posicion_x); 
	if(posicion_x >= -RANGO_X && posicion_x <= RANGO_X){
		desplazarVehiculo(posicion_y);
	}
}
