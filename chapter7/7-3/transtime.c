#include <stdio.h>
#include <string.h>

const short BYTES_SECOND = 960; /* bytes/second speed of serial transmission */

char              line[100];          /* input line */
float             input_size;         /* file size number */
char              unit_type[4];       /* kB/MB/GB */
unsigned long int size_bytes;         /* size converted to bytes */
unsigned long int required_seconds;   /* required seconds */
char              required_time[100]; /* required time string */

void display_instructions();
unsigned long int calc_bytes(float number, char unit_type[4]); /* converts to bytes */
unsigned long int calc_required_seconds(unsigned long int file_size_bytes); /* calculates required time in seconds */
char *set_required_time(char *required_time, unsigned long int required_seconds);

int main()
{
	display_instructions();

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f %s", &input_size, unit_type);

	size_bytes = calc_bytes(input_size, unit_type);
	required_seconds = calc_required_seconds(size_bytes);
	set_required_time(required_time, required_seconds);

	printf("Required time: %s\n", required_time);

	return 0;
}

unsigned long int calc_bytes(float number, char unit_type[4])
{
	if (strcmp(unit_type, "kB") == 0 || strcmp(unit_type, "kb") == 0 || strcmp(unit_type, "KB") == 0)
		return number * 1000;
	else if (strcmp(unit_type, "MB") == 0 || strcmp(unit_type, "mb") == 0)
		return number * 1000 * 1000;
	else if (strcmp(unit_type, "GB") == 0 || strcmp(unit_type, "gb") == 0)
		return number * 1000 * 1000 * 1000;
	else
		return 0;
}

unsigned long int calc_required_seconds(unsigned long int file_size_bytes)
{
	return file_size_bytes / BYTES_SECOND;
}

char *set_required_time(char *required_time, unsigned long int required_seconds)
{
	const double YEAR_IN_SECONDS = 31556926.0;
	const double MONTH_IN_SECONDS = 2629743.83;
	const double WEEK_IN_SECONDS = 604800.0;
	const double DAY_IN_SECONDS = 86400.0;
	const double HOUR_IN_SECONDS = 3600.0;
	const double MINUTE_IN_SECONDS = 60.0;

	if (required_seconds > YEAR_IN_SECONDS)
		snprintf(required_time, 100, "%.2f year(s)", (required_seconds / YEAR_IN_SECONDS));
	else if (required_seconds > MONTH_IN_SECONDS)
		snprintf(required_time, 100, "%.2f month(s)", (required_seconds / MONTH_IN_SECONDS));
	else if (required_seconds > WEEK_IN_SECONDS)
		snprintf(required_time, 100, "%.2f week(s)", (required_seconds / WEEK_IN_SECONDS));
	else if (required_seconds > DAY_IN_SECONDS)
		snprintf(required_time, 100, "%.2f day(s)", (required_seconds / DAY_IN_SECONDS));
	else if (required_seconds > HOUR_IN_SECONDS)
		snprintf(required_time, 100, "%.2f hour(s)", (required_seconds / HOUR_IN_SECONDS));
	else if (required_seconds > MINUTE_IN_SECONDS)
		snprintf(required_time, 100, "%.2f minute(s)", (required_seconds / MINUTE_IN_SECONDS));
	else
		snprintf(required_time, 100, "%lu seconds(s)", required_seconds);

	return required_time;
}

void display_instructions()
{
	printf("Input format:\n"
	"number type\n\n"

	"Valid unit types:\n"
	"kB\n"
	"MB\n"
	"GB\n\n"

	"Enter the file size and unit type: ");
}
