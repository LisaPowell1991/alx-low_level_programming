#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: the string to be reversed.
 *
 * Return: nothing.
 */
void rev_string(char *s)
{
	int a = 0, b;
	char tmp;

	for (; s[a] != '\0'; a++)
		;

	for (b = 0; b < (i / 2); b++)
	{
		tmp = s[b];
		s[b] = s[a - b - 1];
		s[a - b - 1] = tmp;
	}
}
