#include "main.h"

/**
 * factorial - function that returns the factorial of a given number.
 * @n: integer
 * Return: returns -1 if n < 0.
 */

int factorial(int n)
{
	int next;

	if (n == 0)
		return (1);
	else if (n < 0)
		return (-1);

	next = factorial(n - 1);

	return (n * next);
}
