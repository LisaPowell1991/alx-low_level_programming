#include "main.h"

/**
 * rev_string - reverses a string.
 * @s: the string to be reversed.
 *
 * Return: nothing.
 */
void rev_string(char *s)
{

int a, b, c;
	char temp;

	for (a = 0; s[a] != '\0'; a++)
	b = 0;
	c = a / 2;

	while (c--)
	{
		temp = s[a - b - 1];
		s[a - b - 1] = s[b];
		s[b] = temp;
		b++;
	}
}

