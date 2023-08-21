#include "main.h"
/**
 * _atoi - convert a string to an integer
 * @s: char to check
 *
 * Return: 0 is success
 */

int _atoi(char *s)
{
	int a = 1;
	unsigned int i = 0;

	do {
		if (*s == '-')
		{
			a *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			i = i * 10 + (*s - '0');
		}
		else if (i > 0)
			break;
	} while (*s++);
	return (i * a);
}
