/*
 * ch_type package
 *
 * This module is used to determine the type of various characters.
 *
 * Public functions:
 * 	init_char_type -- Initializes the table.
 * 	is_char_type -- Is a character of a given type?
 * 	get_char_type -- Given char, return type.
 */
#include <stdio.h>

#include "ch_type.h"

/* Define the type information array */
static enum CHAR_TYPE type_info[256];
static int ch_setup = 0; /* True of character type info setup */

/*
 * fill_range -- Fills in a range of types for the character type class.
 *
 * Parameters
 * 	start, end -- Range of items to fill in.
 * 	type -- Type to use for filling
 */
static void fill_range(int start, int end, enum CHAR_TYPE type)
{
 int cur_ch; /* Character we are handling now */
 for (cur_ch = start; cur_ch <= end; ++cur_ch) {
 type_info[cur_ch] = type;

 }
}
/*********************************************************
 * init_char_type -- Initializes the char type table. *
 *********************************************************/
static void init_char_type(void)
{
 fill_range(0, 255, C_WHITE);
 fill_range('A', 'Z', C_ALPHA);
 fill_range('a', 'z', C_ALPHA);
 type_info['_'] = C_ALPHA;
 fill_range('0', '9', C_DIGIT);
 type_info['!'] = C_OPERATOR;
 type_info['#'] = C_OPERATOR;
 type_info['$'] = C_OPERATOR;
 type_info['%'] = C_OPERATOR;
 type_info['^'] = C_OPERATOR;
 type_info['&'] = C_OPERATOR;
 type_info['*'] = C_OPERATOR;
 type_info['-'] = C_OPERATOR;
 type_info['+'] = C_OPERATOR;
 type_info['='] = C_OPERATOR;
 type_info['|'] = C_OPERATOR;
 type_info['~'] = C_OPERATOR;
 type_info[','] = C_OPERATOR;
 type_info[':'] = C_OPERATOR;
 type_info['?'] = C_OPERATOR;
 type_info['.'] = C_OPERATOR;
 type_info['<'] = C_OPERATOR;
 type_info['>'] = C_OPERATOR;
 type_info['/'] = C_SLASH;
 type_info['\n'] = C_NEWLINE;
 type_info['('] = C_L_PAREN;
 type_info[')'] = C_R_PAREN;
 type_info['{'] = C_L_CURLY;
 type_info['}'] = C_R_CURLY;
 type_info['"'] = C_DOUBLE;
 type_info['\''] = C_SINGLE;
}
/********************************************************
 * is_char_type -- Determines if a character belongs to *
 * a given character type. *
 * *
 * Parameters *
 * ch -- Character to check. *
 * kind -- Type to check it for. *
 * *
 * Returns: *
 * 0 -- Character is not of the specified kind. *
 * 1 -- Character is of the specified kind. *
 ********************************************************/
int is_char_type(int ch, enum CHAR_TYPE kind)
{
 if (!ch_setup) {
 init_char_type();
 ch_setup = 1;
 }
 if (ch == EOF) return (kind == C_EOF);
 switch (kind) {
 case C_HEX_DIGIT:
 if (type_info[ch] == C_DIGIT)
 return (1);
 if ((ch >= 'A') && (ch <= 'F'))
 return (1);
 if ((ch >= 'a') && (ch <= 'f'))
 return (1);
 return (0);
 case C_ALPHA_NUMERIC:
 return ((type_info[ch] == C_ALPHA) ||
 (type_info[ch] == C_DIGIT));
 default:
 return (type_info[ch] == kind);
 }
};
/********************************************************
 * get_char_type -- Given a character, returns its type.*
 *
 * Note: We return the simple types. Composite types *
 * such as C_HEX_DIGIT and C_ALPHA_NUMERIC are not *
 * returned. *
 * *
 * Parameters: *
 * ch -- Character having the type we want. *
 * *
 * Returns *
 * character type. *
 ********************************************************/
enum CHAR_TYPE get_char_type(int ch) {
 if (!ch_setup) {
 init_char_type();
 ch_setup = 1;
 }
 if (ch == EOF) return (C_EOF);
 return (type_info[ch]);
}
