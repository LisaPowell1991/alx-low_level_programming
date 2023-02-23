#include "main.h"

/**
 * print_line  - prints a straight line
 *@n: interger
 * Return: nothing
 */

void print_line(int n)
{
	int n;

	while (--n > 0)
	{
		_putchar('_');
	}
	_putchar('\n');
}
