#include <stdio.h>
#include <math.h>

char line[100]; /* Input line */
float distance; /* Distance between two points */
float square; /* Square of the distance between two points */
float actual_distance; /* Square root of square */

int main()
{
	printf("Enter the distance: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &distance);

	square = distance * distance;

	printf("The square of the distance is: %f\n", square);

	actual_distance = sqrt(square);

	printf("The actual distance is: %f\n", actual_distance);

	return 0;
}
