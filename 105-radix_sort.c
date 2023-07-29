#include <stdlib.h>
#include "sort.h"
#define NUMDIGIT 10

/**
 * findMaxPower10 - find the max value in `array` and return the number
 * of significant digits in base 10
 * @array: array to check
 * @size: size of `array`
 *
 * Return: number of significant digits of max value in `array`
 */
size_t findMaxPower10(int *array, size_t size)
{
	size_t i, base10;
	int max = array[0];

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	for (base10 = 0; max > 0; max /= 10)
		base10++;
	return (base10);
}

/**
 * radix_sort - sorts data using Radix and prints it out
 * @array: data to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	size_t digit, divisor, base10, i, oldCount, z, count[NUMDIGIT];
	int *output;

	if (array == NULL || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	for (i = 0; i < NUMDIGIT; i++)
		count[i] = 0;
	base10 = findMaxPower10(array, size);
	for (z = 0, divisor = 1; z < base10; z++, divisor *= 10)
	{
		for (i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			count[digit]++;
		}
		for (i = 1; i < NUMDIGIT; i++)
		{
			oldCount = count[i - 1];
			count[i] = oldCount + count[i];
		}
		for (i = size; i > 0; i--)
		{
			digit = (array[i - 1] / divisor) % 10;
			output[count[digit] - 1] = array[i - 1];
			count[digit]--;
		}
		for (i = 0; i < size; i++)
			array[i] = output[i];
		for (i = 0; i < NUMDIGIT; i++)
			count[i] = 0;
		print_array(array, size);
	}
	free(output);
}
