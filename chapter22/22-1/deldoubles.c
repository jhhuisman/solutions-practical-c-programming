#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fileptr;
	char *line;
	size_t len;
	char *token; 
	char *prev_token; 

	line = NULL;
	len = 0;

	fileptr = fopen("input.txt", "r");

	if (fileptr == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, fileptr) != -1) {
		token = strtok(line, " "); 
		prev_token = NULL;

		while (token != NULL) { 
			if (prev_token == NULL)
				printf("%s", token); 
			else if (strcmp(token, prev_token) != 0)
				printf(" %s", token); 

			prev_token = token;
			token = strtok(NULL, " "); 
		} 
	}

	fclose(fileptr);

	return 0;
}
