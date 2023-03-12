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
		count++;

		if ((cents - 25) > 0)
		{
			cents -= 25;
			continue;
		}
		if ((cents - 10) > 0)
		{
			cents -= 10;
			continue;
		}
		if ((cents - 5) > 0)
		{
			cents -= 5;
			continue;
		}
		if ((cents - 2) > 0)
		{
			cents -= 2;
			continue;
		}
		cents--;
	}
	printf("%d\n", count);
	return (0);
}


