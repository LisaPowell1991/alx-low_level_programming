#include "main.h"
/**
 * times_table -  a function that prints the 9 times table, starting with 0
 * Return: void
 */

void times_table(void)
{
	int row = 0;
	int col;
	int n;

	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			n = row * col;
			if (n > 9)
			{
				putchar(n / 10 + '0');
				putchar(n % 10 + '0');
			}
			else if (col != 0)
			{
				putchar(' ');
				putchar(n + '0');
			}
			else
			{
				putchar(n + '0');
			}
			if (col != 9)
			{
				putchar(',');
				putchar(' ');
			}
			col++;
		}
		putchar('\n');
		row++;
	}
}
