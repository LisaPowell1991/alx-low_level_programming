#include <stdio.h>
#include <stdlib.h>

/**
 * main -  function that prints the minimum number of coins
 * to make change for an amount of money.
 * @argc:integer
 * @argv:integer
 * Return: returns 1 if number of arguments
 * passed to your program is not exactly 1
 * or 0 if it's successful
 */

int main(int argc, char *argv[])
{
	int cents, count = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);

	while (cents > 0)
	{
		if (cents >= 25)
		{
			cents -= 25;
		}
		else if (cents >= 10)
		{
			cents -= 10;

		}
		else if (cents >= 5)
		{
			cents -= 5;
		}
		else if (cents >= 2)
		{
			cents -= 2;
		}
		else if (cents >= 1)
			cents -= 1;
		count += 1;
	}
	printf("%d\n", count);
	return (0);
}
