/**
 *
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

#include "printf.h"
module TestPrintfC {
  uses {
    interface Boot;
    interface Timer<TMilli>;
  }
}
implementation {
	
  uint8_t dummyVar1 = 123;
  uint16_t dummyVar2 = 12345;
  uint32_t dummyVar3 = 1234567890;

  event void Boot.booted() {
    call Timer.startPeriodic(10000);	
  }

  event void Timer.fired() {
  	printf("Hi I am writing to you from my TinyOS application!!\n");
  	printf("Here is a uint8: %u\n", dummyVar1);
  	printf("Here is a uint16: %u\n", dummyVar2);
  	printf("Here is a uint32: %ld\n", dummyVar3);
  	printfflush();
  }
}
