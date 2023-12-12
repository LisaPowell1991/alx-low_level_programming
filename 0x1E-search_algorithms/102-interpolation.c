#include "search_algos.h"

/**
 * interpolation_search - function that searches for a value in
 * a sorted array of integers using the Interpolation search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in array.
 * @value: The value to search for.
 *
 * Return: First index where value is located,
 * If value is not present in array or if array is NULL,
 * your function must return -1
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low, high, probe_position;
	double numerator, denominator;

	low = 0;
	high = size - 1;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high)
	{
		numerator = (double)(high - low);
		denominator = array[high] - array[low];
		probe_position = low + ((numerator / denominator) * (value - array[low]));

		printf("
				Value checked array[%lu] = [%d]\n", probe_position, array[probe_position]);

		if (array[probe_position] == value)
			return (probe_position);
		else if (array[probe_position] < value)
			low = probe_position + 1;
		else
			high = probe_position - 1;
	}
	return (-1);
}
