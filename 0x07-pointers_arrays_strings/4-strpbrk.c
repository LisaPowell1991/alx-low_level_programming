#include "main.h"

/**
 * _strpbrk - function that searches a string for any of a set of bytes.
 * @s: pointer
 * @accept:pointer
 * Return: Returns a pointer to the byte in s
 * that matches one of the bytes in accept,
 * or returns NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	char *a = s, *b = accept;

	for (;;)
	{
		if (*b == 0)
			return (char *s);

		if (*a == 0)
			return (NULL);
		if (*a++ != *b++)
		{
			a = ++s;
			b = accept;
		}
	}
}
