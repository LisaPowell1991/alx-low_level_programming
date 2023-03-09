#include "main.h"

int is_prime_number(int n);
int is_prime(int n, int i);

/**
 * is_prime_number - function that indicates if input integer is a prime number
 * @n: integer
 * Return: returns 1 if the input integer is a prime number
 * otherwise 0.
 */

int is_prime_number(int n)
{
	if (n == 2)
		return (1);
	else if (n < 2)
		return (0);
	return (is_prime(n, 2));
}

/**
 * is_prime - test if num is prime
 * @n: number to check
 * @i: integer
 * Return: 1 if prime, otherwise 0.
 */

int is_prime(int n, int i)
{
	if (i >= n / 2)
		return (1);
	if (n % i)
		return (is_prime(n, i + 1));
	return (0);
}
