#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_array - function that creates an array of chars,
 * and initializes it with a specific char.
 * @size: unsigned integer
 * @c: character
 * Return: returns a pointer to the array,
 * or NULL if it fails or size = 0
 */

char *create_array(unsigned int size, char c)
{
	char *ptr;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}
	ptr = malloc(size * sizeof(char));

	if (ptr == NULL)
	{
		return (NULL);

	}
	for (i = 0; i < size; i++)
		ptr[i] = c;

	return (ptr);
}
