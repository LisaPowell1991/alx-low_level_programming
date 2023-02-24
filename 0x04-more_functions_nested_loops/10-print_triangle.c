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
		for (a = 0; a < size; a++)
		{
			for (b = size - a; b > 1; b--)
			{
				putchar(32);
			}

			for (c = 0; c <= a; c++)
			{
				putchar(35);
			}
			putchar('\n');
		}
	}
}

