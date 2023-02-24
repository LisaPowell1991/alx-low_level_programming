#include <stdio.h>

/**
 * main  - prime factor numbers
 *
 * Return: 0
 */

int main(void)
{
int i, j, num, ;

for (i = 1; i <= 100; i++)
{
	if (i % 3 == 0 && i % 5 == 0)
	{
		printf("FizzBuzz ");
	}
	else if (i % 5 == 0 && i == 100)
	{
		printf("Buzz");
	}
	else if (i % 5 == 0)
	{
		printf("Buzz ");
	}
	else if (i % 3 == 0)
	{
		printf("Fizz ");
	}
	else
	{
		printf("%d ", i);
	}
}
printf("\n");
return (0);
}
