#include <stdio.h>
#include <string.h>

char first[100];
char last[100];
char full[200];

int main()
{
	printf("Enter first name: ");
	fgets(first, sizeof(first), stdin);

	/* Remove line break character (second to last character) */
	first[strlen(first)-1] = '\0';

	printf("Enter last name: ");
	fgets(last, sizeof(last), stdin);

	/* Remove line break character (second to last character) */
	last[strlen(last)-1] = '\0';

	strcpy(full, first);
	strcat(full, " ");
	strcat(full, last);

	printf("Full name: %s\n", full);

	return 0;
}
