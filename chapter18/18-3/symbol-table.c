#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

int main()
{
	struct symbol *symbol_ptr;

	enter("one");
	enter("two");
	enter("three");
	enter("four");
	enter("five");
	enter("six");

	delete("six");
	delete("four");

	symbol_ptr = last_symbol_ptr;

	/* Loop through symbols and display them */
	while (symbol_ptr != NULL) {
		printf("%s\n", symbol_ptr->name);
		symbol_ptr = symbol_ptr->prev;
	}

	return 0;
}
