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
		while (dest[n] != '\0')
		{
			dest[n] = src[n];
			n++;
		}
	src[n] = '\0';
	
	return (dest);
}
