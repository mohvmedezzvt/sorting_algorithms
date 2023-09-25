#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker Sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;

		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				swapped = 1;
				print_list(*list);
			} else
				current = current->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		end = current;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current);
				swapped = 1;
				if (current->prev == NULL)
					*list = current;
				print_list(*list);
			} else
				current = current->prev;
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @n1: First node to be swapped.
 * @n2: Second node to be swapped.
 */
void swap_nodes(listint_t *n1, listint_t *n2)
{
	if (n1->prev)
		n1->prev->next = n2;
	if (n2->next)
		n2->next->prev = n1;

	n1->next = n2->next;
	n2->prev = n1->prev;

	n1->prev = n2;
	n2->next = n1;
}
