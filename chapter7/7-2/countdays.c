#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

char     first_input[12];  /* first input line */
char     second_input[12]; /* second input line */
char     first_date[12];   /* first input date dd-mm-yyyy */
char     second_date[12];  /* second input date dd-mm-yyyy */
long int days_difference;  /* number of days between the two dates */

long int days_between_dates(char *first_date_string, char *second_date_string);
time_t strtotime(char *date_string);
double seconds_to_hours(double seconds);
int is_valid_date_string(char *date_string);

int main()
{
	printf("Valid date format: dd-mm-yyyy\n\n");

	do {
		printf("Enter the first date: ");
		fgets(first_input, sizeof(first_input), stdin);
		sscanf(first_input, "%s", first_date);
	} while (! is_valid_date_string(first_date));

	do {
		printf("Enter the second date: ");
		fgets(second_input, sizeof(second_input), stdin);
		sscanf(second_input, "%s", second_date);
	} while (! is_valid_date_string(second_date));

	days_difference = days_between_dates(first_date, second_date);

	printf("There is/are %ld day(s) between %s and %s\n", days_difference, first_date, second_date);

	return 0;
}

long int days_between_dates(char *first_date_string, char *second_date_string)
{
	time_t time_first_date;    /* first date string converted to time */
	time_t time_second_date;   /* second date string converted to time */
	double difference_seconds; /* difference between the two dates in seconds */
	double difference_days;    /* difference converted to hours */

	time_first_date = strtotime(first_date_string);
	time_second_date = strtotime(second_date_string);

	difference_seconds = difftime(time_second_date, time_first_date);
	difference_days = seconds_to_hours(difference_seconds);

	return difference_days;
}

time_t strtotime(char *date_string)
{
	struct tm date = {0}; /* set all fields to 0 */

	unsigned short day;   /* day extracted from time string */
	unsigned short month; /* month extracted from time string */
	unsigned short year;  /* year extracted from time string */

	sscanf(date_string, "%hu-%hu-%hu", &day, &month, &year);

	date.tm_mday = day;
	date.tm_mon = month;
	date.tm_year = year;

	return mktime(&date);
}

double seconds_to_hours(double seconds)
{
	return seconds / 60 / 60 / 24;
}

int is_valid_date_string(char *str)
{
	int result; /* result of validity check */
	
	result =
		isdigit(str[0]) &&
		isdigit(str[1]) &&
		str[2] == '-' &&
		isdigit(str[3]) &&
		isdigit(str[4]) &&
		str[5] == '-' &&
		isdigit(str[6]) &&
		isdigit(str[7]) &&
		isdigit(str[8]) &&
		isdigit(str[9]);

	if (! result)
		printf("Invalid date.\n");

	return result;
}
