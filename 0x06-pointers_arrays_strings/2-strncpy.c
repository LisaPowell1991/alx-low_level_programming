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
	for (n = 0; dest[n] != '\0'; n++)
	{
		src[n] = dest[n];
	}
	dest[n] = '\0';
	return (dest);
}
