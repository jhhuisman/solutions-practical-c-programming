/*
 * Program: rm-high-chars
 *
 * Purpose:
 * 	Copies a file and replaces all characters with the hight bit set
 *
 * Usage:
 * 	rm-high-chars <filename> <new filename>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char src_filename[20];    /* filename source file to be copied */
char dest_filename[20];   /* destination filename */

int main(int argc, char *argv[])
{
	int  ch;          /* character of input file */
	FILE *source_ptr; /* source file pointer */
	FILE *dest_ptr;   /* destination file pointer */

	/* Check for required filename parameter */
	if (argc < 3) {
		fprintf(stderr, "Error: Missing filename\n");
		fprintf(stderr, "Usage: rm-high-chars <filename> <new filename>\n");
		exit(8);
	}

	/* Set filenames variable */
	strcpy(src_filename, argv[1]);
	strcpy(dest_filename, argv[2]);

	/* Open files */
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

		/* Skip characters with high bit set */
		if ((ch & 0x80) != 0)
			continue;

		fputc(ch, dest_ptr);
	}

	fclose(source_ptr);
	fclose(dest_ptr);

	return 0;
}
