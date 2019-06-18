#include <stdio.h>

char line[100]; /* input line */

float money; /* amount of money */
float remaining_money; /* amount of remaining money to be devided by coins */

int quarters = 0; /* number of quarters */
int dimes = 0; /* number of dimes */
int nickels = 0; /* number of nickels */
int pennies = 0; /* number of pennies */

int main()
{
	printf("Enter the amount of money (less than $1.00)\n");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &money);

	remaining_money = money;

	while (remaining_money >= 0.01) {
		if (remaining_money >= 0.25) {
			++quarters;
			remaining_money -= 0.25;
		}
		else if (remaining_money >= 0.10) {
			++dimes;
			remaining_money -= 0.10;
		}
		else if (remaining_money >= 0.05) {
			++nickels;
			remaining_money -= 0.05;
		}
		else {
			++pennies;
			remaining_money -= 0.01;
		}
	}

	printf("For $%f you need: \n", money);
	printf("%d quarters\n", quarters);
	printf("%d dimes\n", dimes);
	printf("%d nickels\n", nickels);
	printf("%d pennies\n", pennies);

	return 0;
}
