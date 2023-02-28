#include "main.h"

/**
 * puts_half - function that prints half a string.
 * followed by a new line.
 * @str: char to check
 * Return: void.
 */

void puts_half(char *str)
{
int n;

for (n = 0; str[n] != '\0'; n++)
{
n++;

for (n /= 2; str[n] != '\0'; n++)
{
_putchar(str[n]);
}
}
putchar('\n');
}
