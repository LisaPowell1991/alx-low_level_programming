#include "main.h"

/**
 * rot13 - function that encodes a string using rot13
 * @str: string to be encoded
 * Return: returns str.
 */

char *rot13(char *str)
{
	int i, j;
	char *first = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *second = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i] != '\0'; i++)
		for (j = 0; first[j] != '\0'; j++)
		if (str[i] == first[j])
		{
			str[i] = second[j];
			break;
		}

	return (str);
}
