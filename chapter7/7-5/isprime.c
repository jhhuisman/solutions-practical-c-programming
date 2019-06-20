#include <stdio.h>

char line[100]; /* input line */
unsigned int number; /* input number */

/* https://stackoverflow.com/a/5281794/2915422 */
int is_prime(int num);

int main()
{
	printf("Enter a number: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%u", &number);

	if (is_prime(number))
		printf("%u is a prime number.\n", number);
	else
		printf("%u is *not* a prime number.\n", number);

	return 0;
}

/* https://stackoverflow.com/a/5281794/2915422 */
int is_prime(int num)
{
     if (num <= 1) return 0;
     if (num % 2 == 0 && num > 2) return 0;
     for(int i = 3; i < num / 2; i+= 2)
     {
         if (num % i == 0)
             return 0;
     }
     return 1;
}
