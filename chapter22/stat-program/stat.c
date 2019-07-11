/********************************************************
 * stat *
 * Produces statistics about a program. *
 * *
 * Usage: *
 * stat [options] <file-list> *
 * *
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ch_type.h"
#include "in_file.h"
#include "token.h"
/********************************************************
 ********************************************************
 ********************************************************
 * line_counter -- Handles line number / line count *
 * stat. *
 * *
 * Counts the number of T_NEW_LINE tokens seen and *
 * outputs the current line number at the beginning *
 * of the line. *
 * *
 * At EOF, it will output the total number of lines. *
 ********************************************************/
static int cur_line; /* Current line number */
/********************************************************
 * lc_init -- Initializes the line counter variables. *
 ********************************************************/
static void lc_init(void)
{
 cur_line = 0;
};
/********************************************************
 * lc_take_token -- Consumes tokens and looks for *
 * end-of-line tokens. *
 * *
 * Parameters *
 * token -- The token coming in from the input *
 * stream. *
 ********************************************************/
static void lc_take_token(enum TOKEN_TYPE token) {
 if (token == T_NEWLINE)
 ++cur_line;
}
/********************************************************
 * lc_line_start -- Outputs the per-line statistics, *
 * namely the current line number. *
 ********************************************************/
static void lc_line_start(void) {
 printf("%4d ", cur_line);
}
/********************************************************
 * lc_eof -- Outputs the eof statistics. *
 * In this case, the number of lines. *
 ********************************************************/
static void lc_eof(void) {
 printf("Total number of lines: %d\n", cur_line);
}
/********************************************************
 ********************************************************
 ********************************************************
 * paren_count -- Counts the nesting level of (). *
 * *
 * Counts the number of T_L_PAREN vs T_R_PAREN tokens *
 * and writes the current nesting level at the beginning*
 * of each line. *
 * *
 * Also keeps track of the maximum nesting level. *
 ********************************************************/
static int pc_cur_level;
static int pc_max_level;
/********************************************************
 * pc_init -- Initializes the () counter variables. *
 ********************************************************/
void pc_init(void) {
 pc_cur_level = 0;
 pc_max_level = 0;
};
/********************************************************
 * pc_take_token -- Consumes tokens and looks for *
 * () tokens. *
 * *
 * Parameters *
 * token -- The token coming in from the input *
 * stream. *
 ********************************************************/
void pc_take_token(enum TOKEN_TYPE token) {
 switch (token) {
 case T_L_PAREN:
 ++pc_cur_level;
 if (pc_cur_level > pc_max_level)
 pc_max_level = pc_cur_level;
 break;
 case T_R_PAREN:
 --pc_cur_level;
 break;
 default:
 /* Ignore */
 break;
 }
}
/********************************************************
 * pc_line_start -- Outputs the per-line statistics, *
 * namely the current () nesting. *
 ********************************************************/
static void pc_line_start(void) {
 printf("(%-2d ", pc_cur_level);
}
/********************************************************
 * pc_eof -- Outputs the eof statistics. *
 * In this case, the max nesting of (). *
 ********************************************************/
void pc_eof(void) {
 printf("Maximum nesting of () : %d\n", pc_max_level);
}
/********************************************************
 ********************************************************
 ********************************************************
 * brace_counter -- Counts the nesting level of {}. *
 * *
 * Counts the number of T_L_CURLY vs T_R_CURLY tokens *
 * and writes the current nesting level at the beginning*
 * of each line. *
 * *
 * Also, keeps track of the maximum nesting level. *
 * *
 * Note: brace_counter and paren_counter should *
 * probably be combined. *
 ********************************************************/
static int bc_cur_level; /* Current nesting level */
static int bc_max_level; /* Maximum nesting level */
/********************************************************
 * pc_init -- Initialize the {} counter variables. *
 ********************************************************/
void bc_init(void) {
 bc_cur_level = 0;
 bc_max_level = 0;
};
/********************************************************
 * bc_take_token -- Consumes tokens and looks for *
 * {} tokens. *
 * *
 * Parameters *
 * token -- The token coming in from the input *
 * stream. *
 ********************************************************/
void bc_take_token(enum TOKEN_TYPE token) {
 switch (token) {
 case T_L_CURLY:
 ++bc_cur_level;
 if (bc_cur_level > bc_max_level)
 bc_max_level = bc_cur_level;
 break;
 case T_R_CURLY:
 --bc_cur_level;
 break;
 default:
 /* Ignore */
 break;
 }
}
/********************************************************
 * bc_line_start -- Outputs the per-line statistics, *
 * namely the current {} nesting. *
 ********************************************************/
