#include <stdio.h>

struct file {
	char filename[50];
};

FILE *search_open(struct file files[], int number_files)
{
	FILE *search_file = NULL;
	int counter;

	for (counter = 0; counter < number_files; ++counter) {
		search_file = fopen(files[counter].filename, "r");

		if (search_file != NULL)
			return search_file;
	}

	return NULL;
}
