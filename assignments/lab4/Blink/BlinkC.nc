#include "Timer.h”
module BlinkC
{
    uses interface Timer<TMilli> as Timer0;
    uses interface Timer<TMilli> as Timer1;
    uses interface Leds;
    uses interface Boot;
}
implementation
{
    event void Boot.booted()
    {
        call Timer0.startPeriodic( 250 );
        call Timer1.startPeriodic( 500 );
    }
    event void Timer0.fired()
    {
        call Leds.led0Toggle();
    }
    event void Timer1.fired()
    {
        call Leds.led1Toggle();
    }
}