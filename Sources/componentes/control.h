
#ifndef CONTROL_H_
#define CONTROL_H_
/* Modulos compartidos*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
/* MODULOS */
#include "M1pwm.h"
#include "M2pwm.h"
#include "M1bit.h"
#include "M2bit.h"

#include "componentes/cmu.h"
#include "componentes/sharp.h"
#include "componentes/motores.h"

#include <math.h>
#include <stdlib.h>

void seguirColor(void);

#endif /* CONTROL_H_ */
