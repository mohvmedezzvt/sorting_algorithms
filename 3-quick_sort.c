#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * swapper - swaps two integers
 * @arr: array to be sorted
 * @low: lowest index of the array
 * @high: highest index of the array
 * Return: index of the pivot
 */
size_t swapper(int *arr, size_t low, size_t high)
{
	size_t i = low - 1;
	int pivot = arr[high];

	for (size_t j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
/**
 * quicksort_helper - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 */
void quicksort_helper(int *array, size_t low, size_t high, size_t size)
{
	size_t idx;

	if (low < high)
	{
		idx = swapper(array, low, high);
		if (idx != 0)
			quicksort_helper(array, low, idx - 1, size);
		print_array(array, size);

		if (idx != size - 1)
			quicksort_helper(array, idx + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	quicksort_helper(array, 0, size - 1, size);
}
