
#ifndef MOTORES_H_
#define MOTORES_H_

/* MODULOS */
#include "M1pwm.h"
#include "M2pwm.h"
#include "M1bit.h"
#include "M2bit.h"

#include "componentes/cmu.h"

void girarVehiculo(int posicionX);
void desplazarVehiculo(float posicionY);

#endif /* MOTORES_H_ */
