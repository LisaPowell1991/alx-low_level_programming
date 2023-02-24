#include <stdio.h>

/**
 * main  - prime factor numbers
 *
 * Return: 0
 */

int main(void)
{
	long num = 612852475143, i;

	for (i = 2; i < num; i++)
	{
		while (num % i == 0)
			num = num / i;
	}
			printf("%lu\n", num);
	return (0);
}
