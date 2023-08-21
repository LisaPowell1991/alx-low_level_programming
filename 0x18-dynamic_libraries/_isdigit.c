#include "main.h"

/**
 * _isdigit - check if character is uppercase.
 *
 *@c: The character to print.
 * Return:returns 1 if c is uppercase,else returns 0.
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
