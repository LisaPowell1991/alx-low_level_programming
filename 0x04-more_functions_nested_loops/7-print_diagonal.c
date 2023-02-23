#include "main.h"

/**
 * print_diagonal - prints a diagonal line
 *@n: interger
 * Return: nothing
 */

void print_diagonal(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			_putchar(92);
		}
		_putchar('\n');
	}
}
