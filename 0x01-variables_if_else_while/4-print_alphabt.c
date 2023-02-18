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
for (n = 'A'; n <= 'z'; n++)
{
	n = tolower(n);
	while (n <= 'z')
	{
	n++;
	if (n == 'q' || n == 'e')
		n++;
	}
	putchar(n);
	}
putchar('\n');
return (0);
}
