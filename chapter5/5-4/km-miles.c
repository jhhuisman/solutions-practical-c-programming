#include <stdio.h>

char line[100]; /* Input line */

float km; /* Km/hour */
float miles; /* Correspondig miles/hour */

int main()
{
	printf("Enter the km/hour to get the miles/hour: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &km);

	miles = km * 0.6213712;

	printf("Miles/hour: %f\n", miles);

	return 0;
}
