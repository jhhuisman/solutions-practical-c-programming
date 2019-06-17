#include <string.h>
#include <stdio.h>

char first[100]; /* First name */
char last[100]; /* Last name */
char full_name[200]; /* Full name */

int main()
{
	printf("Enter your first name:\n");
	fgets(first, sizeof(first), stdin);
	/* Trim off last character \n new line character */
	first[strlen(first)-1] = '\0';

	printf("Enter your last name:\n");
	fgets(last, sizeof(last), stdin);
	/* Trim off last character \n new line character */
	last[strlen(last)-1] = '\0';

	strcpy(full_name, first);
	strcat(full_name, " ");
	strcat(full_name, last);

	printf("The name is: %s\n", full_name);

	return 0;
}
