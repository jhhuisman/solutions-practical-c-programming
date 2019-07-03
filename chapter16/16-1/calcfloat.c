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
		printf("Result: %s\n", ftos(total, string_total));

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

/* ftos -- converts float to string +0.000E+0 format */
char *ftos(double number, char string[])
{
	char sign;       /* + or - */
	char exponent_sign; /* sign after E + or - */
	int  exponent;   /* based on shift positions */

	sign = '+';       /* default number sign */
	exponent_sign = '+'; /* default shifht sign */
	exponent = 0;     /* default exponent */

	/* Adjustments negative numbers */
	if (number < 0) {
		sign = '-'; /* Set sign minus for negative number */
		number *= -1; /* Conver to positive number */
	}

	string[0] = sign;

	/* 
	 * Shift numbers above 10 to right
	 * 144.4 --> 1.444
	 */
	while (number >= 10) {
		number /= 10;
		++exponent;
	}

	/* 
	 * Shift numbers below 0 to left
	 * 0.8 --> 8.000
	 */
	while (number < 1 && number != 0) {
		number *= 10;
		--exponent;
	}

	if (exponent < 0) {
		exponent_sign = '-';
		exponent *= -1;
	}

	sprintf(&string[1], "%.3fE%c%d", number, exponent_sign, exponent);

	return string;
}
