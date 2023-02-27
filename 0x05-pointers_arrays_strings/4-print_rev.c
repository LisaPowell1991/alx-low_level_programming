#include "main.h"

/**
 * print_rev - function that prints a string in reverse.
 * followed by a new line.
 * @s: char to check
 * Return: void.
 */

void print_rev(char *s)
{
	int a = 0, b;
	char d; 

	for (; s[a] != '\0'; a++)
		;

	for (b = 0; b (a / 2); b++)
	{
		d = s[b];
		s[b] = s[a - b - 1];
		s[a - b - 1] = d;
	}
}
