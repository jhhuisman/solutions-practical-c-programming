/*
 * Program: copy-with-spaces
 *
 * Purpose:
 * 	Copies a file and replaces all tabs by multiple spaces
 *
 * Usage:
 * 	copy-with-spaces [options] <filename> <new filename>
 *
 * Options
 *  -s<spaces> 	sets number of spaces
 *  			(default=4)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE (16 * 1024) /* 16K buffer */

char src_filename[20];    /* filename source file to be copied */
char dest_filename[20];   /* destination filename */
int  spaces = 4;          /* number of spaces for tab replacement, default 4 */

void usage(void);

int main(int argc, char *argv[])
{
	int  ch;            /* character of input file */
	int  space_counter; /* used in for loop to replace tab by correct number of spaces */
	FILE *source_ptr;   /* source file pointer */
	FILE *dest_ptr;     /* destination file pointer */

	/* Process optional -s option */
	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 's') {
		/* Save given spaces value */
		sscanf(&(argv[1][2]), "%d", &spaces);

		/* 
		 * Process option
		 * 1) move argument list up one
		 * 2) move argument count down one
		 */
		++argv;
		--argc;
	}

	/* Check for required filename parameters */
	if (argc < 3) {
		fprintf(stderr, "Error: Missing filename(s)\n");
		usage();
		exit(8);
	}

	/* 
	 * Syntax okay
	 * Set source and destination
	 */
	strcpy(src_filename, argv[1]);
	strcpy(dest_filename, argv[2]);

	source_ptr = fopen(src_filename, "r");
	dest_ptr = fopen(dest_filename, "w");

	if (source_ptr == NULL) {
		fprintf(stderr, "Can not open source file %s\n", src_filename);
		exit(8);
	}

	if (dest_ptr == NULL) {
		fprintf(stderr, "Can not open destination file %s\n", dest_filename);
		exit(8);
	}

	/* Loop through file characters one by one */
	while (1) {
		ch = fgetc(source_ptr);

		if (ch == EOF)
			break;

		/* Check if character is tab */
		if (ch == '\t') {
			/* Replace tab by spaces */
			for (space_counter = 0; space_counter < spaces; ++space_counter) {
				/* Put space inf ile */
				fputc(' ', dest_ptr);
			}
		}
		else  {
			/* Write character to file */
			fputc(ch, dest_ptr);
		}
	}

	fclose(source_ptr);
	fclose(dest_ptr);

	return 0;
}

void usage(void)
{
	fprintf(stderr, "Usage: copy-with-spaces [options] <filename> <new filename>\n");
	fprintf(stderr, "Options\n");
	fprintf(stderr, " 	-s<spaces> 	set number of spaces\n");
}
