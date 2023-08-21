#include "main.h"

/**
 * _strspn - function that gets the length of a prefix substring.
 * @s: pointer
 * @accept:pointer
 * Return: Returns the number of bytes in the initial segment of s
 * which consist only of bytes from accept.
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, j, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (count != i)
			break;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				count++;
		}
	}
	return (count);
}
