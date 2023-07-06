#include "main.h"

/**
 * flip_bits - function to get the num of bits needed
 * to flip from one num to another
 * @n: unsigned long int representing the first num
 * @m: unsigned long int representing the second num
 *
 * Return: the num of bits needed to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_val = n ^ m;
	int count = 0;

	while (xor_val)
	{
		if (xor_val & 1)
			count++;
		xor_val >>= 1;
	}
	return (count);
}
