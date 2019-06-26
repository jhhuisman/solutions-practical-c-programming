#include <stdio.h>

int count_integer_bits(int integer);

int main()
{
	int test_integer = 14; /* test integer to count bits */

	printf("Number of bits set in %d: %d\n", test_integer, count_integer_bits(test_integer));

	return 0;
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
