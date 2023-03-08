#include "main.h"

/**
 * _print_rev_recursion - function that prints a string in reverse.
 * @s:char
 * Return: returns void.
 */

void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_putchar(s[0]);
		_print_rev_recursion(s + 1);

	}
}
