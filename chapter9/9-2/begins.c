#include <stdio.h>
#include <string.h>

int begins(char *string1, char *string2);

int main()
{
	char first_input[1000]; /* first input string */
	char second_input[1000]; /* second input string */

	/* prompt and save for first string */
	printf("Enter first string (haystack):\n");
	fgets(first_input, sizeof(first_input), stdin);
	/* remove return line break input last character */
	first_input[strlen(first_input)-1] = '\0';
	
	/* prompt and save for second string */
	printf("Enter second string (needle):\n");
	fgets(second_input, sizeof(second_input), stdin);
	/* remove return line break input last character */
	second_input[strlen(second_input)-1] = '\0';

	if (begins(first_input, second_input) != 0)
		printf("The first string *does* start with the second string\n");
	else
		printf("The first string does *not* start with the second string\n");

	return 0;
}

/*
 * begins -- checks is string1 strarts with string 2
 *
 * Parameters
 * 	string1 -- haystack
 * 	string2 -- needle
 *
 * Returns
 * 	true 1 if string 1 starts with string 2
 */
int begins(char *string1, char *string2)
{
	int counter;

	for (counter = 0; counter < strlen(string2); ++counter) {
		if (string1[counter] != string2[counter])
			return 0;
	}

	return 1;
}
