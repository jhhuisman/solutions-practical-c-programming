#include <stdio.h>

int count_lines(char file_name[]);

int main()
{
	printf("Line count: %d\n", count_lines("dummy.txt"));

	return 0;
}

int count_lines(char file_name[])
{
	FILE *in_file; /* file of which to count the lines */
	int  lines;    /* number of lines so far */
	int  ch;       /* current character */

	in_file = fopen(file_name, "r");
	lines = 0;

	for (ch = getc(in_file); ch != EOF; ch = getc(in_file)) {
		if (ch == '\n')
			++lines;
	}

	fclose(in_file);

	return lines;
}
