#include "printf.h"

/*
To specify, I created a demo folder in:
/opt/tinyos-main/apps/tutorials/
*/

module DemoP
{
    uses interface Boot;
    uses interface Read<uint16_t> as Photo;

    //make TempRead available to use
    uses interface Read<uint16_t> as TempRead;

    uses interface SplitControl as RadioControl;
    uses interface AMSend;
    uses interface Receive;
    uses interface Packet;
    uses interface SplitControl as SerialControl;
    uses interface Packet as SerialPacket;
    uses interface AMSend as SerialAMSend;
    uses interface Leds;
    uses interface Timer<TMilli>;
}
implementation
{
    message_t buf;
    message_t *receivedBuf;

    //Count added to print temperature reading every other second
    //celcius is initialized
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

    //check TOS_NODE_ID equal to 1 to start a timer
    event void RadioControl.startDone(error_t err)
    {
        if(TOS_NODE_ID == 1)
            call Timer.startPeriodic(1000);
    }
    event void Timer.fired()
    {
        post readSensor();
        //read the temperature sensor
        post readTempSensor();
    }

    event void RadioControl.stopDone(error_t err){}
    event void SerialControl.startDone(error_t err){}
    event void SerialControl.stopDone(error_t err){}

    //attempts to read ambient light intensity sensor
    task void readSensor()
    {
        if(call Photo.read() != SUCCESS)
            post readSensor();
    }

    //repeat readTempSensor until TempRead succeds
    task void readTempSensor()
    {
        if(call TempRead.read() != SUCCESS)
            post readTempSensor();
    }

    //receives data from ambient light sensor 
    //adds this value to the payload
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

    //checks the temperature sensor and adds temperature value to a payload
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
        }
    }

    //broadcasts the packet to other motes
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

    //this is what occurs when a mote receives a packet
    //count is incremented
    //used to print temperature every other second.
    event message_t * Receive.receive(message_t * msg, void * payload, uint8_t len)
    {
        demo_message_t * demoPayload = (demo_message_t *)payload;;
        count++;
        printf("Ambient Light: %d\n", demoPayload->photoReading);
        if(count % 2 == 0)
            printf("Temperature: %d\n", demoPayload->tempReading);
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
