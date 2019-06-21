#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[100];       /* input line */
int  number;          /* current number */
char number_word[50]; /* number to word string */
int  counter;         /* counter for loop */

char *set_number_word(char *number_word, int number);

int main()
{
	fgets(line, sizeof(line), stdin);

	for (counter = 0; counter < strlen(line); ++counter) {
		if (! isdigit(line[counter]))
			continue;

		/* reset value to avoid using previous numer word */
		strcpy(number_word, "");

		/* digit chracter to integer */
		number = line[counter] - '0';
		set_number_word(number_word, number);

		printf("%s ", number_word);
	}

	printf("\n");

	return 0;
}

char *set_number_word(char *number_word, int number)
{
	switch (number) {
		case 1:
			strcpy(number_word, "one");
			break;
		case 2:
			strcpy(number_word, "two");
			break;
		case 3:
			strcpy(number_word, "three");
			break;
		case 4:
			strcpy(number_word, "four");
			break;
		case 5:
			strcpy(number_word, "five");
			break;
		case 6:
			strcpy(number_word, "six");
			break;
		case 7:
			strcpy(number_word, "seven");
			break;
		case 8:
			strcpy(number_word, "eight");
			break;
		case 9:
			strcpy(number_word, "nine");
			break;
	}

	return number_word;
}
