#include "search_algos.h"

/**
 * advanced_binary - a Function that searches for a
 * value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in array.
 * @value: The value to search for.
 *
 * Return: the index where value is located
 * or If value is not present in array or if array is NULL,
 * your function must return -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t index, middle;
	int result;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array: ");
	for (index = 0; index < size; index++)
	{
		printf("%d", array[index]);

		if (index < size - 1)
			printf(", ");
	}
	printf("\n");

	middle = size / 2;

	if (array[middle] == value)
		return (middle);
	else if (array[middle] > value)
		return (advanced_binary(array, middle, value));

	result = advanced_binary(array + middle + 1, size - middle - 1, value);
	return ((result == -1) ? -1 : (int)(middle + 1 + result));
}
