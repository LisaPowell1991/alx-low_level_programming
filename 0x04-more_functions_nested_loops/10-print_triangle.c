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
	int a, b;

	if (size > 0)
	{
		for (a = 1; a <= size; a++)
		{
			for ((b = size - a); b > 0; b--)
			{
				putchar(' ');
			}

			for (b = 0; b < a; b++)
			{
				putchar('#');
			}

			if (a == size)
			{
				continue;
			}

			putchar('\n');
		}
	}
	putchar('\n');
}

