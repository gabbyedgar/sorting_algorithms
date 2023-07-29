#include "sort.h"

/**
 * bubble_sort - the worst sorting algorithm
 * @array: array to be sorted in place
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int max;

	for (i = size; i > 1; i--)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				max = array[j];
				array[j] = array[j + 1];
				array[j + 1] = max;
				print_array(array, size);
			}
		}
	}
}
