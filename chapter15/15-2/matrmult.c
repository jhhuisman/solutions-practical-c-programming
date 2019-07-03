#include <stdio.h>
#define ROWS 2
#define COLS 2
#define MAX ((ROWS > COLS) ? ROWS : COLS)

int matrix1[ROWS][COLS] = {
	{2, 1},
	{5, 2}
};

int matrix2[ROWS][COLS] = {
	{1, 4},
	{3, 6}
};

void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result_matrix[ROWS][COLS]);
void display_matrix(int matrix[ROWS][COLS]);

int main()
{
	int matrix_multiplied[ROWS][COLS];

	multiply_matrices(matrix1, matrix2, matrix_multiplied);
	display_matrix(matrix_multiplied);

	return 0;
}

/*
 * multiply_matrices -- multiplies two 2 by 2 matrices
 * 	stores result matrix in result_matrix
 *
 * Parameters
 * 	matrix1 -- first matrix to be multiplied
 * 	matrix2 -- second matrix to be multiplied
 * 	result_matrix -- resulting matrix of multiplication
 */
void multiply_matrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result_matrix[ROWS][COLS])
{
	int row_counter, col_counter, times;

	for (row_counter = 0; row_counter < ROWS; ++row_counter) {
		for (col_counter = 0; col_counter < COLS; ++col_counter) {
			result_matrix[row_counter][col_counter] = 0;

			for (times = 0; times < MAX; times++) 
                result_matrix[row_counter][col_counter] += matrix1[row_counter][times] * matrix2[times][col_counter]; 
		}
	}
}

/* 
 * display_matrix -- prints matrix
 *
 * Parameters
 * 	matrix -- matrix to be displayed
 */
void display_matrix(int matrix[ROWS][COLS])
{
	int row_counter, col_counter;

	for (row_counter = 0; row_counter < ROWS; ++row_counter) {
		for (col_counter = 0; col_counter < COLS; ++col_counter) {
			printf("%d ", matrix[row_counter][col_counter]);
		}

		printf("\n");
	}
}
