#include "main.h"
#include <stdio.h>

/**
 * main - function that prints fizz, buzz, fizzbuzz
 *@size: interger
 * Return: nothing
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("Fizz\n");
		}
		
		else if (i % 5 == 0)
		{
			printf("Buzz\n");
		}
		
		else if (i % 15 == 0)
		{
			printf("FizzBuzz");
		}
		else {
			printf("%d\n", i);
		}
	}
	return (0);
}










}
