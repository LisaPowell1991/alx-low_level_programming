#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: character
 * Return: returns a pointer to the duplicated string if successful
 * or returns NULL if str = 0 or if insufficient memory was available
 */

char *_strdup(char *str)
{
	char *ptr;
	int length = 0, i;

	if (str == 0)
	{
		return (NULL);
	}
	while (str[length] != '\0')
		length++;

	ptr = malloc((length + 1) * sizeof(char));

	if (ptr == NULL)
	{
		return (NULL);

	}
	for (i = 0; i < length; i++)
		ptr[i] = str[i];
	ptr[i] = '\0';

	return (ptr);
}
