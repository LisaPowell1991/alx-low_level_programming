#include "main.h"

int is_palindrome(char *s);
int find_strlen(char *s);
int check_if_palindrome(char *s, int index, int length);

/**
 * is_palindrome - function that confirm a string is a palindrome.
 * @s: integer
 * Return: returns 1 if palindrome
 * otherwise 0.
 */

int is_palindrome(char *s)
{
	if (!s)
		return (1);
	return (check_if_palindrome(s, 0, find_strlen(s)));

}
/**
 * find_strlen - function that determines length of string.
 * @s: integer
 * Return: returns length of string
 */

int find_strlen(char *s)
{
	if (*s != '\0')
		return (1 + find_strlen(s + 1));
	else
		return (0);
}

/**
 * check_if_palindrome - function that check if a string is a palindrome.
 * @s: string
 * @index: index
 * @length: length of string
 * Return: returns 1 if palindrome
 * otherwise 0.
 */

int check_if_palindrome(char *s, int index, int length)
{
	if (s[index] == s[length / 2])
	return (1);

	if (s[index] == s[length - index - 1])
		return (check_if_palindrome(s, index + 1, length));

	return (0);
}
