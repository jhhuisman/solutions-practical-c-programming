#ifndef PAGE_H
#define PAGE_H

extern FILE *printer_file; /* Pointer to printer file */
extern char heading_text[]; /* Heading text */

FILE *open_file(char *name);

void define_header(char *heading);

void print_line(char *line);

void page(void); /* Starts new page */

int close_file(void);

void print_page_header(void);

#endif /* PAGE_H */
