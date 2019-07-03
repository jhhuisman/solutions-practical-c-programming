#include <stdio.h>
#include <string.h>

double calc(char operator, double number, double total);
char *ftos(double number, char string[]);

int main()
{
	char   line[100];        /* input line */
	double total;            /* current total */
	char   string_total[10]; /* total converted to +0.000E+0 format string */
	char   operator;         /* a + - * */
	double number;           /* number to use in calculation */

	total = 0.0; 

	while (1) {
		printf("Result: %09.4f\n", total); /* 0001.500 format */

		printf("Enter a operator and number (or q to quit): ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c %lf", &operator, &number);

		if (operator == 'q' || operator == 'Q')
			break;

		total = calc(operator, number, total);
	}

	return 0;
}

double calc(char operator, double number, double total)
{
	switch (operator) {
		case '+':
			total += number;
			break;
		case '-':
			total -= number;
			break;
		case '*':
			total *= number;
			break;
		case '/':
			total /= number;
			break;
		default:
			fprintf(stderr, "Invalid operator %c\n", operator);
			break;
	}

	return total;
}
