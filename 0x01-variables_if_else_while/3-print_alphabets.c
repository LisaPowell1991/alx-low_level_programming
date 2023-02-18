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
	int n = 'a';

	while (n <= 'z')
	putchar(n++);
	n = 'A';

	while (n <= 'Z')
	putchar(n++);
	putchar('\n');
	return (0);
}
