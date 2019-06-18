#include <stdio.h>

char  line[100];   /* input line */
int   hours;       /* number of hours worked by employee */
float hourly_wage; /* in dollars */
float weekly_pay;  /* weekly pay based on hours worked and hourly wage */

float get_weekly_pay(int hours, float hourly_wage) {
	int   overtime; /* overtime hours */
	float pay;      /* weekly pay */

	if (hours <= 40) {
		pay = hours * hourly_wage;
	}
	else {
		overtime = hours - 40;
		pay = 40 * hourly_wage;
		pay += overtime * (hourly_wage / 2);
	}

	return pay;
}

int main()
{
	printf("Enter the number of hours worked by employee: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &hours);

	printf("Enter the hourly wage of the employee in dollars: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &hourly_wage);

	printf("The weekly pay is: $%f\n", get_weekly_pay(hours, hourly_wage));

	return 0;
}
