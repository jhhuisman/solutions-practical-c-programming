#include <stdio.h>
#include <string.h>

char *replace_hyphens(char *string);

int main()
{
	char string[] = "test-string-test";

	printf("%s\n", replace_hyphens(string));

	return 0;
}

/*
 * replace_hyphens -- replace hyphen '-' by underscore '_'
 *
 * Parameters
 * 	string -- string to scan for hyphens
 *
 * Return
 * 	returns pointer to (replaced) string
 */
char *replace_hyphens(char *string)
{
	int counter;

	for (counter = 0; counter < strlen(string); ++counter) {
		if (string[counter] == '-')
			string[counter] = '_';
	}

	return string;
}
