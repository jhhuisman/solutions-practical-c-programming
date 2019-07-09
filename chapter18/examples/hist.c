/********************************************************
 * hist -- Generates a histogram of an array of numbers.*
 * *
 * Usage *
 * hist <file> *
 * *
 * Where *
 * file is the name of the file to work on. *
 ********************************************************/
#include "ia.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
/*
 * Define the number of lines in the histogram
 */
#define NUMBER_OF_LINES 30 /* Number of lines in the histogram */
const int DATA_MIN = 1; /* Number of the smallest item */
const int DATA_MAX = 30; /* Number of the largest item */
/*
 * WARNING: The number of items from DATA_MIN to DATA_MAX (inclusive)
 * must match the number of lines.
 */
/* number of characters wide to make the histogram */
const int WIDTH = 60;
static struct infinite_array data_array;
static int data_items;
int main(int argc, char *argv[])
{
 /* Function to read data */
 void read_data(const char name[]);
 /* Function to print the histogram */
 void print_histogram(void);
 if (argc != 2) {
 fprintf(stderr, "Error:Wrong number of arguments\n");
 fprintf(stderr, "Usage is:\n");

 fprintf(stderr, " hist <data-file>\n");
 exit(8);
 }
 ia_init(&data_array);
 data_items = 0;
 read_data(argv[1]);
 print_histogram();
 return (0);
}
/********************************************************
 * read_data -- Reads data from the input file into *
 * the data_array. *
 * *
 * Parameters *
 * name -- The name of the file to read. *
 ********************************************************/
void read_data(const char name[])
{
 char line[100]; /* line from input file */
 FILE *in_file; /* input file */
 int data; /* data from input */
 in_file = fopen(name, "r");
 if (in_file == NULL) {
 fprintf(stderr, "Error:Unable to open %s\n", name);
 exit(8);
 }
 while (1) {
 if (fgets(line, sizeof(line), in_file) == NULL)
 break;
 if (sscanf(line, "%d", &data) != 1) {
 fprintf(stderr,
 "Error: Input data not integer number\n");
 fprintf(stderr, "Line:%s", line);
 }
 ia_store(&data_array, data_items, data);
 ++data_items;
 }
 fclose(in_file);
}
/********************************************************
 * print_histogram -- Prints the histogram output. *

 ********************************************************/
void print_histogram(void)
{
 /* upper bound for printout */
 int counters[NUMBER_OF_LINES];
 int out_of_range = 0;/* number of items out of bounds */
 int max_count = 0;/* biggest counter */
 float scale; /* scale for outputting dots */
 int index; /* index into the data */
 memset(counters, '\0', sizeof(counters));
 for (index = 0; index < data_items; ++index) {
 int data;/* data for this point */
 data = ia_get(&data_array, index);
 if ((data < DATA_MIN) || (data > DATA_MAX))
 ++out_of_range;
 else {
 ++counters[data - DATA_MIN];
 if (counters[data - DATA_MIN] > max_count)
 max_count = counters[data - DATA_MIN];
 }
 }
 scale = ((float) max_count) / ((float) WIDTH);
 for (index = 0; index < NUMBER_OF_LINES; ++index) {
 /* index for outputting the dots */
 int char_index;
 int number_of_dots; /* number of * to output */
 printf("%2d (%4d): ", index + DATA_MIN, counters[index]);
 number_of_dots = (int) (((float) counters[index]) / scale);
 for (char_index = 0;
 char_index < number_of_dots;
 ++char_index) {
 printf("*");
 }
 printf("\n");
 }

 printf("%d items out of range\n", out_of_range);
}
