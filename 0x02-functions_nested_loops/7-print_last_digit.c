#include "main.h"

/**
 * print_last_digit - Print last num
 *
 * @n: check last num is printed
 *
 * Return: value of last digit.
 */

int print_last_digit(int n)
{
	int last_digit;

	if (n < 0)
	{
		n = -n;
	}

	last_digit = n % 10;

	if (last_digit < 0)
	{
		last_digit = -last_digit;
	}

	return (last_digit);
}
