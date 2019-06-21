#include <stdio.h>

int horizontal_squares; /* number of horizontal squares */
int vertical_squares;   /* number of vertical squares */
int line_number;        /* current line number */
int counter;            /* counter for loops */
int total_lines;        /* total number of lines for board */

int main()
{
	horizontal_squares = 8;
	vertical_squares = 8;

	/* One square is 4 lines, first square has one extra line on top */
	total_lines = vertical_squares * 4 + 1;

	for (line_number = 0; line_number < total_lines; ++line_number) {
		if (line_number == 0 || line_number%4 == 0) {
			for (counter = 0; counter < horizontal_squares; ++counter)
				printf("+-----");

			printf("+\n");
		}
		else {
			for (counter = 0; counter < horizontal_squares; ++counter)
				printf("|     ");

			printf("|\n");
		}
	}

	return 0;
}
