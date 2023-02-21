#include "main.h"

/**
 * _isalpha - letter check
 *@c: is c an integer argument
 *
 * Return: Always 0.
 */

int _isalpha(int c)
{
	if (isdigit(c) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
