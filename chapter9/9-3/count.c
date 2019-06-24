#include <stdio.h>

int count(int number, int *array, int length);

int main()
{
	int array[4] = {5, 4, 3, 4};
	int number = 4;

	printf("Array contains %d times the number %d\n", count(number, array, 4), number);

	return 0;
}

/*
 * count -- counts the number of times that the number appears in array
 *
 * Parameters
 * 	number -- number to check and count
 * 	array -- array containing numbers
 * 	length -- lenth of array, number of elements
 *
 * Returns
 *  number of times that the number appears in array
 */
int count(int number, int *array, int length)
{
	int number_count = 0; /* intialize number count, defaults 0 */
	int counter; /* counter used to loop array elements */

	for (counter = 0; counter < length; ++counter) {
		if (array[counter] == number)
			++number_count;
	}

	return number_count;
}
