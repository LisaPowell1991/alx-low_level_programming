#include <stdio.h>
#include <stdlib.h>

/**
 * main -  function that multiplies two numbers,
 * followed by a new line.
 * @argc:integer
 * @argv:integer
 * Return: returns 0 or 1 if there is not 2 arguments.
 */

int main(int argc, char *argv[])
{
	int i, j, mul;

	if (argc <= 2)
	{
		printf("Error\n");
		return (1);
	}

	i = atoi(argv[1]);
	j = atoi(argv[2]);
	mul = i * j;

	printf("%d\n", mul);

	return (0);
}
