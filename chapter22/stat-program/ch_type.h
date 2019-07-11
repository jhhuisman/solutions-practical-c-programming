/*
 * char_type -- Character type module
 */
enum CHAR_TYPE {
	C_EOF,
	C_WHITE,
	C_NEWLINE,
	C_ALPHA,
	C_DIGIT,
	C_OPERATOR,
	C_SLASH,
	C_L_PAREN,
	C_R_PAREN,
	C_L_CURLY,
	C_R_CURLY,
	C_SINGLE,
	C_DOUBLE,
	C_HEX_DIGIT,
	C_ALPHA_NUMERIC
};

/*
 * is_char_type -- Determines if a character belongs to a given character type.
 *
 * Parameters
 * 	ch -- Character to check.
 * 	kind -- Type to check it for.
 *
 * Returns:
 * 	0 -- Character is not of the specified kind.
 * 	1 -- Character is of the specified kind.
 */
extern int is_char_type(int ch, enum CHAR_TYPE kind);

/*
 * get_char_type -- Given a character, returns its type.
 *
 * Parameters:
 * 	ch -- Character having the type we want.
 *
 * Returns
 * 	character type.
 */
extern enum CHAR_TYPE get_char_type(int ch);
