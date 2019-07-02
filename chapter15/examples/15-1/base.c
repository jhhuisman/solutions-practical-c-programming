/*
 * Database -- A very simple database program to look up names in a harcoded list.
 *
 * Usage:
 * 	database
 * 		Program will ask you for a name.
 * 		Enter the name; it will tell you if the name is in the list.
 *
 * 		A blank name terminates the program.
 */
#define STRING_LENGTH 80 /* length of a typical string */
#include <stdio.h>
#include <string.h>

int main()
{
	char name[STRING_LENGTH]; /* a name to lookup */

	int lookup(char const *const name); /* lookup a name */

	while (1) {
		printf("Enter name: ");
		fgets(name, sizeof(name), stdin);

		/* Check for a blank name */
		/* (remember 1 character for newline) */
		if (strlen(name) <= 1)
			break;

		/* Get rid of newline */
		name[strlen(name)-1] = '\0';

		if (lookup(name))
			printf("%s is in the list\n", name);
		else
			printf("%s is not in the list\n", name);
	}

	return 0;
}

/*
 * lookup -- Looks up a name in a list
 *
 * Parameters
 * 	name -- Name to lookup
 *
 * Returns
 * 	1 -- Name is in the list.
 * 	0 -- Name not in the list
 */
int lookup(char const *const name)
{
	/* List of people in the databse */
	/* Note: Last name is a NULL for end of list */
	static char *list[] = {
		"John",
		"Jim",
		"Jane",
		"Clyde",
		NULL
	};

	int index; /* index into list */

	for (index = 0; list[index] != NULL; ++index) {
		if (strcmp(list[index], name) == 0)
			return 1;
	}

	return 0;
}
