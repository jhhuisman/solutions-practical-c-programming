/*
 * infinite-array -- routine sto handle infinite arrays
 *
 * An infinite array in an array that grows as needed.
 * There is no index too large for an infinite array
 * (unless we run out of memory)
 */
#include "ia.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * ia_locate -- Gets the location of an infinite array element.
 *
 * Parameters
 * 	array_ptr -- Pointer to the array to use.
 * 	index -- Index inot the array.
 * 	current_index -- Pointer to the index into this bucket (returned).
 *
 * Returns
 * 	pointer to the current bucket
 */
static struct infinite_array *ia_locate(
		struct infinite_array *array_ptr, int index,
		int *current_index_ptr)
{
	/* pointer to the current bucket */
	struct infinite_array *current_ptr;

	current_ptr = array_ptr;
	*current_index_ptr = index;

	while (*current_index_ptr >= BLOCK_SIZE) {
		if (current_ptr->next == NULL) {
			current_ptr->next = malloc(sizeof(struct infinite_array));

			if (current_ptr->next == NULL) {
				fprintf(stderr, "Error: Out of memory\n");
				exit(8);
			}

			memset(current_ptr->next, '\0', sizeof(struct infinite_array));
		}

		current_ptr = current_ptr->next;
		*current_index_ptr -= BLOCK_SIZE;
	}

	return current_ptr;
}

/*
 * ia_store -- Stores an element into the infinite array
 *
 * Parameters
 * 	array_ptr -- Pointer to the array to use
 * 	index -- Index into the array
 * 	store_data -- Data to store
 */
void ia_store(struct infinite_array * array_ptr,
		int index, int store_data)
{
	/* pointer to the current bucket */
	struct infinite_array *current_ptr;
	int current_index;

	current_ptr = ia_locate(array_ptr, index, &current_index);
	current_ptr->data[current_index] = store_data;
}

/*
 * ia_get -- Gets an element from in infinite array
 *
 * Parameters
 * 	array_ptr -- Pointer to the array to use
 * 	index -- Index into the array
 *
 * Returns
 * 	the value of the element
 *
 * Note: You can get an element that has not previously been stores.
 * 	The value of any uninitialized element is zero.
 */
int ia_get(struct infinite_array *array_ptr, int index)
{
	/* pointer tot he current bucket */
	struct infinite_array *current_ptr;

	int current_index; /* index into the current bucket */

	current_ptr = ia_locate(array_ptr, index, & current_index);
	return (current_ptr->data[current_index]);
}
