#include "main.h"

/**
 * cap_string - function that capitalizes all words of a string.
 * @str:integer
 * Return: returns str.
 */

char *cap_string(char *str)
{
	int i = 0;
	int space = 0;

	while (str[i] != '\0')
	{
		if ((space % 2 == 1) && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}

		if (str[i] == ' ')
			i++;
	}
	return (str);
}
