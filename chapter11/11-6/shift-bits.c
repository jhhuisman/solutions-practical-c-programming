#include <stdio.h>

int left_shift_bits(int number);    /* shifts all its bits to left */
int count_integer_bits(int number); /* count number of bits in integer */

int main()
{
	int number; /* integer number which bits should be left shifted */

	number = 3;

	printf("%d bits left shifted = %d\n", number, left_shift_bits(number));
	printf("%d bits left shifted = %#x\n", number, left_shift_bits(number));

	return 0;
}

/*
 * left_shift_bits -- shift all set bits to the left
 *
 * Important
 * 	Assumes 4 byte int (16 bits)
 *
 * Parameter
 * 	number -- integer which bits should be left shifted
 *
 * Return
 * 	int -- number with bits left shifted
 */
int left_shift_bits(int number)
{
	int bit_count;      /* number of set bits in number */
	int shifted_number; /* number with bits shifted */
	int counter;        /* counter for loop to add the set bits on one side */

	if (number == 0)
		return 0;

	/* Count set bits in number */
	bit_count = count_integer_bits(number);

	/* 
	 * Place first bit on right side
	 * 0000 0000 0000 0001
	 */
	shifted_number = 1;

	/* 
	 * Sets the other bits on the right based on bit_count
	 * For example if bit count is 4, 3 more bits will be added the right side 
	 * 0000 0000 0000 1111
	 */
	for (counter = 0; counter < (bit_count - 1); ++counter) {
		shifted_number = shifted_number << 1;
		shifted_number += 1;
	}

	/* 
	 * Shift the bits to the right side
	 * Total bits of 4 byte int = 16 (4x4)
	 * Shift 16 - bit_count to the left
	 * 1111 0000 0000 0000
	 */
	shifted_number = shifted_number << (16 - bit_count);

	return shifted_number;
}

/*
 * count_teger_bits -- count number of bits in integer
 *
 * Parameter
 * 	number -- integer which set bits should be counted
 *
 * Return
 * 	int -- number of set bits
 */
int count_integer_bits(int number)
{
	int number_of_bits = 0; /* initialize bit count */
	int test_bit; /* bit to test, used in loop */

	/* 
	 * Loop through all bits of integer
	 * Assumes 4 byte int
	 */
	for (test_bit = 0x8000; test_bit != 0; test_bit = (test_bit >> 1)) {
		/* Test if bit is set */
		if ((test_bit & number) != 0)
			++number_of_bits;
	}

	return number_of_bits;
}
