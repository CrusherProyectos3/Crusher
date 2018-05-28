/* ###################################################################
**     Filename    : Events.c
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
** @file Events.c
** @version 01.02
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
extern unsigned char estado;
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
void SHARPadc_OnEnd(void)
{
  /* Write your code here ... */

}


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
void  BLUETOOTHserial_OnError(void)
{
  /* Write your code here ... */
}

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
void  BLUETOOTHserial_OnRxChar(void)
{
  /* Write your code here ... */
}

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
void  BLUETOOTHserial_OnTxChar(void)
{
  /* Write your code here ... */
}

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
void  BLUETOOTHserial_OnFullRxBuf(void)
{
  /* Write your code here ... */
	
}

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
void  BLUETOOTHserial_OnFreeTxBuf(void)
{
  /* Write your code here ... */
}

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
void  CMUserial_OnError(void)
{
  /* Write your code here ... */
}

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
void  CMUserial_OnRxChar(void)
{
  /* Write your code here ... */
	if (estado == 1){
		recibirColor();
	}
}

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
void  CMUserial_OnTxChar(void)
{
  /* Write your code here ... */
}

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
void  CMUserial_OnFullRxBuf(void)
{
  /* Write your code here ... */
}

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
void  CMUserial_OnFreeTxBuf(void)
{
  /* Write your code here ... */
}
