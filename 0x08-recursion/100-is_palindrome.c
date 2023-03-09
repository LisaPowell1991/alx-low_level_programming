#include "main.h"

/**
 * wildcmp- function that compares 2 strings
 * @s1: integer
 * @s2: integer
 * Return: returns 1 if identical
 * otherwise 0.
 */

int wildcmp(char *s1, char *s2)
{
	if ((*s1 == '\0' && *s2 != '\0')
	|| (*s1 != '\0' && *s2 == '\0')
	|| *s1 != *s2)
	{
		return (0);
	}
		return (1);
}
