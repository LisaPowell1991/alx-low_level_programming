#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * str_concat - function that concatenates two strings.
 * @s1: character
 * @s2: character
 * Return:returns a newly allocated space in memory which contains
 * the contents of s1, followed by the contents of s2
 * or returns NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	char *concat_string;
	int i, c = 0, length = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	for (i = 0; s1[i] || s2[i]; i++)
		length++;

	concat_string = malloc(length * sizeof(char));

	if (concat_string == NULL)
	{
		return (NULL);

	}
	for (i = 0; s1[i]; i++)
		concat_string[c++] = s1[i];

	for (i = 0; s2[i]; i++)
		concat_string[c++] = s2[i];

	return (concat_string);
}
