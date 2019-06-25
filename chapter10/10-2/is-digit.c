#include <stdio.h>

#define IS_DIGIT(x) ((x) >= 0 && (x) <= 9)

int main()
{
	if (IS_DIGIT(9))
		printf("Argument is a decimal digit\n");
	else
		printf("Argument is *not* a decimal digit\n");

	return 0;
}
