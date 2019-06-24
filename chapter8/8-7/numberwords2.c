#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[100];       /* input line */
int  total_number;    /* total input number */
int  number;          /* current number */
char number_word[50]; /* number to word string */
int  counter;         /* counter for loop */

char *set_number_word(char *number_word, int number, int total_number);

int main()
{
	printf("Enter a number in the range of 0 - 100: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &total_number);

	if (total_number < 0 || total_number > 100) {
		printf("The input is out of the range 0 - 100.\n");
		return 1;
	}

	for (counter = 0; counter < strlen(line); ++counter) {
		if (! isdigit(line[counter]))
			continue;

		/* digit chracter to integer */
		number = line[counter] - '0';

		/* Add space before number */
		if (counter > 0)
			strcat(number_word, " ");

		set_number_word(number_word, number, total_number);
	}

	printf("%s\n", number_word);

	return 0;
}

char *set_number_word(char *number_word, int number, int total_number)
{
	/* Special cases 11-19 and 100 */
	switch (total_number) {
		case 100:
			strcpy(number_word, "hundred");
			return number_word;
			break;
		case 11:
			strcpy(number_word, "eleven");
			return number_word;
			break;
		case 12:
			strcpy(number_word, "twelve");
			return number_word;
			break;
		case 13:
			strcpy(number_word, "thirteen");
			return number_word;
			break;
		case 14:
			strcpy(number_word, "fourteen");
			return number_word;
			break;
		case 15:
			strcpy(number_word, "fifteen");
			return number_word;
			break;
		case 16:
			strcpy(number_word, "sixteen");
			return number_word;
			break;
		case 17:
			strcpy(number_word, "seventeen");
			return number_word;
			break;
		case 18:
			strcpy(number_word, "eighteen");
			return number_word;
			break;
		case 19:
			strcpy(number_word, "nineteen");
			return number_word;
			break;
	}
	
	switch (number) {
		case 0:
			if (total_number == 0)
				strcat(number_word, "zero");
			break;
		case 1:
			strcat(number_word, "one");
			break;
		case 2:
			if (total_number >= 20 && total_number < 30)
				strcat(number_word, "twenty");
			else 
				strcat(number_word, "two");
			break;
		case 3:
			if (total_number >= 30 && total_number < 40)
				strcat(number_word, "thirty");
			else 
				strcat(number_word, "three");
			break;
		case 4:
			if (total_number >= 40 && total_number < 50)
				strcat(number_word, "fourty");
			else 
				strcat(number_word, "four");
			break;
		case 5:
			if (total_number >= 50 && total_number < 60)
				strcat(number_word, "fivety");
			else 
				strcat(number_word, "five");
			break;
		case 6:
			if (total_number >= 60 && total_number < 70)
				strcat(number_word, "sixty");
			else 
				strcat(number_word, "six");
			break;
		case 7:
			if (total_number >= 70 && total_number < 80)
				strcat(number_word, "seventy");
			else 
				strcat(number_word, "seven");
			break;
		case 8:
			if (total_number >= 80 && total_number < 90)
				strcat(number_word, "eighty");
			else 
				strcat(number_word, "eight");
			break;
		case 9:
			if (total_number >= 90 && total_number < 100)
				strcat(number_word, "ninety");
			else 
				strcat(number_word, "nine");
			break;
	}

	return number_word;
}
