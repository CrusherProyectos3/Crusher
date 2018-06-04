/* MODULOS */
#include "Cpu.h"
#include "componentes/control.h"

extern const int RANGO_X; //Rango para estar centrado

/* Variables para la posicion del Color */
extern int posicion_x;  //Se modifica en la funcion ubicarColor de cmu.c
extern float posicion_y; //Se modifica en la funcion medirSharp de sharp.c

/*FUNCIONES PARA SEGUIR COLOR*/

void seguirColor(){
	//Obtiene la posicion del color
	medirSharp();
	ubicarColor();
	
	//control de los motores
	girarVehiculo(posicion_x);
	//Si el color esta centrado puedes desplazas el vehiculo
	if(posicion_x >= -RANGO_X && posicion_x <= RANGO_X){
		desplazarVehiculo(posicion_y);
	}
}
