#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 * @list: Pointer to the doubly linked list to be sorted.
 *
 * Return: nothing (void).
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *cur, *node;

	if (list == NULL || *list == NULL)
		return;
	cur = *list;
	while (cur != NULL)
	{
		node = cur;
		while (node->prev != NULL && node->prev->n > node->n)
		{
			temp = node->prev;

			if (temp->prev != NULL)
				temp->prev->next = node;

			temp->next = node->next;
			node->next = temp;

			node->prev = temp->prev;
			temp->prev = node;

			if (temp->next != NULL)
				temp->next->prev = temp;

			if (node->prev == NULL)
				*list = node;
			print_list(*list);
		}
		cur = cur->next;
	}
}
