/*
 * words -- Scan a file and print out a list of words in ASCII order.
 *
 * Usage:
 * 	words <file>
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct node {
	struct node *left;
	struct node *right;
	char *word;
};

/* The top of the tree */
static struct node *root = NULL;

void memory_error(void)
{
	fprintf(stderr, "Error: Out of memory\n");
	exit(8);
}

/*
 * save_string -- Saves a string on the heap.
 *
 * Parameters
 * 	string -- String to save
 *
 * Returns
 * 	pointer to malloc-ed section of memory with the string copied into it.
 */
char *save_string(char *string)
{
	char *new_string;

	new_string = malloc((unsigned) (strlen(string) +1));

	if (new_string == NULL)
		memory_error();

	strcpy(new_string, string);

	return new_string;
}

/*
 * enter -- Enters a word into the tree.
 *
 * Parameters
 * 	node -- Current node we are looking at.
 * 	word -- Word to enter
 */
void enter(struct node **node, char *word)
{
	int result; /* result of strcmp */

	char *save_string(char *);

	/*
	 * If current node is null, we have reached the bottom of the tree and must create a new node
	 */
	if ((*node) == NULL) {
		/* Allocate memory for a new node */
		(*node) = malloc(sizeof(struct node));

		if((*node) == NULL)
			memory_error();

		/* Initialize new node */
		(*node)->left = NULL;
		(*node)->right = NULL;
		(*node)->word = save_string(word);
		return;
	}

	/* Check to see where the word goes */
	result = strcmp((*node)->word, word);

	if (result == 0)
		return;

	if (result < 0)
		enter(&(*node)->right, word);
	else
		enter(&(*node)->left, word);
}

/*
 * scan -- Scans the file for words.
 *
 * Parameters
 * 	name -- Name of the file to scan
 */
void scan(char *name)
{
	char word[100];
	int index;
	int ch;
	FILE *in_file;

	in_file = fopen(name, "r");

	if (in_file == NULL) {
		fprintf(stderr, "Error: Unable to open %s\n", name);
		exit(8);
	}

	while (1) {
		while (1) {
			ch = fgetc(in_file);

			if (isalpha(ch) || ch == EOF)
				break;
		}

		if (ch == EOF)
			break;

		word[0] = ch;

		for (index = 1; index <sizeof(word); ++index) {
			ch = fgetc(in_file);

			if (!isalpha(ch))
				break;

			word[index] = ch;
		}

		word[index] = '\0';

		enter(&root, word);
	}

	fclose(in_file);
}

/*
 * print_tree -- Prints out the words in a tree.
 *
 * Parameters
 * 	top -- The root of the tree to print
 */
void print_tree(struct node *top)
{
	if (top == NULL)
		return;

	print_tree(top->left);
	printf("%s\n", top->word);
	print_tree(top->right);
}

/*
 * enter -- Deletes a node from the tree.
 *
 * Parameters
 * 	word -- Word to delete
 */
void delete(char *word)
{
	struct node *current_ptr;
	struct node *parent_ptr;
	struct node *bottom_ptr;

	int result_strcmp; 

	current_ptr = root;
	parent_ptr = NULL;

	while (current_ptr != NULL) {
		result_strcmp = strcmp(word, current_ptr->word);

		/* Word found */
		if (result_strcmp == 0)
			break;

		/* Word not found yet, move along */
		parent_ptr = current_ptr;

		if (result_strcmp > 0)
			current_ptr = current_ptr->right;
		else if (result_strcmp < 0)
			current_ptr = current_ptr->left;
	}
	
	/* Word not in tree */
	if (current_ptr == NULL) {
		printf("Word '%s' not in tree.\n", word);
		return;
	}

	/* Word belongs to right branch of parent branch */
	if (strcmp(word, parent_ptr->right->word) == 0) {
		/* Add left branch of deleted word to parent branch*/
		parent_ptr->right = current_ptr->left;

		/* Find bottom of this tree */
		while (parent_ptr->right != NULL)
			parent_ptr = parent_ptr->right;

		/* Add right branch of deleted word to bottom */
		parent_ptr->right = current_ptr->right;
	}
	/* Word belongs to left branch of parent branch */
	else if (strcmp(word, parent_ptr->left->word) == 0) {
		/* Add right branch of deleted word to parent branch*/
		parent_ptr->left = current_ptr->right;

		/* Find bottom of this tree */
		while (parent_ptr->left != NULL)
			parent_ptr = parent_ptr->left;

		/* Add left branch of deleted word to bottom */
		parent_ptr->left = current_ptr->left;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Error: Wrong number of parameters\n");
		exit(8);
	}

	scan(argv[1]);
	delete("grape");
	print_tree(root);

	return 0;
}
