#include <stdio.h>

char  line[10];          /* input line */
int   number_resistors;  /* number of resistors (user input) */
int   counter_resistors; /* counter resistor value input for loop */
float resistors[100];    /* array with resistor values */
float total_resistance;  /* computed total resistance of parallel resistors */

float calc_resistance(int number_resistors, float *resistors); /* computed total resistance parallel resistors */

int main()
{
	printf("Enter the number of resistors (max 100): ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &number_resistors);

	if (number_resistors < 0 || number_resistors > 100) {
		printf("Error: invalid input\n");
		return 1;
	}

	for (counter_resistors = 0; counter_resistors < number_resistors; ++counter_resistors) {
		printf("Enter the resistance value of resistor %d: ", counter_resistors + 1);
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%f", &resistors[counter_resistors]);
	}

	total_resistance = calc_resistance(number_resistors, resistors);
	printf("Total resistance: %f\n", total_resistance);

	return 0;
}

float calc_resistance(int number_resistors, float *resistors)
{
	int   counter;             /* for counter */
	float resistance_fraction; /* resistance fraction used to calculate total resistance */

	resistance_fraction = 0;

	for (counter = 0; counter < number_resistors; ++counter)
		resistance_fraction += (1.0 / resistors[counter]);

	return 1 / resistance_fraction;
}
