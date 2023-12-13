#include "search_algos.h"

/**
 * exponential_search - a Function that searches for a value in a
 * sorted array of integers using the Exponential search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in array.
 * @value: The value to search for.
 *
 * Return: the first index where value is located,
 * or If value is not present in array or if array is NULL,
 * your function must return -1.
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t low, high, mid, i;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	low = bound / 2;
	high = (bound < size - 1) ? bound : size - 1;

	printf("Value found between indexes [%lu] and [%lu]\n", low, high);

	while (low <= high)
	{
		mid = low + (high - low) / 2;

		printf("Searching in array:");

		for (i = low; i <= high; ++i)
		{
			printf(" %d", array[i]);
			if (i < high)
				printf(",");
		}
		printf("\n");

		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}
