#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0
 * at a given index
 * @n: Pointer to the unsigned long integer
 * @index: Index of the bit to be cleared
 *
 * Return: 1 if successful,
 * or -1 on failure
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(*n) * 8 - 1)
		return (-1);

	*n &= ~(1UL << index);

	return (1);
}
