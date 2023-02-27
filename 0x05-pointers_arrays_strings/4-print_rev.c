#include "main.h"

/**
 * print_rev - function that prints a string in reverse.
 * followed by a new line.
 * @s: char to check
 * Return: void.
 */

void print_rev(char *s)
{
	int a = 0, b, c;
	char *str, temp;

	while (a >= 0)
	{
		if (s[a] == '\0')
			break;
		a++;
	}
	str = s;
	
	for (b = 0; b < (a - 1); b++)
	{
		for (c = b + 1; c > 0; c--)
		{
			temp = *(str + c);
			*(str +c) = *(str + (c - 1));
			*(str + (c - 1)) = temp;

		}
	}
}
