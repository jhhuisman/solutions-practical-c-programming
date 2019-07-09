#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "search-open.h"

int main()
{
	struct file files[2];
	FILE *file_ptr = NULL;

	strcpy(files[0].filename, "first");
	strcpy(files[1].filename, "example-file.txt");

	file_ptr = search_open(files, 2);

	if (file_ptr == NULL) {
		fprintf(stderr, "Error: Could not open any of the files.\n");
		exit(8);
	}

	/* One of the files is opened at this point, pointer in file_ptr */

	fclose(file_ptr);

	return 0;
}
