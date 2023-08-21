#include "main.h"

/**
 * _strcat -  function that concatenates two strings.
 * @dest: integer
 * @src: integer
 * Return: returns concate string.
 */

char *_strcat(char *dest, char *src)
{
	int char_used = 0;
	int max_size = 0;

	while (dest[char_used] != '\0')
		char_used++;

	while (src[max_size] != '\0')
	{
		dest[char_used] = src[max_size];
		char_used++;
		max_size++;
	}
	dest[char_used] = '\0';
	return (dest);
}
