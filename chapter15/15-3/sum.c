#include <stdio.h>

int sum(int numbers[], int elements);
int sum_recursive(int numbers[], int elements);

int main()
{
	int numbers[5] = {2, 4, 6, 8, 12};

	printf("Sum of elements is: %d\n", sum(numbers, 5));
	printf("Sum of elements is: %d (recursive function)\n", sum_recursive(numbers, 5));

	return 0;
}

/*
 * sum -- sums elements
 *
 * Parameters
 * 	numbers -- array containing numbers
 * 	elements -- number of elements
 */
int sum(int numbers[], int elements)
{
	int sum = 0;
	int counter;

	for (counter = 0; counter < elements; ++counter)
		sum += numbers[counter];

	return sum;
}

/*
 * sum_recursive -- sums elements
 *
 * Description
 * 	Recursive version for practice an optimization purposes
 *
 * Parameters
 * 	numbers -- array containing numbers
 * 	elements -- number of elements
 */
int sum_recursive(int numbers[], int elements)
{
	if (elements == 0)
		return 0;
	else {
		return numbers[elements - 1] + sum_recursive(numbers, elements-1);
	}
}
