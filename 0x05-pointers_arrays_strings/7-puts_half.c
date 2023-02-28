#include "main.h"

/**
 * puts_half - function that prints half a string.
 * followed by a new line.
 * @str: char to check
 * Return: void.
 */

void puts_half(char *str)
{
int n = 0, i;

while (n >= 0)
{
if (str[n] == '\0')
break;
n++;
}

if (n % 2 == 1)
i = n / 2;
else
i = (count - 1) / 2;

for (i++; i < n; i++)
_putchar(str[i]);

putchar('\n');
}
