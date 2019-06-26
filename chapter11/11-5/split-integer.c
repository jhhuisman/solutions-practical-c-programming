#include <stdio.h>

#define NUMBER_OF_PARTS 8

int main()
{
	/* 
	 * integer to be split into 8 parts
	 *
	 * number 1 should be 15 (F)
	 * number 2 should be 2
	 * etc.
	 */
	long int integer = 0xF2187283;
	long int numbers[NUMBER_OF_PARTS]; /* array with 8 numbers, to be used as 4 bit integer parts */

	int counter; /* counter for loop */
	int shift; /* how many places to shift integer to right */
	long int mask = 0xF0000000;

	shift = NUMBER_OF_PARTS * 4 - 4; /* initialize shift */

	for (counter = 0; counter < NUMBER_OF_PARTS; ++counter) {
		numbers[counter] = (integer & mask) >> shift;
		mask = mask >> 4;
		shift -= 4;
	}

	for (counter = 0; counter < NUMBER_OF_PARTS; ++counter)
		printf("Number %d is = %lx\n", (counter + 1), numbers[counter]);

	return 0;
}
