#include "main.h"

/**
 * get_endianness - function that checks the endianness
 *
 * Return: returns 0 if big endian,
 * or 1 of it is a little endian
 */

int get_endianness(void)
{
	unsigned int val = 1;
	char *n = (char *)&val;

	if (*n == 1)
		return (1);

	return (0);
}
