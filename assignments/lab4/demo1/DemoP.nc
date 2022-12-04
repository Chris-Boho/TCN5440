#include "printf.h"

module DemoP
{
    uses interface Boot;

    uses interface Read<uint16_t> as Photo;
    uses interface Read<uint16_t> as TempRead;

    uses interface SplitControl as RadioControl_1;
    uses interface SplitControl as RadioControl_2;


    uses interface AMSend as AMSend_1;
    uses interface Receive as AMReceive_1;
    uses interface Packet as AMPacket_1;

    uses interface AMSend as AMSend_2;
    uses interface Receive as AMReceive_2;
    uses interface Packet as AMPacket_2;

    uses interface SplitControl as SerialControl_1;
    uses interface Packet as SerialPacket_1;
    uses interface AMSend as SerialAMSend_1;

    uses interface SplitControl as SerialControl_2;
    uses interface Packet as SerialPacket_2;
    uses interface AMSend as SerialAMSend_2;


    uses interface Leds;
    uses interface Timer<TMilli> as Timer1;
    uses interface Timer<TMilli> as Timer2;

}
implementation
{
    message_t buf_1;
    message_t *receivedBuf_1;

    message_t buf_2;
    message_t *receivedBuf_2;


    uint16_t celcius;
    task void readSensor();
    task void readTempSensor();

    task void sendPacket();
    task void sendTempPacket();

    task void sendSerialPacket_1();
    task void sendSerialPacket_2();


    event void Boot.booted()
    {
        call RadioControl_1.start();
        call RadioControl_2.start();

        call SerialControl_1.start();
        call SerialControl_2.start();
    }
    event void RadioControl_1.startDone(error_t err)
    {
        if(TOS_NODE_ID == 1)
            call Timer1.startPeriodic(1000);
    }
    event void RadioControl_2.startDone(error_t err)
    {
        if(TOS_NODE_ID == 1)
            call Timer2.startPeriodic(2000);
    }


    event void Timer1.fired()
    {
        post readSensor();  
    }

    event void Timer2.fired()
    {
        post readTempSensor();  
    }

    event void RadioControl_1.stopDone(error_t err){}
    event void RadioControl_2.stopDone(error_t err){}

    event void SerialControl_1.startDone(error_t err){}
    event void SerialControl_1.stopDone(error_t err){}

    event void SerialControl_2.startDone(error_t err){}
    event void SerialControl_2.stopDone(error_t err){}

    task void readSensor()
    {
        if(call Photo.read() != SUCCESS)
        post readSensor();
    }
    event void Photo.readDone(error_t err, uint16_t value)
    {
        if(err != SUCCESS)
            post readSensor();
        else
        {
            demo_message_t * payload_1 = (demo_message_t *)call
            AMPacket_1.getPayload(&buf_1,sizeof(demo_message_t));
            payload_1->photoReading = value;
            // printf("VALUE LIGHT: %d\n", value);
            post sendPacket();
        }
    }

    task void readTempSensor()
    {

        if(call TempRead.read() != SUCCESS)
        post readTempSensor();
    }
    event void TempRead.readDone(error_t err, uint16_t value)
    {
        if(err != SUCCESS)
            post readTempSensor();
        else
        {
            demo_temp_message_t * payload_2 = (demo_temp_message_t *)call
            AMPacket_2.getPayload(&buf_2,sizeof(demo_temp_message_t));
            celcius = (-39.60 + 0.01 * value);
            payload_2->tempReading = celcius;
            // printf("VALUE TEMP: %d\n", celcius);
            post sendTempPacket();
        }
    }



    task void sendPacket()
    {
        if(call AMSend_1.send(AM_BROADCAST_ADDR, &buf_1, sizeof(demo_message_t)) != SUCCESS)
            post sendPacket();
    }
    event void AMSend_1.sendDone(message_t * msg, error_t err)
    {
        if(err != SUCCESS)
            post sendPacket();
    }

    task void sendTempPacket()
    {
        if(call AMSend_2.send(AM_BROADCAST_ADDR, &buf_2, sizeof(demo_temp_message_t)) != SUCCESS)
            post sendTempPacket();
    }
    event void AMSend_2.sendDone(message_t * msg, error_t err)
    {
        if(err != SUCCESS)
            post sendTempPacket();
    }



    event message_t * AMReceive_1.receive(message_t * msg, void * payload, uint8_t len)
    {
        demo_message_t * demoPayload_1 = (demo_message_t *)payload;
        // call Leds.set(demoPayload->photoReading / 200);
        receivedBuf_1 = msg;
        if(TOS_NODE_ID == 2){
            printf("Ambient Light Intensity Received: %d\n", demoPayload_1->photoReading);
            printfflush();
            // printf("Temperature Received: %d\n", demoPayload->tempReading);
                
        }
        post sendSerialPacket_1();
        // printf("MSG 1: %s\n", msg);
        return msg;
    }

    event message_t * AMReceive_2.receive(message_t * msg, void * payload, uint8_t len)
    {
        demo_temp_message_t * demoPayload_2 = (demo_temp_message_t *)payload;
        // call Leds.set(demoPayload->photoReading / 200);
        receivedBuf_2 = msg;
        if(TOS_NODE_ID == 2){
            // printf("Ambient Light Intensity Received: %d\n", demoPayload->photoReading);
            printf("Temperature Received: %d\n", demoPayload_2->tempReading);
            printfflush();
                
        }
        post sendSerialPacket_2();
        // printf("MSG 2: %s\n", msg);
        return msg;
    }


    task void sendSerialPacket_1()
    {
        if(call SerialAMSend_1.send(AM_BROADCAST_ADDR, receivedBuf_1, sizeof(demo_message_t))!= SUCCESS)
            post sendSerialPacket_1();
    }
    event void SerialAMSend_1.sendDone(message_t* ptr, error_t success)
    {
        if(success!=SUCCESS)
            post sendSerialPacket_1();
    }


    task void sendSerialPacket_2()
    {
        if(call SerialAMSend_2.send(AM_BROADCAST_ADDR, receivedBuf_2, sizeof(demo_temp_message_t))!= SUCCESS)
            post sendSerialPacket_2();
    }
    event void SerialAMSend_2.sendDone(message_t* ptr, error_t success)
    {
        if(success!=SUCCESS)
            post sendSerialPacket_2();
    }

}