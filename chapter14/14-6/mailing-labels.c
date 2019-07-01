/*
 * Program: mailing-labels
 *
 * Purpose:
 * 	Reads .prsn file and produces mailing labels
 *
 * Usage:
 * 	mailing-labels <filename>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char filename[20]; /* filename source file */
int  len_filename; /* length filename */

struct mailing {
	char first_name[30];
	char last_name[30];
	char email[40];
};

int main(int argc, char *argv[])
{
	char extension[5];         /* file extension */
	FILE *file_ptr;            /* pointer to .prsn input file */
	char *line = NULL;         /* current line */
	size_t line_length = 0;    /* length current file line */
	struct mailing subscriber; /* subscriber data to be set by file */

	/* Check for required filename parameter */
	if (argc < 2) {
		fprintf(stderr, "Error: Missing filename\n");
		fprintf(stderr, "Usage: mailing-labels <filename>\n");
		exit(8);
	}
	
	/* Save filename */
	strcpy(filename, argv[1]);
	len_filename = strlen(filename);

	/* Check if file has correct extension .prsn */
	if (len_filename < 5 || (strcmp(&filename[len_filename - 5], ".prsn") != 0)) {
		fprintf(stderr, "Invalid file extension\n");
		exit(8);
	}

	/* Open file */
	file_ptr = fopen(filename, "r");

	if (file_ptr == NULL) {
		fprintf(stderr, "Can not open input file %s\n", filename);
		exit(8);
	}

	while (getline(&line, &line_length, file_ptr) != -1) {
		/* Remove \n from line */
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		/* Extract first name from file */
		if (strncmp(line, "first name:", 11) == 0)
			strcpy(subscriber.first_name, &line[12]);

		/* Extract last name from file */
		if (strncmp(line, "last name:", 10) == 0)
			strcpy(subscriber.last_name, &line[11]);

		/* Extract last name from file */
		if (strncmp(line, "email:", 6) == 0)
			strcpy(subscriber.email, &line[7]);
	}

	printf("* Subscriber added *\n");
	printf("First name: %s\n", subscriber.first_name);
	printf("Last name: %s\n", subscriber.last_name);
	printf("Email: %s\n", subscriber.email);

	return 0;
}
