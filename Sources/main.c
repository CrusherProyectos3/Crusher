/* ###################################################################
**     Filename    : main.c
**     Project     : Crusher
**     Processor   : MCF51QE128CLK
**     Version     : Driver 01.00
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2018-04-30, 13:47, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.00
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "M1pwm.h"
#include "M2pwm.h"
#include "M1bit.h"
#include "M2bit.h"
#include "SHARPadc.h"
#include "CMUserial.h"
#include "BLUETOOTHserial.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
/* Librerias para cada componente */

#include "componentes/cmu.h"
#include "componentes/sharp.h"
#include "componentes/control.h"

double sharpDistancia;

void main(void)
{
  /* Write your local variable definition here */
	/* Constantes para la maquina de estados */
	enum ESTADOS {
		INICIAR,
		BLUETOOTH,
		CMU,
		SHARP,
		CONTROL
	};

	/* Variables para la maquina de estados */
	unsigned char estado = INICIAR;
	
	

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

	PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  /* Write your code here */
	
	/*CRUSHER IS HERE!*/
	for(;;){
		switch(estado){
			case INICIAR:
				//M1pwm_Disable();
				//M2pwm_Disable();
				estado = BLUETOOTH;
				break;
			case BLUETOOTH:		
				estado = CMU;
				break;
			case CMU:
				estado = SHARP;
				break;
			case SHARP:
				sharpDistancia = MedirSharp();
				estado = CONTROL;
				break;
			case CONTROL:
				distanciaConstante(sharpDistancia);
				estado = BLUETOOTH;
				break;
			default:
				break;
		}
	}

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */


/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/
