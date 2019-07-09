#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *printer_file = NULL; /* Pointer to printer file */
char heading_text[200]; /* Heading text */

FILE *open_file(char *name)
{
	printer_file = fopen(name, "r");
	
	if (printer_file == NULL) {
		fprintf(stderr, "Error: could not open file %s\n", name);
		exit(8);
	}

	return printer_file;
}

void define_header(char *heading)
{
	strcpy(heading_text, heading);
}

void print_line(char *line)
{
	printf("%s", line);
}

void page(void)
{
	putchar('\f');
}

int close_file(void)
{
	return fclose(printer_file);
}

void print_page_header(void)
{
	printf("%s\n\n", heading_text);
}
