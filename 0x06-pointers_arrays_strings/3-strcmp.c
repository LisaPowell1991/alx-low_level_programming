#include "main.h"

/**
 * _strcmp - function that compares two string.
 * @s1: integer
 * @s2: integer
 * Return: returns 0 if s1 == s2.
 * negative value if s1 < s2.
 * positive value if s1 > s2.
 */

int _strcmp(char *s1, char *s2)
{
	int compare = 0;

	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
	}

		if (s1 != s2)
		{
			compare = *s1 - *s2;
		}
		return (compare);
}
