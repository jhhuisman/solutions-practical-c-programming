#include <stdio.h>
#include <ctype.h>

char         line[100]; /* input line */
int          number;    /* input number */
unsigned int positives; /* count positives */
unsigned int negatives; /* count negatives */

int main()
{
	positives = 0; /* initialize counts */
	negatives = 0;

	printf("Enter a series of numbers, press q when you are done.\n");

	while (1) {
		number = 0; /* intialize and reset number */

		fgets(line, sizeof(line), stdin);

		if (line[0] == 'q' || line[0] == 'Q')
			break; /* q skips to results */

		sscanf(line, "%d", &number);

		if (number > 0)
			++positives;
		else if (number < 0)
			++negatives;
	}

	printf("\nResult:\n");
	printf("%u positive number(s)\n", positives);
	printf("%u negative number(s)\n", negatives);

	return 0;
}
