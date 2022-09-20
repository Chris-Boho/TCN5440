#include <stdio.h>

#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_A_HOUR 60

#define TRACE __LINE__

int numSeconds(int hours, int minutes, int seconds);

struct time timeDif(struct time time1, struct time time2);

struct time {
	int Hours;
	int Minutes;
	int Seconds;
};

int main() {
	struct time t1 = {
		.Hours = 3,
		.Minutes = 45,
		.Seconds = 15
	};

	struct time t2 = {
		.Hours = 9,
		.Minutes = 44,
		.Seconds = 3
	};

	printf("Total Seconds: %d\n", numSeconds(t2.Hours, t2.Minutes, t2.Seconds) );

	struct time Result = timeDif(t1, t2);
	printf("Result Time: %d:%d:%d\n", Result.Hours, Result.Minutes), Result.Seconds;

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
