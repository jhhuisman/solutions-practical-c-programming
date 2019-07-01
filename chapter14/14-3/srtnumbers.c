/*
 * Program: srtnumbers
 *
 * Purpose:
 * 	Reads a file containing a list of numbers and sorts the numbers.
 * 	Writes two files:
 * 	- divisible.txt: containing all numbers divisisible by 3
 * 	- others.txt: containg all other number
 *
 * Usage:
 * 	srtnumbers <filename>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename[20]; /* filename source file with numbers */

int main(int argc, char *argv[])
{
	int  number;         /* current number to evaluate */
	FILE *file_ptr;      /* pointer to file with numbers */
	FILE *divisible_ptr; /* pointer to created file containing numbers divisible by 3 */
	FILE *others_ptr;    /* pointer to created file containing other remaining numbers */
	char *line = NULL;   /* current line of file */
	size_t  len = 0;     /* current line length */

	/* Check for required filename parameter */
	if (argc < 2) {
		fprintf(stderr, "Error: Missing filename\n");
		fprintf(stderr, "Usage: srtnumbers <filename>\n");
		exit(8);
	}

	/* Set filename variable */
	strcpy(filename, argv[1]);

	/* Open files */
	file_ptr = fopen(filename, "r");
	divisible_ptr = fopen("divisible.txt", "w");
	others_ptr = fopen("others.txt", "w");

	/* Check if files have been openen */
	if (file_ptr == NULL) {
		printf("Can not open file: %s\n", filename);
		exit(8);
	}

	if (divisible_ptr == NULL) {
		printf("Can not create file divisible.txt\n");
		exit(8);
	}

	if (others_ptr == NULL) {
		printf("Can not create file others.txt\n");
		exit(8);
	}

	/* Loop through lines of file */
	while (getline(&line, &len, file_ptr) != -1) {
		/* Extract number from line */
		sscanf(line, "%d", &number);

		/* Check if number is divisible by 3 and place result in correct file */
		if ((number % 3) == 0)
			fprintf(divisible_ptr, "%d\n", number);
		else
			fprintf(others_ptr, "%d\n", number);
	}

	/* Free allocated memory */
	free(line);

	/* Close all files */
	fclose(file_ptr);
	fclose(divisible_ptr);
	fclose(others_ptr);

	return 0;
}
