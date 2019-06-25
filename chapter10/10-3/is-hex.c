#include <stdio.h>

#define IS_DIGIT(x) ((x) >= 0 && (x) <= 9)
#define IS_HEX(x) ((IS_DIGIT(x)) || ((x) >= 'a' && (x) <= 'f') || ((x) >= 'A' && (x) <= 'F'))

int main()
{
	if (IS_HEX('B'))
		printf("Argument is a hex digit\n");
	else
		printf("Argument is *not* a hex digit\n");

	return 0;
}
