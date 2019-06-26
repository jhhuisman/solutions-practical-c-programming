#include <stdio.h>

#define X_SIZE 16 /* size of array in X direction */
#define Y_SIZE 16 /* size of array in Y direction */

/* We use X_SIZE/8 because we pack 8 bits per byte */
char graphics[X_SIZE / 8][Y_SIZE]; /* the graphics data */

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >> ((x)%8))

void set_square(void); /* sets bits for 10x10 square */

int main()
{
	int  loc;                  /* current location we are setting */
	void print_graphics(void); /* print the data */

	set_square();
	print_graphics();

	return 0;
}

/*
 * mark_square -- sets bits for 10x10 square
 *
 * Return
 * 	pointer graphics array
 */
void set_square(void)
{
	int square_width;
	int square_height;
	int y_counter; /* counter for vertical rows */
	int x_counter; /* counter for horizontal columns */

	square_width = 10;
	square_height = 10;

	/* Loop through all vertical rows */
	for (y_counter = 0; y_counter < square_height; ++y_counter) {
		/* Loop through all horizontal columns of grid */
		for (x_counter = 0; x_counter < square_width; ++x_counter) {
			/* For first and last row mark all column grid cells */
			if (y_counter == 0 || y_counter == (square_height - 1))
				SET_BIT(x_counter, y_counter);
			/* For rows in between, mark first and last column grid cells */
			else {
				SET_BIT(0, y_counter);
				SET_BIT((square_width - 1), y_counter);
			}
		}
	}
}

/* print_graphics -- Prints the graphics bit array as a set of X and .'s */
void print_graphics(void)
{
	int          x;   /* current x BYTE */
	int          y;   /* current y location */
	unsigned int bit; /* bit we are testing in the current byte */

	for (y = 0; y < Y_SIZE; ++y) {
		/* Loop for each byte in the array */
		for (x = 0; x < X_SIZE / 8; ++x) {
			/* Handle each bit */
			for (bit = 0x80; bit > 0; bit = (bit >> 1)) {
				if ((graphics[x][y] & bit) != 0)
					printf("X");
				else
					printf(".");
			}
		}

		printf("\n");
	}
}
