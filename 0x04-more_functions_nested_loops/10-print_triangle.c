include "main.h"

/**
 * print_triangle - Prints n triangle according n number of times
 *
 * @size: The number of triangle/number of times
 *
 * Return: void
 */

void print_triangle(int size)
{
	int a, b, c;

	if (size <= 0)
	{
		_putchar('/n');
	}
	else
	{
		for (a = 1; a <= size; a++)
		{
			for (b = size; b > 0; b--)
			{
				if (j == i)
				{
					for (c = a; c > 0; c--)
					{
						putchar('#');
					}
				else if (b > a)
			{
				putchar(' ');
			}
				}
			putchar('\n');
			}
		}
	}
}
