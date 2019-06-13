/* https://www.tutorialspoint.com/learn_c_by_examples/compare_two_integers_in_c.htm */
#include <stdio.h>

int main()
{
	int a, b;

	printf("Enter value for a: ");
	scanf("%d", &a);
	printf("Enter value for b: ");
	scanf("%d", &b);

	if (a > b)
		printf("a is greater than b\n");
	else
		printf("a is not greater than b\n");

	return 0;
}
