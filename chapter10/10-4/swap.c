#include <stdio.h>

#define SWAP_INTEGERS(a,b) a = a + b; b = a - b; a = a -b;

int main()
{
	int first;  /* first integer */
	int second; /* second integer */

	first =  11; /* initialize two integers */
	second = -3;

	SWAP_INTEGERS(first,second);

	printf("Value of the first integer = %d\n", first);
	printf("Value of the second integer = %d\n", second);

	return 0;
}
