#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int n;

	for (n = 'A'; n <= 'Z'; n++)
	{
		n = tolower(n);
		putchar(n);
	}
	for (n = 'a'; n <= 'Z'; n++)
	{
		n = toupper(n);
		putchar(n);
	}
	putchar('\n');
	return (0);
}
