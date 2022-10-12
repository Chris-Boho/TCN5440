#include <stdio.h>

#ifndef MYHEADER_H
#define MYHEADER_H

int numSeconds(int hours, int minutes, int seconds);

struct time timeDif(struct time time1, struct time time2);

enum month { January = 1, February, March, April, May, June, 
        July, August, September, October, November, December };

struct time {
	int Hours;
	int Minutes;
	int Seconds;
};

struct DateTime
{
	struct time tempTime;
	enum month tempMonth;
	int day;
	int year;
};

#endif