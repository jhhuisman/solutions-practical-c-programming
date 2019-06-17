#include <stdio.h>

char line[100]; /* Input line */

float celsius;
float fahrenheit;

int main()
{
	printf("Enter celsius: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &celsius);

	fahrenheit = 9.0 / 5.0 * celsius + 32;

	printf("%f celsius = %f fahrenheit\n", celsius, fahrenheit);

	return 0;
}
