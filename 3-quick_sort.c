#include "sort.h"
#include <stdio.h>

/**
 * partition - partition subarray of `array` around pivot using
 * Lomuto method (always choose right element).
 * @array: array to partition
 * @left: left end of subarray
 * @right: right end of subarray
 * @size: size of array
 *
 * Return: index of pivot after it has been sorted
 */
int partition(int *array, int left, int right, size_t size)
{
	int i, j, tmp, pivot;

	pivot = array[right];
	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	if (array[right] <= array[i + 1])
	{
		i++;
		if (i == right)
			return (i);
		tmp = array[i];
		array[i] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * _quick_sort - recursively partition array until it is fully sorted
 * @array: array to sort
 * @left: left side of subarray for recursion
 * @right: right side of subarray for recursion
 * @size: size of array
 */
void _quick_sort(int *array, int left, int right, size_t size)
{
	int p;

	if (left < right)
	{
		p = partition(array, left, right, size);
		_quick_sort(array, left, p - 1, size);
		_quick_sort(array, p + 1, right, size);
	}
}

/**
 * quick_sort - wrapper around recursive quicksort function
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	_quick_sort(array, 0, size - 1, size);
}
