#include <stdio.h>

int maximum(int *array, int length);

int main()
{
	int numbers[4] = {3, 9, 4, 7};
	
	printf("Maximum number = %d\n", maximum(numbers, 4));

	return 0;
}

/*
 * maximum -- get maximum value of an array of numbers
 *
 * Parameters
 * 	array -- array of numbers
 * 	length -- array length
 *
 * Returns
 *  maximum value of an array of numbers
 */
int maximum(int *array, int length)
{
	int maximum = 0; /* intialize maximum, defaults to 0 */
	int counter;

	for (counter = 0; counter < length; ++counter) {
		if (array[counter] > maximum)
			maximum = array[counter];
	}

	return maximum;
}
