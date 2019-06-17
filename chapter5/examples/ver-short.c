#include <stdio.h>

signed char ver_short; /* Very short integer */
char line[100];
int temp; /* Temporary number */

int main()
{
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &temp);

	ver_short = temp;
	printf("%d\n", ver_short);

	return 0;
}
