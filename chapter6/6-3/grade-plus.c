#include <stdio.h>

char line[100]; /* Input line */

int percentage; /* % right */
char grade; /* F-A */
char modifier; /* - + or blank */

int main()
{
	modifier = ' '; /* Default blank modifier */

	printf("Enter percentage right: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &percentage);

	if (percentage >= 0 && percentage <= 60) {
		grade = 'F';
	}
	else if (percentage >= 61 && percentage <= 70) {
		grade = 'D';

		if (percentage >= 61 &&  percentage <= 63) {
			modifier = '-';
		}
		else if (percentage >= 68) {
			modifier = '+';
		}
	}
	else if (percentage >= 71 && percentage <= 80) {
		grade = 'C';

		if (percentage >= 71 &&  percentage <= 73) {
			modifier = '-';
		}
		else if (percentage >= 78) {
			modifier = '+';
		}
	}
	else if (percentage >= 81 && percentage <= 90) {
		grade = 'B';

		if (percentage >= 81 &&  percentage <= 83) {
			modifier = '-';
		}
		else if (percentage >= 88) {
			modifier = '+';
		}
	}
	else if (percentage >= 91 && percentage <= 100) {
		grade = 'A';

		if (percentage >= 91 &&  percentage <= 93) {
			modifier = '-';
		}
		else if (percentage >= 98) {
			modifier = '+';
		}
	}

	printf("Grade: %c%c\n", grade, modifier);

	return 0;
}
