/*
 * Program: count_lines
 *
 * Purpose:
 * 	Counts number of lines in a file
 *
 * Usage: 
 * 	count_lines file
 */

#include <stdio.h>
#include <stdlib.h>

int count_lines(char file_name[]);

int main(int argc, char *argv[])
{
	if (argc == 1) {
		fprintf(stderr, "Missing filename\n");
		fprintf(stderr, "Usage: count_line <filename>\n");
		return 1;
	}

	printf("Line count: %d\n", count_lines(argv[1]));

	return 0;
}

int count_lines(char file_name[])
{
	FILE *in_file; /* file of which to count the lines */

	in_file = fopen(file_name, "r");

	if (in_file == NULL) {
		fprintf(stderr, "Error: unable to open file '%s'\n", file_name);
		exit(8);
	}

	int lines; /* number of lines so far */
	int ch;    /* current character */

	lines = 0;

	for (ch = getc(in_file); ch != EOF; ch = getc(in_file)) {
		if (ch == '\n')
			++lines;
	}

	fclose(in_file);

	return lines;
}