static void bc_line_start(void) {
 printf("{%-2d ", bc_cur_level);
}
/********************************************************
 * bc_eof -- Outputs the eof statistics. *
 * In this case, the max nesting of {}. *
 ********************************************************/
static void bc_eof(void) {
 printf("Maximum nesting of {} : %d\n", bc_max_level);
}
/********************************************************
 ********************************************************
 ********************************************************
 * comment_counter -- Counts the number of lines *
 * with and without comments. *
 * *
 * Outputs nothing at the beginning of each line, but *
 * will output a ratio at the end of file. *
 * *
 * Note: This class makes use of two bits: *
 * CF_COMMENT -- a comment was seen *
 * CF_CODE -- code was seen *
 * to collect statistics. *
 * *
 * These are combined to form an index into the counter *
 * array so the value of these two bits is very *
 * important. *
 ********************************************************/
static const int CF_COMMENT = (1<<0); /* Line contains comment */
static const int CF_CODE = (1<<1); /* Line contains code */
/* These bits are combined to form the statistics */
/* 0 -- [0] Blank line */
/* CF_COMMENT -- [1] Comment-only line */
/* CF_CODE -- [2] Code-only line */
/* CF_COMMENT|CF_CODE -- [3] Comments and code on this line */
static int counters[4]; /* Count of various types of stats. */
static int flags; /* Flags for the current line */
/********************************************************
 * cc_init -- Initializes the comment counter variables.*
 ********************************************************/
static void cc_init(void) {
 memset(counters, '\0', sizeof(counters));
 flags = 0;
};
/********************************************************
 * cc_take_token -- Consumes tokens and looks for *
 * comments tokens. *
 * *
 * Parameters *
 * token -- The token coming in from the input *
 * stream. *
 ********************************************************/
void cc_take_token(enum TOKEN_TYPE token) {
 switch (token) {
 case T_COMMENT:
 flags |= CF_COMMENT;
 break;
 default:
 flags |= CF_CODE;
 break;
 case T_NEWLINE:
 ++counters[flags];
 flags = 0;
 break;
 }
}
/********************************************************
 * cc_line_start -- Outputs the per-line statistics. *
 ********************************************************/
static void cc_line_start(void)
{
 /* Do nothing */
}
/********************************************************
 * cc_eof -- Outputs the eof statistics. *
 * In this case, the comment/code ratios. *
 ********************************************************/
static void cc_eof(void) {
 printf("Number of blank lines .................%d\n",
 counters[0]);
 printf("Number of comment only lines ..........%d\n",
 counters[1]);
 printf("Number of code only lines .............%d\n",
 counters[2]);
 printf("Number of lines with code and comments %d\n",
 counters[3]);
 printf("Comment to code ratio %3.1f%%\n",
 (float)(counters[1] + counters[3]) /
 (float)(counters[2] + counters[3]) * 100.0);
}
/********************************************************
 * do_file -- Processes a single file. *
 * *
 * Parameters *
 * name -- The name of the file to process. *
 ********************************************************/
static void do_file(const char *const name)
{
 enum TOKEN_TYPE cur_token; /* Current token type */
 /*
 * Initialize the counters
 */
 lc_init();
 pc_init();
 bc_init();
 cc_init();
 if (in_open(name) != 0) {
 printf("Error: Could not open file %s for reading\n", name);
 return;
 }
 while (1) {
 cur_token = next_token();
 lc_take_token(cur_token);
 pc_take_token(cur_token);
 bc_take_token(cur_token);
 cc_take_token(cur_token);
 switch (cur_token) {
 case T_NEWLINE:
 lc_line_start();
 pc_line_start();
 bc_line_start();
 cc_line_start();
 in_flush();
 break;
 case T_EOF:
 lc_eof();
 pc_eof();
 bc_eof();
 cc_eof();
 in_close();
 return;
 default:
 /* Do nothing */
 break;
 }
 }
}
int main(int argc, char *argv[])
{
 char *prog_name = argv[0]; /* Name of the program */
 if (argc == 1) {
 printf("Usage is %s [options] <file-list>\n", prog_name);
 exit (8);
 }
 for (/* argc set */; argc > 1; --argc) {
 do_file(argv[1]);
 ++argv;
 }
 return (0);
}
