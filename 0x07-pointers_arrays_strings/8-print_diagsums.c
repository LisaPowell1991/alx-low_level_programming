#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers.
 * @a: pointer
 * @size: integer
 * Return: Returns void
 */

void print_diagsums(int *a, int size)
{
	int i;
	int j = 0;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		j += a[i];
		k += a[size - i - 1];
		a += size;
	}
	printf("%d, ", j);
	printf("%d\n", k);
}
