#include "main.h"

/**
 * print_diagonal - prints a diagonal line
 *@n: interger
 * Return: nothing
 */

void print_diagonal(int n)
{
	int i, gap;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			for (gap = 0; gap < i; gap++)
			{
			_putchar(' ');
			}

			 _putchar(92);
			 _putchar('\n');
		}
	}
}
