#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void _merge_split(int *array, int *output, size_t left, size_t right);
void _merge(int *array, int *output, size_t left, size_t mid, size_t right);
void copy_output_to_input(int *array, int *output, size_t size);

/**
 * merge_sort - recursive merge sort algorithm using top down merge strategy
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *output;

	if (array == NULL || size <= 1)
		return;
	output = malloc(sizeof(array[0]) * size);
	if (!output)
		return;
	copy_output_to_input(output, array, size);
	_merge_split(output, array, 0, size);
	free(output);
}

/**
 * _merge_split - recursively called subroutine to split array and merge after
 * @output: temporary array to store intermediate sorted subarrays
 * @array: unsorted input array
 * @left: left index of subarray
 * @right: right index of subarray (non-inclusive)
 */
void _merge_split(int *output, int *array, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;
	mid = (right + left) / 2;
	_merge_split(array, output, left, mid);
	_merge_split(array, output, mid, right);
	_merge(output, array, left, mid, right);
}

/**
 * _merge - merge subroutine to merge sorted subarrays
 * @array: input array
 * @output: temporary array to store intermediate sorted subarrays
 * @left: left index of subarray
 * @mid: midpoint between two subarrays
 * @right: right endpoint of subarrays (non-inclusive)
 */
void _merge(int *array, int *output, size_t left, size_t mid, size_t right)
{
	size_t i, j, k, n = right - left;

	i = left;
	j = mid;
	printf("Merging...\n");
	printf("[left]: ");
	print_array((const int *) array + left, mid - left);
	printf("[right]: ");
	print_array((const int *) array + mid, right - mid);
	for (k = 0; k < n; k++)
	{
		if (i < mid && (j >= right || array[i] <= array[j]))
		{
			output[k + left] = array[i];
			i++;
		}
		else
		{
			output[k + left] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array((const int *) output + left, n);
}

/**
 * copy_output_to_input - copy `output` to `array` of length `size`
 * @array: input array
 * @output: array to copy from
 * @size: size of `array`
 */
void copy_output_to_input(int *array, int *output, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		array[i] = output[i];
}
