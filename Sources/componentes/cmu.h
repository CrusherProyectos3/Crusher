#ifndef __cmu_H
#define __cmu_H

/* Modulos compartidos*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"

/* MODULOS */
#include "CMUserial.h"

/* FUNCIONES */
void ajusteInicialCMU(void);
byte comprobarRespuesta(unsigned char data0);

/* END cmu */
#endif /* __cmu_H*/

