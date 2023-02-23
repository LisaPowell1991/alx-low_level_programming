#include "main.h"

/**
 * print_line  - prints a straight line
 *@n: interger
 * Return: nothing
 */

void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (n = 1; i <= n; i++)
		{
			_putchar('_');
		}
	}
}
