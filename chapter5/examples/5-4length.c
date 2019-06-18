#include <string.h>
#include <stdio.h>

char line[100]; /* Input line */

int main()
{
	printf("Enter a line:\n");
	fgets(line, sizeof(line), stdin);

	printf("The size variable line is: %ld\n", sizeof(line));
	printf("The length of the line is: %ld\n", strlen(line));

	return 0;
}
