/********************************************************
 * token -- Token handling module. *
 * *
 * Functions: *
 * next_token -- Gets the next token from the input.*
 ********************************************************/
/*
 * Define the enumerated list of tokens.
 */
enum TOKEN_TYPE {
 T_NUMBER, /* Simple number (floating point or integer */
 T_STRING, /* String or character constant */
 T_COMMENT, /* Comment */
 T_NEWLINE, /* Newline character */
 T_OPERATOR, /* Arithmetic operator */
 T_L_PAREN, /* Character "(" */
 T_R_PAREN, /* Character ")" */
 T_L_CURLY, /* Character "{" */
 T_R_CURLY, /* Character "}" */
 T_ID, /* Identifier */
 T_EOF /* End of File */
};
/*
 * We use #define here instead of "const int" because so many old
 * software packages use #define. We must have picked
 * up a header file that uses #define for TRUE/FALSE. Consequently,
 * we protect against double defines as well as against using #define
 * ourselves.
 */
#ifndef TRUE
#define TRUE 1 /* Define a simple TRUE/FALSE values */
#define FALSE 0
#endif /* TRUE */
/*********************************************************
 * next_token -- Reads the next token in an input stream.*
 * *
 * Parameters *
 * in_file -- File to read. *
 * *
 * Returns *
 * next token. *
 *********************************************************/
extern enum TOKEN_TYPE next_token(void);
