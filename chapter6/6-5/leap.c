#include <stdio.h>

char line[100]; /* input line */
int year; /* Entered year */

/* Checks if year is a leap year */
int isleap(int year)
{
	int leap = 0; /* default false */

	/* A leap year is any year divisble by 4 */
	if ((year % 4) == 0) {
		leap = 1;

		/* Unless the year is divisible by 100 but not by 400 */
		if ((year % 100) == 0 && (year % 400) != 0) {
			leap = 0;
		}
	}

	return leap;
}

int main()
{
	printf("Enter year number: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &year);

	if (isleap(year)) {
		printf("Year %d is a leap year\n", year);
	}
	else {
		printf("Year %d is not a leap year\n", year);
	}

	return 0;
}
