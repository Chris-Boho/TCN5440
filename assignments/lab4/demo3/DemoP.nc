#include "printf.h"

module DemoP
{
    uses interface Boot;
    uses interface Read<uint16_t> as Photo;
    uses interface Read<uint16_t> as TempRead;
    uses interface SplitControl as RadioControl;
    uses interface AMSend;
    uses interface Receive;
    uses interface Packet;
    uses interface SplitControl as SerialControl;
    uses interface Packet as SerialPacket;
    uses interface AMSend as SerialAMSend;
    uses interface Leds;

    uses interface Timer<TMilli> as Timer_1;
    uses interface Timer<TMilli> as Timer_2;
}
implementation
{
    message_t buf;
    message_t *receivedBuf;
    uint16_t count = 0;
    uint16_t celcius;
    task void readSensor();
    task void readTempSensor();
    task void sendPacket();
    task void sendSerialPacket();

    event void Boot.booted()
    {
        call RadioControl.start();
        call SerialControl.start();
    }
    event void RadioControl.startDone(error_t err)
    {
        if(TOS_NODE_ID == 1){
            call Timer_1.startPeriodic(1000);
            call Timer_1.startPeriodic(2000);
        }
    }
    event void Timer_1.fired()
    {
        post readSensor();
    }

    event void Timer_2.fired()
    {
        post readTempSensor();
    }

    event void RadioControl.stopDone(error_t err){}
    event void SerialControl.startDone(error_t err){}
    event void SerialControl.stopDone(error_t err){}

    task void readSensor()
    {
        if(call Photo.read() != SUCCESS)
            post readSensor();
    }

    task void readTempSensor()
    {
        if(call TempRead.read() != SUCCESS)
            post readTempSensor();
    }

    event void Photo.readDone(error_t err, uint16_t value)
    {
        if(err != SUCCESS)
            post readSensor();
        else
        {
            demo_message_t * payload = (demo_message_t *)call
            Packet.getPayload(&buf,sizeof(demo_message_t));
            payload->photoReading = value;
            post sendPacket();
        }
    }

    event void TempRead.readDone(error_t err, uint16_t value)
    {
        if(err != SUCCESS)
            post readSensor();
        else
        {
            demo_message_t * payload = (demo_message_t *)call
            Packet.getPayload(&buf,sizeof(demo_message_t));
            celcius = (-39.60 + 0.01 * value);
            payload->tempReading = celcius;
            post sendPacket();
        }
    }

    task void sendPacket()
    {
        if(call AMSend.send(AM_BROADCAST_ADDR, &buf, sizeof(demo_message_t)) != SUCCESS)
            post sendPacket();
    }
    event void AMSend.sendDone(message_t * msg, error_t err)
    {
        if(err != SUCCESS)
            post sendPacket();
    }

    event message_t * Receive.receive(message_t * msg, void * payload, uint8_t len)
    {
        demo_message_t * demoPayload = (demo_message_t *)payload;
        // call Leds.set(demoPayload->photoReading / 200);
        // call Leds.led0Toggle();
        count++;
        // printf("Count: %d\n", count);
        printf("Ambient Light: %d\n", demoPayload->photoReading);
        if(count % 2 == 0)
            printf("Temperature: %d\n", demoPayload->tempReading);
        // printf("LEDS1: %d\n", (call Leds.get() & LEDS_LED1));
        // printf("LEDS2: %d\n", (call Leds.get() & LEDS_LED2));
        // printf("LEDS3: %d\n", (call Leds.get() & LEDS_LED3));
        receivedBuf = msg;
        post sendSerialPacket();
        return msg;
    }
    task void sendSerialPacket()
    {
        if(call SerialAMSend.send(AM_BROADCAST_ADDR, receivedBuf, sizeof(demo_message_t))!=
        SUCCESS)
            post sendSerialPacket();
    }

    event void SerialAMSend.sendDone(message_t* ptr, error_t success)
    {
        if(success!=SUCCESS)
            post sendSerialPacket();
    }

}