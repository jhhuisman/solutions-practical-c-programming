#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YES 1
#define NO 0

void process_file(char filename[]);
void check_words(char line[]);
void replace_word(char word[]);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Missing <filename>.\n");
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	process_file(argv[1]);

	return 0;
}

void process_file(char filename[])
{
	FILE *file_ptr;
	char *line = NULL;
	size_t len = 0;

	file_ptr = fopen(filename, "r");
	
	if (file_ptr == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file_ptr) != -1) {
		check_words(line);
	}

	fclose(file_ptr);
}

void check_words(char line[])
{
	char *word;
	int wcount = 0;

	/* Get first word */
	word = strtok(line, " ");

	/* Loop through words */
	while (word != NULL) {
		if (wcount != 0)
			printf(" ");

		if (strlen(word) == 4)
			replace_word(word);
		else
			printf("%s", word);

		word = strtok(NULL, " ");
		++wcount;
	}
}

void replace_word(char word[])
{
	int index;
	int found;
	int replace_index;

	struct replacement_word {
		char word[5];
		char replacement[50];
	};

	struct replacement_word words[] = {
		{
			"test",
			"trial"
		},
		{
			"some",
			"a few"
		},
		{
			"with",
			"containing"
		}
	};

	found = NO;

	for (index = 0; index < 3; ++index) {
		if (strcmp(word, words[index].word) == 0) {
			found = YES;
			replace_index = index;
			break;
		}
	}

	if (found == YES)
		printf("%s", words[replace_index].replacement);
	else
		printf("%s", word);
}
