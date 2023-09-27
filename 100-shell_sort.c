#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i = 0;
	int j = 0;

	if (array == NULL || size < 2)
		return;

	while (1)
	{
		i = 3 * i + 1;
		if (i <= size)
		{
			j = i;
		}
		else
			break;
	}
	shell_sort_helper(array, size, j);
}
/**
 * shell_sort_helper - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of the array
 * @knuth: knuth number
 * Return: void
 */
void shell_sort_helper(int *array, size_t size, int knuth)
{
	size_t j = 0;
	int q = 0;

	while (knuth >= 1)
	{
		j = knuth;
		while (j < size)
		{
			q = j;
			while (array[q] < array[q - knuth] && q >= knuth)
			{
				swap(&array[q], &array[q - knuth]);
				q -= knuth;
			}
			j++;
		}
		print_array(array, size);
		knuth = (knuth - 1) / 3;
	}
}

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