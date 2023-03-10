#include "main.h"

/**
 * _strchr - function that locates a character in a string.
 * @s: pointer
 * @c: character
 * Return:returns a pointer to the first occurrence
 * of the character c in the string s.
 * or returns NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index] >= '\0'; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return ('\0');
}
