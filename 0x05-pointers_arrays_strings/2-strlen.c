#include "main.h"

/**
 *  _strlen - function that returns the length of a string.
 * @s: char to check
 * Return: void.
 */

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
