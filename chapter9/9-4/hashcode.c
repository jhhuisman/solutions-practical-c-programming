#include <stdio.h>
#include <string.h>

int stringtotal(char *string); /* gives sum of character values */
void printhex(int number); /* prints hex code of number */

int main()
{
	char string[] = "AA";

	printhex(stringtotal(string));

	return 0;
}

/*
 * stringtotal -- gives sum of character values
 *
 * Description
 * 	Takes a character array and adds up values
 *
 * Parameter
 * 	string -- character array
 *
 * Return
 * 	Returns int sum of character values
 */
int stringtotal(char *string)
{
	int counter;
	int total = 0; /* total of all characters */

	for (counter = 0; counter < strlen(string); ++counter) {
		total += string[counter];
	}

	return total;
}

/* 
 * printhex -- prints hex code of number
 *
 * Paramter
 * 	number -- number to convert to hex
 */
void printhex(int number)
{
	printf("%#x\n", number);
}
