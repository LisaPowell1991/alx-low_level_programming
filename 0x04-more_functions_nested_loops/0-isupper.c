#include "main.h"
#include <stdio.h>

/**
 * _isupper - check if character is uppercase.
 *
 *@c: The character to print.
 * Return:returns 1 if c is uppercase,else returns 0.
 */

int _isupper(int c)
{
	char ch = c;

	if (ch >= 65 && ch <= 90)
		return (1);	
	else
		return (0);
}
