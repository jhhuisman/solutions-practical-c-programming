#include <stdio.h>

const float PI = 3.1415927;

char line[100];

float volume; /* Volume of a sphere */
float radius; /* Radius of sphere */

int main()
{
	printf("Enter the radius of the sphere: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &radius);

	volume = 4.0 / 3.0 * PI * (radius * radius * radius);

	printf("The volume of the sphere is: %f\n", volume);

	return 0;
}
