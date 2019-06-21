#include <stdio.h>
#include <ctype.h>

char line[100]; /* input line */
char character; /* input character to check */

int isvowel(char character);

int main()
{
	printf("Enter a character: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%c", &character);

	/* To lower case so it is easier to check */
	character = tolower(character);

	if (! isalpha(character)) {
		printf("%c is not an alphabetic character.\n", character);
		return 1;
	}

	if (isvowel(character))
		printf("%c is a vowel.\n", character);
	else
		printf("%c is *not* a vowel.\n", character);

	return 0;
}

int isvowel(char character)
{
	switch (character) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;
			break;
		default:
			return 0;
	}
}
