#include "sort.h"

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * the Radix sort algorithm.
 * @array: Pointer to the integer array to be sorted.
 * @size: The number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
    int *buckets[10], *temp;
    size_t i, j, k, max_digits = 0, digit = 0, divisor = 1;

    if (!array || size < 2)
        return;

    for (i = 0; i < 10; i++)
        buckets[i] = malloc(sizeof(int) * size);

    temp = malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        temp[i] = array[i];
        if (array[i] > (int)max_digits)
            max_digits = array[i];
    }
    printf("max_digits: %lu\n", max_digits);

    for (i = max_digits; i > 0; i /= 10)
    {
        digit++;
        printf("digit: %lu\n", digit);
    }
    printf("digit: %lu\n", digit);
    max_digits = digit;
    digit = 0;
    for (i = 0; i < max_digits; i++)
    {
        for (j = 0; j < size; j++)
        {
            digit = (array[j] / divisor) % 10;
            buckets[digit][j] = array[j];
        }

        for (j = 0, k = 0; j < 10; j++)
        {
            while (k < size)
            {
                if (buckets[j][k])
                {
                    array[j] = buckets[j][k];
                    k++;
                    break;
                }
                k++;
            }
        }
        print_array(array, size);
        divisor *= 10;
    }

    for (i = 0; i < 10; i++)
        free(buckets[i]);
    free(temp);
}