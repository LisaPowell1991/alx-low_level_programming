#include "main.h"

/**
 * _memcpy - function that copies memory area.
 * @dest: pointer
 * @src: pointer
 * @n: number of bytes filled
 * Return:returns a pointer to dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	int bytes = n;

	if (bytes > 0)
	{
		int j;

	for (j = 0; j < bytes; j++)
	{
		dest[j] = src[j];
	}
	}
	return (dest);
}
