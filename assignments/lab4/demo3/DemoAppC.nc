#include "DemoMessage.h"
#include <stdio.h>
#include <string.h>
#include "printf.h"

configuration DemoAppC
{
}
implementation
{
    components DemoP, MainC, new HamamatsuS10871TsrC() as PhotoC;
    components new SensirionSht11C() as TempC;
    components ActiveMessageC;
    components new AMSenderC(AM_DEMO_MESSAGE), new AMReceiverC(AM_DEMO_MESSAGE);
    components LedsC;
    components new TimerMilliC() as Timer1;
    components new TimerMilliC() as Timer2;
    components SerialPrintfC;
    components SerialStartC;
    components SerialActiveMessageC as SerialC;

    DemoP.Boot -> MainC;
    DemoP.Photo -> PhotoC;
    DemoP.TempRead -> TempC.Temperature;

    DemoP.RadioControl -> ActiveMessageC;
    DemoP.AMSend -> AMSenderC;
    DemoP.Receive -> AMReceiverC;
    DemoP.Packet -> ActiveMessageC;
    DemoP.SerialControl -> SerialC;
    DemoP.SerialAMSend -> SerialC.AMSend[AM_DEMO_MESSAGE];
    DemoP.SerialPacket -> SerialC;
    DemoP.Leds -> LedsC;

    DemoP.Timer_1 -> Timer1;
    DemoP.Timer_1 -> Timer2;

}