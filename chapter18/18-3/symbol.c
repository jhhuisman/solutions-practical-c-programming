#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symbol {
	char name[30];
	struct symbol *prev;
};

struct symbol *last_symbol_ptr = NULL;

void enter(char *name)
{
	struct symbol *symbol_ptr;
	struct symbol *prev_symbol_ptr;

	/* Allocate dynamic memory */
	symbol_ptr = malloc(sizeof(struct symbol));

	if (symbol_ptr == NULL) {
		fprintf(stderr, "Error: out of memory.");
		exit(8);
	}

	/* Set name */
	strcpy(symbol_ptr->name, name);

	/* Set link to previous element */
	symbol_ptr->prev = last_symbol_ptr;

	/* Set last symbol pointer to this newly created symbol */
	last_symbol_ptr = symbol_ptr;
}

void delete(char *name)
{
	struct symbol *symbol_ptr;
	struct symbol *next_symbol_ptr;

	symbol_ptr = last_symbol_ptr;
	next_symbol_ptr = NULL;

	/* Loop through symbols */
	while (symbol_ptr != NULL) {
		/* Check if symbol is found */
		if (strcmp(symbol_ptr->name, name) == 0) {
			/* Found, adjust prev pointer of following symbol */
			if (next_symbol_ptr != NULL)
				next_symbol_ptr->prev = symbol_ptr->prev;
			
			/* If this symbol is last one in list, then adjust last_symbol_ptr */
			if (symbol_ptr == last_symbol_ptr)
				last_symbol_ptr = last_symbol_ptr->prev;

			/* Delete this pointer */
			free(symbol_ptr);
			symbol_ptr = NULL;

			return;
		}

		next_symbol_ptr = symbol_ptr;
		symbol_ptr = symbol_ptr->prev;
	}
}

int lookup(char *name)
{
	struct symbol *symbol_ptr;

	symbol_ptr = last_symbol_ptr;

	/* Loop through symbols */
	while (symbol_ptr != NULL) {
		/* Check if symbol is found */
		if (strcmp(symbol_ptr->name, name) == 0) {
			return 1;
		}

		symbol_ptr = symbol_ptr->prev;
	}

	return 0;
}
