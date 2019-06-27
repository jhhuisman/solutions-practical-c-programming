#include <stdio.h>

struct time {
	int day;     /* day number 1 - 31 */
	int month;   /* month number 1 - 12 */
	int year;    /* year number i.e. 2019 */
	int hour;    /* hour number 1 - 23 */
	int minutes; /* 0 - 59 */
};

struct flight {
	int         flight_number;
	char        departure[4];   /* airport code 3 characters */
	char        destination[4]; /* airport code 3 characters */
	struct time starting_time;  /* starting time containing data and time */
	struct time arrival_time;   /* arrival time containing data and time */
};

struct flight flights[] = {
	{
		239394,   /* flight number */
		"AMS",    /* departure airport code */
		"TAN",    /* destination airport code */
		{         /* starting date and time */
			30,   /* day number */
			8,    /* month number */
			2019, /* year */
			15,   /* hour */
			15    /* minutes */
		},
		{         /* departure date and time */
			30,   /* day number */
			8,    /* month number */
			2019, /* year */
			19,   /* hour */
			10    /* minutes */
		},
	},
	{
		302834,   /* flight number */
		"TAN",    /* departure airport code */
		"AMS",    /* destination airport code */
		{         /* starting date and time */
			30,   /* day number */
			8,    /* month number */
			2019, /* year */
			19,   /* hour */
			30    /* minutes */
		},
		{         /* departure date and time */
			30,   /* day number */
			8,    /* month number */
			2019, /* year */
			21,   /* hour */
			30    /* minutes */
		},
	},
	{
		432345,   /* flight number */
		"MAD",    /* departure airport code */
		"PAR",    /* destination airport code */
		{         /* starting date and time */
			3,    /* day number */
			9,    /* month number */
			2019, /* year */
			10,   /* hour */
			35    /* minutes */
		},
		{         /* departure date and time */
			3,    /* day number */
			9,    /* month number */
			2019, /* year */
			12,   /* hour */
			40    /* minutes */
		},
	},
};

int flights_count = sizeof(flights) / sizeof(flights[0]);

void list_flights(void);

int main()
{
	list_flights();

	return 0;
}

void list_flights(void)
{
	int counter; /* flights loop counter */

	printf("*** Flights ***\n\n");

	for (counter = 0; counter < flights_count; ++counter) {
		printf("* Flight %d *\n", (counter + 1));
		printf("Flight number: %d\n", flights[counter].flight_number);
		printf("Departure airport code: %s\n", flights[counter].departure);
		printf("Destination airport code: %s\n", flights[counter].destination);
		printf("Starting time: %d-%d-%d %d:%d\n", flights[counter].starting_time.day, flights[counter].starting_time.month, flights[counter].starting_time.year, flights[counter].starting_time.hour, flights[counter].starting_time.minutes);
		printf("Arrival time: %d-%d-%d %d:%d\n", flights[counter].arrival_time.day, flights[counter].arrival_time.month, flights[counter].arrival_time.year, flights[counter].arrival_time.hour, flights[counter].arrival_time.minutes);

		printf("\n");
	}
}
