#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_words(char *string); /* Counts words in string */

int main()
{
	char line[1000]; /* input line */

	/* Prompt for input string to be used and save the input */
	printf("Enter string:\n");
	fgets(line, sizeof(line), stdin);

	/* Remove input return line break from end of string */
	line[strlen(line)-1] = '\0';

	/* Display result */
	printf("String contains %d words\n", count_words(line));

	return 0;
}

/*
 * count_words -- Counts the number of words in a string
 *
 * Definition of a word
 *  contiguous characters separated by white space
 *
 * Parameters
 * 	string -- string with words to count
 * 	
 * Returns
 * 	number of words
 */
int count_words(char *string)
{
	int word_count;              /* current word count */
	int counter;                 /* counter for looping through characters */
	int contains_word_character; /* contains non white space characters */

	word_count =              1; /* initialize word count */
	contains_word_character = 0; /* defaults to false, checks for true in loop */

	for (counter = 0; counter < strlen(string); ++counter) {
		if (isspace(string[counter])) {
			/* Don't count double spaces as double words */
			if (! isspace(string[counter - 1]))
				++word_count;
		}
		else
			contains_word_character = 1;
	}

	/* Return 0 if string contains no word characters (non white space) */
	if (contains_word_character == 0)
		word_count = 0;
	
	return word_count;
}
