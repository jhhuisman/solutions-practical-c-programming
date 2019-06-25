#include <stdio.h>

int count(int number, int *array, int length);

int main()
{
	int array[5] = {5, 4, 4, 3, 4};
	int number = 4;

	printf("Array contains %d times the number %d\n", count(number, array, 5), number);

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
	if (length == 0)
		return 0;

	return (*array == number) + count(number, array+1, length-1);
}
