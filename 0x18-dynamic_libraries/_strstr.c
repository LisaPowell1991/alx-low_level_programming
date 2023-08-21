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
	int a = 0, b, c;

	if (needle[0] == '\0')
		return (haystack);

	while (haystack[a] != '\0') /* iterate through haystack */
	{
		/* if a byte matches first char of needle */
		/* interate through needle until match ends */
		if (haystack[a] == needle[0])
		{
			c = a, b = 0;

			while (needle[b] != '\0')
			{
				if (haystack[c] == needle[b])
					c++, b++;
				else
					break;
			} /* if matched throughout, return haystack */

			if (needle[b] == '\0')
			{
				return (haystack + a);
			}
		}
		a++;
	}
	return (NULL); /* No match */
}
