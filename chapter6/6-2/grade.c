#include <stdio.h>

char line[100]; /* Input line */

int percentage; /* % right */
char grade; /* F-A */

int main()
{
	printf("Enter percentage right: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &percentage);

	if (percentage >= 0 && percentage <= 60) {
		grade = 'F';
	}
	else if (percentage >= 61 && percentage <= 70) {
		grade = 'D';
	}
	else if (percentage >= 71 && percentage <= 80) {
		grade = 'C';
	}
	else if (percentage >= 81 && percentage <= 90) {
		grade = 'B';
	}
	else if (percentage >= 91 && percentage <= 100) {
		grade = 'A';
	}

	printf("Grade: %c\n", grade);

	return 0;
}
