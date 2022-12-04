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

    components ActiveMessageC as ActMesC_1;
    components ActiveMessageC as Packet1;
    components new AMSenderC(AM_DEMO_MESSAGE) as Send1;
    components new AMReceiverC(AM_DEMO_MESSAGE) as Recv1;
    components SerialActiveMessageC as SerialC1;

    components ActiveMessageC as ActMesC_2;
    components ActiveMessageC as Packet2;
    components new AMSenderC(AM_DEMO_MESSAGE) as Send2;
    components new AMReceiverC(AM_DEMO_MESSAGE) as Recv2;
    components SerialActiveMessageC as SerialC2;

    components LedsC;
    components new TimerMilliC() as Timer1;
    components new TimerMilliC() as Timer2;
    components SerialPrintfC;

    DemoP.Boot -> MainC;
    DemoP.Photo -> PhotoC;
    DemoP.TempRead -> TempC.Temperature;

    DemoP.RadioControl_1 -> ActMesC_1;
    DemoP.RadioControl_2 -> ActMesC_2;
    
    DemoP.AMSend_1 -> Send1;
    DemoP.AMReceive_1 -> Recv1;
    DemoP.AMPacket_1 -> Packet1;

    DemoP.AMSend_2 -> Send2;
    DemoP.AMReceive_2 -> Recv2;
    DemoP.AMPacket_2 -> Packet2;

    DemoP.SerialControl_1 -> SerialC1;
    DemoP.SerialAMSend_1 -> SerialC1.AMSend[AM_DEMO_MESSAGE];
    DemoP.SerialPacket_1 -> SerialC1;

    DemoP.SerialControl_2 -> SerialC2;
    DemoP.SerialAMSend_2 -> SerialC2.AMSend[AM_DEMO_MESSAGE];
    DemoP.SerialPacket_2 -> SerialC2;


    DemoP.Leds -> LedsC;

    DemoP.Timer1 -> Timer1;
    DemoP.Timer2 -> Timer2;
}