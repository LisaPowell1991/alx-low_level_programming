#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char charType;
	int intType;
	long int longInt;
	long long int longLongInt;
	float floatType;

printf("Size of a char: %ld byte(s)\n", sizeof(charType));
printf("Size of an int: %ld byte(s)\n", sizeof(intType));
printf("Size of a long int: %ld byte(s)\n", sizeof(longInt));
printf("Size of a long long int: %ld byte(s)\n", sizeof(longLongInt));
printf("Size of a float: %ld byte(s)\n", sizeof(floatType));

return (0);
}
