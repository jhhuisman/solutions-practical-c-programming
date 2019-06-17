#include <stdio.h>

char line[100]; /* Input line */

float hours;
unsigned int minutes;

int main()
{
	printf("Enter number of hours: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &hours);

	printf("Enter number of minutes: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &minutes);

	minutes = minutes + (hours * 60);

	printf("%d minutes\n", minutes);

	return 0;
}
