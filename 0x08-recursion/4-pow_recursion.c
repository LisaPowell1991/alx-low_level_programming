#include "main.h"

/**
 * _pow_recursion - function that returns the value
 * of x raised to the power of y.
 * @x: integer
 * @y: integer
 * Return: returns value of x raised to the power of y
 * or -1 if y < 0.
 */

int _pow_recursion(int x, int y)
{
	int power;

	if (y < 0)
		return (-1);

	power = _pow_recursion(x, y - 1);

	return (x * power);
}
