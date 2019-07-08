#include <stdio.h>
#include <stdlib.h>

struct linked_list {
	int number;
	struct linked_list *next;
};

struct linked_list *head_ptr = NULL;

void add_item(int number);
void print_list(void);
int is_list_empty(void);
void memory_error(void);

int main()
{
	int numbers[] = {5, 8, 17, 38, 2, 1, 100};
	int counter;

	for (counter = 0; counter < (sizeof(numbers) / sizeof(numbers[0])); ++counter)
		add_item(numbers[counter]);

	print_list();

	return 0;
}

void add_item(int number)
{
	struct linked_list *new_item_ptr;
	struct linked_list *previous_ptr;

	/* Create list item */
	new_item_ptr = malloc(sizeof(struct linked_list));

	if (new_item_ptr == NULL)
		memory_error();

	new_item_ptr->number = number;
	new_item_ptr->next = NULL;

	/* Set head_ptr if list is empty */
	if (is_list_empty()) {
		head_ptr = new_item_ptr;
		return;
	}

	/* Find last list item */
	previous_ptr = head_ptr;

	while (previous_ptr->next != NULL)
		previous_ptr = previous_ptr->next;

	/* Add next pointer on last item to new item */
	previous_ptr->next = new_item_ptr;
}

void print_list(void)
{
	struct linked_list *current_ptr;

	current_ptr = head_ptr;

	while (current_ptr != NULL) {
		printf("%d\n", current_ptr->number);
		current_ptr = current_ptr->next;
	}
}

int is_list_empty(void)
{
	return head_ptr == NULL;
}

void memory_error(void)
{
	fprintf(stderr, "Error: Not enough memory to create list item.");
	exit(8);
}
