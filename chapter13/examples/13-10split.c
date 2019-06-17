#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strchar(char *string_ptr, char find) {
	while (*string_ptr != find) {
		/* Check for end */
		if(*string_ptr == '\0')
			return NULL; /* Not found */

		++string_ptr;
	}

	return string_ptr; /* found */
}

int main()
{
	char line[80];
	char *first_ptr;
	char *last_ptr;

	fgets(line, sizeof(line), stdin);

	return 0;
}
