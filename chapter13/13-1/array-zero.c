#include <stdio.h>

#define MAX_NUMBERS 5

int main()
{
	int numbers[MAX_NUMBERS] = {2, 4, 5, 6, 8};
	int *numbers_ptr; /* pointer to numbers array */

	for (numbers_ptr = &numbers[0]; numbers_ptr < &numbers[MAX_NUMBERS]; ++numbers_ptr) {
		*numbers_ptr = 0;
	}

	int counter;

	for (counter = 0; counter < MAX_NUMBERS; ++counter) {
		printf("numbers[%d] = %d\n", counter, numbers[counter]);
	}

	return 0;
}
