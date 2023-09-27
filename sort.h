#ifndef SORT_H
#define SORT_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void swap(int *a, int *b);

/* Assistance Functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Mandatory Functions */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
/* Quick Sort functions */
void quick_sort(int *array, size_t size);
void quicksort_helper(int *array, int low, int high, size_t size);
int swapper(int *arr, int low, int high, size_t size);

/* Merge Sort functions */
void merge_sort(int *array, size_t size);
void splitter(int *array, int *temp, int low, int high);
void merge(int *array, int *temp, int low, int mid, int high);

/* Shell Sort functions */
void shell_sort(int *array, size_t size);
void shell_sort_helper(int *array, size_t size, int knuth);

/* Cocktail shaker sort */
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t *n1, listint_t *n2);
/* radix sort*/
void radix_sort(int *array, size_t size);

#endif /* SORT_H */
