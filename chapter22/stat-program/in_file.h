/* 
 * input_file -- Data from the input file
 *
 * The current two characters are stored in cur_Char and next_char
 * Lines are buffered so that they can be output to the screen after a line is assembled.
 *
 * Functions:
 * 	in_open -- Opens the input file.
 * 	in_close -- Closes the input file.
 * 	read_char -- Reads the next character.
 * 	in_cur_char -- Returns the current character.
 * 	in next_char -- Returns the next character.
 * 	in_flush -- Sends line to the screen
 */

/*
 * in_open -- Opens the input file.
 *
 * Parameters
 * 	name -- Name of disk file to use for input.
 *
 * Returns 
 * 	0 -- Open succeded.
 * 	nonzero -- Open failed.
 */
extern int in_open(const char name[]);

/*
 * in_close -- Closes the input file.
 */
extern void in_close(void);

/*
 * in_read_char -- Read the next character from the input file.
 */
extern void in_read_char(void);

/*
 * in_cur_char -- Gets the current input character.
 *
 * Returns
 * 	current character.
 */
extern int in_cur_char(void);

/*
 * in_next_char -- Peeks ahead one character.
 *
 * Returns
 * 	next character.
 */
extern int in_next_char(void);

/*
 * in_flush -- Flushes the buffered input line to the screen.
 */
extern void in_flush(void);
