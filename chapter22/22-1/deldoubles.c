#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fileptr;
	char *line;
	size_t len;
	char *word; 
	char *prev_word; 

	line = NULL;
	len = 0;

	fileptr = fopen("input.txt", "r");

	if (fileptr == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, fileptr) != -1) {
		word = strtok(line, " "); 
		prev_word = NULL;

		while (word != NULL) { 
			if (prev_word == NULL)
				printf("%s", word); 
			else if (strcmp(word, prev_word) != 0)
				printf(" %s", word); 

			prev_word = word;
			word = strtok(NULL, " "); 
		} 
	}

	fclose(fileptr);

	return 0;
}
