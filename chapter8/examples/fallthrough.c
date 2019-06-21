#include <stdio.h>

int control;

int main()
{
	control = 0;

	switch (control) {
		case 0:
			printf("Case 0\n");
			/* Fall throught */
		case 1:
			printf("Case 1\n");
			break;
		case 2:
			printf("Case 2\n");
			break;
		default:
			/* Do nothing */
			break;
	}
	

	return 0;
}
