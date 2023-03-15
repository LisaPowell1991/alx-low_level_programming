#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * argstostr - function that concatenates all
 * the arguments of your program.
 * @ac: integer
 * @av: character
 * Return: returns pointer to a new string,
 * or NULL if it fails
 * or returns NULL if ac==0 || av==NULL
 */

char *argstostr(int ac, char **av)
{
	char *str;
	int a, b, c, length = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b] != '\0'; b++)
			length++;
		length++;
	}

	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
	{
		return (NULL);
	}

	c = 0;
	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b] != '\0'; b++)
		{
			str[c] = av[a][b];
			c++;
		}
		str[c] = '\n';
		c++;
	}
	return (str);
}
