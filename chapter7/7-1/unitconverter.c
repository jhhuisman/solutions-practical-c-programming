#include <stdio.h>
#include <string.h>

char  line[100];        /* input line */
char  abbreviation[4];  /* unit type abbreviation */
float number;           /* input number to convert */
char  metric[4];           /* Corresponsing metric abbreviation */
float converted_number; /* converted number to corresponding metric */

int main()
{
	printf("Valid unit types:\n");	
	printf("ft  (foot)\n");	
	printf("mi  (miles)\n");	
	printf("lb  (pounds)\n");	
	printf("gal (gallon)\n");	
	printf("F   (Fahrenheit)\n\n");	

	printf("Enter the unit type abbreviation and number: ");	
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%s %f", abbreviation, &number);

	if (strcmp(abbreviation, "ft") == 0) {
		strcpy(metric, "m");
		converted_number = number / 3.28;
	} else if (strcmp(abbreviation, "mi") == 0) {
		strcpy(metric, "km");
		converted_number = number * 1.609344;
	} else if (strcmp(abbreviation, "lb") == 0) {
		strcpy(metric, "kg");
		converted_number = number * 0.45359237;
	} else if (strcmp(abbreviation, "gal") == 0) {
		strcpy(metric, "ltr");
		converted_number = number * 3.78541178;
	} else if (strcmp(abbreviation, "F") == 0) {
		strcpy(metric, "C");
		converted_number = (number - 32) / 1.8;
	} else {
		printf("Invalid unit type abbreviation.\n");
		return 1;
	}

	/* Displays for example 1.829268 m */
	printf("%f %s\n", converted_number, metric);

	return 0;
}
