#include "main.h"

/**
 * _strstr - function that locates a substring.
 * @haystack: pointer
 * @needle: pointer
 * Return: Returns a pointer to the beginning of the located substring
 * or NULL if the substring is not found.
 */

char *_strstr(char *haystack, char *needle)
{
	int a = 0, b = 0;

	while ((*(haystack + b) != '\0') && (*(needle + a) != '\0'))
	{
		if (*(needle + a) != *(haystack + b))
		{
			b++;
			a = 0;
		}
		else
		{
			a++;
			b++;
		}
	}
	if (*needle == '\0')
		return (haystack);

	return ('\0');
}
