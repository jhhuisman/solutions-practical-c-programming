#include <stdio.h>

int  number;   /* number we are converting */
char  type;     /* type of conversion to do */
char line[80]; /* input line */

int main()
{
	while (1) {
		printf("Enter conversion and number: ");

		fgets(line, sizeof(line), stdin);
		sscanf(line, "%c", &type);

		if (type == 'q' || type == 'Q')
			break;

		switch (type) {
			case 'o':
			case 'O': /* octal conversion */
				sscanf(line, "%c %o", &type, &number);
				break;
			case 'x':
			case 'X': /* hexadecimal */
				sscanf(line, "%c %x", &type, &number);
				break;
			case 'd':
			case 'D': /* decimal */
				sscanf(line, "%c %d", &type, &number);
				break;
			default:
				printf("Invalid input\n");
				/* Don't display result */
				continue;
		}

		printf("Result: %d\n", number);
	}

	return 0;
}
