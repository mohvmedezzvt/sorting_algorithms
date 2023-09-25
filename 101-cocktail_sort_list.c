#include "sort.h"

/**
 * swap_nodes - swaps the positions of two nodes in the list.
 *
 * @left: left node.
 * @right: right node.
 */
void swap_nodes(listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	right->next = left;
	left->prev = right;
}

/**
 * forward_pass - forward pass of the Cocktail Shaker Sort algorithm.
 *
 * @list: pointer to the linked list.
 * @temp: temporary pointer for traversal.
 * @sorted: flag to track whether any swaps were made.
 */
void forward_pass(listint_t **list, listint_t **temp, int *sorted)
{
	while ((*temp)->next)
	{
		if ((*temp)->n > (*temp)->next->n)
		{
			listint_t *n = (*temp)->next;

			swap_nodes(*temp, n);

			if (!n->prev)
				*list = n;

			*sorted = 0;
			print_list(*list);
		}
		else
		{
			*temp = (*temp)->next;
		}
	}
}

/**
 * backward_pass -backward pass of the Cocktail Shaker Sort algorithm.
 *
 * @list: pointer to the linked list.
 * @temp: temporary pointer for traversal.
 * @sorted: flag to track whether any swaps were made.
 */
void backward_pass(listint_t **list, listint_t **temp, int *sorted)
{
	while ((*temp)->prev)
	{
		if ((*temp)->n < (*temp)->prev->n)
		{
			listint_t *p = (*temp)->prev;

			swap_nodes(p, *temp);

			if (!(*temp)->prev)
				*list = *temp;

			*sorted = 0;
			print_list(*list);
		}
		else
		{
			*temp = (*temp)->prev;
		}
	}
}

/**
 * cocktail_sort_list - sorts a linked list of integers in ascending order,
 * using the Cocktail Shaker Sort algorithm.
 *
 * @list: a pointer to the list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int sorted = 0;

	if (!list || !(*list))
		return;

	temp = *list;

	while (!sorted)
	{
		sorted = 1;

		forward_pass(list, &temp, &sorted);
		backward_pass(list, &temp, &sorted);
	}
}
