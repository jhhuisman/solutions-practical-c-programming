#include <stdio.h>

char line[100]; /* Input line */
int total; /* Total of all numbers so far */
int item; /* Next item tot add */
int minus_items; /* Number of negative items */

int main()
{
	total = 0;
	minus_items = 0;

	while (1) {
		printf("Enter number to add\n");
		printf("or enter 0 to stop: ");

		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &item);

		if (item == 0)
			break;

		if (item < 0) {
			++minus_items;
			continue;
		}

		total += item;

		printf("Total: %d\n", total);
	}

	printf("Final total: %d\n", total);
	printf("%d negative items omitted\n", minus_items);

	return 0;
}
