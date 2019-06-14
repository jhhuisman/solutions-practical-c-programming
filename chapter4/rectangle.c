#include <stdio.h>

int main()
{
	float width; /* Width of rectangle in inches */
	float height; /* Height of rectangle in inches */
	float area; /* Area in inches */
	float perimeter; /* Perimeter in inches */

	width = 6.8;
	height = 2.3;

	area = width * height;
	perimeter = width + width + height + height;

	printf("The area of a rectangle with a width of %f and a height of %f is: %f inches\n", width, height, area);
	printf("The perimeter of a rectangle with a width of %f and a height of %f is: %f inches\n", width, height, perimeter);

	return 0;
}
