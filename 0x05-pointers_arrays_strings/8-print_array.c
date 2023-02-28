#include "main.h"
#include <stdio.h>

/**
 * print_array - Prints n elements of an array of integers.
 * followed by a new line.
 * @a: integer
 * @n: integer
 * Return: void.
 */

void print_array(int *a, int n)
{
int i = 0;

for (n--; n >= 0; n--, i++)
{
printf("%d", a[i]);

if (n > 0)
{
printf(", ");
}
}
putchar('\n');
}
