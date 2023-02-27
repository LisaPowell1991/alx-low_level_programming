#include "main.h"

/**
 * swap_int - function that swaps the values of two integers.
 * @a:int to check.
 * @b:int to check.
 * Return: void.
 */

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
