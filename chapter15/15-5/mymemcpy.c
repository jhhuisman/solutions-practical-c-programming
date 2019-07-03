#include <stdio.h>

void *mymemcpy(void *dest, const void *src, size_t n_bytes);

int main()
{
	char source[] = "Source text";
	char destination[100];

	mymemcpy(destination, source, (sizeof(source) / sizeof(source[0])));

	printf("Result: %s\n", destination);

	return 0;
}

void *mymemcpy(void *dest, const void *src, size_t n_bytes)
{
	/* Typecast src and dest to char (1 byte) */
	char *cdest = (char *)dest;
	char *csrc = (char *)src;

	int counter;

	for (counter = 0; counter < n_bytes; ++counter) {
		cdest[counter] = csrc[counter];
	}

	return cdest;
}
