#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subscriber {
	char first_name[100];
	char last_name[100];
	char email[100];
};

struct subscriber list[100];

int cmpfunc(const void *p1, const void *p2);
void labels_clear(void);
void labels_write(char filename[]);
int labels_read(void);
void labels_sort(int labels_count);
void labels_print(int label_count);

int main(int argc, char *argv[])
{
	int labels_count;

	if (argc < 2) {
		fprintf(stderr, "Missing filename(s).\n");
		fprintf(stderr, "Usage: %s <filename> (<filename2> <filename3>)\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	labels_clear();

	while (argc > 1) {
		labels_write(argv[1]);

		++argv;
		--argc;
	}

	labels_count = labels_read();
	labels_sort(labels_count);
	labels_print(labels_count);
	
	return 0;
}

/* Clears/erases labels file content by opening the file in read mode */
void labels_clear(void)
{
	FILE *file_ptr;

	file_ptr = fopen("labels.txt", "w");

	if (file_ptr == NULL) {
		fprintf(stderr, "Error: could not open labels file: labels.txt\n");
		exit(EXIT_FAILURE);
	}

	fclose(file_ptr);
}

void labels_write(char filename[])
{
	FILE *in_file_ptr;
	FILE *out_file_ptr;
	char *line = NULL;
	size_t len = 0;

	in_file_ptr = fopen(filename, "r");

	if (in_file_ptr == NULL) {
		fprintf(stderr, "Error: could not open input file: %s\n", filename);
		exit(EXIT_FAILURE);
	}

	out_file_ptr = fopen("labels.txt", "a");

	if (out_file_ptr == NULL) {
		fprintf(stderr, "Error: could not open output file: labels.txt\n");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, in_file_ptr) != -1) {
		fprintf(out_file_ptr, "%s", line);
	}

	/* Extra white line to seperate labels and improve readability */
	fprintf(out_file_ptr, "\n");

	fclose(in_file_ptr);
	fclose(out_file_ptr);
}

int labels_read(void)
{
	FILE *file_ptr;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	file_ptr = fopen("labels.txt", "r");

	if (file_ptr == NULL) {
		fprintf(stderr, "Error: could not open labels file: labels.txt\n");
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file_ptr) != -1) {
		if (strncmp(line, "first name: ", 12) == 0) {
			strcpy(list[counter].first_name, &line[12]);

			/* Remove last line break character \n */
			list[counter].first_name[strlen(list[counter].first_name) - 1] = '\0';
		}
		else if (strncmp(line, "last name: ", 11) == 0) {
			strcpy(list[counter].last_name, &line[11]);

			/* Remove last line break character \n */
			list[counter].last_name[strlen(list[counter].last_name) - 1] = '\0';
		}
		else if (strncmp(line, "email: ", 7) == 0) {
			strcpy(list[counter].email, &line[7]);

			/* Remove last line break character \n */
			list[counter].email[strlen(list[counter].email) - 1] = '\0';

			++counter;
		}
	}

	fclose(file_ptr);

	return counter;
}

void labels_sort(int labels_count)
{
	qsort(list, labels_count, sizeof(struct subscriber), cmpfunc);
}

void labels_print(int labels_count)
{
	int counter;

	for (counter = 0; counter < labels_count; ++counter) {
		printf("Last name: %s\n", list[counter].last_name);
		printf("First name: %s\n", list[counter].first_name);
		printf("Email: %s\n", list[counter].email);

		/* Extra white line to seperate labels and improve readability */
		if ((counter + 1) != labels_count)
			printf("\n");
	}
}

int cmpfunc(const void *p1, const void *p2)
{
	const struct subscriber *subscriber1 = p1;
	const struct subscriber *subscriber2 = p2;

	return strcmp(subscriber1->last_name, subscriber2->last_name);
}
