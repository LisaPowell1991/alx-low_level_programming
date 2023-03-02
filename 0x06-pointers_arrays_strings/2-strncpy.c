#include "main.h"

/**
 *  _strncpy - function that copies a string.
 * @dest: integer
 * @src: integer
 * @n: integer
 * Return: returns dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	src[n] = dest[n];
	if (dest[n] == '\0')
	return dest;

	_strncpy(dest, src, (n + 1));
	return 0;
}
