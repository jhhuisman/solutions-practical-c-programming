#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_LIMIT 100

void process_file(char *file_name);
void split_line(char line[], size_t len);

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Missing filename.\n");
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
	}

	process_file(argv[1]);

	return 0;
}

void process_file(char *filename)
{
	FILE *file_ptr;
	char *line = NULL;
	size_t len = 0;
	ssize_t n_read;

	file_ptr = fopen(filename, "r");

	if (file_ptr == NULL) {
		perror("Error");
		exit(EXIT_FAILURE);
	}

	while ((n_read = getline(&line, &len, file_ptr)) != -1) {
		if (n_read > CHAR_LIMIT)
			split_line(line, n_read);
		else
			printf("%s", line);
	}

	fclose(file_ptr);
}

void split_line(char line[], size_t len)
{
	int index;
	int last_index;
	int split_point_index;

	last_index = CHAR_LIMIT - 1;

	while (last_index < len) {
		split_point_index = 0;

		for (index = last_index; index > split_point_index; --index) {
			if (line[index] == '.') {
				split_point_index = index + 1;
				break;
			}
			else if (line[index] == ' ' && split_point_index == 0)
				split_point_index = index;
		}

		line[split_point_index] = '\n';
		last_index = split_point_index + CHAR_LIMIT;
	}

	printf("%s", line);
}
