#include <stdio.h>

char line[100]; /* input line */
int  result;    /* the result of the calculcation */
char operator;  /* calculation operator to be used */
int  value;     /* value to be used with the operator */

int main()
{
	result = 0; /* Initialize result*/

	/* Loop until q/Q entered or force quit */
	while (1) {
		printf("Result: %d\n", result);

		printf("Enter operator and value: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c %d", &operator, &value);

		if (operator == 'q' || operator == 'Q')
			break;

		if (operator == '+')
			result += value;
		else if (operator == '-')
			result -= value;
		else if (operator == '*')
			result *= value;
		else if (operator == '/')
			result /= value;
		else
			printf("Incorrect operator %c\n", operator);
	}

	return 0;
}
