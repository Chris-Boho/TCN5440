#include <stdio.h>
#include "myHeader.h"

#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_A_HOUR 60

#define TRACE __LINE__

int main() {
	struct time t1 = {
		.Hours = 1,
		.Minutes = 30,
		.Seconds = 45
	};

	struct time t2 = {
		.Hours = 16,
		.Minutes = 30,
		.Seconds = 45
	};

	struct time t3 = {
		.Hours = 0,
		.Minutes = 1,
		.Seconds = 1
	};
	
	struct time t4 = {
		.Hours = 23,
		.Minutes = 59,
		.Seconds = 59
	};

	struct time t5 = {
		.Hours = 12,
		.Minutes = 0,
		.Seconds = 0
	};

	struct time t6 = {
		.Hours = 12,
		.Minutes = 0,
		.Seconds = 0
	};

	struct DateTime dt1 = {
		.tempTime = {
			.Hours = 12,
			.Minutes = 01,
			.Seconds = 0
		},
		.tempMonth = January,
		.day = 19,
		.year = 1809
	};

	struct DateTime dt2 = {
		.tempTime = {
			.Hours = 6,
			.Minutes = 0,
			.Seconds = 0
		},
		.tempMonth = November,
		.day = 11,
		.year = 1922
	};

	struct DateTime dt3 = {
		.tempTime = {
			.Hours = 8,
			.Minutes = 22,
			.Seconds = 0
		},
		.tempMonth = January,
		.day = 6,
		.year = 2000
	};


	struct time Result1 = timeDif(t1, t2);
	struct time Result2 = timeDif(t3, t4);
	struct time Result3 = timeDif(t5, t6);

	printf("Result 1 Time Elapsed: %02d:%02d:%02d\n", Result1.Hours, Result1.Minutes, Result1.Seconds);
	printf("Result 2 Time Elapsed: %02d:%02d:%02d\n", Result2.Hours, Result2.Minutes, Result2.Seconds);
	printf("Result 3 Time Elapsed: %02d:%02d:%02d\n", Result3.Hours, Result3.Minutes, Result3.Seconds);

	printf("Date Time 1: %d/%d/%d %d:%02d\n", dt1.tempMonth, dt1.day, dt1.year, dt1.tempTime.Hours, dt1.tempTime.Minutes);
	printf("Date Time 2: %d/%d/%d %d:%02d\n", dt2.tempMonth, dt2.day, dt2.year, dt2.tempTime.Hours, dt2.tempTime.Minutes);
	printf("Date Time 3: %d/%d/%d %d:%02d\n", dt3.tempMonth, dt3.day, dt3.year, dt3.tempTime.Hours, dt3.tempTime.Minutes);


	return 0;
}

int numSeconds(int hours, int minutes, int seconds){
	printf("Line #: %d\n", TRACE);
	int total = 0;
	total += (hours * MINUTES_IN_A_HOUR) * SECONDS_IN_A_MINUTE;
	total += minutes * SECONDS_IN_A_MINUTE;
	total += seconds;
	return total;
}

struct time timeDif(struct time time1, struct time time2){

	struct time endTime = {
		.Hours = 0,
		.Minutes = 0,
		.Seconds = 0
	};

	double secondsDif = 0;
	int t1seconds = numSeconds(time1.Hours, time1.Minutes, time1.Seconds);
	int t2seconds = numSeconds(time2.Hours, time2.Minutes, time2.Seconds);

	if (t1seconds > t2seconds) {
		secondsDif = t1seconds - t2seconds;
	} else {
		secondsDif = t2seconds - t1seconds;
	}

	endTime.Hours = secondsDif / 3600;
	endTime.Minutes = ((secondsDif / 3600) - endTime.Hours) * 60;	
	endTime.Seconds = ((((secondsDif / 3600) - endTime.Hours) * 60) - endTime.Minutes) * 60;

	return endTime;
}
