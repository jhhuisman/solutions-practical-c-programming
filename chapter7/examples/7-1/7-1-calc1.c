#include <stdio.h>

char line[100]; /* input line */
int  result;    /* the result of the calculcation */
char operator;  /* calculation operator to be used */
int  value;     /* value to be used with the operator */

int main()
{
	result = 0; /* Initialize result*/

	/* Loop forever (untill force break program) */
	while (1) {
		printf("Result: %d\n", result);

		printf("Enter operator and value: ");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c %d", &operator, &value);

		if (operator == '+') {
			result += value;
		}
		else {
			printf("Incorrect operator %c\n", operator);
		}
	}

	return 0;
}
