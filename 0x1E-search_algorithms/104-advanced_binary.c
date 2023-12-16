#include "search_algos.h"

/**
 * print_array - Prints the elements of an array between 2 indices.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t index;

	printf("Searching in array: ");
	for (index = start; index <= end; index++)
	{
		printf("%d", array[index]);
		if (index < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursively searches
 * for a value in a sorted array.
 * @array: Pointer to the first element of the array.
 * @start: Starting index of the subarray.
 * @end: Ending index of the subarray.
 * @value: The value to search for.
 *
 * Return: The index where the value is located, or -1 if not found.
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int value)
{
	size_t middle;
	int result;

	if (start > end)
		return (-1);

	print_array(array, start, end);

	middle = start + (end - start) / 2;

	if (array[middle] == value)
	{
		return (middle);
	}
	else if (array[middle] > value)
	{
		return (advanced_binary_recursive(array, start, middle - 1, value));
	}
	else
	{
		result = advanced_binary_recursive(array, middle + 1, end, value);
		if (result != -1)
			return ((int)(middle + 1 + result));
		return (-1);
	}
}

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
	if (array == NULL || size == 0)
		return (-1);

	print_array(array, 0, size - 1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
