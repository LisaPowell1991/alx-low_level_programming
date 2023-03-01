#include "main.h"

/**
 * puts2 - function that prints every other char.
 * followed by a new line.
 * @str: char to check
 * Return: void.
 */

void puts2(char *str)
{
int n = 0;

while (str[n] != '\0')
{
if (n % 2 == 0)
{
_putchar(str[n]);
}
n++;
}
putchar('\n');
}
