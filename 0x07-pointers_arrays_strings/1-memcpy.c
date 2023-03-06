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
	int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
