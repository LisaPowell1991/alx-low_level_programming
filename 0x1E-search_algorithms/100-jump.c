#include "search_algos.h"

/**
 * jump_search - a function that searches for a value
 * in a sorted array of integers using the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: The number of elements in array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located
 * or If value is not present in array or if array is NULL,
 * your function must return -1.
 */

int jump_search(int *array, size_t size, int value)
{
	size_t jump_step, previous, current, index;

	jump_step = sqrt(size);
	previous = 0;
	current = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (current < size && array[current] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", current, array[current]);

		previous = current;
		current += jump_step;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", previous, current);

	for (index = previous; index <= current && index < size; ++index)
	{
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);

		if (array[index] == value)
			return (index);
	}
	return (-1);
}
