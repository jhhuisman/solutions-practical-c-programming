#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *nonwhite(char *string); /* finds first nonwhite character in a string */

int main()
{
	char string[] = "   This is an example string";

	printf("First none white character in the string is: '%c'\n", *nonwhite(string));

	return 0;
}

/*
 * nonwhite -- finds first nonwhite character in a string
 *
 * Argument
 *  string -- string to investigate
 *
 * Return
 *  pointer to first non white character in string
 */
char *nonwhite(char *string)
{
	/* Loop through all string characters */
	while (*string != '\0') {
		/* Check if character is nonwhite */
		if (! isspace(*string))
			/* Return pointer to this first nonwhite character */
			return string;
		++string;
	}

	return string;
}
