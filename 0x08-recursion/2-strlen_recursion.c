#include "main.h"

/**
 * _strlen_recursion - function that returns the length of a string.
 * @s:char
 * Return: returns void.
 */

int _strlen_recursion(char *s)
{
	int len = 0;

	if (*s != '\0')
	{
		len++;
		 _strlen_recursion(++s);
	}
	return (len);
}
