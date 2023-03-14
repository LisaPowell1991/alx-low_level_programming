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
	char *s;
	int i;

	s = malloc((size + 1) * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return (s);
}
