#include <stdio.h>

char line[100]; /* Input line */
int value; /* Value to double */

int main()
{
	printf("Enter a number: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &value);

	printf("Twice %d is %d\n", value, value * 2);

	return 0;
}
