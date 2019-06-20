#include <stdio.h>
#include <string.h>
#include <ctype.h>

char  line[100]; /* input line */
float amount;    /* entered amount */
float tax;       /* calculated 8% sales tax */
float total;     /* total amount including 8% sales tax */

int validate_input_amount(char *amount);

int main()
{
	do {
		printf("Enter the amount in dollars: ");
		fgets(line, sizeof(line), stdin);
	} while (! validate_input_amount(line));

	sscanf(line, "%f", &amount);

	tax = amount * 0.08;
	total = amount + tax;

	printf("The sales tax is $ %.2f\n", tax);
	printf("The total amount with tax is $ %.2f\n", total);

	return 0;
}

int validate_input_amount(char *input)
{
	int index; /* used to increase index in for loop */

	if(strlen(input) == 1) /* just enter/return, no number */
		return 0;

	for (index = 0; index < (strlen(input) - 1); ++index) {
		if (! isdigit(input[index]) && '.' != input[index]) {
			printf("Invalid input character: %c\n", input[index]);
			return 0;
		}
	}

	return 1;
}
