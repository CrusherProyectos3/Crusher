/* ###################################################################
**     Filename    : Events.h
**     Project     : Crusher
**     Processor   : MCF51QE128CLK
**     Component   : Events
**     Version     : Driver 01.02
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2018-04-30, 13:47, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.02
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H

/* MODULE Events */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "M1pwm.h"
#include "M2pwm.h"
#include "M1bit.h"
#include "M2bit.h"
#include "SHARPadc.h"
#include "CMUserial.h"
#include "BLUETOOTHserial.h"
#include "Bit1.h"

#include "componentes/cmu.h"

void SHARPadc_OnEnd(void);
/*
** ===================================================================
**     Event       :  SHARPadc_OnEnd (module Events)
**
**     Component   :  SHARPadc [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void BLUETOOTHserial_OnError(void);
/*
** ===================================================================
**     Event       :  BLUETOOTHserial_OnError (module Events)
**
**     Component   :  BLUETOOTHserial [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void BLUETOOTHserial_OnRxChar(void);
/*
** ===================================================================
**     Event       :  BLUETOOTHserial_OnRxChar (module Events)
**
**     Component   :  BLUETOOTHserial [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void BLUETOOTHserial_OnTxChar(void);
/*
** ===================================================================
**     Event       :  BLUETOOTHserial_OnTxChar (module Events)
**
**     Component   :  BLUETOOTHserial [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void BLUETOOTHserial_OnFullRxBuf(void);
/*
** ===================================================================
**     Event       :  BLUETOOTHserial_OnFullRxBuf (module Events)
**
**     Component   :  BLUETOOTHserial [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void BLUETOOTHserial_OnFreeTxBuf(void);
/*
** ===================================================================
**     Event       :  BLUETOOTHserial_OnFreeTxBuf (module Events)
**
**     Component   :  BLUETOOTHserial [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void CMUserial_OnError(void);
/*
** ===================================================================
**     Event       :  CMUserial_OnError (module Events)
**
**     Component   :  CMUserial [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void CMUserial_OnRxChar(void);
/*
** ===================================================================
**     Event       :  CMUserial_OnRxChar (module Events)
**
**     Component   :  CMUserial [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void CMUserial_OnTxChar(void);
/*
** ===================================================================
**     Event       :  CMUserial_OnTxChar (module Events)
**
**     Component   :  CMUserial [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void CMUserial_OnFullRxBuf(void);
/*
** ===================================================================
**     Event       :  CMUserial_OnFullRxBuf (module Events)
**
**     Component   :  CMUserial [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void CMUserial_OnFreeTxBuf(void);
/*
** ===================================================================
**     Event       :  CMUserial_OnFreeTxBuf (module Events)
**
**     Component   :  CMUserial [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

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
