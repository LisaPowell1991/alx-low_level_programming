#include "main.h"

/**
 * print_square - function that prints a squaare
 *@size: interger
 * Return: nothing
 */

void print_square(int size)
{
	int i, n;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			for (n = 0; n < size; n++)
			{
				_putchar(35);
			}
			_putchar('\n');
		}
	}
}
