#include "main.h"

/**
 * _puts_recursion -  function that prints a string, followed by a new line.
 * @s:char
 * Return: returns void.
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		return;
	}
	_puts_recursion(s - 1);

	_putchar(*s);

	_putchar('\n');
}
