#include <stdio.h>

char line[100]; /* Input line */

int minutes; /* Number of minutes */
int hours; /* Number of hours */

int main()
{
	printf("Enter the number of minutes: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &minutes);

	hours = minutes / 60;
	
	minutes = minutes - (hours * 60);

	printf("%d hour(s) %d minute(s)\n", hours, minutes);

	return 0;
}
