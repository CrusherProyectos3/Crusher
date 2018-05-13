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
#include "BLUETOOTHserial.h"

/*Variables*/




void mandarCMU(unsigned char bloque[],unsigned int tam);
void mandarSerial(unsigned char bloque[],unsigned int tam);
unsigned char recibirCMU(void);

/* END cmu */
#endif /* __cmu_H*/
