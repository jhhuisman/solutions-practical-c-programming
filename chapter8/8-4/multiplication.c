#include <stdio.h>

int rows;            /* number of rows */
int row_counter;     /* counts current row */
int columns;         /* number of columns */
int columns_counter; /* counts current column */
int current_value;   /* current multiplication value */

int main()
{
	rows = 12;
	columns = 12;

	for (row_counter = 0; row_counter < rows; ++row_counter) {
		for (columns_counter = 0; columns_counter < columns; ++columns_counter) {
			current_value = (row_counter + 1) * (columns_counter + 1);
			printf("%3d ", current_value);
		}

		printf("\n");
	}

	return 0;
}
