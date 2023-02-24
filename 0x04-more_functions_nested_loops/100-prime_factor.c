#include <stdio.h>

/**
 * main  - prime factor numbers
 *
 * Return: 0
 */

int main(void)
{
	int num = 612852475143, i;

	for (i = 1; i <= num; ++i)
	{
		if (num % i == 0)
		{
			printf("%d ", i)
		}
	}
	printf("\n");

	return (0);
}
