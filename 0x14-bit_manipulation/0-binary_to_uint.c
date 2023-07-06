#include "main.h"

/**
 * binary_to_uint - Converts a binary num to an unsigned int.
 * @b: Binary num as a string
 *
 * Return: The converted num or 0 if b
 * contains non-binary characters or is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int val = 0;
	int i = 0;

	if (b == NULL)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		val = 2 * val + (b[i] - '0');
	}
	return (val);
}
