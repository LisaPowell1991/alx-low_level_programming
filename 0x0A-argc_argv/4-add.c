#include <stdio.h>
#include <stdlib.h>

/**
 * main -  function that adds two positive numbers,
 * followed by a new line.
 * @argc:integer
 * @argv:integer
 * Return: returns 0 or 1 if there is not 2 arguments.
 */

int main(int argc, char *argv[])
{
	int i, j, sum = 0;
	
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j])
			{
				printf("Error\n");
				return (1);
			}
		}
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
