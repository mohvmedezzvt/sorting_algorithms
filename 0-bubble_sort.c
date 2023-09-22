#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm.
 * @array: Pointer to the integer array to be sorted.
 * @size: The number of elements in the array.
 *
 * Return: nothing (void).
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;
	int flag = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				flag = 1;
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
			if (flag == 0)
				break;
		}
	}
}
