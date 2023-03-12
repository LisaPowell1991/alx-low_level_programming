#include <stdio.h>

/**
 * main -  function that prints all arguments it receives,
 * followed by a new line.
 * @argc:integer
 * @argv:integer
 * Return: returns 0.
 */

int main(int argc, char __attribute__((__unused__)) *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
