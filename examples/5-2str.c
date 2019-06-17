#include <string.h>
#include <stdio.h>

char name[30]; /* First name */

int main()
{
	strcpy(name, "Sam");
	printf("The name is %s\n", name);

	return 0;
}
