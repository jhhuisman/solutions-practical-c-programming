#include <string.h>
#include <stdio.h>

char first[100]; /* First name */
char last[100]; /* Last name */
char full_name[200]; /* Full name */

int main()
{
	strcpy(first, "Steve");
	strcpy(last, "Oualline");

	strcpy(full_name, first);
	strcat(full_name, " ");
	strcat(full_name, last);

	printf("Full name is: %s\n", full_name);

	return 0;
}
