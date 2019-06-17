#include <stdio.h>

char line[100]; /* Input line */

float width; /* Width rectangle in cm */
float height; /* Height rectangle in cm */
float perimeter;  /* Perimeter rectangle in cm */

int main()
{
	printf("Enter width and height of rectangle (width height): ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f %f", &width, &height);

	perimeter = 2 * (width * height);

	printf("The perimeter of the rectangle is: %f\n", perimeter);

	return 0;
}
