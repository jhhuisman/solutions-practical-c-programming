#include <stdio.h>

char line[100]; /* input line */

int   number;  /* current number */
int   total;   /* total of numbers combined so far */
float average; /* average number */

int counter;        /* counter for loop */
int amount_numbers; /* amount of numbers entered */

int main()
{
	number = 0; /* initialize variables */
	total = 0;
	average = 0;

	printf("Enter the numbers, one number each line.\n");
	printf("Press q to quit.\n");

	while (1) {
		fgets(line, sizeof(line), stdin);

		if (line[0] == 'q' || line[0] == 'Q')
			break;
			
		sscanf(line, "%d", &number);
		total += number;

		++amount_numbers;
	}

	average = (float)total / amount_numbers;

	printf("Average: %.2f\n", average);

	return 0;
}
