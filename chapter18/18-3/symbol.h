struct symbol {
	char name[30];
	struct symbol *prev;
};

extern struct symbol *last_symbol_ptr;

extern void enter(char *name);

extern void delete(char *name);

extern int lookup(char *name);
