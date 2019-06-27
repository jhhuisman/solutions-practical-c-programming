#include <stdio.h>

struct time {
	int day;     /* day number 1 - 31 */
	int month;   /* month number 1 - 12 */
	int year;    /* year number i.e. 2019 */
	int hour;    /* hour number 0 - 23 */
	int minutes; /* 0 - 59 */
};

int timediff(struct time first_time, struct time second_time); /* calculates time difference in minutes between two times */

int main()
{
	struct time times[] = {
		{
			2,    /* month */
			12,   /* month */
			2018, /* year */
			15,   /* hour */
			23    /* minutes */
		},
		{
			7,    /* month */
			8,    /* month */
			2019, /* year */
			16,   /* hour */
			20    /* minutes */
		}
	};

	printf("Time difference is %d minutes\n", timediff(times[0], times[1]));

	return 0;
}

/*
 * timediff -- calculates time difference in minutes between two times
 *
 * Parameters
 * 	first_time -- time (structure) containing date and time
 * 	second_time -- time (structure) containing date and time
 *
 * Return
 * 	number of minutes difference between two times
 */
int timediff(struct time first_time, struct time second_time)
{
	int first_minutes;  /* total number of minutes first time */
	int second_minutes; /* total number of minutes second time */

	first_minutes = first_time.minutes + (first_time.hour * 60);
	second_minutes = second_time.minutes + (second_time.hour * 60);

	if (first_minutes >= second_minutes)
		return first_minutes - second_minutes;
	else
		return second_minutes - first_minutes;
}
