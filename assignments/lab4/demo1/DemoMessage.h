#ifndef __DEMOAPP_H
#define __DEMOAPP_H
enum
{
AM_DEMO_MESSAGE = 150,
};
typedef nx_struct demo_message
{
nx_uint16_t photoReading;
// nx_uint16_t tempReading;
} demo_message_t;

typedef nx_struct demo_temp_message
{
nx_uint16_t tempReading;
} demo_temp_message_t;
#endif // __DEMOAPP_H