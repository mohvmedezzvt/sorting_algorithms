#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array and returns the index of the pivot.
 * @array: The array to be sorted.
 * @low: The lowest index of the array.
 * @high: The highest index of the array.
 * @size: The size of the array.
 * Return: The index of the pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int left = low;
	int right;
	int pivot = array[high];

	for (right = low; right <= high - 1; right++)
	{
		if (array[right] <= pivot)
		{
			if (left != right)
			{
				swap(&array[left], &array[right]);
				print_array(array, size);
			}
			left++;
		}
	}

	if (array[left] != array[high])
	{
		swap(&array[left], &array[high]);
		print_array(array, size);
	}
	return (left);
}

/**
 * quicksort_helper - Sorts an array of integers in ascending order
 * @array: The array to be sorted.
 * @low: The lowest index of the array.
 * @high: The highest index of the array.
 * @size: The size of the array.
 */
void quicksort_helper(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		quicksort_helper(array, low, pivot_index - 1, size);
		quicksort_helper(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_helper(array, 0, size - 1, size);
}
