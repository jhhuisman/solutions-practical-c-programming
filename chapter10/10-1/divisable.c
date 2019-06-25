#include <stdio.h>

#define DIVISABLE_BY_10(x) (((x) % 10) == 0)

int main()
{
	if (DIVISABLE_BY_10(20))
		printf("Number is divisable by 10.\n");
	else
		printf("Number is *not* divisable by 10.\n");

	return 0;
}
