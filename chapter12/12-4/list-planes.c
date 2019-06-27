#include <stdio.h>
#include <string.h>

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

void list_flights(char *airport_code);

int main()
{
	char line[100]; /* input line */
	char first_airport_code[4];
	char second_airport_code[4];

	printf("Enter first airport code: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%3s", first_airport_code);

	printf("Enter second airport code: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%3s", second_airport_code);

	list_flights(first_airport_code);
	list_flights(second_airport_code);

	return 0;
}

/*
 * list_flights -- lists and prints flights from given airport
 *
 * Parameter
 * 	airport_code -- 3 character airport code of departure
 */
void list_flights(char *airport_code)
{
	int counter; /* flights loop counter */

	printf("*** Flights from %s ***\n\n", airport_code);

	for (counter = 0; counter < flights_count; ++counter) {
		/* Skip and don't list flight if airport code does not match */
		if (strcmp(flights[counter].departure, airport_code) != 0)
			continue;

		printf("* Flight *\n");
		printf("Flight number: %d\n", flights[counter].flight_number);
		printf("Departure airport code: %s\n", flights[counter].departure);
		printf("Destination airport code: %s\n", flights[counter].destination);
		printf("Starting time: %d-%d-%d %d:%d\n", flights[counter].starting_time.day, flights[counter].starting_time.month, flights[counter].starting_time.year, flights[counter].starting_time.hour, flights[counter].starting_time.minutes);
		printf("Arrival time: %d-%d-%d %d:%d\n", flights[counter].arrival_time.day, flights[counter].arrival_time.month, flights[counter].arrival_time.year, flights[counter].arrival_time.hour, flights[counter].arrival_time.minutes);

		printf("\n");
	}
}
