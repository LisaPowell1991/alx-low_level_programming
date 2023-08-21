#include <stdio.h>

/**
 * add - Adds 2 integers.
 * @a: The first int
 * @b: The second int
 *
 * Return: The sum of both integers
 */

int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - Subtracts two integers
 * @a: The first int
 * @b: The second int
 *
 * Return: The result of first int minus second int
 */

int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - Multiplies two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: The product of the two integers
 */

int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - Divides two integers
 * @a: First int
 * @b: Second int
 *
 * Return: The reslt of integer division of @a by @b.
 */

int div(int a, int b)
{
	return (a / b);
}

/**
 * mod - Computes the modulo of two integers
 * @a: First int
 * @b: Second int
 *
 * Return: The remainder of the division of the two integers
 */

int mod(int a, int b)
{
	return (a % b);
}
