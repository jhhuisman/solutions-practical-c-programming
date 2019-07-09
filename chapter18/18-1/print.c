#include <stdio.h>
#include <stdlib.h>
#include "page.h"

#define MAX_LINES 5 /* Max lines per page */

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	int page_line_count = 0;

	if (argc < 2) {
		fprintf(stderr, "Missing filename.\n");
		fprintf(stderr, "Usage: print <filename>\n");
		exit(8);
	}

	open_file(argv[1]);
	define_header("--- Very important page heading ---");

	while (getline(&line, &len, printer_file) != -1) {
		if (page_line_count == 0)
			print_page_header();

		print_line(line);
		++page_line_count;

		if (page_line_count > MAX_LINES) {
			page();
			page_line_count = 0;
		}
	}

	close_file();

	free(line);
}
