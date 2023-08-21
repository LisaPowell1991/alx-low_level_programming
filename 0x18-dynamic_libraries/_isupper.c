#include "main.h"

/**
 * _isupper - check if character is uppercase.
 *
 *@c: The character to print.
 * Return:returns 1 if c is uppercase,else returns 0.
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
