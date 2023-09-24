#include "sort.h"
/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge sort algorithm.
 * @array: Pointer to the integer array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	splitter(array, temp, 0, size - 1);
	free(temp);
}
/**
 * splitter - Splits the array into subarrays.
 * @array: Pointer to the integer array to be sorted.
 * @temp: Pointer to the temporary array.
 * @low: The lower index of the subarray.
 * @high: The higher index of the subarray.
 */
void splitter(int *array, int *temp, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		splitter(array, temp, low, mid);
		splitter(array, temp, mid + 1, high);
		merge(array, temp, low, mid, high);
	}
}

/**
 * merge - Merges the subarrays back into one array.
 * @array: Pointer to the integer array to be sorted.
 * @temp: Pointer to the temporary array.
 * @low: The lower index of the subarray.
 * @mid: The middle index of the subarray.
 * @high: The higher index of the subarray.
 */
void merge(int *array, int *temp, int low, int mid, int high)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + low, mid - low + 1);
	printf("[right]: ");
	print_array(array + mid + 1, high - mid);
	for (i = low, j = mid + 1, k = low; k <= high; k++)
	{
		if (i == mid + 1)
		{
			temp[k] = array[j];
			j++;
		}
		else if (j == high + 1)
		{
			temp[k] = array[i];
			i++;
		}
		else if (array[i] < array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}
	for (i = low; i <= high; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array + low, high - low + 1);
}
