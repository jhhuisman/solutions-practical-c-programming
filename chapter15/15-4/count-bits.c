#include <stdio.h>
#include <string.h>

int count_string_bits(char string[]);
int count_integer_bits(int integer);

int main()
{
	char string[] = "Test string";

	printf("%d bits set\n", count_string_bits(string));

	return 0;
}

int count_string_bits(char string[])
{
	int bitcount = 0;
	int counter = 0;

	for (counter = 0; counter < strlen(string); ++counter) {
		bitcount += count_integer_bits((int)string[counter]);
	}

	return bitcount;
}

int count_integer_bits(int integer)
{
	int number_of_bits = 0; /* initialize bit count */
	int test_bit; /* bit to test, used in loop */

	/* 
	 * Loop through all bits of integer
	 * Assumes 4 byte int
	 */
	for (test_bit = 0x8000; test_bit != 0; test_bit = (test_bit >> 1)) {
		/* Test if bit is set */
		if ((test_bit & integer) != 0)
			++number_of_bits;
	}

	return number_of_bits;
}
