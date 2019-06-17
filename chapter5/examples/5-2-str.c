#include <stdio.h>
#include <string.h>

char name[30]; 

int main()
{
	strcpy(name, "Sam");
	printf("The name is %s\n", name);

	return 0;
}
