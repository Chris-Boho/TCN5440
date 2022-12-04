/**
 * This application is used to test the basic functionality of the printf service.  
 * It is initiated by calling the start() command of the SplitControl interface 
 * provided by the PrintfC component.  After starting the printf service, calls to 
 * the standard c-style printf command are made to print various strings of text 
 * over the serial line.  Only upon calling PrintfFlush.flush() does the data 
 * actually get sent out over the serial line.
 *
 * @author Kevin Klues (klueska@cs.wustl.edu)
 * @version $Revision: 1.3 $
 * @date $Date: 2010-06-29 22:07:40 $
 */
 
// Note: You can also add this define in your makefile to supress the 
//       warning about the new printf semanics.  Just all the following line:
//       CFLAGS += -DNEW_PRINTF_SEMANTICS
#define NEW_PRINTF_SEMANTICS
#include "printf.h"

configuration TestPrintfAppC{
}
implementation {
  components MainC, TestPrintfC;
  components new TimerMilliC();
  components PrintfC;
  components SerialStartC;

  TestPrintfC.Boot -> MainC;
  TestPrintfC.Timer -> TimerMilliC;
}
